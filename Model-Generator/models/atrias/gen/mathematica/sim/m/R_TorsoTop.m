function [x_R_TorsoTop] = R_TorsoTop(x)
%R_TorsoTop
%    x_R_TorsoTop = R_TorsoTop(x)

% This function was generated by Mathematica Common 
% Subexpression Eliminating Package (CseOptimization)
% Thu 26 Jan 2017 21:34:17

t1=x(6);
t2=cos(t1);
t3=x(5);
t4=x(4);
t5=cos(t4);
t6=sin(t3);
t7=sin(t4);
t8=sin(t1);
t9=cos(t3);
x_R_TorsoTop=[t2.*t9,t2.*t6.*t7 + t5.*t8,(-1).*t2.*t5.*t6 + t7.*t8,(-1).*t8.* ...
  t9,t2.*t5 + (-1).*t6.*t7.*t8,t2.*t7 + t5.*t6.*t8,t6,(-1).*t7.*t9, ...
  t5.*t9];

end %function