function install_connector_helper
try
    productName = 'MATLAB Connector';
    
    msg = sprintf('Installing %s...', productName);
    disp(msg)
    
    % installing to matlabroot
    install_dir = matlabroot;
    connectorRoot = fullfile(install_dir, 'toolbox', 'connector');
    zip_file = 'MATLABconnector.zip';
    
    %remove the old files
    if isdir(connectorRoot)
        [a,b,c] = rmdir(connectorRoot,'s'); %#ok<ASGLU,NASGU>
    end
    
    % unzip zip file to install_dir
    msg = sprintf('Extracting archive %s to %s...', zip_file, install_dir);
    disp(msg)
    unzipped_files = unzip(zip_file, install_dir);
    
    % check if files were extracted from zip file
    if (isempty(unzipped_files))
        error('No files were extracted from archive %s.\n%s installation failed.', zip_file, productName)
    end
    
    % fix permissions on extracted files - make files writable
    for i = 1:length(unzipped_files)
        file = unzipped_files{i};
        fileattrib(file, '+w');
    end
    
    %update and save the path
    install_connector_path_update(true);
    
catch ex
    disp(ex.message);
end
end