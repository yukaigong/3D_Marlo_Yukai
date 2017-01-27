function [x_Jp_fourBarALeft] = Jp_fourBarALeft(x)
%Jp_fourBarALeft
%    x_Jp_fourBarALeft = Jp_fourBarALeft(x)

% This function was generated by Mathematica Common 
% Subexpression Eliminating Package (CseOptimization)
% Thu 26 Jan 2017 21:34:14

t1=x(4);
t2=x(6);
t3=cos(t1);
t4=x(5);
t5=x(12);
t6=cos(t4);
t7=cos(t5);
t8=cos(t2);
t9=sin(t4);
t10=t3.*t8.*t9;
t11=sin(t1);
t12=sin(t2);
t13=(-1).*t11.*t12;
t14=t10 + t13;
t15=sin(t5);
t16=x(13);
t17=cos(t16);
t18=(-1).*t11.*t8;
t19=(-1).*t12.*t3.*t9;
t20=t18 + t19;
t21=(-1).*t3.*t6.*t7;
t22=t14.*t15;
t23=t21 + t22;
t24=sin(t16);
t25=x(15);
t26=cos(t25);
t27=t17.*t23;
t28=(-1).*t20.*t24;
t29=t27 + t28;
t30=t17.*t20;
t31=t23.*t24;
t32=t30 + t31;
t33=sin(t25);
t34=(-1).*t26;
t35=1 + t34;
t36=t11.*t8.*t9;
t37=t12.*t3;
t38=t36 + t37;
t39=t3.*t8;
t40=(-1).*t11.*t12.*t9;
t41=t39 + t40;
t42=(-1).*t11.*t6.*t7;
t43=t15.*t38;
t44=t42 + t43;
t45=t17.*t44;
t46=(-1).*t24.*t41;
t47=t45 + t46;
t48=t17.*t41;
t49=t24.*t44;
t50=t48 + t49;
t51=t6.*t7;
t52=(-1).*t15.*t8.*t9;
t53=t51 + t52;
t54=t17.*t53;
t55=(-1).*t12.*t24.*t9;
t56=t54 + t55;
t57=t12.*t17.*t9;
t58=t24.*t53;
t59=t57 + t58;
t60=t11.*t7.*t9;
t61=t11.*t15.*t6.*t8;
t62=t60 + t61;
t63=t17.*t62;
t64=t11.*t12.*t24.*t6;
t65=t63 + t64;
t66=(-1).*t11.*t12.*t17.*t6;
t67=t24.*t62;
t68=t66 + t67;
t69=(-1).*t3.*t7.*t9;
t70=(-1).*t15.*t3.*t6.*t8;
t71=t69 + t70;
t72=t17.*t71;
t73=(-1).*t12.*t24.*t3.*t6;
t74=t72 + t73;
t75=t12.*t17.*t3.*t6;
t76=t24.*t71;
t77=t75 + t76;
t78=(-1).*t12.*t15.*t17.*t6;
t79=t24.*t6.*t8;
t80=t78 + t79;
t81=(-1).*t17.*t6.*t8;
t82=(-1).*t12.*t15.*t24.*t6;
t83=t81 + t82;
t84=(-1).*t11.*t8.*t9;
t85=(-1).*t12.*t3;
t86=t84 + t85;
t87=t15.*t17.*t41;
t88=(-1).*t24.*t86;
t89=t87 + t88;
t90=t17.*t86;
t91=t15.*t24.*t41;
t92=t90 + t91;
t93=t11.*t8;
t94=t12.*t3.*t9;
t95=t93 + t94;
t96=t15.*t17.*t95;
t97=(-1).*t14.*t24;
t98=t96 + t97;
t99=t14.*t17;
t100=t15.*t24.*t95;
t101=t100 + t99;
t102=t6.*t7.*t8;
t103=(-1).*t15.*t9;
t104=t102 + t103;
t105=t38.*t7;
t106=t11.*t15.*t6;
t107=t105 + t106;
t108=(-1).*t3.*t8.*t9;
t109=t11.*t12;
t110=t108 + t109;
t111=t110.*t7;
t112=(-1).*t15.*t3.*t6;
t113=t111 + t112;
t114=t7.*t9;
t115=t15.*t6.*t8;
t116=t114 + t115;
t117=t12.*t17.*t6;
t118=(-1).*t116.*t24;
t119=t117 + t118;
t120=t116.*t17;
t121=t12.*t24.*t6;
t122=t120 + t121;
t123=(-1).*t17.*t41;
t124=(-1).*t24.*t44;
t125=t123 + t124;
t126=t3.*t6.*t7;
t127=t110.*t15;
t128=t126 + t127;
t129=(-1).*t17.*t95;
t130=(-1).*t128.*t24;
t131=t129 + t130;
t132=t128.*t17;
t133=(-1).*t24.*t95;
t134=t132 + t133;
t135=(2/5).*t122.*t33;
t136=(-1).*t12.*t17.*t6;
t137=t116.*t24;
t138=t136 + t137;
t139=(-1).*t122.*t33;
t140=(2/5).*t33.*t47;
t141=(-1).*t33.*t47;
t142=(2/5).*t134.*t33;
t143=t17.*t95;
t144=t128.*t24;
t145=t143 + t144;
t146=(-1).*t134.*t33;
x_Jp_fourBarALeft=[1,0,0,0,1,0,0,0,1,0,(2/5).*t32.*t33 + (2/5).*(t26.*t29 + (-1).* ...
  t32.*t33) + (2/5).*t29.*t35 + (-1831/10000).*(t15.*t3.*t6 + t14.* ...
  t7),(-1831/10000).*t107 + (2/5).*t35.*t47 + (2/5).*t33.*t50 + ( ...
  2/5).*(t26.*t47 + (-1).*t33.*t50),(2/5).*t35.*t56 + (2/5).*t33.* ...
  t59 + (2/5).*(t26.*t56 + (-1).*t33.*t59) + (-1831/10000).*((-1).* ...
  t15.*t6 + (-1).*t7.*t8.*t9),(2/5).*t35.*t65 + (2/5).*t33.*t68 + ( ...
  2/5).*(t26.*t65 + (-1).*t33.*t68) + (-1831/10000).*(t11.*t6.*t7.* ...
  t8 + (-1).*t11.*t15.*t9),(2/5).*t35.*t74 + (2/5).*t33.*t77 + (2/5) ...
  .*(t26.*t74 + (-1).*t33.*t77) + (-1831/10000).*((-1).*t3.*t6.*t7.* ...
  t8 + t15.*t3.*t9),(1831/10000).*t12.*t6.*t7 + (2/5).*t35.*t80 + ( ...
  2/5).*t33.*t83 + (2/5).*(t26.*t80 + (-1).*t33.*t83),(-1831/10000) ...
  .*t41.*t7 + (2/5).*t35.*t89 + (2/5).*t33.*t92 + (2/5).*(t26.*t89 + ...
   (-1).*t33.*t92),(2/5).*t101.*t33 + (-1831/10000).*t7.*t95 + (2/5) ...
  .*t35.*t98 + (2/5).*((-1).*t101.*t33 + t26.*t98),0,0,0,0,0,0,0,0, ...
  0,0,0,0,0,0,0,(2/5).*t104.*t24.*t33 + (2/5).*(t104.*t17.*t26 + ( ...
  -1).*t104.*t24.*t33) + (2/5).*t104.*t17.*t35 + (-1831/10000).*(( ...
  -1).*t15.*t6.*t8 + (-1).*t7.*t9),(2/5).*t107.*t24.*t33 + (2/5).*( ...
  t107.*t17.*t26 + (-1).*t107.*t24.*t33) + (2/5).*t107.*t17.*t35 + ( ...
  -1831/10000).*((-1).*t15.*t38 + t11.*t6.*t7),(-1831/10000).*((-1) ...
  .*t110.*t15 + t21) + (2/5).*t113.*t24.*t33 + (2/5).*(t113.*t17.* ...
  t26 + (-1).*t113.*t24.*t33) + (2/5).*t113.*t17.*t35,t135 + (2/5).* ...
  (t139 + t119.*t26) + (2/5).*t119.*t35,t140 + (2/5).*(t141 + t125.* ...
  t26) + (2/5).*t125.*t35,t142 + (2/5).*(t146 + t131.*t26) + (2/5).* ...
  t131.*t35,0,0,0,t135 + (2/5).*t138.*t26 + (2/5).*(t139 + (-1).* ...
  t138.*t26),t140 + (2/5).*t26.*t50 + (2/5).*(t141 + (-1).*t26.*t50) ...
  ,t142 + (2/5).*t145.*t26 + (2/5).*(t146 + (-1).*t145.*t26),0,0,0]; ...
  

end %function