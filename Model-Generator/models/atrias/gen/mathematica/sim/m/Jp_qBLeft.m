function [x_Jp_qBLeft] = Jp_qBLeft(x)
%Jp_qBLeft
%    x_Jp_qBLeft = Jp_qBLeft(x)

% This function was generated by Mathematica Common 
% Subexpression Eliminating Package (CseOptimization)
% Thu 26 Jan 2017 21:34:13

t1=x(4);
t2=x(6);
t3=cos(t1);
t4=x(5);
t5=x(12);
t6=cos(t5);
t7=cos(t2);
t8=sin(t1);
t9=sin(t4);
t10=sin(t2);
t11=cos(t4);
t12=sin(t5);
t13=t7.*t8.*t9;
t14=t10.*t3;
t15=t13 + t14;
x_Jp_qBLeft=[1,0,0,0,1,0,0,0,1,0,(-1831/10000).*(t11.*t12.*t3 + t6.*((-1).* ...
  t10.*t8 + t3.*t7.*t9)),(-1831/10000).*(t15.*t6 + t11.*t12.*t8),( ...
  -1831/10000).*((-1).*t11.*t12 + (-1).*t6.*t7.*t9),(-1831/10000).*( ...
  t11.*t6.*t7.*t8 + (-1).*t12.*t8.*t9),(-1831/10000).*((-1).*t11.* ...
  t3.*t6.*t7 + t12.*t3.*t9),(1831/10000).*t10.*t11.*t6,(-1831/10000) ...
  .*t6.*(t3.*t7 + (-1).*t10.*t8.*t9),(-1831/10000).*t6.*(t7.*t8 +  ...
  t10.*t3.*t9),0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,(-1831/10000).*((-1).* ...
  t11.*t12.*t7 + (-1).*t6.*t9),(-1831/10000).*((-1).*t12.*t15 +  ...
  t11.*t6.*t8),(-1831/10000).*((-1).*t11.*t3.*t6 + (-1).*t12.*(t10.* ...
  t8 + (-1).*t3.*t7.*t9)),0,0,0,0,0,0,0,0,0,0,0,0];

end %function