function [x_w_world_fourBarARight] = w_world_fourBarARight(x)
%w_world_fourBarARight
%    x_w_world_fourBarARight = w_world_fourBarARight(x)

% This function was generated by Mathematica Common 
% Subexpression Eliminating Package (CseOptimization)
% Thu 26 Jan 2017 21:34:09

t1=x(5);
t2=x(7);
t3=cos(t1);
t4=x(6);
t5=x(8);
t6=cos(t5);
t7=sin(t4);
t8=cos(t2);
t9=sin(t1);
t10=t8.*t9;
t11=cos(t4);
t12=sin(t2);
t13=t11.*t12.*t3;
t14=t10 + t13;
t15=sin(t5);
t16=x(10);
t17=cos(t16);
t18=(-1).*t3.*t6.*t7;
t19=t14.*t15;
t20=t18 + t19;
t21=t14.*t6;
t22=t15.*t3.*t7;
t23=t21 + t22;
t24=sin(t16);
t25=x(21);
t26=x(23);
t27=x(4);
t28=sin(t27);
t29=cos(t27);
t30=(-1).*t28.*t3.*t8;
t31=t11.*t28.*t9;
t32=t29.*t7;
t33=t31 + t32;
t34=t12.*t33;
t35=t30 + t34;
t36=t11.*t29;
t37=(-1).*t28.*t7.*t9;
t38=t36 + t37;
t39=x(20);
t40=x(22);
t41=t29.*t3.*t8;
t42=(-1).*t11.*t29.*t9;
t43=t28.*t7;
t44=t42 + t43;
t45=t12.*t44;
t46=t41 + t45;
t47=t11.*t28;
t48=t29.*t7.*t9;
t49=t47 + t48;
t50=t17.*t20;
t51=t23.*t24;
t52=t50 + t51;
t53=x(24);
t54=t25.*t3.*t8;
t55=(-1).*t11.*t12.*t25.*t9;
t56=(-1).*t12.*t3.*t40.*t7;
t57=t11.*t26.*t3.*t8;
t58=(-1).*t12.*t26.*t9;
t59=t54 + t55 + t56 + t57 + t58;
t60=x(26);
t61=t11.*t28.*t39.*t9;
t62=t29.*t39.*t7;
t63=(-1).*t11.*t25.*t29.*t3;
t64=t11.*t28.*t40;
t65=t29.*t40.*t7.*t9;
t66=t61 + t62 + t63 + t64 + t65;
t67=t11.*t29.*t39;
t68=(-1).*t28.*t39.*t7.*t9;
t69=t25.*t29.*t3.*t7;
t70=t11.*t29.*t40.*t9;
t71=(-1).*t28.*t40.*t7;
t72=t67 + t68 + t69 + t70 + t71;
t73=(-1).*t28.*t3.*t39.*t8;
t74=(-1).*t25.*t29.*t8.*t9;
t75=t12.*t66;
t76=t26.*t44.*t8;
t77=(-1).*t12.*t26.*t29.*t3;
t78=t73 + t74 + t75 + t76 + t77;
t79=t49.*t6;
t80=t15.*t46;
t81=t79 + t80;
t82=t46.*t6;
t83=(-1).*t15.*t49;
t84=t82 + t83;
t85=t11.*t29.*t39.*t9;
t86=(-1).*t28.*t39.*t7;
t87=t11.*t25.*t28.*t3;
t88=t11.*t29.*t40;
t89=(-1).*t28.*t40.*t7.*t9;
t90=t85 + t86 + t87 + t88 + t89;
t91=(-1).*t11.*t28.*t39;
t92=(-1).*t29.*t39.*t7.*t9;
t93=(-1).*t25.*t28.*t3.*t7;
t94=(-1).*t11.*t28.*t40.*t9;
t95=(-1).*t29.*t40.*t7;
t96=t91 + t92 + t93 + t94 + t95;
t97=(-1).*t29.*t3.*t39.*t8;
t98=t25.*t28.*t8.*t9;
t99=t12.*t90;
t100=t26.*t33.*t8;
t101=t12.*t26.*t28.*t3;
t102=t100 + t101 + t97 + t98 + t99;
t103=t38.*t6;
t104=t15.*t35;
t105=t103 + t104;
t106=t35.*t6;
t107=(-1).*t15.*t38;
t108=t106 + t107;
t109=t11.*t3.*t8;
t110=(-1).*t12.*t9;
t111=t109 + t110;
t112=t17.*t23;
t113=(-1).*t20.*t24;
t114=t112 + t113;
t115=t25.*t6.*t7.*t9;
t116=(-1).*t11.*t3.*t40.*t6;
t117=t15.*t59;
t118=t14.*t53.*t6;
t119=t15.*t3.*t53.*t7;
t120=t115 + t116 + t117 + t118 + t119;
t121=(-1).*t15.*t25.*t7.*t9;
t122=t11.*t15.*t3.*t40;
t123=t59.*t6;
t124=t3.*t53.*t6.*t7;
t125=(-1).*t14.*t15.*t53;
t126=t121 + t122 + t123 + t124 + t125;
t127=t6.*t96;
t128=t102.*t15;
t129=t35.*t53.*t6;
t130=(-1).*t15.*t38.*t53;
t131=t127 + t128 + t129 + t130;
t132=(-1).*t15.*t96;
t133=t102.*t6;
t134=(-1).*t38.*t53.*t6;
t135=(-1).*t15.*t35.*t53;
t136=t132 + t133 + t134 + t135;
t137=t6.*t72;
t138=t15.*t78;
t139=t46.*t53.*t6;
t140=(-1).*t15.*t49.*t53;
t141=t137 + t138 + t139 + t140;
t142=(-1).*t15.*t72;
t143=t6.*t78;
t144=(-1).*t49.*t53.*t6;
t145=(-1).*t15.*t46.*t53;
t146=t142 + t143 + t144 + t145;
t147=t108.*t17;
t148=(-1).*t105.*t24;
t149=t147 + t148;
t150=(-1).*t11.*t25.*t8.*t9;
t151=(-1).*t12.*t25.*t3;
t152=(-1).*t3.*t40.*t7.*t8;
t153=(-1).*t26.*t8.*t9;
t154=(-1).*t11.*t12.*t26.*t3;
t155=t150 + t151 + t152 + t153 + t154;
t156=t155.*t52;
t157=t105.*t17;
t158=t108.*t24;
t159=t157 + t158;
t160=t12.*t29.*t3.*t39;
t161=(-1).*t12.*t25.*t28.*t9;
t162=t8.*t90;
t163=t26.*t28.*t3.*t8;
t164=(-1).*t12.*t26.*t33;
t165=t160 + t161 + t162 + t163 + t164;
t166=t159.*t165;
t167=t17.*t81;
t168=t24.*t84;
t169=t167 + t168;
t170=t12.*t28.*t3.*t39;
t171=t12.*t25.*t29.*t9;
t172=t66.*t8;
t173=(-1).*t26.*t29.*t3.*t8;
t174=(-1).*t12.*t26.*t44;
t175=t170 + t171 + t172 + t173 + t174;
t176=t169.*t175;
t177=t156 + t166 + t176;
t178=(-1).*t120.*t24;
t179=t126.*t17;
t180=(-1).*t17.*t20.*t60;
t181=(-1).*t23.*t24.*t60;
t182=t178 + t179 + t180 + t181;
t183=t111.*t182;
t184=t44.*t8;
t185=(-1).*t12.*t29.*t3;
t186=t184 + t185;
t187=(-1).*t141.*t24;
t188=t146.*t17;
t189=(-1).*t17.*t60.*t81;
t190=(-1).*t24.*t60.*t84;
t191=t187 + t188 + t189 + t190;
t192=t186.*t191;
t193=t33.*t8;
t194=t12.*t28.*t3;
t195=t193 + t194;
t196=(-1).*t131.*t24;
t197=t136.*t17;
t198=(-1).*t105.*t17.*t60;
t199=(-1).*t108.*t24.*t60;
t200=t196 + t197 + t198 + t199;
t201=t195.*t200;
t202=t183 + t192 + t201;
t203=t120.*t17;
t204=t126.*t24;
t205=t17.*t23.*t60;
t206=(-1).*t20.*t24.*t60;
t207=t203 + t204 + t205 + t206;
t208=t114.*t207;
t209=t131.*t17;
t210=t136.*t24;
t211=t108.*t17.*t60;
t212=(-1).*t105.*t24.*t60;
t213=t209 + t210 + t211 + t212;
t214=t149.*t213;
t215=t17.*t84;
t216=(-1).*t24.*t81;
t217=t215 + t216;
t218=t141.*t17;
t219=t146.*t24;
t220=t17.*t60.*t84;
t221=(-1).*t24.*t60.*t81;
t222=t218 + t219 + t220 + t221;
t223=t217.*t222;
t224=t208 + t214 + t223;
x_w_world_fourBarARight=[t114.*t177 + t111.*t224 + t202.*t52,t149.*t177 + t159.*t202 +  ...
  t195.*t224,t169.*t202 + t177.*t217 + t186.*t224];

end %function