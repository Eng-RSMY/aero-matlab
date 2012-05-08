%% 1D Heat Transfer LBM D1Q2
% by Manuel Diaz
clc; clear; %close all;

%% Domain Grid
L = 30;    % Length
n = 30;    % Nodes
dx = L/n; dt = 1;
x  = 1:dx:L;

%% Initial Condition
f1 = zeros(1,n);
f2 = zeros(1,n);
rho= zeros(1,n); % initial value of the dependent variable rho = T(x,t)
feq= zeros(1,n);

%% Constants
csq   = (dx^2)/(dt^2);
alpha = 0.25;
omega = 1/(alpha/(dt*csq)+0.5);
w     = [1/2,1/2];
cx    = [  1, -1];
cy    = [  0,  0];
links = [  1,  2];
iter  = 200; % time steps

%% Boundary Conditions
twall = 1; 

%% Main Loop
for k = 1:iter;
    % Collision process
    rho = f1+f2;
    
    % for this case k1=k2=1/2m then feq1=feq2=feq
    feq = 0.5*rho;  
               
    f1 = (1-omega) * f1 + omega * feq;
    f2 = (1-omega) * f2 + omega * feq;
    % Streaming process
    f1 = stream2d( f1 , [cx(1),cy(1)]);
    f2 = stream2d( f2 , [cx(2),cy(2)]);

%   % Original streaming process in A.A.Mohamad    
%     for i = 2:n-1;  % Double streaming in one loop
%         f1(n-i+1) = f1(n-i);  % Streaming
%         f2( i-1 ) = f2( i );  % Streaming
%     end
    
    % Boundary condition
    f1(1) = twall-f2(1);    %Dirichlet BC
    f1(n) = f1(n-1);        %Neumann BC
    f2(n) = f2(n-1);        %Neumann BC
end

%% Make pretty figures
plot(x,rho);