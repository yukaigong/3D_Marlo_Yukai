@echo off
set MATLAB=C:\PROGRA~1\MATLAB\R2016a
set MATLAB_ARCH=win64
set MATLAB_BIN="C:\Program Files\MATLAB\R2016a\bin"
set ENTRYPOINT=mexFunction
set OUTDIR=.\
set LIB_NAME=J_yaw_LeftStance_mex
set MEX_NAME=J_yaw_LeftStance_mex
set MEX_EXT=.mexw64
call setEnv.bat
echo # Make settings for J_yaw_LeftStance > J_yaw_LeftStance_mex.mki
echo COMPILER=%COMPILER%>> J_yaw_LeftStance_mex.mki
echo COMPFLAGS=%COMPFLAGS%>> J_yaw_LeftStance_mex.mki
echo OPTIMFLAGS=%OPTIMFLAGS%>> J_yaw_LeftStance_mex.mki
echo DEBUGFLAGS=%DEBUGFLAGS%>> J_yaw_LeftStance_mex.mki
echo LINKER=%LINKER%>> J_yaw_LeftStance_mex.mki
echo LINKFLAGS=%LINKFLAGS%>> J_yaw_LeftStance_mex.mki
echo LINKOPTIMFLAGS=%LINKOPTIMFLAGS%>> J_yaw_LeftStance_mex.mki
echo LINKDEBUGFLAGS=%LINKDEBUGFLAGS%>> J_yaw_LeftStance_mex.mki
echo MATLAB_ARCH=%MATLAB_ARCH%>> J_yaw_LeftStance_mex.mki
echo BORLAND=%BORLAND%>> J_yaw_LeftStance_mex.mki
echo OMPFLAGS= >> J_yaw_LeftStance_mex.mki
echo OMPLINKFLAGS= >> J_yaw_LeftStance_mex.mki
echo EMC_COMPILER=msvcsdk>> J_yaw_LeftStance_mex.mki
echo EMC_CONFIG=optim>> J_yaw_LeftStance_mex.mki
"C:\Program Files\MATLAB\R2016a\bin\win64\gmake" -B -f J_yaw_LeftStance_mex.mk
