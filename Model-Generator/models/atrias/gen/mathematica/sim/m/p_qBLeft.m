function [x_p_qBLeft] = p_qBLeft(x)
%p_qBLeft
%    x_p_qBLeft = p_qBLeft(x)

% This function was generated by Mathematica Common 
% Subexpression Eliminating Package (CseOptimization)
% Thu 26 Jan 2017 21:34:13

t1=x(5);
t2=x(12);
t3=cos(t2);
t4=x(6);
t5=cos(t4);
t6=sin(t1);
t7=x(4);
t8=cos(t1);
t9=sin(t7);
t10=sin(t2);
t11=cos(t7);
t12=sin(t4);
x_p_qBLeft=[0. + (-1831/10000).*((-1).*t10.*t6 + t3.*t5.*t8) + x(1),0. + ( ...
  -1831/10000).*(t10.*t8.*t9 + t3.*(t11.*t12 + t5.*t6.*t9)) + x(2), ...
  0. + (-1831/10000).*((-1).*t10.*t11.*t8 + t3.*((-1).*t11.*t5.*t6 + ...
   t12.*t9)) + x(3)];

end %function