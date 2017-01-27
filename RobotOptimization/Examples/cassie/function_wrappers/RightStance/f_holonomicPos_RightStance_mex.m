function [ output ] = f_holonomicPos_RightStance_mex( vars )
%F_HOLONOMICPOSITION Function wrapper to combine mathematica and matlab
% generated functions for comupting the holonomic position constraint. 

% Input variables - {'q',h'}
DOF = 22;
nh1 = 4; % Fixed joints
nh2 = 2; % Four bar 
nh3 = 3; % Back toe
nh4 = 3; % Front toe

q = vars(1:DOF);
h1 = vars(DOF+1:DOF+nh1);
h2 = vars(DOF+nh1+1:DOF+nh1+nh2);
h3 = vars(DOF+nh1+nh2+1:DOF+nh1+nh2+nh3);
h4 = vars(DOF+nh1+nh2+nh3+1:end);

%% Construct constraint from mathematica generated functions

% Fixed
f_name = 'f_holConstrPosition_fixed';
tmp1 = feval(f_name,[q,h1]);

% Four bar
f_name = 'f_holConstrPosition_fourbar';
tmp2 = feval(f_name,[q,h2]);

% Back toe
f_name = 'f_holConstrPosition_toebottomrightback';
tmp3 = feval(f_name,[q,h3]);

% Front toe
f_name = 'f_holConstrPosition_toebottomrightfront';
tmp4 = feval(f_name,[q,h4]);

% h - h_des = 0
output = [tmp1; tmp2; tmp3; tmp4];

