function [x_dJw_world_qALeft] = dJw_world_qALeft(x)
%dJw_world_qALeft
%    x_dJw_world_qALeft = dJw_world_qALeft(x)

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
t10=x(13);
t11=cos(t10);
t12=cos(t3);
t13=cos(t5);
t14=sin(t5);
t15=sin(t10);
t16=(-1).*t12.*t13.*t7;
t17=t6.*t7.*t8;
t18=t2.*t9;
t19=t17 + t18;
t20=t14.*t19;
t21=t16 + t20;
t22=t2.*t6;
t23=(-1).*t7.*t8.*t9;
t24=t22 + t23;
t25=x(21);
t26=x(28);
t27=(-1).*t12.*t13.*t2;
t28=t2.*t6.*t8;
t29=(-1).*t7.*t9;
t30=t28 + t29;
t31=t14.*t30;
t32=t27 + t31;
t33=(-1).*t6.*t7;
t34=(-1).*t2.*t8.*t9;
t35=t33 + t34;
t36=(-1).*t2.*t6.*t8;
t37=t7.*t9;
t38=t36 + t37;
t39=t11.*t21;
t40=(-1).*t15.*t24;
t41=t39 + t40;
t42=x(22);
t43=x(29);
t44=t11.*t24;
t45=t15.*t21;
t46=t44 + t45;
t47=t13.*t19;
t48=t12.*t14.*t7;
t49=t47 + t48;
t50=t6.*t7;
t51=t2.*t8.*t9;
t52=t50 + t51;
t53=t12.*t13.*t2;
t54=t14.*t38;
t55=t53 + t54;
t56=t12.*t13.*t25;
t57=(-1).*t14.*t25.*t6.*t8;
t58=(-1).*t12.*t14.*t42.*t9;
t59=t12.*t13.*t26.*t6;
t60=(-1).*t14.*t26.*t8;
t61=t56 + t57 + t58 + t59 + t60;
t62=t13.*t8;
t63=t12.*t14.*t6;
t64=t62 + t63;
t65=t11.*t52;
t66=t15.*t55;
t67=t65 + t66;
t68=x(20);
t69=t13.*t30;
t70=t12.*t14.*t2;
t71=t69 + t70;
t72=t2.*t6.*t68.*t8;
t73=(-1).*t68.*t7.*t9;
t74=t12.*t25.*t6.*t7;
t75=t2.*t42.*t6;
t76=(-1).*t42.*t7.*t8.*t9;
t77=t72 + t73 + t74 + t75 + t76;
t78=t11.*t32;
t79=(-1).*t15.*t35;
t80=t78 + t79;
t81=t12.*t14.*t2.*t68;
t82=(-1).*t14.*t25.*t7.*t8;
t83=t13.*t77;
t84=t12.*t13.*t26.*t7;
t85=(-1).*t14.*t19.*t26;
t86=t81 + t82 + t83 + t84 + t85;
t87=t6.*t68.*t7.*t8;
t88=t2.*t68.*t9;
t89=(-1).*t12.*t2.*t25.*t6;
t90=t42.*t6.*t7;
t91=t2.*t42.*t8.*t9;
t92=t87 + t88 + t89 + t90 + t91;
t93=t13.*t38;
t94=(-1).*t12.*t14.*t2;
t95=t93 + t94;
t96=(-1).*t6.*t68.*t7;
t97=(-1).*t2.*t68.*t8.*t9;
t98=(-1).*t12.*t25.*t7.*t9;
t99=(-1).*t42.*t6.*t7.*t8;
t100=(-1).*t2.*t42.*t9;
t101=t100 + t96 + t97 + t98 + t99;
t102=(-1).*t12.*t13.*t2.*t68;
t103=t13.*t25.*t7.*t8;
t104=t14.*t77;
t105=t13.*t19.*t26;
t106=t12.*t14.*t26.*t7;
t107=t102 + t103 + t104 + t105 + t106;
t108=(-1).*t6.*t68.*t7.*t8;
t109=(-1).*t2.*t68.*t9;
t110=t12.*t2.*t25.*t6;
t111=(-1).*t42.*t6.*t7;
t112=(-1).*t2.*t42.*t8.*t9;
t113=t108 + t109 + t110 + t111 + t112;
t114=(-1).*t2.*t6.*t68;
t115=t68.*t7.*t8.*t9;
t116=(-1).*t12.*t2.*t25.*t9;
t117=(-1).*t2.*t42.*t6.*t8;
t118=t42.*t7.*t9;
t119=t114 + t115 + t116 + t117 + t118;
t120=t12.*t13.*t68.*t7;
t121=t13.*t2.*t25.*t8;
t122=t113.*t14;
t123=t13.*t26.*t30;
t124=t12.*t14.*t2.*t26;
t125=t120 + t121 + t122 + t123 + t124;
t126=t11.*t55;
t127=(-1).*t15.*t52;
t128=t126 + t127;
t129=t101.*t11;
t130=t107.*t15;
t131=t11.*t21.*t43;
t132=(-1).*t15.*t24.*t43;
t133=t129 + t130 + t131 + t132;
t134=t11.*t35;
t135=t15.*t32;
t136=t134 + t135;
t137=(-1).*t101.*t15;
t138=t107.*t11;
t139=(-1).*t11.*t24.*t43;
t140=(-1).*t15.*t21.*t43;
t141=t137 + t138 + t139 + t140;
t142=t2.*t6.*t68;
t143=(-1).*t68.*t7.*t8.*t9;
t144=t12.*t2.*t25.*t9;
t145=t2.*t42.*t6.*t8;
t146=(-1).*t42.*t7.*t9;
t147=t142 + t143 + t144 + t145 + t146;
t148=(-1).*t12.*t13.*t68.*t7;
t149=(-1).*t13.*t2.*t25.*t8;
t150=t14.*t92;
t151=t13.*t26.*t38;
t152=(-1).*t12.*t14.*t2.*t26;
t153=t148 + t149 + t150 + t151 + t152;
t154=t128.*t46;
t155=t136.*t41;
t156=t154 + t155;
t157=t49.*t80;
t158=t41.*t95;
t159=t157 + t158;
t160=t46.*t71;
t161=t49.*t67;
t162=t160 + t161;
t163=t67.*t86;
t164=(-1).*t12.*t14.*t68.*t7;
t165=(-1).*t14.*t2.*t25.*t8;
t166=t113.*t13;
t167=t12.*t13.*t2.*t26;
t168=(-1).*t14.*t26.*t30;
t169=t164 + t165 + t166 + t167 + t168;
t170=t169.*t46;
t171=t11.*t147;
t172=t15.*t153;
t173=t11.*t43.*t55;
t174=(-1).*t15.*t43.*t52;
t175=t171 + t172 + t173 + t174;
t176=t175.*t49;
t177=t133.*t71;
t178=t163 + t170 + t176 + t177;
t179=t80.*t86;
t180=t12.*t14.*t68.*t7;
t181=t14.*t2.*t25.*t8;
t182=t13.*t92;
t183=(-1).*t12.*t13.*t2.*t26;
t184=(-1).*t14.*t26.*t38;
t185=t180 + t181 + t182 + t183 + t184;
t186=t185.*t41;
t187=t141.*t95;
t188=(-1).*t119.*t15;
t189=t11.*t125;
t190=(-1).*t11.*t35.*t43;
t191=(-1).*t15.*t32.*t43;
t192=t188 + t189 + t190 + t191;
t193=t192.*t49;
t194=t179 + t186 + t187 + t193;
t195=t11.*t119;
t196=t125.*t15;
t197=t11.*t32.*t43;
t198=(-1).*t15.*t35.*t43;
t199=t195 + t196 + t197 + t198;
t200=t199.*t41;
t201=t128.*t133;
t202=t136.*t141;
t203=(-1).*t147.*t15;
t204=t11.*t153;
t205=(-1).*t11.*t43.*t52;
t206=(-1).*t15.*t43.*t55;
t207=t203 + t204 + t205 + t206;
t208=t207.*t46;
t209=t200 + t201 + t202 + t208;
t210=t11.*t64;
t211=t12.*t15.*t9;
t212=t210 + t211;
t213=(-1).*t13.*t25.*t6.*t8;
t214=(-1).*t12.*t14.*t25;
t215=(-1).*t12.*t13.*t42.*t9;
t216=(-1).*t13.*t26.*t8;
t217=(-1).*t12.*t14.*t26.*t6;
t218=t213 + t214 + t215 + t216 + t217;
t219=(-1).*t13.*t2.*t8;
t220=(-1).*t12.*t14.*t2.*t6;
t221=t219 + t220;
t222=t13.*t7.*t8;
t223=t12.*t14.*t6.*t7;
t224=t222 + t223;
t225=t12.*t13.*t6;
t226=(-1).*t14.*t8;
t227=t225 + t226;
t228=t12.*t13;
t229=(-1).*t14.*t6.*t8;
t230=t228 + t229;
t231=t11.*t25.*t8.*t9;
t232=(-1).*t11.*t12.*t42.*t6;
t233=t15.*t61;
t234=t11.*t43.*t64;
t235=t12.*t15.*t43.*t9;
t236=t231 + t232 + t233 + t234 + t235;
t237=(-1).*t11.*t12.*t9;
t238=t15.*t64;
t239=t237 + t238;
t240=(-1).*t15.*t25.*t8.*t9;
t241=t12.*t15.*t42.*t6;
t242=t11.*t61;
t243=t11.*t12.*t43.*t9;
t244=(-1).*t15.*t43.*t64;
t245=t240 + t241 + t242 + t243 + t244;
t246=(-1).*t13.*t6.*t8;
t247=(-1).*t12.*t14;
t248=t246 + t247;
t249=(-1).*t12.*t13.*t2.*t6;
t250=t14.*t2.*t8;
t251=t249 + t250;
t252=t12.*t13.*t6.*t7;
t253=(-1).*t14.*t7.*t8;
t254=t252 + t253;
t255=t11.*t230;
t256=(-1).*t15.*t8.*t9;
t257=t255 + t256;
t258=t11.*t224;
t259=t12.*t15.*t7.*t9;
t260=t258 + t259;
t261=t11.*t221;
t262=(-1).*t12.*t15.*t2.*t9;
t263=t261 + t262;
t264=t13.*t68.*t7.*t8;
t265=t12.*t14.*t6.*t68.*t7;
t266=(-1).*t12.*t13.*t2.*t25;
t267=t14.*t2.*t25.*t6.*t8;
t268=t12.*t14.*t2.*t42.*t9;
t269=(-1).*t12.*t13.*t2.*t26.*t6;
t270=t14.*t2.*t26.*t8;
t271=t264 + t265 + t266 + t267 + t268 + t269 + t270;
t272=t13.*t2.*t68.*t8;
t273=t12.*t14.*t2.*t6.*t68;
t274=t12.*t13.*t25.*t7;
t275=(-1).*t14.*t25.*t6.*t7.*t8;
t276=(-1).*t12.*t14.*t42.*t7.*t9;
t277=t12.*t13.*t26.*t6.*t7;
t278=(-1).*t14.*t26.*t7.*t8;
t279=t272 + t273 + t274 + t275 + t276 + t277 + t278;
t280=(-1).*t13.*t25.*t8;
t281=(-1).*t12.*t14.*t25.*t6;
t282=t14.*t42.*t8.*t9;
t283=(-1).*t13.*t26.*t6.*t8;
t284=(-1).*t12.*t14.*t26;
t285=t280 + t281 + t282 + t283 + t284;
t286=t11.*t8.*t9;
t287=t15.*t230;
t288=t286 + t287;
t289=(-1).*t11.*t12.*t7.*t9;
t290=t15.*t224;
t291=t289 + t290;
t292=t11.*t12.*t2.*t9;
t293=t15.*t221;
t294=t292 + t293;
t295=t128.*t294;
t296=t291.*t41;
t297=t212.*t288;
t298=t295 + t296 + t297;
t299=t263.*t95;
t300=t260.*t49;
t301=t227.*t257;
t302=t299 + t300 + t301;
t303=t239.*t248;
t304=t254.*t46;
t305=t251.*t67;
t306=t303 + t304 + t305;
t307=t12.*t13.*t6.*t68.*t7;
t308=(-1).*t14.*t68.*t7.*t8;
t309=t13.*t2.*t25.*t6.*t8;
t310=t12.*t14.*t2.*t25;
t311=t12.*t13.*t2.*t42.*t9;
t312=t13.*t2.*t26.*t8;
t313=t12.*t14.*t2.*t26.*t6;
t314=t307 + t308 + t309 + t310 + t311 + t312 + t313;
t315=t314.*t67;
t316=t12.*t13.*t2.*t6.*t68;
t317=(-1).*t14.*t2.*t68.*t8;
t318=(-1).*t13.*t25.*t6.*t7.*t8;
t319=(-1).*t12.*t14.*t25.*t7;
t320=(-1).*t12.*t13.*t42.*t7.*t9;
t321=(-1).*t13.*t26.*t7.*t8;
t322=(-1).*t12.*t14.*t26.*t6.*t7;
t323=t316 + t317 + t318 + t319 + t320 + t321 + t322;
t324=t323.*t46;
t325=(-1).*t12.*t13.*t25.*t6;
t326=t14.*t25.*t8;
t327=t13.*t42.*t8.*t9;
t328=(-1).*t12.*t13.*t26;
t329=t14.*t26.*t6.*t8;
t330=t325 + t326 + t327 + t328 + t329;
t331=t239.*t330;
t332=t236.*t248;
t333=t175.*t251;
t334=t133.*t254;
t335=t315 + t324 + t331 + t332 + t333 + t334;
t336=t218.*t257;
t337=t260.*t86;
t338=t185.*t263;
t339=t12.*t15.*t68.*t7.*t9;
t340=t15.*t2.*t25.*t8.*t9;
t341=(-1).*t12.*t15.*t2.*t42.*t6;
t342=t11.*t271;
t343=(-1).*t11.*t12.*t2.*t43.*t9;
t344=(-1).*t15.*t221.*t43;
t345=t339 + t340 + t341 + t342 + t343 + t344;
t346=t345.*t95;
t347=t12.*t15.*t2.*t68.*t9;
t348=(-1).*t15.*t25.*t7.*t8.*t9;
t349=t12.*t15.*t42.*t6.*t7;
t350=t11.*t279;
t351=t11.*t12.*t43.*t7.*t9;
t352=(-1).*t15.*t224.*t43;
t353=t347 + t348 + t349 + t350 + t351 + t352;
t354=t353.*t49;
t355=(-1).*t12.*t15.*t25.*t9;
t356=(-1).*t15.*t42.*t6.*t8;
t357=t11.*t285;
t358=(-1).*t11.*t43.*t8.*t9;
t359=(-1).*t15.*t230.*t43;
t360=t355 + t356 + t357 + t358 + t359;
t361=t227.*t360;
t362=t336 + t337 + t338 + t346 + t354 + t361;
t363=(-1).*t11.*t12.*t68.*t7.*t9;
t364=(-1).*t11.*t2.*t25.*t8.*t9;
t365=t11.*t12.*t2.*t42.*t6;
t366=t15.*t271;
t367=t11.*t221.*t43;
t368=(-1).*t12.*t15.*t2.*t43.*t9;
t369=t363 + t364 + t365 + t366 + t367 + t368;
t370=t128.*t369;
t371=(-1).*t11.*t12.*t2.*t68.*t9;
t372=t11.*t25.*t7.*t8.*t9;
t373=(-1).*t11.*t12.*t42.*t6.*t7;
t374=t15.*t279;
t375=t11.*t224.*t43;
t376=t12.*t15.*t43.*t7.*t9;
t377=t371 + t372 + t373 + t374 + t375 + t376;
t378=t377.*t41;
t379=t11.*t12.*t25.*t9;
t380=t11.*t42.*t6.*t8;
t381=t15.*t285;
t382=t11.*t230.*t43;
t383=(-1).*t15.*t43.*t8.*t9;
t384=t379 + t380 + t381 + t382 + t383;
t385=t212.*t384;
t386=t245.*t288;
t387=t141.*t291;
t388=t207.*t294;
t389=t370 + t378 + t385 + t386 + t387 + t388;
t390=(-1).*t6.*t7.*t8;
t391=(-1).*t2.*t9;
t392=t390 + t391;
t393=(-1).*t11.*t12.*t14.*t9;
t394=t12.*t15.*t6;
t395=t393 + t394;
t396=t11.*t14.*t24;
t397=(-1).*t15.*t392;
t398=t396 + t397;
t399=t11.*t14.*t52;
t400=(-1).*t15.*t30;
t401=t399 + t400;
t402=(-1).*t2.*t6.*t68.*t8;
t403=t68.*t7.*t9;
t404=(-1).*t12.*t25.*t6.*t7;
t405=(-1).*t2.*t42.*t6;
t406=t42.*t7.*t8.*t9;
t407=t402 + t403 + t404 + t405 + t406;
t408=(-1).*t11.*t12.*t6;
t409=(-1).*t12.*t14.*t15.*t9;
t410=t408 + t409;
t411=t11.*t392;
t412=t14.*t15.*t24;
t413=t411 + t412;
t414=t11.*t30;
t415=t14.*t15.*t52;
t416=t414 + t415;
t417=t212.*t410;
t418=t128.*t416;
t419=t41.*t413;
t420=t417 + t418 + t419;
t421=t227.*t395;
t422=t398.*t49;
t423=t401.*t95;
t424=t421 + t422 + t423;
t425=(-1).*t12.*t13.*t239.*t9;
t426=t13.*t24.*t46;
t427=t13.*t52.*t67;
t428=t425 + t426 + t427;
t429=t13.*t239.*t25.*t8.*t9;
t430=(-1).*t12.*t13.*t239.*t42.*t6;
t431=t101.*t13.*t46;
t432=t13.*t147.*t67;
t433=t12.*t14.*t239.*t26.*t9;
t434=(-1).*t14.*t24.*t26.*t46;
t435=(-1).*t14.*t26.*t52.*t67;
t436=(-1).*t12.*t13.*t236.*t9;
t437=t13.*t175.*t52;
t438=t13.*t133.*t24;
t439=t429 + t430 + t431 + t432 + t433 + t434 + t435 + t436 + t437 +  ...
  t438;
t440=t218.*t395;
t441=t398.*t86;
t442=t185.*t401;
t443=t11.*t14.*t25.*t8.*t9;
t444=(-1).*t15.*t25.*t6.*t8;
t445=(-1).*t11.*t12.*t14.*t42.*t6;
t446=(-1).*t12.*t15.*t42.*t9;
t447=(-1).*t11.*t12.*t13.*t26.*t9;
t448=t11.*t12.*t43.*t6;
t449=t12.*t14.*t15.*t43.*t9;
t450=t443 + t444 + t445 + t446 + t447 + t448 + t449;
t451=t227.*t450;
t452=t11.*t14.*t147;
t453=(-1).*t113.*t15;
t454=t11.*t13.*t26.*t52;
t455=(-1).*t11.*t30.*t43;
t456=(-1).*t14.*t15.*t43.*t52;
t457=t452 + t453 + t454 + t455 + t456;
t458=t457.*t95;
t459=t101.*t11.*t14;
t460=(-1).*t15.*t407;
t461=t11.*t13.*t24.*t26;
t462=(-1).*t11.*t392.*t43;
t463=(-1).*t14.*t15.*t24.*t43;
t464=t459 + t460 + t461 + t462 + t463;
t465=t464.*t49;
t466=t440 + t441 + t442 + t451 + t458 + t465;
t467=t11.*t25.*t6.*t8;
t468=t14.*t15.*t25.*t8.*t9;
t469=t11.*t12.*t42.*t9;
t470=(-1).*t12.*t14.*t15.*t42.*t6;
t471=(-1).*t12.*t13.*t15.*t26.*t9;
t472=(-1).*t11.*t12.*t14.*t43.*t9;
t473=t12.*t15.*t43.*t6;
t474=t467 + t468 + t469 + t470 + t471 + t472 + t473;
t475=t212.*t474;
t476=t101.*t14.*t15;
t477=t11.*t407;
t478=t13.*t15.*t24.*t26;
t479=t11.*t14.*t24.*t43;
t480=(-1).*t15.*t392.*t43;
t481=t476 + t477 + t478 + t479 + t480;
t482=t41.*t481;
t483=t14.*t147.*t15;
t484=t11.*t113;
t485=t13.*t15.*t26.*t52;
t486=t11.*t14.*t43.*t52;
t487=(-1).*t15.*t30.*t43;
t488=t483 + t484 + t485 + t486 + t487;
t489=t128.*t488;
t490=t245.*t410;
t491=t141.*t413;
t492=t207.*t416;
t493=t475 + t482 + t489 + t490 + t491 + t492;
t494=t95.^2;
t495=t49.^2;
t496=t227.^2;
t497=(-1).*t13.*t8;
t498=(-1).*t12.*t14.*t6;
t499=t497 + t498;
t500=(-1).*t14.*t38;
t501=t27 + t500;
t502=t12.*t13.*t7;
t503=(-1).*t14.*t19;
t504=t502 + t503;
t505=t15.*t212.*t227;
t506=t128.*t15.*t95;
t507=t15.*t41.*t49;
t508=t505 + t506 + t507;
t509=t11.*t494;
t510=t11.*t495;
t511=t11.*t496;
t512=t509 + t510 + t511;
t513=2.*t11.*t218.*t227;
t514=2.*t11.*t49.*t86;
t515=2.*t11.*t185.*t95;
t516=(-1).*t15.*t43.*t494;
t517=(-1).*t15.*t43.*t495;
t518=(-1).*t15.*t43.*t496;
t519=t513 + t514 + t515 + t516 + t517 + t518;
t520=t239.*t499;
t521=t46.*t504;
t522=t501.*t67;
t523=t520 + t521 + t522;
t524=(-1).*t14.*t92;
t525=(-1).*t13.*t26.*t38;
t526=t120 + t121 + t124 + t524 + t525;
t527=t526.*t67;
t528=t12.*t13.*t2.*t68;
t529=(-1).*t13.*t25.*t7.*t8;
t530=(-1).*t14.*t77;
t531=(-1).*t13.*t19.*t26;
t532=(-1).*t12.*t14.*t26.*t7;
t533=t528 + t529 + t530 + t531 + t532;
t534=t46.*t533;
t535=(-1).*t12.*t13.*t25;
t536=t14.*t25.*t6.*t8;
t537=t12.*t14.*t42.*t9;
t538=(-1).*t12.*t13.*t26.*t6;
t539=t14.*t26.*t8;
t540=t535 + t536 + t537 + t538 + t539;
t541=t239.*t540;
t542=t236.*t499;
t543=t175.*t501;
t544=t133.*t504;
t545=t527 + t534 + t541 + t542 + t543 + t544;
t546=t15.*t212.*t218;
t547=t15.*t41.*t86;
t548=t128.*t15.*t185;
t549=t11.*t212.*t227.*t43;
t550=t11.*t128.*t43.*t95;
t551=t11.*t41.*t43.*t49;
t552=t15.*t227.*t245;
t553=t141.*t15.*t49;
t554=t15.*t207.*t95;
t555=t546 + t547 + t548 + t549 + t550 + t551 + t552 + t553 + t554;
t556=t212.^2;
t557=t128.^2;
t558=t41.^2;
t559=t11.*t12.*t9;
t560=(-1).*t15.*t64;
t561=t559 + t560;
t562=(-1).*t11.*t24;
t563=(-1).*t15.*t21;
t564=t562 + t563;
t565=(-1).*t11.*t52;
t566=(-1).*t15.*t55;
t567=t565 + t566;
t568=t556 + t557 + t558;
t569=t227.*t561;
t570=t49.*t564;
t571=t567.*t95;
t572=t569 + t570 + t571;
t573=t218.*t561;
t574=t564.*t86;
t575=t185.*t567;
t576=(-1).*t11.*t25.*t8.*t9;
t577=t11.*t12.*t42.*t6;
t578=(-1).*t15.*t61;
t579=(-1).*t11.*t43.*t64;
t580=(-1).*t12.*t15.*t43.*t9;
t581=t576 + t577 + t578 + t579 + t580;
t582=t227.*t581;
t583=(-1).*t11.*t147;
t584=(-1).*t15.*t153;
t585=(-1).*t11.*t43.*t55;
t586=t15.*t43.*t52;
t587=t583 + t584 + t585 + t586;
t588=t587.*t95;
t589=(-1).*t101.*t11;
t590=(-1).*t107.*t15;
t591=(-1).*t11.*t21.*t43;
t592=t15.*t24.*t43;
t593=t589 + t590 + t591 + t592;
t594=t49.*t593;
t595=t573 + t574 + t575 + t582 + t588 + t594;
t596=2.*t212.*t245;
t597=2.*t141.*t41;
t598=2.*t128.*t207;
t599=t596 + t597 + t598;
x_dJw_world_qALeft=[0,0,0,0,0,0,0,0,0,t178.*t212 + t156.*t218 + t209.*t227 + t159.* ...
  t236 + t194.*t239 + t162.*t245,t133.*t159 + t141.*t162 + t178.* ...
  t41 + t194.*t46 + t209.*t49 + t156.*t86,t159.*t175 + t128.*t178 +  ...
  t156.*t185 + t162.*t207 + t194.*t67 + t209.*t95,t218.*t298 +  ...
  t236.*t302 + t245.*t306 + t212.*t335 + t239.*t362 + t227.*t389, ...
  t133.*t302 + t141.*t306 + t335.*t41 + t362.*t46 + t389.*t49 +  ...
  t298.*t86,t185.*t298 + t175.*t302 + t207.*t306 + t128.*t335 +  ...
  t362.*t67 + t389.*t95,t218.*t420 + t236.*t424 + t245.*t428 +  ...
  t212.*t439 + t239.*t466 + t227.*t493,t133.*t424 + t141.*t428 +  ...
  t41.*t439 + t46.*t466 + t49.*t493 + t420.*t86,t185.*t420 + t175.* ...
  t424 + t207.*t428 + t128.*t439 + t466.*t67 + t493.*t95,0,0,0,0,0, ...
  0,0,0,0,0,0,0,0,0,0,t218.*t508 + t236.*t512 + t239.*t519 + t245.* ...
  t523 + t212.*t545 + t227.*t555,t133.*t512 + t46.*t519 + t141.* ...
  t523 + t41.*t545 + t49.*t555 + t508.*t86,t185.*t508 + t175.*t512 + ...
   t207.*t523 + t128.*t545 + t519.*t67 + t555.*t95,t218.*t568 +  ...
  t236.*t572 + t239.*t595 + t227.*t599,t133.*t572 + t46.*t595 +  ...
  t49.*t599 + t568.*t86,t185.*t568 + t175.*t572 + t595.*t67 + t599.* ...
  t95,0,0,0,0,0,0,0,0,0];

end %function