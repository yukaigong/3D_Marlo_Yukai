function [x_w_body_qBRight] = w_body_qBRight(x)
%w_body_qBRight
%    x_w_body_qBRight = w_body_qBRight(x)

% This function was generated by Mathematica Common 
% Subexpression Eliminating Package (CseOptimization)
% Thu 26 Jan 2017 21:34:08

t1=x(5);
t2=x(7);
t3=cos(t1);
t4=x(6);
t5=x(9);
t6=cos(t5);
t7=sin(t1);
t8=sin(t4);
t9=cos(t4);
t10=sin(t5);
t11=cos(t2);
t12=x(21);
t13=sin(t2);
t14=x(22);
t15=x(23);
t16=t11.*t7;
t17=t13.*t3.*t9;
t18=t16 + t17;
t19=x(25);
t20=x(4);
t21=cos(t20);
t22=sin(t20);
t23=x(20);
t24=(-1).*t21.*t7.*t9;
t25=t22.*t8;
t26=t24 + t25;
t27=t11.*t21.*t3;
t28=t13.*t26;
t29=t27 + t28;
t30=t22.*t9;
t31=t21.*t7.*t8;
t32=t30 + t31;
t33=t22.*t7.*t9;
t34=t21.*t8;
t35=t33 + t34;
t36=(-1).*t11.*t22.*t3;
t37=t13.*t35;
t38=t36 + t37;
t39=t21.*t9;
t40=(-1).*t22.*t7.*t8;
t41=t39 + t40;
t42=t11.*t12.*t3;
t43=(-1).*t12.*t13.*t7.*t9;
t44=(-1).*t13.*t14.*t3.*t8;
t45=t11.*t15.*t3.*t9;
t46=(-1).*t13.*t15.*t7;
t47=t42 + t43 + t44 + t45 + t46;
t48=(-1).*t22.*t23.*t9;
t49=(-1).*t21.*t23.*t7.*t8;
t50=(-1).*t12.*t22.*t3.*t8;
t51=(-1).*t14.*t22.*t7.*t9;
t52=(-1).*t14.*t21.*t8;
t53=t48 + t49 + t50 + t51 + t52;
t54=(-1).*t11.*t21.*t23.*t3;
t55=t11.*t12.*t22.*t7;
t56=t21.*t23.*t7.*t9;
t57=(-1).*t22.*t23.*t8;
t58=t12.*t22.*t3.*t9;
t59=t14.*t21.*t9;
t60=(-1).*t14.*t22.*t7.*t8;
t61=t56 + t57 + t58 + t59 + t60;
t62=t13.*t61;
t63=t11.*t15.*t35;
t64=t13.*t15.*t22.*t3;
t65=t54 + t55 + t62 + t63 + t64;
t66=t21.*t23.*t9;
t67=(-1).*t22.*t23.*t7.*t8;
t68=t12.*t21.*t3.*t8;
t69=t14.*t21.*t7.*t9;
t70=(-1).*t14.*t22.*t8;
t71=t66 + t67 + t68 + t69 + t70;
t72=(-1).*t11.*t22.*t23.*t3;
t73=(-1).*t11.*t12.*t21.*t7;
t74=t22.*t23.*t7.*t9;
t75=t21.*t23.*t8;
t76=(-1).*t12.*t21.*t3.*t9;
t77=t14.*t22.*t9;
t78=t14.*t21.*t7.*t8;
t79=t74 + t75 + t76 + t77 + t78;
t80=t13.*t79;
t81=t11.*t15.*t26;
t82=(-1).*t13.*t15.*t21.*t3;
t83=t72 + t73 + t80 + t81 + t82;
x_w_body_qBRight=[((-1).*t10.*t41 + t38.*t6).*((-1).*t10.*t19.*t41 + t19.*t38.*t6 + ...
   t53.*t6 + t10.*t65) + ((-1).*t10.*t32 + t29.*t6).*((-1).*t10.* ...
  t19.*t32 + t19.*t29.*t6 + t6.*t71 + t10.*t83) + (t18.*t6 + t10.* ...
  t3.*t8).*(t10.*t47 + t18.*t19.*t6 + t10.*t19.*t3.*t8 + t12.*t6.* ...
  t7.*t8 + (-1).*t14.*t3.*t6.*t9),(t13.*t22.*t3 + t11.*t35).*((-1).* ...
  t10.*t19.*t38 + (-1).*t10.*t53 + (-1).*t19.*t41.*t6 + t6.*t65) + ( ...
  t11.*t26 + (-1).*t13.*t21.*t3).*((-1).*t10.*t19.*t29 + (-1).*t19.* ...
  t32.*t6 + (-1).*t10.*t71 + t6.*t83) + ((-1).*t13.*t7 + t11.*t3.* ...
  t9).*((-1).*t10.*t18.*t19 + t47.*t6 + t19.*t3.*t6.*t8 + (-1).* ...
  t10.*t12.*t7.*t8 + t10.*t14.*t3.*t9),(t10.*t38 + t41.*t6).*(t11.* ...
  t15.*t22.*t3 + t13.*t21.*t23.*t3 + (-1).*t13.*t15.*t35 + t11.*t61  ...
  + (-1).*t12.*t13.*t22.*t7) + (t10.*t29 + t32.*t6).*((-1).*t13.* ...
  t15.*t26 + (-1).*t11.*t15.*t21.*t3 + t13.*t22.*t23.*t3 + t12.* ...
  t13.*t21.*t7 + t11.*t79) + (t10.*t18 + (-1).*t3.*t6.*t8).*((-1).* ...
  t12.*t13.*t3 + (-1).*t11.*t15.*t7 + (-1).*t11.*t14.*t3.*t8 + (-1) ...
  .*t13.*t15.*t3.*t9 + (-1).*t11.*t12.*t7.*t9)];

end %function