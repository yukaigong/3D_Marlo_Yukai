@echo off
set MATLAB=C:\PROGRA~1\MATLAB\R2016a
set MATLAB_ARCH=win64
set MATLAB_BIN="C:\Program Files\MATLAB\R2016a\bin"
set ENTRYPOINT=mexFunction
set OUTDIR=.\
set LIB_NAME=f_initFourBar_RightStance_mex
set MEX_NAME=f_initFourBar_RightStance_mex
set MEX_EXT=.mexw64
call setEnv.bat
echo # Make settings for f_initFourBar_RightStance > f_initFourBar_RightStance_mex.mki
echo COMPILER=%COMPILER%>> f_initFourBar_RightStance_mex.mki
echo COMPFLAGS=%COMPFLAGS%>> f_initFourBar_RightStance_mex.mki
echo OPTIMFLAGS=%OPTIMFLAGS%>> f_initFourBar_RightStance_mex.mki
echo DEBUGFLAGS=%DEBUGFLAGS%>> f_initFourBar_RightStance_mex.mki
echo LINKER=%LINKER%>> f_initFourBar_RightStance_mex.mki
echo LINKFLAGS=%LINKFLAGS%>> f_initFourBar_RightStance_mex.mki
echo LINKOPTIMFLAGS=%LINKOPTIMFLAGS%>> f_initFourBar_RightStance_mex.mki
echo LINKDEBUGFLAGS=%LINKDEBUGFLAGS%>> f_initFourBar_RightStance_mex.mki
echo MATLAB_ARCH=%MATLAB_ARCH%>> f_initFourBar_RightStance_mex.mki
echo BORLAND=%BORLAND%>> f_initFourBar_RightStance_mex.mki
echo OMPFLAGS= >> f_initFourBar_RightStance_mex.mki
echo OMPLINKFLAGS= >> f_initFourBar_RightStance_mex.mki
echo EMC_COMPILER=msvcsdk>> f_initFourBar_RightStance_mex.mki
echo EMC_CONFIG=optim>> f_initFourBar_RightStance_mex.mki
"C:\Program Files\MATLAB\R2016a\bin\win64\gmake" -B -f f_initFourBar_RightStance_mex.mk
