function [ output ] = f_guard_groundHeight_RightStance_mex( vars, extra )
%F_GUARD_GROUNDHEIGHT Function wrapper to combine mathematica generated 
% functions for comupting the guard constraint. 

% Input variables - {'q'}
% Extra variables - groundHeight
q = vars;
groundHeight = extra;

%% Construct constraint from mathematica generated functions
f_name = 'p_toebottomleftback';
tmp1 = feval(f_name,q);

f_name = 'p_toebottomleftfront';
tmp2 = feval(f_name,q);

% swingFootHeight - groundHeight = 0
output = [tmp1(3) - groundHeight; tmp2(3) - groundHeight];

