function [x_dJw_body_qHLeft] = dJw_body_qHLeft(x)
%dJw_body_qHLeft
%    x_dJw_body_qHLeft = dJw_body_qHLeft(x)

% This function was generated by Mathematica Common 
% Subexpression Eliminating Package (CseOptimization)
% Thu 26 Jan 2017 21:34:12

t1=x(4);
t2=cos(t1);
t3=x(5);
t4=x(6);
t5=x(12);
t6=cos(t4);
t7=sin(t1);
t8=sin(t3);
t9=sin(t4);
t10=x(20);
t11=cos(t3);
t12=x(22);
t13=cos(t5);
t14=sin(t5);
t15=x(21);
t16=(-1).*t2.*t6.*t8;
t17=t7.*t9;
t18=t16 + t17;
t19=x(28);
t20=t6.*t7.*t8;
t21=t2.*t9;
t22=t20 + t21;
t23=(-1).*t10.*t11.*t13.*t2;
t24=t13.*t15.*t7.*t8;
t25=t10.*t2.*t6.*t8;
t26=(-1).*t10.*t7.*t9;
t27=t11.*t15.*t6.*t7;
t28=t12.*t2.*t6;
t29=(-1).*t12.*t7.*t8.*t9;
t30=t25 + t26 + t27 + t28 + t29;
t31=t14.*t30;
t32=t13.*t19.*t22;
t33=t11.*t14.*t19.*t7;
t34=t23 + t24 + t31 + t32 + t33;
t35=t2.*t6.*t8;
t36=(-1).*t7.*t9;
t37=t35 + t36;
t38=(-1).*t11.*t13.*t7;
t39=t14.*t22;
t40=t38 + t39;
t41=t10.*t6.*t7.*t8;
t42=t10.*t2.*t9;
t43=(-1).*t11.*t15.*t2.*t6;
t44=t12.*t6.*t7;
t45=t12.*t2.*t8.*t9;
t46=t41 + t42 + t43 + t44 + t45;
t47=(-1).*t10.*t6.*t7;
t48=(-1).*t10.*t2.*t8.*t9;
t49=(-1).*t11.*t15.*t7.*t9;
t50=(-1).*t12.*t6.*t7.*t8;
t51=(-1).*t12.*t2.*t9;
t52=t47 + t48 + t49 + t50 + t51;
t53=t13.*t22;
t54=t11.*t14.*t7;
t55=t53 + t54;
t56=t10.*t11.*t14.*t2;
t57=(-1).*t14.*t15.*t7.*t8;
t58=t13.*t30;
t59=t11.*t13.*t19.*t7;
t60=(-1).*t14.*t19.*t22;
t61=t56 + t57 + t58 + t59 + t60;
t62=t2.*t6;
t63=(-1).*t7.*t8.*t9;
t64=t62 + t63;
t65=(-1).*t10.*t6.*t7.*t8;
t66=(-1).*t10.*t2.*t9;
t67=t11.*t15.*t2.*t6;
t68=(-1).*t12.*t6.*t7;
t69=(-1).*t12.*t2.*t8.*t9;
t70=t65 + t66 + t67 + t68 + t69;
t71=t11.*t13.*t2;
t72=t14.*t18;
t73=t71 + t72;
t74=t13.*t8;
t75=t11.*t14.*t6;
t76=t74 + t75;
t77=(-1).*t10.*t11.*t13.*t7;
t78=(-1).*t13.*t15.*t2.*t8;
t79=t14.*t46;
t80=t13.*t18.*t19;
t81=(-1).*t11.*t14.*t19.*t2;
t82=t77 + t78 + t79 + t80 + t81;
t83=t13.*t18;
t84=(-1).*t11.*t14.*t2;
t85=t83 + t84;
t86=t10.*t11.*t14.*t7;
t87=t14.*t15.*t2.*t8;
t88=t13.*t46;
t89=(-1).*t11.*t13.*t19.*t2;
t90=(-1).*t14.*t18.*t19;
t91=t86 + t87 + t88 + t89 + t90;
t92=(-1).*t13.*t6.*t8;
t93=(-1).*t11.*t14;
t94=t92 + t93;
t95=t10.*t2.*t6;
t96=(-1).*t10.*t7.*t8.*t9;
t97=t11.*t15.*t2.*t9;
t98=t12.*t2.*t6.*t8;
t99=(-1).*t12.*t7.*t9;
t100=t95 + t96 + t97 + t98 + t99;
t101=t6.*t7;
t102=t2.*t8.*t9;
t103=t101 + t102;
t104=t11.*t13.*t15;
t105=(-1).*t14.*t15.*t6.*t8;
t106=(-1).*t11.*t12.*t14.*t9;
t107=t11.*t13.*t19.*t6;
t108=(-1).*t14.*t19.*t8;
t109=t104 + t105 + t106 + t107 + t108;
t110=t11.*t13.*t6;
t111=(-1).*t14.*t8;
t112=t110 + t111;
t113=(-1).*t13.*t15.*t6.*t8;
t114=(-1).*t11.*t14.*t15;
t115=(-1).*t11.*t12.*t13.*t9;
t116=(-1).*t13.*t19.*t8;
t117=(-1).*t11.*t14.*t19.*t6;
t118=t113 + t114 + t115 + t116 + t117;
t119=t9.^2;
t120=t11.^2;
t121=t103.^2;
t122=t64.^2;
t123=(-1).*t13.*t8;
t124=(-1).*t11.*t14.*t6;
t125=t123 + t124;
t126=(-1).*t11.*t13.*t2;
t127=t10.*t11.*t13.*t7;
t128=t13.*t15.*t2.*t8;
t129=t11.*t14.*t19.*t2;
x_dJw_body_qHLeft=[0,0,0,0,0,0,0,0,0,t52.*t73 + t64.*t82 + t34.*((-1).*t6.*t7 + (-1) ...
  .*t2.*t8.*t9) + t40.*((-1).*t10.*t2.*t6 + (-1).*t12.*t2.*t6.*t8 +  ...
  (-1).*t11.*t15.*t2.*t9 + t12.*t7.*t9 + t10.*t7.*t8.*t9),(t126 +  ...
  t14.*t37).*t61 + t55.*(t127 + t128 + t129 + t13.*t19.*t37 + t14.* ...
  t70) + t34.*t85 + t40.*t91,(t11.*t14.*t2 + t13.*t37).*t52 + t100.* ...
  t55 + t103.*t61 + t64.*(t11.*t13.*t19.*t2 + (-1).*t14.*t19.*t37 +  ...
  (-1).*t10.*t11.*t14.*t7 + t13.*t70 + (-1).*t14.*t15.*t2.*t8),(-1) ...
  .*t11.*t12.*t40.*t6.*t7 + t11.*t12.*t2.*t6.*t73 + t12.*t6.*t76.* ...
  t8 + (-1).*t10.*t11.*t2.*t40.*t9 + (-1).*t11.*t34.*t7.*t9 + (-1).* ...
  t10.*t11.*t7.*t73.*t9 + t11.*t15.*t76.*t9 + t109.*t8.*t9 + t15.* ...
  t40.*t7.*t8.*t9 + (-1).*t15.*t2.*t73.*t8.*t9 + t11.*t2.*t82.*t9, ...
  t118.*(t11.*t13 + (-1).*t14.*t6.*t8) + t61.*(t11.*t14.*t6.*t7 +  ...
  t13.*t7.*t8) + t85.*((-1).*t11.*t13.*t15.*t2 + (-1).*t11.*t13.* ...
  t19.*t2.*t6 + t10.*t11.*t14.*t6.*t7 + t14.*t19.*t2.*t8 + t14.* ...
  t15.*t2.*t6.*t8 + t10.*t13.*t7.*t8 + t11.*t12.*t14.*t2.*t9) +  ...
  t55.*(t10.*t11.*t14.*t2.*t6 + t11.*t13.*t15.*t7 + t11.*t13.*t19.* ...
  t6.*t7 + t10.*t13.*t2.*t8 + (-1).*t14.*t19.*t7.*t8 + (-1).*t14.* ...
  t15.*t6.*t7.*t8 + (-1).*t11.*t12.*t14.*t7.*t9) + t112.*((-1).* ...
  t11.*t14.*t19 + (-1).*t11.*t14.*t15.*t6 + (-1).*t13.*t15.*t8 + ( ...
  -1).*t13.*t19.*t6.*t8 + t12.*t14.*t8.*t9) + ((-1).*t11.*t14.*t2.* ...
  t6 + (-1).*t13.*t2.*t8).*t91,t100.*((-1).*t11.*t13.*t2.*t6 + t14.* ...
  t2.*t8) + t52.*(t11.*t13.*t6.*t7 + (-1).*t14.*t7.*t8) + t103.*( ...
  t11.*t14.*t15.*t2 + t11.*t14.*t19.*t2.*t6 + t10.*t11.*t13.*t6.*t7  ...
  + t13.*t19.*t2.*t8 + t13.*t15.*t2.*t6.*t8 + (-1).*t10.*t14.*t7.* ...
  t8 + t11.*t12.*t13.*t2.*t9) + t64.*(t10.*t11.*t13.*t2.*t6 + (-1).* ...
  t11.*t14.*t15.*t7 + (-1).*t11.*t14.*t19.*t6.*t7 + (-1).*t10.*t14.* ...
  t2.*t8 + (-1).*t13.*t19.*t7.*t8 + (-1).*t13.*t15.*t6.*t7.*t8 + ( ...
  -1).*t11.*t12.*t13.*t7.*t9) + (-1).*t11.*t9.*((-1).*t11.*t13.*t19  ...
  + (-1).*t11.*t13.*t15.*t6 + t14.*t15.*t8 + t14.*t19.*t6.*t8 +  ...
  t12.*t13.*t8.*t9) + (-1).*t11.*t12.*t6.*t94 + t15.*t8.*t9.*t94,( ...
  -1).*t109.*t11.*t6 + t70.*t73 + t15.*t6.*t76.*t8 + t37.*t82 +  ...
  t11.*t12.*t76.*t9 + t34.*((-1).*t6.*t7.*t8 + (-1).*t2.*t9) + t40.* ...
  ((-1).*t12.*t2.*t6 + (-1).*t11.*t15.*t6.*t7 + (-1).*t10.*t2.*t6.* ...
  t8 + t10.*t7.*t9 + t12.*t7.*t8.*t9),t14.*t52.*t55 + (-1).*t11.* ...
  t112.*t12.*t14.*t6 + t13.*t19.*t55.*t64 + t14.*t61.*t64 + t100.* ...
  t14.*t85 + t103.*t13.*t19.*t85 + (-1).*t11.*t118.*t14.*t9 + (-1).* ...
  t11.*t112.*t13.*t19.*t9 + t112.*t14.*t15.*t8.*t9 + t103.*t14.*t91, ...
  2.*t100.*t103.*t13 + (-1).*t119.*t120.*t14.*t19 + (-1).*t121.* ...
  t14.*t19 + (-1).*t122.*t14.*t19 + 2.*t13.*t52.*t64 + (-2).*t11.* ...
  t119.*t13.*t15.*t8 + 2.*t12.*t120.*t13.*t6.*t9,0,0,0,0,0,0,0,0,0, ...
  0,0,0,0,0,0,0,2.*t112.*t118 + 2.*t55.*t61 + 2.*t85.*t91,t100.*( ...
  t126 + (-1).*t14.*t18) + t103.*(t127 + t128 + t129 + (-1).*t13.* ...
  t18.*t19 + (-1).*t14.*t46) + (-1).*t11.*t12.*t125.*t6 + t52.*((-1) ...
  .*t14.*t22 + t11.*t13.*t7) + t64.*(t10.*t11.*t13.*t2 + (-1).*t13.* ...
  t19.*t22 + (-1).*t14.*t30 + (-1).*t11.*t14.*t19.*t7 + (-1).*t13.* ...
  t15.*t7.*t8) + t125.*t15.*t8.*t9 + (-1).*t11.*t9.*((-1).*t11.* ...
  t13.*t15 + (-1).*t11.*t13.*t19.*t6 + t14.*t19.*t8 + t14.*t15.*t6.* ...
  t8 + t11.*t12.*t14.*t9),0,0,0,0,0,0,0,0,0,0,0,0];

end %function