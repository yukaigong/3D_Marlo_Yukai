/*
 * Automatically Generated from Mathematica.
 * Thu 26 Jan 2017 21:34:05 GMT-05:00
 */
#include "math2mat.hpp"

/*
 * Sub functions
 */
static void output1(double *p_output1,const double *x)
{
  double t1;
  double t2;
  double t3;
  double t4;
  double t5;
  double t6;
  double t7;
  double t8;
  double t9;
  double t10;
  double t11;
  double t12;
  double t13;
  double t14;
  double t15;
  double t16;
  double t17;
  double t18;
  double t19;
  double t20;
  double t21;
  double t22;
  double t23;
  double t24;
  double t25;
  double t26;
  double t27;
  double t28;
  double t29;
  double t30;
  double t31;
  double t32;
  double t33;
  double t34;
  double t35;
  double t36;
  double t37;
  double t38;
  double t39;
  double t40;
  double t41;
  double t42;
  double t43;
  double t44;
  double t45;
  double t46;
  double t47;
  double t48;
  double t49;
  double t50;
  double t51;
  double t52;
  double t53;
  double t54;
  double t55;
  double t56;
  double t57;
  double t58;
  double t59;
  double t60;
  double t61;
  double t62;
  double t63;
  double t64;
  double t65;
  double t66;
  double t67;
  double t68;
  double t69;
  double t70;
  double t71;
  double t72;
  double t73;
  double t74;
  double t75;
  double t76;
  double t77;
  double t78;
  double t79;
  double t80;
  double t81;
  double t82;
  double t83;
  double t84;
  double t85;
  double t86;
  double t87;
  double t88;
  double t89;
  double t90;
  double t91;
  double t92;
  double t93;
  double t94;
  double t95;
  double t96;
  double t97;
  double t98;
  double t99;
  double t100;
  double t101;
  double t102;
  double t103;
  double t104;
  double t105;
  double t106;
  double t107;
  double t108;
  double t109;
  double t110;
  double t111;
  double t112;
  double t113;
  double t114;
  double t115;
  double t116;
  double t117;
  double t118;
  double t119;
  double t120;
  double t121;
  double t122;
  double t123;
  double t124;
  double t125;
  double t126;
  double t127;
  double t128;
  double t129;
  double t130;
  double t131;
  double t132;
  double t133;
  double t134;
  double t135;
  double t136;
  double t137;
  double t138;
  double t139;
  double t140;
  double t141;
  double t142;
  double t143;
  double t144;
  double t145;
  double t146;
  double t147;
  double t148;
  double t149;
  double t150;
  double t151;
  double t152;
  double t153;
  double t154;
  double t155;
  double t156;
  double t157;
  double t158;
  double t159;
  double t160;
  double t161;
  double t162;
  double t163;
  double t164;
  double t165;
  double t166;
  double t167;
  double t168;
  double t169;
  double t170;
  double t171;
  double t172;
  t1 = x[4];
  t2 = Cos(t1);
  t3 = x[11];
  t4 = x[5];
  t5 = Sin(t1);
  t6 = Cos(t3);
  t7 = Cos(t4);
  t8 = Sin(t3);
  t9 = Sin(t4);
  t10 = x[6];
  t11 = Cos(t10);
  t12 = Sin(t10);
  t13 = 0.00025*t5*t9;
  t14 = -1.*t2*t8;
  t15 = -1.*t6*t7*t5;
  t16 = t14 + t15;
  t17 = t6*t2;
  t18 = -1.*t7*t8*t5;
  t19 = t17 + t18;
  t20 = x[12];
  t21 = Cos(t20);
  t22 = Sin(t20);
  t23 = -1.*t2*t12;
  t24 = -1.*t11*t7*t5;
  t25 = t23 + t24;
  t26 = t11*t2;
  t27 = -1.*t7*t12*t5;
  t28 = t26 + t27;
  t29 = x[7];
  t30 = Cos(t29);
  t31 = Sin(t29);
  t32 = x[13];
  t33 = Cos(t32);
  t34 = Sin(t32);
  t35 = x[8];
  t36 = Cos(t35);
  t37 = Sin(t35);
  t38 = t22*t19;
  t39 = t21*t5*t9;
  t40 = t38 + t39;
  t41 = x[14];
  t42 = t21*t19;
  t43 = -1.*t22*t5*t9;
  t44 = t42 + t43;
  t45 = Sin(t41);
  t46 = Cos(t41);
  t47 = t31*t28;
  t48 = t30*t5*t9;
  t49 = t47 + t48;
  t50 = x[9];
  t51 = t30*t28;
  t52 = -1.*t31*t5*t9;
  t53 = t51 + t52;
  t54 = Sin(t50);
  t55 = Cos(t50);
  t56 = t34*t19;
  t57 = t33*t5*t9;
  t58 = t56 + t57;
  t59 = x[15];
  t60 = t33*t19;
  t61 = -1.*t34*t5*t9;
  t62 = t60 + t61;
  t63 = Sin(t59);
  t64 = Cos(t59);
  t65 = t37*t28;
  t66 = t36*t5*t9;
  t67 = t65 + t66;
  t68 = x[10];
  t69 = t36*t28;
  t70 = -1.*t37*t5*t9;
  t71 = t69 + t70;
  t72 = Sin(t68);
  t73 = Cos(t68);
  t74 = -0.00025*t2*t7;
  t75 = -1.*t46;
  t76 = 1. + t75;
  t77 = t2*t7*t22;
  t78 = -1.*t21*t2*t8*t9;
  t79 = t77 + t78;
  t80 = -1.*t21*t2*t7;
  t81 = -1.*t2*t22*t8*t9;
  t82 = t80 + t81;
  t83 = -1.*t64;
  t84 = 1. + t83;
  t85 = t2*t7*t34;
  t86 = -1.*t33*t2*t8*t9;
  t87 = t85 + t86;
  t88 = -1.*t33*t2*t7;
  t89 = -1.*t2*t34*t8*t9;
  t90 = t88 + t89;
  t91 = -1.*t55;
  t92 = 1. + t91;
  t93 = t2*t7*t31;
  t94 = -1.*t30*t2*t12*t9;
  t95 = t93 + t94;
  t96 = -1.*t30*t2*t7;
  t97 = -1.*t2*t31*t12*t9;
  t98 = t96 + t97;
  t99 = -1.*t73;
  t100 = 1. + t99;
  t101 = t2*t7*t37;
  t102 = -1.*t36*t2*t12*t9;
  t103 = t101 + t102;
  t104 = -1.*t36*t2*t7;
  t105 = -1.*t2*t37*t12*t9;
  t106 = t104 + t105;
  t107 = -1.*t2*t7*t12;
  t108 = -1.*t11*t5;
  t109 = t107 + t108;
  t110 = t11*t2*t7;
  t111 = -1.*t12*t5;
  t112 = t110 + t111;
  t113 = t2*t7*t12;
  t114 = t11*t5;
  t115 = t113 + t114;
  t116 = -1.*t31*t115;
  t117 = t30*t2*t9;
  t118 = t116 + t117;
  t119 = t30*t115;
  t120 = t2*t31*t9;
  t121 = t119 + t120;
  t122 = -1.*t37*t115;
  t123 = t36*t2*t9;
  t124 = t122 + t123;
  t125 = t36*t115;
  t126 = t2*t37*t9;
  t127 = t125 + t126;
  t128 = 0.4*t54*t121;
  t129 = t31*t115;
  t130 = -1.*t30*t2*t9;
  t131 = t129 + t130;
  t132 = t55*t121;
  t133 = -1.*t54*t121;
  t134 = 0.5*t72*t127;
  t135 = t37*t115;
  t136 = -1.*t36*t2*t9;
  t137 = t135 + t136;
  t138 = t73*t127;
  t139 = -1.*t72*t127;
  t140 = -1.*t2*t7*t8;
  t141 = -1.*t6*t5;
  t142 = t140 + t141;
  t143 = t6*t2*t7;
  t144 = -1.*t8*t5;
  t145 = t143 + t144;
  t146 = t2*t7*t8;
  t147 = t6*t5;
  t148 = t146 + t147;
  t149 = -1.*t22*t148;
  t150 = t21*t2*t9;
  t151 = t149 + t150;
  t152 = t21*t148;
  t153 = t2*t22*t9;
  t154 = t152 + t153;
  t155 = -1.*t34*t148;
  t156 = t33*t2*t9;
  t157 = t155 + t156;
  t158 = t33*t148;
  t159 = t2*t34*t9;
  t160 = t158 + t159;
  t161 = 0.4*t45*t154;
  t162 = t22*t148;
  t163 = -1.*t21*t2*t9;
  t164 = t162 + t163;
  t165 = t46*t154;
  t166 = -1.*t45*t154;
  t167 = 0.5*t63*t160;
  t168 = t34*t148;
  t169 = -1.*t33*t2*t9;
  t170 = t168 + t169;
  t171 = t64*t160;
  t172 = -1.*t63*t160;
  p_output1[0]=1.;
  p_output1[4]=0.245484455592049*(t13 - 0.1834*t16 + 0.00678*t19) + 0.245484455592049*(t13 + 0.1834*t25 + 0.00678*t28) + 0.0144432421685319*(-0.1786*t16 - 0.0157*t40 + 0.1822*t44) + 0.0144432421685319*(0.1786*t25 - 0.0157*t49 + 0.1822*t53) + 0.014665004722013*(-0.1893*t16 + 0.0253*t58 + 0.1435*t62) + 0.014665004722013*(0.1893*t25 + 0.0253*t67 + 0.1435*t71) + 0.0075447061837341*(0.18312*t25 + 0.5*t100*t71 + 0.5*t67*t72 + 0.00017*(t71*t72 + t67*t73) + 0.65203*(-1.*t67*t72 + t71*t73)) + 0.0123498801335164*(-0.1831*t16 + 0.4*t40*t45 + 0.0014*(t44*t45 + t40*t46) + 0.5137*(-1.*t40*t45 + t44*t46) + 0.4*t44*t76) + 0.0075447061837341*(-0.18312*t16 + 0.5*t58*t63 + 0.00017*(t62*t63 + t58*t64) + 0.65203*(-1.*t58*t63 + t62*t64) + 0.5*t62*t84) + 0.411025422400312*(0.4024*t2 - 0.0018*t5*t9) + 0.0123498801335164*(0.1831*t25 + 0.4*t49*t54 + 0.0014*(t53*t54 + t49*t55) + 0.5137*(-1.*t49*t54 + t53*t55) + 0.4*t53*t92);
  p_output1[5]=0.000739845760320562*t2*t7 + 0.014665004722013*(0.1435*t103 + 0.0253*t106 - 0.1893*t11*t2*t9) + 0.0075447061837341*(0.5*t100*t103 + 0.5*t106*t72 + 0.65203*(-1.*t106*t72 + t103*t73) + 0.00017*(t103*t72 + t106*t73) - 0.18312*t11*t2*t9) + 0.245484455592049*(t74 - 0.1834*t11*t2*t9 - 0.00678*t12*t2*t9) + 0.0144432421685319*(0.1822*t79 - 0.0157*t82 + 0.1786*t2*t6*t9) + 0.0123498801335164*(0.4*t76*t79 + 0.4*t45*t82 + 0.5137*(t46*t79 - 1.*t45*t82) + 0.0014*(t45*t79 + t46*t82) + 0.1831*t2*t6*t9) + 0.245484455592049*(t74 + 0.1834*t2*t6*t9 - 0.00678*t2*t8*t9) + 0.014665004722013*(0.1435*t87 + 0.1893*t2*t6*t9 + 0.0253*t90) + 0.0075447061837341*(0.5*t84*t87 + 0.18312*t2*t6*t9 + 0.5*t63*t90 + 0.65203*(t64*t87 - 1.*t63*t90) + 0.00017*(t63*t87 + t64*t90)) + 0.0144432421685319*(-0.1786*t11*t2*t9 + 0.1822*t95 - 0.0157*t98) + 0.0123498801335164*(-0.1831*t11*t2*t9 + 0.4*t92*t95 + 0.4*t54*t98 + 0.5137*(t55*t95 - 1.*t54*t98) + 0.0014*(t54*t95 + t55*t98));
  p_output1[6]=0.245484455592049*(0.1834*t109 + 0.00678*t112) + 0.0144432421685319*(0.1786*t109 + 0.1822*t112*t30 - 0.0157*t112*t31) + 0.014665004722013*(0.1893*t109 + 0.1435*t112*t36 + 0.0253*t112*t37) + 0.0075447061837341*(0.18312*t109 + 0.5*t100*t112*t36 + 0.5*t112*t37*t72 + 0.65203*(-1.*t112*t37*t72 + t112*t36*t73) + 0.00017*(t112*t36*t72 + t112*t37*t73)) + 0.0123498801335164*(0.1831*t109 + 0.4*t112*t31*t54 + 0.5137*(-1.*t112*t31*t54 + t112*t30*t55) + 0.0014*(t112*t30*t54 + t112*t31*t55) + 0.4*t112*t30*t92);
  p_output1[7]=0.0144432421685319*(0.1822*t118 - 0.0157*t121) + 0.0123498801335164*(t128 + 0.0014*(t132 + t118*t54) + 0.5137*(t133 + t118*t55) + 0.4*t118*t92);
  p_output1[8]=0.014665004722013*(0.1435*t124 + 0.0253*t127) + 0.0075447061837341*(0.5*t100*t124 + t134 + 0.00017*(t138 + t124*t72) + 0.65203*(t139 + t124*t73));
  p_output1[9]=0.0123498801335164*(t128 + 0.0014*(t132 - 1.*t131*t54) + 0.4*t131*t55 + 0.5137*(t133 - 1.*t131*t55));
  p_output1[10]=0.0075447061837341*(t134 + 0.00017*(t138 - 1.*t137*t72) + 0.5*t137*t73 + 0.65203*(t139 - 1.*t137*t73));
  p_output1[11]=0.245484455592049*(-0.1834*t142 + 0.00678*t145) + 0.0144432421685319*(-0.1786*t142 + 0.1822*t145*t21 - 0.0157*t145*t22) + 0.014665004722013*(-0.1893*t142 + 0.1435*t145*t33 + 0.0253*t145*t34) + 0.0123498801335164*(-0.1831*t142 + 0.4*t145*t22*t45 + 0.5137*(-1.*t145*t22*t45 + t145*t21*t46) + 0.0014*(t145*t21*t45 + t145*t22*t46) + 0.4*t145*t21*t76) + 0.0075447061837341*(-0.18312*t142 + 0.5*t145*t34*t63 + 0.65203*(-1.*t145*t34*t63 + t145*t33*t64) + 0.00017*(t145*t33*t63 + t145*t34*t64) + 0.5*t145*t33*t84);
  p_output1[12]=0.0144432421685319*(0.1822*t151 - 0.0157*t154) + 0.0123498801335164*(t161 + 0.0014*(t165 + t151*t45) + 0.5137*(t166 + t151*t46) + 0.4*t151*t76);
  p_output1[13]=0.014665004722013*(0.1435*t157 + 0.0253*t160) + 0.0075447061837341*(t167 + 0.00017*(t171 + t157*t63) + 0.65203*(t172 + t157*t64) + 0.5*t157*t84);
  p_output1[14]=0.0123498801335164*(t161 + 0.0014*(t165 - 1.*t164*t45) + 0.4*t164*t46 + 0.5137*(t166 - 1.*t164*t46));
  p_output1[15]=0.0075447061837341*(t167 + 0.00017*(t171 - 1.*t170*t63) + 0.5*t170*t64 + 0.65203*(t172 - 1.*t170*t64));
}

static void output2(double *p_output2,const double *x)
{
  double t1;
  double t2;
  double t3;
  double t4;
  double t5;
  double t6;
  double t7;
  double t8;
  double t9;
  double t10;
  double t11;
  double t12;
  double t13;
  double t14;
  double t15;
  double t16;
  double t17;
  double t18;
  double t19;
  double t20;
  double t21;
  double t22;
  double t23;
  double t24;
  double t25;
  double t26;
  double t27;
  double t28;
  double t29;
  double t30;
  double t31;
  double t32;
  double t33;
  double t34;
  double t35;
  double t36;
  double t37;
  double t38;
  double t39;
  double t40;
  double t41;
  double t42;
  double t43;
  double t44;
  double t45;
  double t46;
  double t47;
  double t48;
  double t49;
  double t50;
  double t51;
  double t52;
  double t53;
  double t54;
  double t55;
  double t56;
  double t57;
  double t58;
  double t59;
  double t60;
  double t61;
  double t62;
  double t63;
  double t64;
  double t65;
  double t66;
  double t67;
  double t68;
  double t69;
  double t70;
  double t71;
  double t72;
  double t73;
  double t74;
  double t75;
  double t76;
  double t77;
  double t78;
  double t79;
  double t80;
  double t81;
  double t82;
  double t83;
  double t84;
  double t85;
  double t86;
  double t87;
  double t88;
  double t89;
  double t90;
  double t91;
  double t92;
  double t93;
  double t94;
  double t95;
  double t96;
  double t97;
  double t98;
  double t99;
  double t100;
  double t101;
  double t102;
  double t103;
  double t104;
  double t105;
  double t106;
  double t107;
  double t108;
  double t109;
  double t110;
  double t111;
  double t112;
  double t113;
  double t114;
  double t115;
  double t116;
  double t117;
  double t118;
  double t119;
  double t120;
  double t121;
  double t122;
  double t123;
  double t124;
  double t125;
  double t126;
  double t127;
  double t128;
  double t129;
  double t130;
  double t131;
  double t132;
  double t133;
  double t134;
  double t135;
  double t136;
  double t137;
  double t138;
  double t139;
  double t140;
  double t141;
  double t142;
  double t143;
  double t144;
  double t145;
  double t146;
  double t147;
  double t148;
  double t149;
  double t150;
  double t151;
  double t152;
  double t153;
  double t154;
  double t155;
  double t156;
  double t157;
  double t158;
  double t159;
  double t160;
  double t161;
  double t162;
  double t163;
  double t164;
  double t165;
  double t166;
  double t167;
  double t168;
  double t169;
  double t170;
  double t171;
  double t172;
  double t173;
  double t174;
  double t175;
  double t176;
  double t177;
  double t178;
  double t179;
  double t180;
  double t181;
  double t182;
  double t183;
  double t184;
  double t185;
  double t186;
  double t187;
  double t188;
  double t189;
  double t190;
  double t191;
  double t192;
  double t193;
  double t194;
  double t195;
  double t196;
  double t197;
  double t198;
  double t199;
  double t200;
  double t201;
  double t202;
  double t203;
  double t204;
  double t205;
  double t206;
  double t207;
  double t208;
  double t209;
  double t210;
  double t211;
  double t212;
  double t213;
  double t214;
  double t215;
  double t216;
  double t217;
  double t218;
  double t219;
  double t220;
  double t221;
  double t222;
  double t223;
  double t224;
  double t225;
  double t226;
  double t227;
  t1 = x[3];
  t2 = Cos(t1);
  t3 = x[4];
  t4 = x[5];
  t5 = Cos(t4);
  t6 = Sin(t1);
  t7 = -1.*t5*t6;
  t8 = Sin(t3);
  t9 = Sin(t4);
  t10 = -1.*t2*t8*t9;
  t11 = t7 + t10;
  t12 = Cos(t3);
  t13 = x[11];
  t14 = Cos(t13);
  t15 = Sin(t13);
  t16 = t2*t5*t8;
  t17 = -1.*t6*t9;
  t18 = t16 + t17;
  t19 = 0.00025*t11;
  t20 = x[6];
  t21 = Cos(t20);
  t22 = Sin(t20);
  t23 = t2*t12*t15;
  t24 = t14*t18;
  t25 = t23 + t24;
  t26 = x[12];
  t27 = -1.*t14*t2*t12;
  t28 = t15*t18;
  t29 = t27 + t28;
  t30 = Cos(t26);
  t31 = Sin(t26);
  t32 = x[13];
  t33 = Cos(t32);
  t34 = Sin(t32);
  t35 = t2*t12*t22;
  t36 = t21*t18;
  t37 = t35 + t36;
  t38 = x[7];
  t39 = -1.*t21*t2*t12;
  t40 = t22*t18;
  t41 = t39 + t40;
  t42 = Cos(t38);
  t43 = Sin(t38);
  t44 = x[8];
  t45 = Cos(t44);
  t46 = Sin(t44);
  t47 = -1.*t31*t11;
  t48 = t30*t29;
  t49 = t47 + t48;
  t50 = x[14];
  t51 = t30*t11;
  t52 = t31*t29;
  t53 = t51 + t52;
  t54 = Sin(t50);
  t55 = Cos(t50);
  t56 = -1.*t34*t11;
  t57 = t33*t29;
  t58 = t56 + t57;
  t59 = x[15];
  t60 = t33*t11;
  t61 = t34*t29;
  t62 = t60 + t61;
  t63 = Sin(t59);
  t64 = Cos(t59);
  t65 = -1.*t43*t11;
  t66 = t42*t41;
  t67 = t65 + t66;
  t68 = x[9];
  t69 = t42*t11;
  t70 = t43*t41;
  t71 = t69 + t70;
  t72 = Sin(t68);
  t73 = Cos(t68);
  t74 = -1.*t46*t11;
  t75 = t45*t41;
  t76 = t74 + t75;
  t77 = x[10];
  t78 = t45*t11;
  t79 = t46*t41;
  t80 = t78 + t79;
  t81 = Sin(t77);
  t82 = Cos(t77);
  t83 = -0.00025*t12*t6*t9;
  t84 = t14*t12*t5*t6;
  t85 = -1.*t15*t6*t8;
  t86 = t84 + t85;
  t87 = t12*t5*t15*t6;
  t88 = t14*t6*t8;
  t89 = t87 + t88;
  t90 = t21*t12*t5*t6;
  t91 = -1.*t22*t6*t8;
  t92 = t90 + t91;
  t93 = t12*t5*t22*t6;
  t94 = t21*t6*t8;
  t95 = t93 + t94;
  t96 = t31*t89;
  t97 = -1.*t30*t12*t6*t9;
  t98 = t96 + t97;
  t99 = -1.*t55;
  t100 = 1. + t99;
  t101 = t30*t89;
  t102 = t12*t31*t6*t9;
  t103 = t101 + t102;
  t104 = t43*t95;
  t105 = -1.*t42*t12*t6*t9;
  t106 = t104 + t105;
  t107 = -1.*t73;
  t108 = 1. + t107;
  t109 = t42*t95;
  t110 = t12*t43*t6*t9;
  t111 = t109 + t110;
  t112 = t34*t89;
  t113 = -1.*t33*t12*t6*t9;
  t114 = t112 + t113;
  t115 = -1.*t64;
  t116 = 1. + t115;
  t117 = t33*t89;
  t118 = t12*t34*t6*t9;
  t119 = t117 + t118;
  t120 = t46*t95;
  t121 = -1.*t45*t12*t6*t9;
  t122 = t120 + t121;
  t123 = -1.*t82;
  t124 = 1. + t123;
  t125 = t45*t95;
  t126 = t12*t46*t6*t9;
  t127 = t125 + t126;
  t128 = -1.*t5*t6*t8;
  t129 = -1.*t2*t9;
  t130 = t128 + t129;
  t131 = t2*t5;
  t132 = -1.*t6*t8*t9;
  t133 = t131 + t132;
  t134 = 0.00025*t130;
  t135 = -1.*t31*t130;
  t136 = t30*t15*t133;
  t137 = t135 + t136;
  t138 = t30*t130;
  t139 = t31*t15*t133;
  t140 = t138 + t139;
  t141 = -1.*t34*t130;
  t142 = t33*t15*t133;
  t143 = t141 + t142;
  t144 = t33*t130;
  t145 = t34*t15*t133;
  t146 = t144 + t145;
  t147 = -1.*t43*t130;
  t148 = t42*t22*t133;
  t149 = t147 + t148;
  t150 = t42*t130;
  t151 = t43*t22*t133;
  t152 = t150 + t151;
  t153 = -1.*t46*t130;
  t154 = t45*t22*t133;
  t155 = t153 + t154;
  t156 = t45*t130;
  t157 = t46*t22*t133;
  t158 = t156 + t157;
  t159 = t12*t22*t6;
  t160 = t5*t6*t8;
  t161 = t2*t9;
  t162 = t160 + t161;
  t163 = t21*t162;
  t164 = t159 + t163;
  t165 = t21*t12*t6;
  t166 = -1.*t22*t162;
  t167 = t165 + t166;
  t168 = -1.*t21*t12*t6;
  t169 = t22*t162;
  t170 = t168 + t169;
  t171 = -1.*t43*t133;
  t172 = t42*t170;
  t173 = t171 + t172;
  t174 = -1.*t42*t133;
  t175 = -1.*t43*t170;
  t176 = t174 + t175;
  t177 = -1.*t46*t133;
  t178 = t45*t170;
  t179 = t177 + t178;
  t180 = -1.*t45*t133;
  t181 = -1.*t46*t170;
  t182 = t180 + t181;
  t183 = 0.4*t72*t173;
  t184 = -1.*t72*t173;
  t185 = t42*t133;
  t186 = t43*t170;
  t187 = t185 + t186;
  t188 = t73*t173;
  t189 = 0.5*t81*t179;
  t190 = -1.*t81*t179;
  t191 = t45*t133;
  t192 = t46*t170;
  t193 = t191 + t192;
  t194 = t82*t179;
  t195 = t12*t15*t6;
  t196 = t14*t162;
  t197 = t195 + t196;
  t198 = t14*t12*t6;
  t199 = -1.*t15*t162;
  t200 = t198 + t199;
  t201 = -1.*t14*t12*t6;
  t202 = t15*t162;
  t203 = t201 + t202;
  t204 = -1.*t31*t133;
  t205 = t30*t203;
  t206 = t204 + t205;
  t207 = -1.*t30*t133;
  t208 = -1.*t31*t203;
  t209 = t207 + t208;
  t210 = -1.*t34*t133;
  t211 = t33*t203;
  t212 = t210 + t211;
  t213 = -1.*t33*t133;
  t214 = -1.*t34*t203;
  t215 = t213 + t214;
  t216 = 0.4*t54*t206;
  t217 = -1.*t54*t206;
  t218 = t30*t133;
  t219 = t31*t203;
  t220 = t218 + t219;
  t221 = t55*t206;
  t222 = 0.5*t63*t212;
  t223 = -1.*t63*t212;
  t224 = t33*t133;
  t225 = t34*t203;
  t226 = t224 + t225;
  t227 = t64*t212;
  p_output2[1]=1.;
  p_output2[3]=0.411025422400312*(-0.0018*t11 - 0.4024*t12*t2) + 0.245484455592049*(t19 - 0.1834*t25 + 0.00678*t29) + 0.245484455592049*(t19 + 0.1834*t37 + 0.00678*t41) + 0.0144432421685319*(-0.1786*t25 + 0.1822*t49 - 0.0157*t53) + 0.0123498801335164*(-0.1831*t25 + 0.4*t100*t49 + 0.4*t53*t54 + 0.5137*(-1.*t53*t54 + t49*t55) + 0.0014*(t49*t54 + t53*t55)) + 0.014665004722013*(-0.1893*t25 + 0.1435*t58 + 0.0253*t62) + 0.0075447061837341*(-0.18312*t25 + 0.5*t116*t58 + 0.5*t62*t63 + 0.65203*(-1.*t62*t63 + t58*t64) + 0.00017*(t58*t63 + t62*t64)) + 0.0144432421685319*(0.1786*t37 + 0.1822*t67 - 0.0157*t71) + 0.0123498801335164*(0.1831*t37 + 0.4*t108*t67 + 0.4*t71*t72 + 0.5137*(-1.*t71*t72 + t67*t73) + 0.0014*(t67*t72 + t71*t73)) + 0.014665004722013*(0.1893*t37 + 0.1435*t76 + 0.0253*t80) + 0.0075447061837341*(0.18312*t37 + 0.5*t124*t76 + 0.5*t80*t81 + 0.65203*(-1.*t80*t81 + t76*t82) + 0.00017*(t76*t81 + t80*t82));
  p_output2[4]=0.014665004722013*(0.0253*t114 + 0.1435*t119 - 0.1893*t86) + 0.0075447061837341*(0.5*t116*t119 + 0.5*t114*t63 + 0.00017*(t119*t63 + t114*t64) + 0.65203*(-1.*t114*t63 + t119*t64) - 0.18312*t86) + 0.245484455592049*(t83 - 0.1834*t86 + 0.00678*t89) + 0.411025422400312*(0.4024*t6*t8 + 0.0018*t12*t6*t9) + 0.0144432421685319*(-0.0157*t106 + 0.1822*t111 + 0.1786*t92) + 0.0123498801335164*(0.4*t108*t111 + 0.4*t106*t72 + 0.0014*(t111*t72 + t106*t73) + 0.5137*(-1.*t106*t72 + t111*t73) + 0.1831*t92) + 0.0075447061837341*(0.5*t124*t127 + 0.5*t122*t81 + 0.00017*(t127*t81 + t122*t82) + 0.65203*(-1.*t122*t81 + t127*t82) + 0.18312*t92) + 0.014665004722013*(0.0253*t122 + 0.1435*t127 + 0.1893*t92) + 0.245484455592049*(t83 + 0.1834*t92 + 0.00678*t95) + 0.0144432421685319*(0.1822*t103 - 0.1786*t86 - 0.0157*t98) + 0.0123498801335164*(0.4*t100*t103 - 0.1831*t86 + 0.4*t54*t98 + 0.5137*(t103*t55 - 1.*t54*t98) + 0.0014*(t103*t54 + t55*t98));
  p_output2[5]=-0.000739845760320562*t130 + 0.0144432421685319*(0.1822*t137 - 0.1786*t133*t14 - 0.0157*t140) + 0.014665004722013*(-0.1893*t133*t14 + 0.1435*t143 + 0.0253*t146) + 0.245484455592049*(t134 - 0.1834*t133*t14 + 0.00678*t133*t15) + 0.0144432421685319*(0.1822*t149 - 0.0157*t152 + 0.1786*t133*t21) + 0.014665004722013*(0.1435*t155 + 0.0253*t158 + 0.1893*t133*t21) + 0.245484455592049*(t134 + 0.1834*t133*t21 + 0.00678*t133*t22) + 0.0123498801335164*(0.4*t100*t137 - 0.1831*t133*t14 + 0.4*t140*t54 + 0.5137*(-1.*t140*t54 + t137*t55) + 0.0014*(t137*t54 + t140*t55)) + 0.0075447061837341*(-0.18312*t133*t14 + 0.5*t116*t143 + 0.5*t146*t63 + 0.65203*(-1.*t146*t63 + t143*t64) + 0.00017*(t143*t63 + t146*t64)) + 0.0123498801335164*(0.4*t108*t149 + 0.1831*t133*t21 + 0.4*t152*t72 + 0.5137*(-1.*t152*t72 + t149*t73) + 0.0014*(t149*t72 + t152*t73)) + 0.0075447061837341*(0.5*t124*t155 + 0.18312*t133*t21 + 0.5*t158*t81 + 0.65203*(-1.*t158*t81 + t155*t82) + 0.00017*(t155*t81 + t158*t82));
  p_output2[6]=0.245484455592049*(0.00678*t164 + 0.1834*t167) + 0.0144432421685319*(0.1786*t167 + 0.1822*t164*t42 - 0.0157*t164*t43) + 0.014665004722013*(0.1893*t167 + 0.1435*t164*t45 + 0.0253*t164*t46) + 0.0123498801335164*(0.1831*t167 + 0.4*t108*t164*t42 + 0.4*t164*t43*t72 + 0.5137*(-1.*t164*t43*t72 + t164*t42*t73) + 0.0014*(t164*t42*t72 + t164*t43*t73)) + 0.0075447061837341*(0.18312*t167 + 0.5*t124*t164*t45 + 0.5*t164*t46*t81 + 0.65203*(-1.*t164*t46*t81 + t164*t45*t82) + 0.00017*(t164*t45*t81 + t164*t46*t82));
  p_output2[7]=0.0144432421685319*(-0.0157*t173 + 0.1822*t176) + 0.0123498801335164*(0.4*t108*t176 + t183 + 0.0014*(t188 + t176*t72) + 0.5137*(t184 + t176*t73));
  p_output2[8]=0.014665004722013*(0.0253*t179 + 0.1435*t182) + 0.0075447061837341*(0.5*t124*t182 + t189 + 0.00017*(t194 + t182*t81) + 0.65203*(t190 + t182*t82));
  p_output2[9]=0.0123498801335164*(t183 + 0.0014*(t188 - 1.*t187*t72) + 0.4*t187*t73 + 0.5137*(t184 - 1.*t187*t73));
  p_output2[10]=0.0075447061837341*(t189 + 0.00017*(t194 - 1.*t193*t81) + 0.5*t193*t82 + 0.65203*(t190 - 1.*t193*t82));
  p_output2[11]=0.245484455592049*(0.00678*t197 - 0.1834*t200) + 0.0144432421685319*(-0.1786*t200 + 0.1822*t197*t30 - 0.0157*t197*t31) + 0.014665004722013*(-0.1893*t200 + 0.1435*t197*t33 + 0.0253*t197*t34) + 0.0123498801335164*(-0.1831*t200 + 0.4*t100*t197*t30 + 0.4*t197*t31*t54 + 0.5137*(-1.*t197*t31*t54 + t197*t30*t55) + 0.0014*(t197*t30*t54 + t197*t31*t55)) + 0.0075447061837341*(-0.18312*t200 + 0.5*t116*t197*t33 + 0.5*t197*t34*t63 + 0.65203*(-1.*t197*t34*t63 + t197*t33*t64) + 0.00017*(t197*t33*t63 + t197*t34*t64));
  p_output2[12]=0.0144432421685319*(-0.0157*t206 + 0.1822*t209) + 0.0123498801335164*(0.4*t100*t209 + t216 + 0.0014*(t221 + t209*t54) + 0.5137*(t217 + t209*t55));
  p_output2[13]=0.014665004722013*(0.0253*t212 + 0.1435*t215) + 0.0075447061837341*(0.5*t116*t215 + t222 + 0.00017*(t227 + t215*t63) + 0.65203*(t223 + t215*t64));
  p_output2[14]=0.0123498801335164*(t216 + 0.0014*(t221 - 1.*t220*t54) + 0.4*t220*t55 + 0.5137*(t217 - 1.*t220*t55));
  p_output2[15]=0.0075447061837341*(t222 + 0.00017*(t227 - 1.*t226*t63) + 0.5*t226*t64 + 0.65203*(t223 - 1.*t226*t64));
}

static void output3(double *p_output3,const double *x)
{
  double t1;
  double t2;
  double t3;
  double t4;
  double t5;
  double t6;
  double t7;
  double t8;
  double t9;
  double t10;
  double t11;
  double t12;
  double t13;
  double t14;
  double t15;
  double t16;
  double t17;
  double t18;
  double t19;
  double t20;
  double t21;
  double t22;
  double t23;
  double t24;
  double t25;
  double t26;
  double t27;
  double t28;
  double t29;
  double t30;
  double t31;
  double t32;
  double t33;
  double t34;
  double t35;
  double t36;
  double t37;
  double t38;
  double t39;
  double t40;
  double t41;
  double t42;
  double t43;
  double t44;
  double t45;
  double t46;
  double t47;
  double t48;
  double t49;
  double t50;
  double t51;
  double t52;
  double t53;
  double t54;
  double t55;
  double t56;
  double t57;
  double t58;
  double t59;
  double t60;
  double t61;
  double t62;
  double t63;
  double t64;
  double t65;
  double t66;
  double t67;
  double t68;
  double t69;
  double t70;
  double t71;
  double t72;
  double t73;
  double t74;
  double t75;
  double t76;
  double t77;
  double t78;
  double t79;
  double t80;
  double t81;
  double t82;
  double t83;
  double t84;
  double t85;
  double t86;
  double t87;
  double t88;
  double t89;
  double t90;
  double t91;
  double t92;
  double t93;
  double t94;
  double t95;
  double t96;
  double t97;
  double t98;
  double t99;
  double t100;
  double t101;
  double t102;
  double t103;
  double t104;
  double t105;
  double t106;
  double t107;
  double t108;
  double t109;
  double t110;
  double t111;
  double t112;
  double t113;
  double t114;
  double t115;
  double t116;
  double t117;
  double t118;
  double t119;
  double t120;
  double t121;
  double t122;
  double t123;
  double t124;
  double t125;
  double t126;
  double t127;
  double t128;
  double t129;
  double t130;
  double t131;
  double t132;
  double t133;
  double t134;
  double t135;
  double t136;
  double t137;
  double t138;
  double t139;
  double t140;
  double t141;
  double t142;
  double t143;
  double t144;
  double t145;
  double t146;
  double t147;
  double t148;
  double t149;
  double t150;
  double t151;
  double t152;
  double t153;
  double t154;
  double t155;
  double t156;
  double t157;
  double t158;
  double t159;
  double t160;
  double t161;
  double t162;
  double t163;
  double t164;
  double t165;
  double t166;
  double t167;
  double t168;
  double t169;
  double t170;
  double t171;
  double t172;
  double t173;
  double t174;
  double t175;
  double t176;
  double t177;
  double t178;
  double t179;
  double t180;
  double t181;
  double t182;
  double t183;
  double t184;
  double t185;
  double t186;
  double t187;
  double t188;
  double t189;
  double t190;
  double t191;
  double t192;
  double t193;
  double t194;
  double t195;
  double t196;
  double t197;
  double t198;
  double t199;
  double t200;
  double t201;
  double t202;
  double t203;
  double t204;
  double t205;
  double t206;
  double t207;
  double t208;
  double t209;
  double t210;
  double t211;
  double t212;
  double t213;
  double t214;
  double t215;
  double t216;
  double t217;
  double t218;
  double t219;
  double t220;
  double t221;
  double t222;
  double t223;
  double t224;
  double t225;
  double t226;
  double t227;
  t1 = x[3];
  t2 = Sin(t1);
  t3 = x[4];
  t4 = x[5];
  t5 = Cos(t1);
  t6 = Cos(t4);
  t7 = t5*t6;
  t8 = Sin(t3);
  t9 = Sin(t4);
  t10 = -1.*t2*t8*t9;
  t11 = t7 + t10;
  t12 = Cos(t3);
  t13 = x[11];
  t14 = Cos(t13);
  t15 = Sin(t13);
  t16 = t6*t2*t8;
  t17 = t5*t9;
  t18 = t16 + t17;
  t19 = 0.00025*t11;
  t20 = x[6];
  t21 = Cos(t20);
  t22 = Sin(t20);
  t23 = t12*t15*t2;
  t24 = t14*t18;
  t25 = t23 + t24;
  t26 = x[12];
  t27 = -1.*t14*t12*t2;
  t28 = t15*t18;
  t29 = t27 + t28;
  t30 = Cos(t26);
  t31 = Sin(t26);
  t32 = x[13];
  t33 = Cos(t32);
  t34 = Sin(t32);
  t35 = t12*t22*t2;
  t36 = t21*t18;
  t37 = t35 + t36;
  t38 = x[7];
  t39 = -1.*t21*t12*t2;
  t40 = t22*t18;
  t41 = t39 + t40;
  t42 = Cos(t38);
  t43 = Sin(t38);
  t44 = x[8];
  t45 = Cos(t44);
  t46 = Sin(t44);
  t47 = -1.*t31*t11;
  t48 = t30*t29;
  t49 = t47 + t48;
  t50 = x[14];
  t51 = t30*t11;
  t52 = t31*t29;
  t53 = t51 + t52;
  t54 = Sin(t50);
  t55 = Cos(t50);
  t56 = -1.*t34*t11;
  t57 = t33*t29;
  t58 = t56 + t57;
  t59 = x[15];
  t60 = t33*t11;
  t61 = t34*t29;
  t62 = t60 + t61;
  t63 = Sin(t59);
  t64 = Cos(t59);
  t65 = -1.*t43*t11;
  t66 = t42*t41;
  t67 = t65 + t66;
  t68 = x[9];
  t69 = t42*t11;
  t70 = t43*t41;
  t71 = t69 + t70;
  t72 = Sin(t68);
  t73 = Cos(t68);
  t74 = -1.*t46*t11;
  t75 = t45*t41;
  t76 = t74 + t75;
  t77 = x[10];
  t78 = t45*t11;
  t79 = t46*t41;
  t80 = t78 + t79;
  t81 = Sin(t77);
  t82 = Cos(t77);
  t83 = 0.00025*t5*t12*t9;
  t84 = -1.*t14*t5*t12*t6;
  t85 = t5*t15*t8;
  t86 = t84 + t85;
  t87 = -1.*t5*t12*t6*t15;
  t88 = -1.*t14*t5*t8;
  t89 = t87 + t88;
  t90 = -1.*t21*t5*t12*t6;
  t91 = t5*t22*t8;
  t92 = t90 + t91;
  t93 = -1.*t5*t12*t6*t22;
  t94 = -1.*t21*t5*t8;
  t95 = t93 + t94;
  t96 = t31*t89;
  t97 = t30*t5*t12*t9;
  t98 = t96 + t97;
  t99 = -1.*t55;
  t100 = 1. + t99;
  t101 = t30*t89;
  t102 = -1.*t5*t12*t31*t9;
  t103 = t101 + t102;
  t104 = t43*t95;
  t105 = t42*t5*t12*t9;
  t106 = t104 + t105;
  t107 = -1.*t73;
  t108 = 1. + t107;
  t109 = t42*t95;
  t110 = -1.*t5*t12*t43*t9;
  t111 = t109 + t110;
  t112 = t34*t89;
  t113 = t33*t5*t12*t9;
  t114 = t112 + t113;
  t115 = -1.*t64;
  t116 = 1. + t115;
  t117 = t33*t89;
  t118 = -1.*t5*t12*t34*t9;
  t119 = t117 + t118;
  t120 = t46*t95;
  t121 = t45*t5*t12*t9;
  t122 = t120 + t121;
  t123 = -1.*t82;
  t124 = 1. + t123;
  t125 = t45*t95;
  t126 = -1.*t5*t12*t46*t9;
  t127 = t125 + t126;
  t128 = t5*t6*t8;
  t129 = -1.*t2*t9;
  t130 = t128 + t129;
  t131 = t6*t2;
  t132 = t5*t8*t9;
  t133 = t131 + t132;
  t134 = 0.00025*t130;
  t135 = -1.*t31*t130;
  t136 = t30*t15*t133;
  t137 = t135 + t136;
  t138 = t30*t130;
  t139 = t31*t15*t133;
  t140 = t138 + t139;
  t141 = -1.*t34*t130;
  t142 = t33*t15*t133;
  t143 = t141 + t142;
  t144 = t33*t130;
  t145 = t34*t15*t133;
  t146 = t144 + t145;
  t147 = -1.*t43*t130;
  t148 = t42*t22*t133;
  t149 = t147 + t148;
  t150 = t42*t130;
  t151 = t43*t22*t133;
  t152 = t150 + t151;
  t153 = -1.*t46*t130;
  t154 = t45*t22*t133;
  t155 = t153 + t154;
  t156 = t45*t130;
  t157 = t46*t22*t133;
  t158 = t156 + t157;
  t159 = -1.*t5*t12*t22;
  t160 = -1.*t5*t6*t8;
  t161 = t2*t9;
  t162 = t160 + t161;
  t163 = t21*t162;
  t164 = t159 + t163;
  t165 = -1.*t21*t5*t12;
  t166 = -1.*t22*t162;
  t167 = t165 + t166;
  t168 = t21*t5*t12;
  t169 = t22*t162;
  t170 = t168 + t169;
  t171 = -1.*t43*t133;
  t172 = t42*t170;
  t173 = t171 + t172;
  t174 = -1.*t42*t133;
  t175 = -1.*t43*t170;
  t176 = t174 + t175;
  t177 = -1.*t46*t133;
  t178 = t45*t170;
  t179 = t177 + t178;
  t180 = -1.*t45*t133;
  t181 = -1.*t46*t170;
  t182 = t180 + t181;
  t183 = 0.4*t72*t173;
  t184 = -1.*t72*t173;
  t185 = t42*t133;
  t186 = t43*t170;
  t187 = t185 + t186;
  t188 = t73*t173;
  t189 = 0.5*t81*t179;
  t190 = -1.*t81*t179;
  t191 = t45*t133;
  t192 = t46*t170;
  t193 = t191 + t192;
  t194 = t82*t179;
  t195 = -1.*t5*t12*t15;
  t196 = t14*t162;
  t197 = t195 + t196;
  t198 = -1.*t14*t5*t12;
  t199 = -1.*t15*t162;
  t200 = t198 + t199;
  t201 = t14*t5*t12;
  t202 = t15*t162;
  t203 = t201 + t202;
  t204 = -1.*t31*t133;
  t205 = t30*t203;
  t206 = t204 + t205;
  t207 = -1.*t30*t133;
  t208 = -1.*t31*t203;
  t209 = t207 + t208;
  t210 = -1.*t34*t133;
  t211 = t33*t203;
  t212 = t210 + t211;
  t213 = -1.*t33*t133;
  t214 = -1.*t34*t203;
  t215 = t213 + t214;
  t216 = 0.4*t54*t206;
  t217 = -1.*t54*t206;
  t218 = t30*t133;
  t219 = t31*t203;
  t220 = t218 + t219;
  t221 = t55*t206;
  t222 = 0.5*t63*t212;
  t223 = -1.*t63*t212;
  t224 = t33*t133;
  t225 = t34*t203;
  t226 = t224 + t225;
  t227 = t64*t212;
  p_output3[2]=1.;
  p_output3[3]=0.411025422400312*(-0.0018*t11 - 0.4024*t12*t2) + 0.245484455592049*(t19 - 0.1834*t25 + 0.00678*t29) + 0.245484455592049*(t19 + 0.1834*t37 + 0.00678*t41) + 0.0144432421685319*(-0.1786*t25 + 0.1822*t49 - 0.0157*t53) + 0.0123498801335164*(-0.1831*t25 + 0.4*t100*t49 + 0.4*t53*t54 + 0.5137*(-1.*t53*t54 + t49*t55) + 0.0014*(t49*t54 + t53*t55)) + 0.014665004722013*(-0.1893*t25 + 0.1435*t58 + 0.0253*t62) + 0.0075447061837341*(-0.18312*t25 + 0.5*t116*t58 + 0.5*t62*t63 + 0.65203*(-1.*t62*t63 + t58*t64) + 0.00017*(t58*t63 + t62*t64)) + 0.0144432421685319*(0.1786*t37 + 0.1822*t67 - 0.0157*t71) + 0.0123498801335164*(0.1831*t37 + 0.4*t108*t67 + 0.4*t71*t72 + 0.5137*(-1.*t71*t72 + t67*t73) + 0.0014*(t67*t72 + t71*t73)) + 0.014665004722013*(0.1893*t37 + 0.1435*t76 + 0.0253*t80) + 0.0075447061837341*(0.18312*t37 + 0.5*t124*t76 + 0.5*t80*t81 + 0.65203*(-1.*t80*t81 + t76*t82) + 0.00017*(t76*t81 + t80*t82));
  p_output3[4]=0.014665004722013*(0.0253*t114 + 0.1435*t119 - 0.1893*t86) + 0.0075447061837341*(0.5*t116*t119 + 0.5*t114*t63 + 0.00017*(t119*t63 + t114*t64) + 0.65203*(-1.*t114*t63 + t119*t64) - 0.18312*t86) + 0.245484455592049*(t83 - 0.1834*t86 + 0.00678*t89) + 0.411025422400312*(-0.4024*t5*t8 - 0.0018*t12*t5*t9) + 0.0144432421685319*(-0.0157*t106 + 0.1822*t111 + 0.1786*t92) + 0.0123498801335164*(0.4*t108*t111 + 0.4*t106*t72 + 0.0014*(t111*t72 + t106*t73) + 0.5137*(-1.*t106*t72 + t111*t73) + 0.1831*t92) + 0.0075447061837341*(0.5*t124*t127 + 0.5*t122*t81 + 0.00017*(t127*t81 + t122*t82) + 0.65203*(-1.*t122*t81 + t127*t82) + 0.18312*t92) + 0.014665004722013*(0.0253*t122 + 0.1435*t127 + 0.1893*t92) + 0.245484455592049*(t83 + 0.1834*t92 + 0.00678*t95) + 0.0144432421685319*(0.1822*t103 - 0.1786*t86 - 0.0157*t98) + 0.0123498801335164*(0.4*t100*t103 - 0.1831*t86 + 0.4*t54*t98 + 0.5137*(t103*t55 - 1.*t54*t98) + 0.0014*(t103*t54 + t55*t98));
  p_output3[5]=-0.000739845760320562*t130 + 0.0144432421685319*(0.1822*t137 - 0.1786*t133*t14 - 0.0157*t140) + 0.014665004722013*(-0.1893*t133*t14 + 0.1435*t143 + 0.0253*t146) + 0.245484455592049*(t134 - 0.1834*t133*t14 + 0.00678*t133*t15) + 0.0144432421685319*(0.1822*t149 - 0.0157*t152 + 0.1786*t133*t21) + 0.014665004722013*(0.1435*t155 + 0.0253*t158 + 0.1893*t133*t21) + 0.245484455592049*(t134 + 0.1834*t133*t21 + 0.00678*t133*t22) + 0.0123498801335164*(0.4*t100*t137 - 0.1831*t133*t14 + 0.4*t140*t54 + 0.5137*(-1.*t140*t54 + t137*t55) + 0.0014*(t137*t54 + t140*t55)) + 0.0075447061837341*(-0.18312*t133*t14 + 0.5*t116*t143 + 0.5*t146*t63 + 0.65203*(-1.*t146*t63 + t143*t64) + 0.00017*(t143*t63 + t146*t64)) + 0.0123498801335164*(0.4*t108*t149 + 0.1831*t133*t21 + 0.4*t152*t72 + 0.5137*(-1.*t152*t72 + t149*t73) + 0.0014*(t149*t72 + t152*t73)) + 0.0075447061837341*(0.5*t124*t155 + 0.18312*t133*t21 + 0.5*t158*t81 + 0.65203*(-1.*t158*t81 + t155*t82) + 0.00017*(t155*t81 + t158*t82));
  p_output3[6]=0.245484455592049*(0.00678*t164 + 0.1834*t167) + 0.0144432421685319*(0.1786*t167 + 0.1822*t164*t42 - 0.0157*t164*t43) + 0.014665004722013*(0.1893*t167 + 0.1435*t164*t45 + 0.0253*t164*t46) + 0.0123498801335164*(0.1831*t167 + 0.4*t108*t164*t42 + 0.4*t164*t43*t72 + 0.5137*(-1.*t164*t43*t72 + t164*t42*t73) + 0.0014*(t164*t42*t72 + t164*t43*t73)) + 0.0075447061837341*(0.18312*t167 + 0.5*t124*t164*t45 + 0.5*t164*t46*t81 + 0.65203*(-1.*t164*t46*t81 + t164*t45*t82) + 0.00017*(t164*t45*t81 + t164*t46*t82));
  p_output3[7]=0.0144432421685319*(-0.0157*t173 + 0.1822*t176) + 0.0123498801335164*(0.4*t108*t176 + t183 + 0.0014*(t188 + t176*t72) + 0.5137*(t184 + t176*t73));
  p_output3[8]=0.014665004722013*(0.0253*t179 + 0.1435*t182) + 0.0075447061837341*(0.5*t124*t182 + t189 + 0.00017*(t194 + t182*t81) + 0.65203*(t190 + t182*t82));
  p_output3[9]=0.0123498801335164*(t183 + 0.0014*(t188 - 1.*t187*t72) + 0.4*t187*t73 + 0.5137*(t184 - 1.*t187*t73));
  p_output3[10]=0.0075447061837341*(t189 + 0.00017*(t194 - 1.*t193*t81) + 0.5*t193*t82 + 0.65203*(t190 - 1.*t193*t82));
  p_output3[11]=0.245484455592049*(0.00678*t197 - 0.1834*t200) + 0.0144432421685319*(-0.1786*t200 + 0.1822*t197*t30 - 0.0157*t197*t31) + 0.014665004722013*(-0.1893*t200 + 0.1435*t197*t33 + 0.0253*t197*t34) + 0.0123498801335164*(-0.1831*t200 + 0.4*t100*t197*t30 + 0.4*t197*t31*t54 + 0.5137*(-1.*t197*t31*t54 + t197*t30*t55) + 0.0014*(t197*t30*t54 + t197*t31*t55)) + 0.0075447061837341*(-0.18312*t200 + 0.5*t116*t197*t33 + 0.5*t197*t34*t63 + 0.65203*(-1.*t197*t34*t63 + t197*t33*t64) + 0.00017*(t197*t33*t63 + t197*t34*t64));
  p_output3[12]=0.0144432421685319*(-0.0157*t206 + 0.1822*t209) + 0.0123498801335164*(0.4*t100*t209 + t216 + 0.0014*(t221 + t209*t54) + 0.5137*(t217 + t209*t55));
  p_output3[13]=0.014665004722013*(0.0253*t212 + 0.1435*t215) + 0.0075447061837341*(0.5*t116*t215 + t222 + 0.00017*(t227 + t215*t63) + 0.65203*(t223 + t215*t64));
  p_output3[14]=0.0123498801335164*(t216 + 0.0014*(t221 - 1.*t220*t54) + 0.4*t220*t55 + 0.5137*(t217 - 1.*t220*t55));
  p_output3[15]=0.0075447061837341*(t222 + 0.00017*(t227 - 1.*t226*t63) + 0.5*t226*t64 + 0.65203*(t223 - 1.*t226*t64));
}



#ifdef MATLAB_MEX_FILE

#include "mex.h"
#include "matrix.h"

/*
 * Main function
 */
void mexFunction( int nlhs, mxArray *plhs[],
                  int nrhs, const mxArray *prhs[] )
{
  size_t mrows, ncols;

  double *x;
  double *p_output1,*p_output2,*p_output3;

  /*  Check for proper number of arguments.  */ 
  if( nrhs != 1)
    {
      mexErrMsgIdAndTxt("MATLAB:MShaped:invalidNumInputs", "One input(s) required (x).");
    }
  else if( nlhs > 3)
    {
      mexErrMsgIdAndTxt("MATLAB:MShaped:maxlhs", "Too many output arguments.");
    }

  /*  The input must be a noncomplex double vector or scaler.  */
  mrows = mxGetM(prhs[0]);
  ncols = mxGetN(prhs[0]);
  if( !mxIsDouble(prhs[0]) || mxIsComplex(prhs[0]) ||
    ( !(mrows == 32 && ncols == 1) && 
      !(mrows == 1 && ncols == 32))) 
    {
      mexErrMsgIdAndTxt( "MATLAB:MShaped:inputNotRealVector", "x is wrong.");
    }

  /*  Assign pointers to each input.  */
  x = mxGetPr(prhs[0]);
   


   
  /*  Create matrices for return arguments.  */
  plhs[0] = mxCreateDoubleMatrix((mwSize) 16, (mwSize) 1, mxREAL);
  p_output1 = mxGetPr(plhs[0]);
  plhs[1] = mxCreateDoubleMatrix((mwSize) 16, (mwSize) 1, mxREAL);
  p_output2 = mxGetPr(plhs[1]);
  plhs[2] = mxCreateDoubleMatrix((mwSize) 16, (mwSize) 1, mxREAL);
  p_output3 = mxGetPr(plhs[2]);


  /* Call the calculation subroutine. */
  output1(p_output1,x);
  output2(p_output2,x);
  output3(p_output3,x);


}

#else // MATLAB_MEX_FILE

#include "Je_com_mat.hh"

namespace symbolic_expression
{
namespace basic
{

void Je_com_mat_raw(double *p_output1, double *p_output2, double *p_output3, const double *x)
{
  // Call Subroutines
  output1(p_output1, x);
  output2(p_output2, x);
  output3(p_output3, x);

}

}
}

#endif // MATLAB_MEX_FILE
