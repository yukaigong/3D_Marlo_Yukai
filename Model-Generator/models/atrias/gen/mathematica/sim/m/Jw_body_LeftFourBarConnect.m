function [x_Jw_body_LeftFourBarConnect] = Jw_body_LeftFourBarConnect(x)
%Jw_body_LeftFourBarConnect
%    x_Jw_body_LeftFourBarConnect = Jw_body_LeftFourBarConnect(x)

% This function was generated by Mathematica Common 
% Subexpression Eliminating Package (CseOptimization)
% Thu 26 Jan 2017 21:34:21

t1=x(4);
t2=x(6);
t3=cos(t1);
t4=x(5);
t5=cos(t2);
t6=sin(t4);
t7=sin(t1);
t8=sin(t2);
t9=x(12);
t10=x(13);
t11=cos(t10);
t12=cos(t4);
t13=cos(t9);
t14=(-1).*t12.*t13.*t3;
t15=t3.*t5.*t6;
t16=(-1).*t7.*t8;
t17=t15 + t16;
t18=sin(t9);
t19=t17.*t18;
t20=t14 + t19;
t21=(-1).*t5.*t7;
t22=(-1).*t3.*t6.*t8;
t23=t21 + t22;
t24=sin(t10);
t25=x(15);
t26=cos(t25);
t27=t3.*t5;
t28=(-1).*t6.*t7.*t8;
t29=t27 + t28;
t30=(-1).*t12.*t13.*t7;
t31=t5.*t6.*t7;
t32=t3.*t8;
t33=t31 + t32;
t34=t18.*t33;
t35=t30 + t34;
t36=sin(t25);
t37=t11.*t29;
t38=t24.*t35;
t39=t37 + t38;
t40=t11.*t35;
t41=(-1).*t24.*t29;
t42=t40 + t41;
t43=t5.*t7;
t44=t3.*t6.*t8;
t45=t43 + t44;
t46=t12.*t13.*t3;
t47=(-1).*t3.*t5.*t6;
t48=t7.*t8;
t49=t47 + t48;
t50=t18.*t49;
t51=t46 + t50;
t52=t26.*t42;
t53=(-1).*t36.*t39;
t54=t52 + t53;
t55=t11.*t20;
t56=(-1).*t23.*t24;
t57=t55 + t56;
t58=t11.*t23;
t59=t20.*t24;
t60=t58 + t59;
t61=t13.*t33;
t62=t12.*t18.*t7;
t63=t61 + t62;
t64=t11.*t45;
t65=t24.*t51;
t66=t64 + t65;
t67=t11.*t51;
t68=(-1).*t24.*t45;
t69=t67 + t68;
t70=t26.*t39;
t71=t36.*t42;
t72=t70 + t71;
t73=t12.*t13;
t74=(-1).*t18.*t5.*t6;
t75=t73 + t74;
t76=t13.*t6;
t77=t12.*t18.*t5;
t78=t76 + t77;
t79=t13.*t6.*t7;
t80=t12.*t18.*t5.*t7;
t81=t79 + t80;
t82=(-1).*t13.*t3.*t6;
t83=(-1).*t12.*t18.*t3.*t5;
t84=t82 + t83;
t85=t26.*t69;
t86=(-1).*t36.*t66;
t87=t85 + t86;
t88=t13.*t49;
t89=(-1).*t12.*t18.*t3;
t90=t88 + t89;
t91=t11.*t84;
t92=(-1).*t12.*t24.*t3.*t8;
t93=t91 + t92;
t94=t11.*t12.*t3.*t8;
t95=t24.*t84;
t96=t94 + t95;
t97=t11.*t81;
t98=t12.*t24.*t7.*t8;
t99=t97 + t98;
t100=(-1).*t11.*t12.*t7.*t8;
t101=t24.*t81;
t102=t100 + t101;
t103=t11.*t75;
t104=(-1).*t24.*t6.*t8;
t105=t103 + t104;
t106=t11.*t6.*t8;
t107=t24.*t75;
t108=t106 + t107;
t109=(-1).*t11.*t12.*t8;
t110=t24.*t78;
t111=t109 + t110;
t112=t11.*t78;
t113=t12.*t24.*t8;
t114=t112 + t113;
t115=t26.*t66;
t116=t36.*t69;
t117=t115 + t116;
t118=t114.*t26;
t119=(-1).*t111.*t36;
t120=t118 + t119;
t121=(-1).*t5.*t6.*t7;
t122=(-1).*t3.*t8;
t123=t121 + t122;
t124=t12.*t13.*t5;
t125=(-1).*t18.*t6;
t126=t124 + t125;
t127=(-1).*t11.*t12.*t18.*t8;
t128=t12.*t24.*t5;
t129=t127 + t128;
t130=(-1).*t11.*t12.*t5;
t131=(-1).*t12.*t18.*t24.*t8;
t132=t130 + t131;
t133=t11.*t18.*t45;
t134=(-1).*t17.*t24;
t135=t133 + t134;
t136=t11.*t17;
t137=t18.*t24.*t45;
t138=t136 + t137;
t139=t11.*t18.*t29;
t140=(-1).*t123.*t24;
t141=t139 + t140;
t142=t11.*t123;
t143=t18.*t24.*t29;
t144=t142 + t143;
t145=t111.*t26;
t146=t114.*t36;
t147=t145 + t146;
t148=t11.*t12.*t8;
t149=(-1).*t24.*t78;
t150=t148 + t149;
t151=(-1).*t11.*t45;
t152=(-1).*t24.*t51;
t153=t151 + t152;
t154=(-1).*t11.*t29;
t155=(-1).*t24.*t35;
t156=t154 + t155;
t157=t120.^2;
t158=t54.^2;
t159=t87.^2;
t160=(-1).*t114.*t36;
t161=(-1).*t36.*t69;
t162=(-1).*t36.*t42;
x_Jw_body_LeftFourBarConnect=[0,0,0,0,0,0,0,0,0,t54.*(t36.*t57 + t26.*t60) + t72.*t87,(t26.* ...
  t57 + (-1).*t36.*t60).*t63 + t54.*t90,t117.*t63 + (t13.*t17 +  ...
  t12.*t18.*t3).*t72,t120.*(t108.*t26 + t105.*t36) + t87.*(t36.*t93  ...
  + t26.*t96) + t54.*(t102.*t26 + t36.*t99),t126.*(t105.*t26 + (-1) ...
  .*t108.*t36) + t90.*(t26.*t93 + (-1).*t36.*t96) + t63.*((-1).* ...
  t102.*t36 + t26.*t99),t117.*((-1).*t12.*t13.*t3.*t5 + t18.*t3.*t6) ...
   + t147.*((-1).*t12.*t18 + (-1).*t13.*t5.*t6) + (t12.*t13.*t5.*t7  ...
  + (-1).*t18.*t6.*t7).*t72,t120.*(t132.*t26 + t129.*t36) + (t144.* ...
  t26 + t141.*t36).*t54 + (t138.*t26 + t135.*t36).*t87,t126.*(t129.* ...
  t26 + (-1).*t132.*t36) + (t141.*t26 + (-1).*t144.*t36).*t63 + ( ...
  t135.*t26 + (-1).*t138.*t36).*t90,t117.*t13.*t45 + t13.*t29.*t72 + ...
   (-1).*t12.*t13.*t147.*t8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,t120.*( ...
  t126.*t24.*t26 + t11.*t126.*t36) + t54.*(t24.*t26.*t63 + t11.* ...
  t36.*t63) + t87.*(t24.*t26.*t90 + t11.*t36.*t90),t126.*(t11.* ...
  t126.*t26 + (-1).*t126.*t24.*t36) + t63.*(t11.*t26.*t63 + (-1).* ...
  t24.*t36.*t63) + t90.*(t11.*t26.*t90 + (-1).*t24.*t36.*t90),t117.* ...
  (t14 + (-1).*t18.*t49) + t147.*((-1).*t12.*t18.*t5 + (-1).*t13.* ...
  t6) + ((-1).*t18.*t33 + t12.*t13.*t7).*t72,t120.*(t118 + t150.* ...
  t36) + (t156.*t36 + t52).*t54 + (t153.*t36 + t85).*t87,t126.*( ...
  t160 + t150.*t26) + (t162 + t156.*t26).*t63 + (t161 + t153.*t26).* ...
  t90,0,0,0,0,t157 + t158 + t159,t126.*(t160 + (-1).*t111.*t26) + ( ...
  t162 + (-1).*t26.*t39).*t63 + (t161 + (-1).*t26.*t66).*t90,0,0,0, ...
  0];

end %function