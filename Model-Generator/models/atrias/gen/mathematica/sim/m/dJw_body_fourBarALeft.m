function [x_dJw_body_fourBarALeft] = dJw_body_fourBarALeft(x)
%dJw_body_fourBarALeft
%    x_dJw_body_fourBarALeft = dJw_body_fourBarALeft(x)

% This function was generated by Mathematica Common 
% Subexpression Eliminating Package (CseOptimization)
% Thu 26 Jan 2017 21:34:14

t1=x(4);
t2=x(6);
t3=x(5);
t4=sin(t1);
t5=cos(t2);
t6=sin(t3);
t7=cos(t1);
t8=sin(t2);
t9=x(12);
t10=x(13);
t11=cos(t10);
t12=cos(t3);
t13=cos(t9);
t14=(-1).*t12.*t13.*t4;
t15=t4.*t5.*t6;
t16=t7.*t8;
t17=t15 + t16;
t18=sin(t9);
t19=t17.*t18;
t20=t14 + t19;
t21=t5.*t7;
t22=(-1).*t4.*t6.*t8;
t23=t21 + t22;
t24=sin(t10);
t25=x(15);
t26=sin(t25);
t27=x(20);
t28=x(22);
t29=x(21);
t30=x(28);
t31=(-1).*t5.*t6.*t7;
t32=t4.*t8;
t33=t31 + t32;
t34=x(29);
t35=cos(t25);
t36=t27.*t5.*t7;
t37=(-1).*t27.*t4.*t6.*t8;
t38=t12.*t29.*t7.*t8;
t39=t28.*t5.*t6.*t7;
t40=(-1).*t28.*t4.*t8;
t41=t36 + t37 + t38 + t39 + t40;
t42=(-1).*t12.*t13.*t27.*t4;
t43=(-1).*t13.*t29.*t6.*t7;
t44=t27.*t4.*t5.*t6;
t45=t27.*t7.*t8;
t46=(-1).*t12.*t29.*t5.*t7;
t47=t28.*t4.*t5;
t48=t28.*t6.*t7.*t8;
t49=t44 + t45 + t46 + t47 + t48;
t50=t18.*t49;
t51=t13.*t30.*t33;
t52=(-1).*t12.*t18.*t30.*t7;
t53=t42 + t43 + t50 + t51 + t52;
t54=t4.*t5;
t55=t6.*t7.*t8;
t56=t54 + t55;
t57=t12.*t13.*t7;
t58=t18.*t33;
t59=t57 + t58;
t60=x(31);
t61=(-1).*t12.*t13.*t7;
t62=t5.*t6.*t7;
t63=(-1).*t4.*t8;
t64=t62 + t63;
t65=t18.*t64;
t66=t61 + t65;
t67=(-1).*t4.*t5;
t68=(-1).*t6.*t7.*t8;
t69=t67 + t68;
t70=(-1).*t27.*t4.*t5;
t71=(-1).*t27.*t6.*t7.*t8;
t72=(-1).*t12.*t29.*t4.*t8;
t73=(-1).*t28.*t4.*t5.*t6;
t74=(-1).*t28.*t7.*t8;
t75=t70 + t71 + t72 + t73 + t74;
t76=(-1).*t12.*t13.*t27.*t7;
t77=t13.*t29.*t4.*t6;
t78=t27.*t5.*t6.*t7;
t79=(-1).*t27.*t4.*t8;
t80=t12.*t29.*t4.*t5;
t81=t28.*t5.*t7;
t82=(-1).*t28.*t4.*t6.*t8;
t83=t78 + t79 + t80 + t81 + t82;
t84=t18.*t83;
t85=t13.*t17.*t30;
t86=t12.*t18.*t30.*t4;
t87=t76 + t77 + t84 + t85 + t86;
t88=t11.*t23;
t89=t20.*t24;
t90=t88 + t89;
t91=t11.*t20;
t92=(-1).*t23.*t24;
t93=t91 + t92;
t94=t11.*t59;
t95=(-1).*t24.*t56;
t96=t94 + t95;
t97=t11.*t56;
t98=t24.*t59;
t99=t97 + t98;
t100=t11.*t75;
t101=t24.*t87;
t102=t11.*t20.*t34;
t103=(-1).*t23.*t24.*t34;
t104=t100 + t101 + t102 + t103;
t105=(-1).*t24.*t75;
t106=t11.*t87;
t107=(-1).*t11.*t23.*t34;
t108=(-1).*t20.*t24.*t34;
t109=t105 + t106 + t107 + t108;
t110=(-1).*t27.*t5.*t7;
t111=t27.*t4.*t6.*t8;
t112=(-1).*t12.*t29.*t7.*t8;
t113=(-1).*t28.*t5.*t6.*t7;
t114=t28.*t4.*t8;
t115=t110 + t111 + t112 + t113 + t114;
t116=t12.*t13.*t27.*t4;
t117=t13.*t29.*t6.*t7;
t118=(-1).*t27.*t4.*t5.*t6;
t119=(-1).*t27.*t7.*t8;
t120=t12.*t29.*t5.*t7;
t121=(-1).*t28.*t4.*t5;
t122=(-1).*t28.*t6.*t7.*t8;
t123=t118 + t119 + t120 + t121 + t122;
t124=t123.*t18;
t125=t13.*t30.*t64;
t126=t12.*t18.*t30.*t7;
t127=t116 + t117 + t124 + t125 + t126;
t128=t11.*t66;
t129=(-1).*t24.*t69;
t130=t128 + t129;
t131=t11.*t69;
t132=t24.*t66;
t133=t131 + t132;
t134=t35.*t93;
t135=(-1).*t26.*t90;
t136=t134 + t135;
t137=t11.*t115;
t138=t127.*t24;
t139=t11.*t34.*t66;
t140=(-1).*t24.*t34.*t69;
t141=t137 + t138 + t139 + t140;
t142=(-1).*t115.*t24;
t143=t11.*t127;
t144=(-1).*t11.*t34.*t69;
t145=(-1).*t24.*t34.*t66;
t146=t142 + t143 + t144 + t145;
t147=(-1).*t104.*t26;
t148=t109.*t35;
t149=(-1).*t35.*t60.*t90;
t150=(-1).*t26.*t60.*t93;
t151=t147 + t148 + t149 + t150;
t152=t12.*t18.*t27.*t7;
t153=(-1).*t18.*t29.*t4.*t6;
t154=t13.*t83;
t155=t12.*t13.*t30.*t4;
t156=(-1).*t17.*t18.*t30;
t157=t152 + t153 + t154 + t155 + t156;
t158=t35.*t90;
t159=t26.*t93;
t160=t158 + t159;
t161=t104.*t35;
t162=t109.*t26;
t163=t35.*t60.*t93;
t164=(-1).*t26.*t60.*t90;
t165=t161 + t162 + t163 + t164;
t166=t13.*t17;
t167=t12.*t18.*t4;
t168=t166 + t167;
t169=t11.*t41;
t170=t24.*t53;
t171=t11.*t34.*t59;
t172=(-1).*t24.*t34.*t56;
t173=t169 + t170 + t171 + t172;
t174=(-1).*t24.*t41;
t175=t11.*t53;
t176=(-1).*t11.*t34.*t56;
t177=(-1).*t24.*t34.*t59;
t178=t174 + t175 + t176 + t177;
t179=t12.*t13;
t180=(-1).*t18.*t5.*t6;
t181=t179 + t180;
t182=t12.*t13.*t29;
t183=(-1).*t18.*t29.*t5.*t6;
t184=(-1).*t12.*t18.*t28.*t8;
t185=t12.*t13.*t30.*t5;
t186=(-1).*t18.*t30.*t6;
t187=t182 + t183 + t184 + t185 + t186;
t188=t13.*t6;
t189=t12.*t18.*t5;
t190=t188 + t189;
t191=(-1).*t13.*t6.*t7;
t192=(-1).*t12.*t18.*t5.*t7;
t193=t191 + t192;
t194=(-1).*t173.*t26;
t195=t178.*t35;
t196=(-1).*t35.*t60.*t99;
t197=(-1).*t26.*t60.*t96;
t198=t194 + t195 + t196 + t197;
t199=t13.*t4.*t6;
t200=t12.*t18.*t4.*t5;
t201=t199 + t200;
t202=t35.*t96;
t203=(-1).*t26.*t99;
t204=t202 + t203;
t205=t13.*t27.*t4.*t6;
t206=t12.*t18.*t27.*t4.*t5;
t207=(-1).*t12.*t13.*t29.*t7;
t208=t18.*t29.*t5.*t6.*t7;
t209=t12.*t18.*t28.*t7.*t8;
t210=(-1).*t12.*t13.*t30.*t5.*t7;
t211=t18.*t30.*t6.*t7;
t212=t205 + t206 + t207 + t208 + t209 + t210 + t211;
t213=t11.*t193;
t214=(-1).*t12.*t24.*t7.*t8;
t215=t213 + t214;
t216=t11.*t12.*t7.*t8;
t217=t193.*t24;
t218=t216 + t217;
t219=t13.*t27.*t6.*t7;
t220=t12.*t18.*t27.*t5.*t7;
t221=t12.*t13.*t29.*t4;
t222=(-1).*t18.*t29.*t4.*t5.*t6;
t223=(-1).*t12.*t18.*t28.*t4.*t8;
t224=t12.*t13.*t30.*t4.*t5;
t225=(-1).*t18.*t30.*t4.*t6;
t226=t219 + t220 + t221 + t222 + t223 + t224 + t225;
t227=t11.*t201;
t228=t12.*t24.*t4.*t8;
t229=t227 + t228;
t230=(-1).*t11.*t12.*t4.*t8;
t231=t201.*t24;
t232=t230 + t231;
t233=t11.*t190;
t234=t12.*t24.*t8;
t235=t233 + t234;
t236=(-1).*t11.*t12.*t8;
t237=t190.*t24;
t238=t236 + t237;
t239=(-1).*t13.*t29.*t6;
t240=(-1).*t12.*t18.*t29.*t5;
t241=t18.*t28.*t6.*t8;
t242=(-1).*t13.*t30.*t5.*t6;
t243=(-1).*t12.*t18.*t30;
t244=t239 + t240 + t241 + t242 + t243;
t245=t11.*t181;
t246=(-1).*t24.*t6.*t8;
t247=t245 + t246;
t248=t11.*t6.*t8;
t249=t181.*t24;
t250=t248 + t249;
t251=t12.*t18.*t27.*t4;
t252=t18.*t29.*t6.*t7;
t253=t13.*t49;
t254=(-1).*t12.*t13.*t30.*t7;
t255=(-1).*t18.*t30.*t33;
t256=t251 + t252 + t253 + t254 + t255;
t257=t13.*t33;
t258=(-1).*t12.*t18.*t7;
t259=t257 + t258;
t260=(-1).*t11.*t12.*t27.*t4.*t8;
t261=(-1).*t11.*t29.*t6.*t7.*t8;
t262=t11.*t12.*t28.*t5.*t7;
t263=t212.*t24;
t264=t11.*t193.*t34;
t265=(-1).*t12.*t24.*t34.*t7.*t8;
t266=t260 + t261 + t262 + t263 + t264 + t265;
t267=t12.*t24.*t27.*t4.*t8;
t268=t24.*t29.*t6.*t7.*t8;
t269=(-1).*t12.*t24.*t28.*t5.*t7;
t270=t11.*t212;
t271=(-1).*t11.*t12.*t34.*t7.*t8;
t272=(-1).*t193.*t24.*t34;
t273=t267 + t268 + t269 + t270 + t271 + t272;
t274=(-1).*t11.*t12.*t27.*t7.*t8;
t275=t11.*t29.*t4.*t6.*t8;
t276=(-1).*t11.*t12.*t28.*t4.*t5;
t277=t226.*t24;
t278=t11.*t201.*t34;
t279=t12.*t24.*t34.*t4.*t8;
t280=t274 + t275 + t276 + t277 + t278 + t279;
t281=t12.*t24.*t27.*t7.*t8;
t282=(-1).*t24.*t29.*t4.*t6.*t8;
t283=t12.*t24.*t28.*t4.*t5;
t284=t11.*t226;
t285=t11.*t12.*t34.*t4.*t8;
t286=(-1).*t201.*t24.*t34;
t287=t281 + t282 + t283 + t284 + t285 + t286;
t288=t11.*t12.*t29.*t8;
t289=t11.*t28.*t5.*t6;
t290=t24.*t244;
t291=t11.*t181.*t34;
t292=(-1).*t24.*t34.*t6.*t8;
t293=t288 + t289 + t290 + t291 + t292;
t294=(-1).*t12.*t24.*t29.*t8;
t295=(-1).*t24.*t28.*t5.*t6;
t296=t11.*t244;
t297=(-1).*t11.*t34.*t6.*t8;
t298=(-1).*t181.*t24.*t34;
t299=t294 + t295 + t296 + t297 + t298;
t300=t35.*t99;
t301=t26.*t96;
t302=t300 + t301;
t303=t11.*t29.*t6.*t8;
t304=(-1).*t11.*t12.*t28.*t5;
t305=t187.*t24;
t306=t11.*t190.*t34;
t307=t12.*t24.*t34.*t8;
t308=t303 + t304 + t305 + t306 + t307;
t309=(-1).*t24.*t29.*t6.*t8;
t310=t12.*t24.*t28.*t5;
t311=t11.*t187;
t312=t11.*t12.*t34.*t8;
t313=(-1).*t190.*t24.*t34;
t314=t309 + t310 + t311 + t312 + t313;
t315=t173.*t35;
t316=t178.*t26;
t317=t35.*t60.*t96;
t318=(-1).*t26.*t60.*t99;
t319=t315 + t316 + t317 + t318;
t320=(-1).*t26.*t308;
t321=t314.*t35;
t322=(-1).*t238.*t35.*t60;
t323=(-1).*t235.*t26.*t60;
t324=t320 + t321 + t322 + t323;
t325=(-1).*t4.*t5.*t6;
t326=(-1).*t7.*t8;
t327=t325 + t326;
t328=t235.*t35;
t329=(-1).*t238.*t26;
t330=t328 + t329;
t331=(-1).*t11.*t12.*t18.*t8;
t332=t12.*t24.*t5;
t333=t331 + t332;
t334=(-1).*t11.*t12.*t5;
t335=(-1).*t12.*t18.*t24.*t8;
t336=t334 + t335;
t337=t11.*t18.*t56;
t338=(-1).*t24.*t64;
t339=t337 + t338;
t340=t11.*t64;
t341=t18.*t24.*t56;
t342=t340 + t341;
t343=(-1).*t27.*t5.*t6.*t7;
t344=t27.*t4.*t8;
t345=(-1).*t12.*t29.*t4.*t5;
t346=(-1).*t28.*t5.*t7;
t347=t28.*t4.*t6.*t8;
t348=t343 + t344 + t345 + t346 + t347;
t349=t11.*t18.*t23;
t350=(-1).*t24.*t327;
t351=t349 + t350;
t352=t11.*t327;
t353=t18.*t23.*t24;
t354=t352 + t353;
t355=(-1).*t13.*t29.*t5.*t6;
t356=(-1).*t12.*t18.*t29;
t357=(-1).*t12.*t13.*t28.*t8;
t358=(-1).*t13.*t30.*t6;
t359=(-1).*t12.*t18.*t30.*t5;
t360=t355 + t356 + t357 + t358 + t359;
t361=t12.*t13.*t5;
t362=(-1).*t18.*t6;
t363=t361 + t362;
t364=t11.*t29.*t5.*t6;
t365=t18.*t24.*t29.*t6.*t8;
t366=t11.*t12.*t28.*t8;
t367=(-1).*t12.*t18.*t24.*t28.*t5;
t368=(-1).*t12.*t13.*t24.*t30.*t8;
t369=(-1).*t11.*t12.*t18.*t34.*t8;
t370=t12.*t24.*t34.*t5;
t371=t364 + t365 + t366 + t367 + t368 + t369 + t370;
t372=t11.*t18.*t29.*t6.*t8;
t373=(-1).*t24.*t29.*t5.*t6;
t374=(-1).*t11.*t12.*t18.*t28.*t5;
t375=(-1).*t12.*t24.*t28.*t8;
t376=(-1).*t11.*t12.*t13.*t30.*t8;
t377=t11.*t12.*t34.*t5;
t378=t12.*t18.*t24.*t34.*t8;
t379=t372 + t373 + t374 + t375 + t376 + t377 + t378;
t380=t18.*t24.*t75;
t381=t11.*t348;
t382=t13.*t23.*t24.*t30;
t383=t11.*t18.*t23.*t34;
t384=(-1).*t24.*t327.*t34;
t385=t380 + t381 + t382 + t383 + t384;
t386=t11.*t18.*t75;
t387=(-1).*t24.*t348;
t388=t11.*t13.*t23.*t30;
t389=(-1).*t11.*t327.*t34;
t390=(-1).*t18.*t23.*t24.*t34;
t391=t386 + t387 + t388 + t389 + t390;
t392=t18.*t24.*t41;
t393=t11.*t123;
t394=t13.*t24.*t30.*t56;
t395=t11.*t18.*t34.*t56;
t396=(-1).*t24.*t34.*t64;
t397=t392 + t393 + t394 + t395 + t396;
t398=t11.*t18.*t41;
t399=(-1).*t123.*t24;
t400=t11.*t13.*t30.*t56;
t401=(-1).*t11.*t34.*t64;
t402=(-1).*t18.*t24.*t34.*t56;
t403=t398 + t399 + t400 + t401 + t402;
t404=t238.*t35;
t405=t235.*t26;
t406=t404 + t405;
t407=t308.*t35;
t408=t26.*t314;
t409=t235.*t35.*t60;
t410=(-1).*t238.*t26.*t60;
t411=t407 + t408 + t409 + t410;
t412=t11.*t12.*t8;
t413=(-1).*t190.*t24;
t414=t412 + t413;
t415=(-1).*t11.*t56;
t416=(-1).*t24.*t59;
t417=t415 + t416;
t418=(-1).*t11.*t23;
t419=(-1).*t20.*t24;
t420=t418 + t419;
t421=(-1).*t11.*t29.*t6.*t8;
t422=t11.*t12.*t28.*t5;
t423=(-1).*t187.*t24;
t424=(-1).*t11.*t190.*t34;
t425=(-1).*t12.*t24.*t34.*t8;
t426=t421 + t422 + t423 + t424 + t425;
t427=(-1).*t11.*t75;
t428=(-1).*t24.*t87;
t429=(-1).*t11.*t20.*t34;
t430=t23.*t24.*t34;
t431=t427 + t428 + t429 + t430;
t432=(-1).*t11.*t41;
t433=(-1).*t24.*t53;
t434=(-1).*t11.*t34.*t59;
t435=t24.*t34.*t56;
t436=t432 + t433 + t434 + t435;
t437=(-1).*t235.*t26;
t438=(-1).*t26.*t93;
t439=(-1).*t26.*t96;
t440=(-1).*t26.*t314;
t441=(-1).*t235.*t35.*t60;
t442=(-1).*t109.*t26;
t443=(-1).*t35.*t60.*t93;
t444=(-1).*t178.*t26;
t445=(-1).*t35.*t60.*t96;
x_dJw_body_fourBarALeft=[0,0,0,0,0,0,0,0,0,t160.*t198 + t165.*t204 + t151.*(t130.*t26 +  ...
  t133.*t35) + t136.*(t146.*t26 + t141.*t35 + (-1).*t133.*t26.*t60 + ...
   t130.*t35.*t60),t136.*t256 + t151.*t259 + t157.*((-1).*t133.*t26  ...
  + t130.*t35) + t168.*((-1).*t141.*t26 + t146.*t35 + (-1).*t130.* ...
  t26.*t60 + (-1).*t133.*t35.*t60),t157.*t302 + t168.*t319 + t165.*( ...
  t13.*t64 + t12.*t18.*t7) + t160.*(t123.*t13 + (-1).*t12.*t18.* ...
  t27.*t4 + (-1).*t18.*t30.*t64 + t12.*t13.*t30.*t7 + (-1).*t18.* ...
  t29.*t6.*t7),t198.*(t215.*t26 + t218.*t35) + t151.*(t229.*t26 +  ...
  t232.*t35) + t324.*(t247.*t26 + t250.*t35) + t204.*(t26.*t273 +  ...
  t266.*t35 + (-1).*t218.*t26.*t60 + t215.*t35.*t60) + t136.*(t26.* ...
  t287 + t280.*t35 + (-1).*t232.*t26.*t60 + t229.*t35.*t60) + t330.* ...
  (t26.*t299 + t293.*t35 + (-1).*t250.*t26.*t60 + t247.*t35.*t60), ...
  t256.*((-1).*t218.*t26 + t215.*t35) + t157.*((-1).*t232.*t26 +  ...
  t229.*t35) + ((-1).*t250.*t26 + t247.*t35).*t360 + t259.*((-1).* ...
  t26.*t266 + t273.*t35 + (-1).*t215.*t26.*t60 + (-1).*t218.*t35.* ...
  t60) + t168.*((-1).*t26.*t280 + t287.*t35 + (-1).*t229.*t26.*t60 + ...
   (-1).*t232.*t35.*t60) + t363.*((-1).*t26.*t293 + t299.*t35 + (-1) ...
  .*t247.*t26.*t60 + (-1).*t250.*t35.*t60),t165.*(t12.*t13.*t4.*t5 + ...
   (-1).*t18.*t4.*t6) + t411.*((-1).*t12.*t18 + (-1).*t13.*t5.*t6) + ...
   t319.*((-1).*t12.*t13.*t5.*t7 + t18.*t6.*t7) + t160.*((-1).*t12.* ...
  t18.*t29.*t4 + (-1).*t12.*t18.*t30.*t4.*t5 + (-1).*t13.*t30.*t4.* ...
  t6 + (-1).*t13.*t29.*t4.*t5.*t6 + t12.*t13.*t27.*t5.*t7 + (-1).* ...
  t18.*t27.*t6.*t7 + (-1).*t12.*t13.*t28.*t4.*t8) + t406.*((-1).* ...
  t12.*t13.*t30 + (-1).*t12.*t13.*t29.*t5 + t18.*t29.*t6 + t18.* ...
  t30.*t5.*t6 + t13.*t28.*t6.*t8) + t302.*(t12.*t13.*t27.*t4.*t5 + ( ...
  -1).*t18.*t27.*t4.*t6 + t12.*t18.*t29.*t7 + t12.*t18.*t30.*t5.*t7  ...
  + t13.*t30.*t6.*t7 + t13.*t29.*t5.*t6.*t7 + t12.*t13.*t28.*t7.*t8) ...
  ,t324.*(t26.*t333 + t336.*t35) + t198.*(t26.*t339 + t342.*t35) +  ...
  t151.*(t26.*t351 + t35.*t354) + t330.*(t35.*t371 + t26.*t379 + ( ...
  -1).*t26.*t336.*t60 + t333.*t35.*t60) + t204.*(t35.*t397 + t26.* ...
  t403 + (-1).*t26.*t342.*t60 + t339.*t35.*t60) + t136.*(t35.*t385 + ...
   t26.*t391 + t35.*t351.*t60 + (-1).*t26.*t354.*t60),t256.*((-1).* ...
  t26.*t342 + t339.*t35) + t157.*(t35.*t351 + (-1).*t26.*t354) + (( ...
  -1).*t26.*t336 + t333.*t35).*t360 + t363.*((-1).*t26.*t371 + t35.* ...
  t379 + (-1).*t26.*t333.*t60 + (-1).*t336.*t35.*t60) + t259.*((-1) ...
  .*t26.*t397 + t35.*t403 + (-1).*t26.*t339.*t60 + (-1).*t342.*t35.* ...
  t60) + t168.*((-1).*t26.*t385 + t35.*t391 + (-1).*t26.*t351.*t60 + ...
   (-1).*t35.*t354.*t60),t13.*t165.*t23 + (-1).*t160.*t18.*t23.*t30  ...
  + t13.*t302.*t41 + (-1).*t12.*t13.*t28.*t406.*t5 + (-1).*t18.* ...
  t30.*t302.*t56 + t13.*t319.*t56 + t13.*t160.*t75 + t12.*t18.*t30.* ...
  t406.*t8 + (-1).*t12.*t13.*t411.*t8 + t13.*t29.*t406.*t6.*t8,0,0, ...
  0,0,0,0,0,0,0,0,0,0,0,0,0,t151.*(t11.*t168.*t26 + t168.*t24.*t35)  ...
  + t198.*(t11.*t259.*t26 + t24.*t259.*t35) + t324.*(t11.*t26.*t363  ...
  + t24.*t35.*t363) + t136.*(t11.*t157.*t26 + (-1).*t168.*t24.*t26.* ...
  t34 + t157.*t24.*t35 + t11.*t168.*t34.*t35 + (-1).*t168.*t24.* ...
  t26.*t60 + t11.*t168.*t35.*t60) + t204.*(t11.*t256.*t26 + (-1).* ...
  t24.*t259.*t26.*t34 + t24.*t256.*t35 + t11.*t259.*t34.*t35 + (-1) ...
  .*t24.*t259.*t26.*t60 + t11.*t259.*t35.*t60) + t330.*(t11.*t26.* ...
  t360 + t24.*t35.*t360 + (-1).*t24.*t26.*t34.*t363 + t11.*t34.* ...
  t35.*t363 + (-1).*t24.*t26.*t363.*t60 + t11.*t35.*t363.*t60), ...
  t157.*((-1).*t168.*t24.*t26 + t11.*t168.*t35) + t256.*((-1).*t24.* ...
  t259.*t26 + t11.*t259.*t35) + t360.*((-1).*t24.*t26.*t363 + t11.* ...
  t35.*t363) + t168.*((-1).*t157.*t24.*t26 + (-1).*t11.*t168.*t26.* ...
  t34 + t11.*t157.*t35 + (-1).*t168.*t24.*t34.*t35 + (-1).*t11.* ...
  t168.*t26.*t60 + (-1).*t168.*t24.*t35.*t60) + t259.*((-1).*t24.* ...
  t256.*t26 + (-1).*t11.*t259.*t26.*t34 + t11.*t256.*t35 + (-1).* ...
  t24.*t259.*t34.*t35 + (-1).*t11.*t259.*t26.*t60 + (-1).*t24.* ...
  t259.*t35.*t60) + t363.*((-1).*t24.*t26.*t360 + t11.*t35.*t360 + ( ...
  -1).*t11.*t26.*t34.*t363 + (-1).*t24.*t34.*t35.*t363 + (-1).*t11.* ...
  t26.*t363.*t60 + (-1).*t24.*t35.*t363.*t60),t165.*((-1).*t17.*t18  ...
  + t12.*t13.*t4) + t302.*(t116 + t117 + t126 + (-1).*t13.*t30.*t33  ...
  + (-1).*t18.*t49) + t411.*((-1).*t12.*t18.*t5 + (-1).*t13.*t6) +  ...
  t319.*((-1).*t18.*t33 + t61) + t406.*((-1).*t12.*t13.*t29 + (-1).* ...
  t12.*t13.*t30.*t5 + t18.*t30.*t6 + t18.*t29.*t5.*t6 + t12.*t18.* ...
  t28.*t8) + t160.*((-1).*t13.*t17.*t30 + (-1).*t12.*t18.*t30.*t4 +  ...
  (-1).*t13.*t29.*t4.*t6 + t12.*t13.*t27.*t7 + (-1).*t18.*t83), ...
  t324.*(t328 + t26.*t414) + t198.*(t202 + t26.*t417) + t151.*(t134  ...
  + t26.*t420) + t330.*(t321 + t323 + t26.*t426 + t35.*t414.*t60) +  ...
  t204.*(t195 + t197 + t26.*t436 + t35.*t417.*t60) + t136.*(t148 +  ...
  t150 + t26.*t431 + t35.*t420.*t60),t360.*(t35.*t414 + t437) +  ...
  t157.*(t35.*t420 + t438) + t256.*(t35.*t417 + t439) + t363.*(t35.* ...
  t426 + t440 + t441 + (-1).*t26.*t414.*t60) + t259.*(t35.*t436 +  ...
  t444 + t445 + (-1).*t26.*t417.*t60) + t168.*(t35.*t431 + t442 +  ...
  t443 + (-1).*t26.*t420.*t60),0,0,0,0,2.*t136.*t151 + 2.*t198.* ...
  t204 + 2.*t324.*t330,t360.*((-1).*t238.*t35 + t437) + t363.*((-1) ...
  .*t308.*t35 + t440 + t441 + t238.*t26.*t60) + t157.*(t438 + (-1).* ...
  t35.*t90) + t168.*((-1).*t104.*t35 + t442 + t443 + t26.*t60.*t90)  ...
  + t256.*(t439 + (-1).*t35.*t99) + t259.*((-1).*t173.*t35 + t444 +  ...
  t445 + t26.*t60.*t99),0,0,0,0];

end %function