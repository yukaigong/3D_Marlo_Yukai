function [x_p_fourBarALeft] = p_fourBarALeft(x)
%p_fourBarALeft
%    x_p_fourBarALeft = p_fourBarALeft(x)

% This function was generated by Mathematica Common 
% Subexpression Eliminating Package (CseOptimization)
% Thu 26 Jan 2017 21:34:14

t1=x(5);
t2=x(12);
t3=cos(t2);
t4=sin(t1);
t5=cos(t1);
t6=x(6);
t7=cos(t6);
t8=sin(t2);
t9=x(13);
t10=cos(t9);
t11=sin(t6);
t12=t3.*t4;
t13=t5.*t7.*t8;
t14=t12 + t13;
t15=sin(t9);
t16=x(15);
t17=cos(t16);
t18=t10.*t14;
t19=t11.*t15.*t5;
t20=t18 + t19;
t21=(-1).*t10.*t11.*t5;
t22=t14.*t15;
t23=t21 + t22;
t24=sin(t16);
t25=x(4);
t26=sin(t25);
t27=(-1).*t17;
t28=1 + t27;
t29=t26.*t4.*t7;
t30=cos(t25);
t31=t11.*t30;
t32=t29 + t31;
t33=t30.*t7;
t34=(-1).*t11.*t26.*t4;
t35=t33 + t34;
t36=(-1).*t26.*t3.*t5;
t37=t32.*t8;
t38=t36 + t37;
t39=t10.*t38;
t40=(-1).*t15.*t35;
t41=t39 + t40;
t42=t10.*t35;
t43=t15.*t38;
t44=t42 + t43;
t45=(-1).*t30.*t4.*t7;
t46=t11.*t26;
t47=t45 + t46;
t48=t26.*t7;
t49=t11.*t30.*t4;
t50=t48 + t49;
t51=t3.*t30.*t5;
t52=t47.*t8;
t53=t51 + t52;
t54=t10.*t53;
t55=(-1).*t15.*t50;
t56=t54 + t55;
t57=t10.*t50;
t58=t15.*t53;
t59=t57 + t58;
x_p_fourBarALeft=[0. + (2/5).*t23.*t24 + (2/5).*(t17.*t20 + (-1).*t23.*t24) + (2/5) ...
  .*t20.*t28 + (-1831/10000).*(t3.*t5.*t7 + (-1).*t4.*t8) + x(1),0.  ...
  + (2/5).*t28.*t41 + (2/5).*t24.*t44 + (2/5).*(t17.*t41 + (-1).* ...
  t24.*t44) + (-1831/10000).*(t3.*t32 + t26.*t5.*t8) + x(2),0. + ( ...
  2/5).*t28.*t56 + (2/5).*t24.*t59 + (2/5).*(t17.*t56 + (-1).*t24.* ...
  t59) + (-1831/10000).*(t3.*t47 + (-1).*t30.*t5.*t8) + x(3)];

end %function