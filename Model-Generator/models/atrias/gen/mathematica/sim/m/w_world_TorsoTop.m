function [x_w_world_TorsoTop] = w_world_TorsoTop(x)
%w_world_TorsoTop
%    x_w_world_TorsoTop = w_world_TorsoTop(x)

% This function was generated by Mathematica Common 
% Subexpression Eliminating Package (CseOptimization)
% Thu 26 Jan 2017 21:34:17

t1=x(5);
t2=cos(t1);
t3=t2.^2;
t4=x(6);
t5=cos(t4);
t6=x(4);
t7=sin(t4);
t8=sin(t6);
t9=cos(t6);
t10=sin(t1);
t11=x(21);
t12=x(20);
t13=x(22);
t14=t5.*t9;
t15=(-1).*t10.*t7.*t8;
t16=t14 + t15;
t17=t11.*t3.*t5;
t18=(-1).*t10.*t5.*t9;
t19=t7.*t8;
t20=t18 + t19;
t21=(-1).*t12.*t2.*t8;
t22=(-1).*t10.*t11.*t9;
t23=t21 + t22;
t24=t20.*t23;
t25=t10.*t5.*t8;
t26=t7.*t9;
t27=t25 + t26;
t28=(-1).*t12.*t2.*t9;
t29=t10.*t11.*t8;
t30=t28 + t29;
t31=t27.*t30;
t32=t17 + t24 + t31;
t33=t10.*t11.*t7;
t34=(-1).*t13.*t2.*t5;
t35=t33 + t34;
t36=t10.*t35;
t37=(-1).*t12.*t5.*t8;
t38=(-1).*t10.*t12.*t7.*t9;
t39=(-1).*t11.*t2.*t7.*t8;
t40=(-1).*t10.*t13.*t5.*t8;
t41=(-1).*t13.*t7.*t9;
t42=t37 + t38 + t39 + t40 + t41;
t43=(-1).*t2.*t42.*t8;
t44=t12.*t5.*t9;
t45=(-1).*t10.*t12.*t7.*t8;
t46=t11.*t2.*t7.*t9;
t47=t10.*t13.*t5.*t9;
t48=(-1).*t13.*t7.*t8;
t49=t44 + t45 + t46 + t47 + t48;
t50=t2.*t49.*t9;
t51=t36 + t43 + t50;
t52=(-1).*t10.*t11.*t5;
t53=(-1).*t13.*t2.*t7;
t54=t52 + t53;
t55=(-1).*t2.*t54.*t7;
t56=t5.*t8;
t57=t10.*t7.*t9;
t58=t56 + t57;
t59=t10.*t12.*t5.*t8;
t60=t12.*t7.*t9;
t61=(-1).*t11.*t2.*t5.*t9;
t62=t13.*t5.*t8;
t63=t10.*t13.*t7.*t9;
t64=t59 + t60 + t61 + t62 + t63;
t65=t58.*t64;
t66=t10.*t12.*t5.*t9;
t67=(-1).*t12.*t7.*t8;
t68=t11.*t2.*t5.*t8;
t69=t13.*t5.*t9;
t70=(-1).*t10.*t13.*t7.*t8;
t71=t66 + t67 + t68 + t69 + t70;
t72=t16.*t71;
t73=t55 + t65 + t72;
x_w_world_TorsoTop=[t2.*t5.*t51 + (-1).*t2.*t32.*t7 + t10.*t73,t16.*t32 + t27.*t51 +  ...
  (-1).*t2.*t73.*t8,t20.*t51 + t32.*t58 + t2.*t73.*t9];

end %function