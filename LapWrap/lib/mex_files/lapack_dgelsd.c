/*
 * clapack_dgelsd.c
 *
 *This program is a C interface to dgelsd.
 *
 * Written by Remi Delmas.
 *
 */

#include "mex.h"

#define min(a,b) ((a)>(b) ? (b) : (a))
#define max(a,b) ((a)<(b) ? (b) : (a))

#if defined(ADD_)
	#define f77_dgelsd dgelsd_
#elif defined(UPCASE)
	#define f77_dgelsd DGELSD
#else
	#define f77_dgelsd dgelsd
#endif

char *select_name;

void mexFunction(int nlhs_m, mxArray *plhs_m[], int nrhs_m, const mxArray *prhs_m[])
{

	int i;

	int * m;
	int * n;
	int * nrhs;
	double * a;
	int * lda;
	double * b;
	int * ldb;
	double * s;
	double * rcond;
	int * rank;
	double * work;
	int * lwork;
	int * iwork;
	int * info;

	plhs_m[0]=mxDuplicateArray(prhs_m[0]);
	m=(int *)mxGetPr(plhs_m[0]);

	plhs_m[1]=mxDuplicateArray(prhs_m[1]);
	n=(int *)mxGetPr(plhs_m[1]);

	plhs_m[2]=mxDuplicateArray(prhs_m[2]);
	nrhs=(int *)mxGetPr(plhs_m[2]);

	plhs_m[4]=mxDuplicateArray(prhs_m[4]);
	lda=(int *)mxGetPr(plhs_m[4]);

	plhs_m[6]=mxDuplicateArray(prhs_m[6]);
	ldb=(int *)mxGetPr(plhs_m[6]);

	plhs_m[9]=mxDuplicateArray(prhs_m[9]);
	rank=(int *)mxGetPr(plhs_m[9]);

	plhs_m[11]=mxDuplicateArray(prhs_m[11]);
	lwork=(int *)mxGetPr(plhs_m[11]);

	plhs_m[13]=mxDuplicateArray(prhs_m[13]);
	info=(int *)mxGetPr(plhs_m[13]);







	plhs_m[3]=mxDuplicateArray(prhs_m[3]);
	a = mxGetPr(plhs_m[3]);



	plhs_m[5]=mxDuplicateArray(prhs_m[5]);
	b = mxGetPr(plhs_m[5]);



	plhs_m[7]=mxDuplicateArray(prhs_m[7]);
	s = mxGetPr(plhs_m[7]);

	plhs_m[8]=mxDuplicateArray(prhs_m[8]);
	rcond = mxGetPr(plhs_m[8]);



	plhs_m[10]=mxDuplicateArray(prhs_m[10]);
	work = mxGetPr(plhs_m[10]);



	plhs_m[12]=mxDuplicateArray(prhs_m[12]);
	iwork = (int *) mxGetPr(plhs_m[12]);



#ifdef F77_INT
	F77_INT* F77_m = m , F77_n = n , F77_nrhs = nrhs , F77_lda = lda , F77_ldb = ldb , F77_rank = rank , F77_lwork = lwork , F77_iwork = iwork , F77_info = info ;
#else
	#define F77_m m 
	#define F77_n n 
	#define F77_nrhs nrhs 
	#define F77_lda lda 
	#define F77_ldb ldb 
	#define F77_rank rank 
	#define F77_lwork lwork 
	#define F77_iwork iwork 
	#define F77_info info 
#endif

	f77_dgelsd(F77_m, F77_n, F77_nrhs, a, F77_lda, b, F77_ldb, s, rcond, F77_rank, work, F77_lwork, F77_iwork, F77_info);

	return;
}
