function [x_R_LeftFoot] = R_LeftFoot(x)
%R_LeftFoot
%    x_R_LeftFoot = R_LeftFoot(x)

% This function was generated by Mathematica Common 
% Subexpression Eliminating Package (CseOptimization)
% Thu 26 Jan 2017 21:34:19

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
t13=x(14);
t14=cos(t13);
t15=t3.*t6;
t16=t10.*t5.*t8;
t17=t15 + t16;
t18=sin(t13);
t19=x(16);
t20=cos(t19);
t21=t5.*t6.*t9;
t22=t11.*t12;
t23=t21 + t22;
t24=(-1).*t3.*t8.*t9;
t25=t10.*t23;
t26=t24 + t25;
t27=t11.*t5;
t28=(-1).*t12.*t6.*t9;
t29=t27 + t28;
t30=sin(t19);
t31=(-1).*t11.*t5.*t6;
t32=t12.*t9;
t33=t31 + t32;
t34=t11.*t3.*t8;
t35=t10.*t33;
t36=t34 + t35;
t37=t5.*t9;
t38=t11.*t12.*t6;
t39=t37 + t38;
t40=t14.*t17;
t41=t12.*t18.*t8;
t42=t40 + t41;
t43=(-1).*t12.*t14.*t8;
t44=t17.*t18;
t45=t43 + t44;
t46=t14.*t26;
t47=(-1).*t18.*t29;
t48=t46 + t47;
t49=t14.*t29;
t50=t18.*t26;
t51=t49 + t50;
t52=t14.*t36;
t53=(-1).*t18.*t39;
t54=t52 + t53;
t55=t14.*t39;
t56=t18.*t36;
t57=t55 + t56;
x_R_LeftFoot=[(-1).*t10.*t6 + t3.*t5.*t8,t23.*t3 + t10.*t8.*t9,t3.*t33 + (-1).* ...
  t10.*t11.*t8,t30.*t42 + t20.*t45,t30.*t48 + t20.*t51,t30.*t54 +  ...
  t20.*t57,t20.*t42 + (-1).*t30.*t45,t20.*t48 + (-1).*t30.*t51,t20.* ...
  t54 + (-1).*t30.*t57];

end %function