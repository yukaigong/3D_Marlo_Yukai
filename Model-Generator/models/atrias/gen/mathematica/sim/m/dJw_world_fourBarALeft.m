function [x_dJw_world_fourBarALeft] = dJw_world_fourBarALeft(x)
%dJw_world_fourBarALeft
%    x_dJw_world_fourBarALeft = dJw_world_fourBarALeft(x)

% This function was generated by Mathematica Common 
% Subexpression Eliminating Package (CseOptimization)
% Thu 26 Jan 2017 21:34:15

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
t52=x(21);
t53=x(28);
t54=t11.*t45;
t55=t24.*t51;
t56=t54 + t55;
t57=t11.*t51;
t58=(-1).*t24.*t45;
t59=t57 + t58;
t60=t26.*t39;
t61=t36.*t42;
t62=t60 + t61;
t63=x(22);
t64=x(29);
t65=t12.*t13.*t52;
t66=(-1).*t18.*t5.*t52.*t6;
t67=(-1).*t12.*t18.*t63.*t8;
t68=t12.*t13.*t5.*t53;
t69=(-1).*t18.*t53.*t6;
t70=t65 + t66 + t67 + t68 + t69;
t71=t13.*t6;
t72=t12.*t18.*t5;
t73=t71 + t72;
t74=x(31);
t75=t26.*t42;
t76=(-1).*t36.*t39;
t77=t75 + t76;
t78=t13.*t33;
t79=t12.*t18.*t7;
t80=t78 + t79;
t81=t11.*t20;
t82=(-1).*t23.*t24;
t83=t81 + t82;
t84=t11.*t23;
t85=t20.*t24;
t86=t84 + t85;
t87=t11.*t52.*t6.*t8;
t88=(-1).*t11.*t12.*t5.*t63;
t89=t24.*t70;
t90=t11.*t64.*t73;
t91=t12.*t24.*t64.*t8;
t92=t87 + t88 + t89 + t90 + t91;
t93=(-1).*t24.*t52.*t6.*t8;
t94=t12.*t24.*t5.*t63;
t95=t11.*t70;
t96=t11.*t12.*t64.*t8;
t97=(-1).*t24.*t64.*t73;
t98=t93 + t94 + t95 + t96 + t97;
t99=t11.*t73;
t100=t12.*t24.*t8;
t101=t100 + t99;
t102=(-1).*t11.*t12.*t8;
t103=t24.*t73;
t104=t102 + t103;
t105=t26.*t83;
t106=(-1).*t36.*t86;
t107=t105 + t106;
t108=x(20);
t109=(-1).*t108.*t3.*t5;
t110=t108.*t6.*t7.*t8;
t111=(-1).*t12.*t3.*t52.*t8;
t112=(-1).*t3.*t5.*t6.*t63;
t113=t63.*t7.*t8;
t114=t109 + t110 + t111 + t112 + t113;
t115=t108.*t12.*t13.*t7;
t116=t13.*t3.*t52.*t6;
t117=(-1).*t108.*t5.*t6.*t7;
t118=(-1).*t108.*t3.*t8;
t119=t12.*t3.*t5.*t52;
t120=(-1).*t5.*t63.*t7;
t121=(-1).*t3.*t6.*t63.*t8;
t122=t117 + t118 + t119 + t120 + t121;
t123=t122.*t18;
t124=t13.*t17.*t53;
t125=t12.*t18.*t3.*t53;
t126=t115 + t116 + t123 + t124 + t125;
t127=t13.*t49;
t128=(-1).*t12.*t18.*t3;
t129=t127 + t128;
t130=t108.*t3.*t5.*t6;
t131=(-1).*t108.*t7.*t8;
t132=t12.*t5.*t52.*t7;
t133=t3.*t5.*t63;
t134=(-1).*t6.*t63.*t7.*t8;
t135=t130 + t131 + t132 + t133 + t134;
t136=(-1).*t108.*t5.*t7;
t137=(-1).*t108.*t3.*t6.*t8;
t138=(-1).*t12.*t52.*t7.*t8;
t139=(-1).*t5.*t6.*t63.*t7;
t140=(-1).*t3.*t63.*t8;
t141=t136 + t137 + t138 + t139 + t140;
t142=(-1).*t108.*t12.*t13.*t3;
t143=t13.*t52.*t6.*t7;
t144=t135.*t18;
t145=t13.*t33.*t53;
t146=t12.*t18.*t53.*t7;
t147=t142 + t143 + t144 + t145 + t146;
t148=t108.*t5.*t6.*t7;
t149=t108.*t3.*t8;
t150=(-1).*t12.*t3.*t5.*t52;
t151=t5.*t63.*t7;
t152=t3.*t6.*t63.*t8;
t153=t148 + t149 + t150 + t151 + t152;
t154=t108.*t3.*t5;
t155=(-1).*t108.*t6.*t7.*t8;
t156=t12.*t3.*t52.*t8;
t157=t3.*t5.*t6.*t63;
t158=(-1).*t63.*t7.*t8;
t159=t154 + t155 + t156 + t157 + t158;
t160=(-1).*t108.*t12.*t13.*t7;
t161=(-1).*t13.*t3.*t52.*t6;
t162=t153.*t18;
t163=t13.*t49.*t53;
t164=(-1).*t12.*t18.*t3.*t53;
t165=t160 + t161 + t162 + t163 + t164;
t166=t26.*t86;
t167=t36.*t83;
t168=t166 + t167;
t169=t11.*t141;
t170=t147.*t24;
t171=t11.*t35.*t64;
t172=(-1).*t24.*t29.*t64;
t173=t169 + t170 + t171 + t172;
t174=(-1).*t173.*t36;
t175=(-1).*t141.*t24;
t176=t11.*t147;
t177=(-1).*t11.*t29.*t64;
t178=(-1).*t24.*t35.*t64;
t179=t175 + t176 + t177 + t178;
t180=t179.*t26;
t181=(-1).*t26.*t39.*t74;
t182=(-1).*t36.*t42.*t74;
t183=t174 + t180 + t181 + t182;
t184=t26.*t59;
t185=(-1).*t36.*t56;
t186=t184 + t185;
t187=t11.*t114;
t188=t126.*t24;
t189=t11.*t20.*t64;
t190=(-1).*t23.*t24.*t64;
t191=t187 + t188 + t189 + t190;
t192=(-1).*t114.*t24;
t193=t11.*t126;
t194=(-1).*t11.*t23.*t64;
t195=(-1).*t20.*t24.*t64;
t196=t192 + t193 + t194 + t195;
t197=t26.*t56;
t198=t36.*t59;
t199=t197 + t198;
t200=t108.*t12.*t18.*t3;
t201=(-1).*t18.*t52.*t6.*t7;
t202=t13.*t135;
t203=t12.*t13.*t53.*t7;
t204=(-1).*t18.*t33.*t53;
t205=t200 + t201 + t202 + t203 + t204;
t206=t13.*t17;
t207=t12.*t18.*t3;
t208=t206 + t207;
t209=t173.*t26;
t210=t179.*t36;
t211=t26.*t42.*t74;
t212=(-1).*t36.*t39.*t74;
t213=t209 + t210 + t211 + t212;
t214=t11.*t159;
t215=t165.*t24;
t216=t11.*t51.*t64;
t217=(-1).*t24.*t45.*t64;
t218=t214 + t215 + t216 + t217;
t219=(-1).*t159.*t24;
t220=t11.*t165;
t221=(-1).*t11.*t45.*t64;
t222=(-1).*t24.*t51.*t64;
t223=t219 + t220 + t221 + t222;
t224=t168.*t77;
t225=t186.*t62;
t226=t224 + t225;
t227=t199.*t80;
t228=t208.*t62;
t229=t227 + t228;
t230=t129.*t77;
t231=t107.*t80;
t232=t230 + t231;
t233=t107.*t205;
t234=t108.*t12.*t18.*t7;
t235=t18.*t3.*t52.*t6;
t236=t13.*t153;
t237=(-1).*t12.*t13.*t3.*t53;
t238=(-1).*t18.*t49.*t53;
t239=t234 + t235 + t236 + t237 + t238;
t240=t239.*t77;
t241=(-1).*t191.*t36;
t242=t196.*t26;
t243=(-1).*t26.*t74.*t86;
t244=(-1).*t36.*t74.*t83;
t245=t241 + t242 + t243 + t244;
t246=t245.*t80;
t247=t129.*t183;
t248=t233 + t240 + t246 + t247;
t249=(-1).*t218.*t36;
t250=t223.*t26;
t251=(-1).*t26.*t56.*t74;
t252=(-1).*t36.*t59.*t74;
t253=t249 + t250 + t251 + t252;
t254=t253.*t62;
t255=t168.*t183;
t256=t186.*t213;
t257=t191.*t26;
t258=t196.*t36;
t259=t26.*t74.*t83;
t260=(-1).*t36.*t74.*t86;
t261=t257 + t258 + t259 + t260;
t262=t261.*t77;
t263=t254 + t255 + t256 + t262;
t264=t199.*t205;
t265=(-1).*t108.*t12.*t18.*t7;
t266=(-1).*t18.*t3.*t52.*t6;
t267=t122.*t13;
t268=t12.*t13.*t3.*t53;
t269=(-1).*t17.*t18.*t53;
t270=t265 + t266 + t267 + t268 + t269;
t271=t270.*t62;
t272=t208.*t213;
t273=t218.*t26;
t274=t223.*t36;
t275=t26.*t59.*t74;
t276=(-1).*t36.*t56.*t74;
t277=t273 + t274 + t275 + t276;
t278=t277.*t80;
t279=t264 + t271 + t272 + t278;
t280=t12.*t13;
t281=(-1).*t18.*t5.*t6;
t282=t280 + t281;
t283=t101.*t26;
t284=(-1).*t104.*t36;
t285=t283 + t284;
t286=t13.*t6.*t7;
t287=t12.*t18.*t5.*t7;
t288=t286 + t287;
t289=(-1).*t13.*t3.*t6;
t290=(-1).*t12.*t18.*t3.*t5;
t291=t289 + t290;
t292=(-1).*t13.*t5.*t52.*t6;
t293=(-1).*t12.*t18.*t52;
t294=(-1).*t12.*t13.*t63.*t8;
t295=(-1).*t13.*t53.*t6;
t296=(-1).*t12.*t18.*t5.*t53;
t297=t292 + t293 + t294 + t295 + t296;
t298=t104.*t26;
t299=t101.*t36;
t300=t298 + t299;
t301=(-1).*t36.*t92;
t302=t26.*t98;
t303=(-1).*t104.*t26.*t74;
t304=(-1).*t101.*t36.*t74;
t305=t301 + t302 + t303 + t304;
t306=t11.*t291;
t307=(-1).*t12.*t24.*t3.*t8;
t308=t306 + t307;
t309=t11.*t12.*t3.*t8;
t310=t24.*t291;
t311=t309 + t310;
t312=t11.*t288;
t313=t12.*t24.*t7.*t8;
t314=t312 + t313;
t315=(-1).*t11.*t12.*t7.*t8;
t316=t24.*t288;
t317=t315 + t316;
t318=t12.*t13.*t5;
t319=(-1).*t18.*t6;
t320=t318 + t319;
t321=t11.*t282;
t322=(-1).*t24.*t6.*t8;
t323=t321 + t322;
t324=t11.*t6.*t8;
t325=t24.*t282;
t326=t324 + t325;
t327=t26.*t92;
t328=t36.*t98;
t329=t101.*t26.*t74;
t330=(-1).*t104.*t36.*t74;
t331=t327 + t328 + t329 + t330;
t332=t26.*t323;
t333=(-1).*t326.*t36;
t334=t332 + t333;
t335=t26.*t314;
t336=(-1).*t317.*t36;
t337=t335 + t336;
t338=t26.*t308;
t339=(-1).*t311.*t36;
t340=t338 + t339;
t341=t108.*t13.*t6.*t7;
t342=t108.*t12.*t18.*t5.*t7;
t343=(-1).*t12.*t13.*t3.*t52;
t344=t18.*t3.*t5.*t52.*t6;
t345=t12.*t18.*t3.*t63.*t8;
t346=(-1).*t12.*t13.*t3.*t5.*t53;
t347=t18.*t3.*t53.*t6;
t348=t341 + t342 + t343 + t344 + t345 + t346 + t347;
t349=t108.*t13.*t3.*t6;
t350=t108.*t12.*t18.*t3.*t5;
t351=t12.*t13.*t52.*t7;
t352=(-1).*t18.*t5.*t52.*t6.*t7;
t353=(-1).*t12.*t18.*t63.*t7.*t8;
t354=t12.*t13.*t5.*t53.*t7;
t355=(-1).*t18.*t53.*t6.*t7;
t356=t349 + t350 + t351 + t352 + t353 + t354 + t355;
t357=(-1).*t13.*t52.*t6;
t358=(-1).*t12.*t18.*t5.*t52;
t359=t18.*t6.*t63.*t8;
t360=(-1).*t13.*t5.*t53.*t6;
t361=(-1).*t12.*t18.*t53;
t362=t357 + t358 + t359 + t360 + t361;
t363=t26.*t326;
t364=t323.*t36;
t365=t363 + t364;
t366=t26.*t311;
t367=t308.*t36;
t368=t366 + t367;
t369=t26.*t317;
t370=t314.*t36;
t371=t369 + t370;
t372=(-1).*t108.*t11.*t12.*t7.*t8;
t373=(-1).*t11.*t3.*t52.*t6.*t8;
t374=t11.*t12.*t3.*t5.*t63;
t375=t24.*t348;
t376=t11.*t291.*t64;
t377=(-1).*t12.*t24.*t3.*t64.*t8;
t378=t372 + t373 + t374 + t375 + t376 + t377;
t379=t108.*t12.*t24.*t7.*t8;
t380=t24.*t3.*t52.*t6.*t8;
t381=(-1).*t12.*t24.*t3.*t5.*t63;
t382=t11.*t348;
t383=(-1).*t11.*t12.*t3.*t64.*t8;
t384=(-1).*t24.*t291.*t64;
t385=t379 + t380 + t381 + t382 + t383 + t384;
t386=(-1).*t108.*t11.*t12.*t3.*t8;
t387=t11.*t52.*t6.*t7.*t8;
t388=(-1).*t11.*t12.*t5.*t63.*t7;
t389=t24.*t356;
t390=t11.*t288.*t64;
t391=t12.*t24.*t64.*t7.*t8;
t392=t386 + t387 + t388 + t389 + t390 + t391;
t393=t108.*t12.*t24.*t3.*t8;
t394=(-1).*t24.*t52.*t6.*t7.*t8;
t395=t12.*t24.*t5.*t63.*t7;
t396=t11.*t356;
t397=t11.*t12.*t64.*t7.*t8;
t398=(-1).*t24.*t288.*t64;
t399=t393 + t394 + t395 + t396 + t397 + t398;
t400=t11.*t12.*t52.*t8;
t401=t11.*t5.*t6.*t63;
t402=t24.*t362;
t403=t11.*t282.*t64;
t404=(-1).*t24.*t6.*t64.*t8;
t405=t400 + t401 + t402 + t403 + t404;
t406=(-1).*t12.*t24.*t52.*t8;
t407=(-1).*t24.*t5.*t6.*t63;
t408=t11.*t362;
t409=(-1).*t11.*t6.*t64.*t8;
t410=(-1).*t24.*t282.*t64;
t411=t406 + t407 + t408 + t409 + t410;
t412=(-1).*t13.*t5.*t6;
t413=(-1).*t12.*t18;
t414=t412 + t413;
t415=t12.*t13.*t5.*t7;
t416=(-1).*t18.*t6.*t7;
t417=t415 + t416;
t418=(-1).*t12.*t13.*t3.*t5;
t419=t18.*t3.*t6;
t420=t418 + t419;
t421=t285.*t365;
t422=t371.*t77;
t423=t186.*t368;
t424=t421 + t422 + t423;
t425=t300.*t414;
t426=t199.*t420;
t427=t417.*t62;
t428=t425 + t426 + t427;
t429=t129.*t340;
t430=t337.*t80;
t431=t320.*t334;
t432=t429 + t430 + t431;
t433=t297.*t334;
t434=t205.*t337;
t435=t239.*t340;
t436=(-1).*t36.*t378;
t437=t26.*t385;
t438=(-1).*t26.*t311.*t74;
t439=(-1).*t308.*t36.*t74;
t440=t436 + t437 + t438 + t439;
t441=t129.*t440;
t442=(-1).*t36.*t392;
t443=t26.*t399;
t444=(-1).*t26.*t317.*t74;
t445=(-1).*t314.*t36.*t74;
t446=t442 + t443 + t444 + t445;
t447=t446.*t80;
t448=(-1).*t36.*t405;
t449=t26.*t411;
t450=(-1).*t26.*t326.*t74;
t451=(-1).*t323.*t36.*t74;
t452=t448 + t449 + t450 + t451;
t453=t320.*t452;
t454=t433 + t434 + t435 + t441 + t447 + t453;
t455=t305.*t365;
t456=t253.*t368;
t457=t183.*t371;
t458=t26.*t378;
t459=t36.*t385;
t460=t26.*t308.*t74;
t461=(-1).*t311.*t36.*t74;
t462=t458 + t459 + t460 + t461;
t463=t186.*t462;
t464=t26.*t392;
t465=t36.*t399;
t466=t26.*t314.*t74;
t467=(-1).*t317.*t36.*t74;
t468=t464 + t465 + t466 + t467;
t469=t468.*t77;
t470=t26.*t405;
t471=t36.*t411;
t472=t26.*t323.*t74;
t473=(-1).*t326.*t36.*t74;
t474=t470 + t471 + t472 + t473;
t475=t285.*t474;
t476=t455 + t456 + t457 + t463 + t469 + t475;
t477=t108.*t12.*t13.*t5.*t7;
t478=(-1).*t108.*t18.*t6.*t7;
t479=t13.*t3.*t5.*t52.*t6;
t480=t12.*t18.*t3.*t52;
t481=t12.*t13.*t3.*t63.*t8;
t482=t13.*t3.*t53.*t6;
t483=t12.*t18.*t3.*t5.*t53;
t484=t477 + t478 + t479 + t480 + t481 + t482 + t483;
t485=t199.*t484;
t486=t108.*t12.*t13.*t3.*t5;
t487=(-1).*t108.*t18.*t3.*t6;
t488=(-1).*t13.*t5.*t52.*t6.*t7;
t489=(-1).*t12.*t18.*t52.*t7;
t490=(-1).*t12.*t13.*t63.*t7.*t8;
t491=(-1).*t13.*t53.*t6.*t7;
t492=(-1).*t12.*t18.*t5.*t53.*t7;
t493=t486 + t487 + t488 + t489 + t490 + t491 + t492;
t494=t493.*t62;
t495=(-1).*t12.*t13.*t5.*t52;
t496=t18.*t52.*t6;
t497=t13.*t6.*t63.*t8;
t498=(-1).*t12.*t13.*t53;
t499=t18.*t5.*t53.*t6;
t500=t495 + t496 + t497 + t498 + t499;
t501=t300.*t500;
t502=t331.*t414;
t503=t213.*t417;
t504=t277.*t420;
t505=t485 + t494 + t501 + t502 + t503 + t504;
t506=(-1).*t5.*t6.*t7;
t507=(-1).*t3.*t8;
t508=t506 + t507;
t509=(-1).*t11.*t12.*t18.*t8;
t510=t12.*t24.*t5;
t511=t509 + t510;
t512=(-1).*t11.*t12.*t5;
t513=(-1).*t12.*t18.*t24.*t8;
t514=t512 + t513;
t515=t11.*t18.*t45;
t516=(-1).*t17.*t24;
t517=t515 + t516;
t518=t11.*t17;
t519=t18.*t24.*t45;
t520=t518 + t519;
t521=t11.*t18.*t29;
t522=(-1).*t24.*t508;
t523=t521 + t522;
t524=t11.*t508;
t525=t18.*t24.*t29;
t526=t524 + t525;
t527=t26.*t511;
t528=(-1).*t36.*t514;
t529=t527 + t528;
t530=t26.*t523;
t531=(-1).*t36.*t526;
t532=t530 + t531;
t533=t26.*t517;
t534=(-1).*t36.*t520;
t535=t533 + t534;
t536=(-1).*t108.*t3.*t5.*t6;
t537=t108.*t7.*t8;
t538=(-1).*t12.*t5.*t52.*t7;
t539=(-1).*t3.*t5.*t63;
t540=t6.*t63.*t7.*t8;
t541=t536 + t537 + t538 + t539 + t540;
t542=t26.*t514;
t543=t36.*t511;
t544=t542 + t543;
t545=t26.*t520;
t546=t36.*t517;
t547=t545 + t546;
t548=t26.*t526;
t549=t36.*t523;
t550=t548 + t549;
t551=t11.*t5.*t52.*t6;
t552=t18.*t24.*t52.*t6.*t8;
t553=t11.*t12.*t63.*t8;
t554=(-1).*t12.*t18.*t24.*t5.*t63;
t555=(-1).*t12.*t13.*t24.*t53.*t8;
t556=(-1).*t11.*t12.*t18.*t64.*t8;
t557=t12.*t24.*t5.*t64;
t558=t551 + t552 + t553 + t554 + t555 + t556 + t557;
t559=t11.*t18.*t52.*t6.*t8;
t560=(-1).*t24.*t5.*t52.*t6;
t561=(-1).*t11.*t12.*t18.*t5.*t63;
t562=(-1).*t12.*t24.*t63.*t8;
t563=(-1).*t11.*t12.*t13.*t53.*t8;
t564=t11.*t12.*t5.*t64;
t565=t12.*t18.*t24.*t64.*t8;
t566=t559 + t560 + t561 + t562 + t563 + t564 + t565;
t567=t159.*t18.*t24;
t568=t11.*t122;
t569=t13.*t24.*t45.*t53;
t570=t11.*t18.*t45.*t64;
t571=(-1).*t17.*t24.*t64;
t572=t567 + t568 + t569 + t570 + t571;
t573=t11.*t159.*t18;
t574=(-1).*t122.*t24;
t575=t11.*t13.*t45.*t53;
t576=(-1).*t11.*t17.*t64;
t577=(-1).*t18.*t24.*t45.*t64;
t578=t573 + t574 + t575 + t576 + t577;
t579=t141.*t18.*t24;
t580=t11.*t541;
t581=t13.*t24.*t29.*t53;
t582=t11.*t18.*t29.*t64;
t583=(-1).*t24.*t508.*t64;
t584=t579 + t580 + t581 + t582 + t583;
t585=t11.*t141.*t18;
t586=(-1).*t24.*t541;
t587=t11.*t13.*t29.*t53;
t588=(-1).*t11.*t508.*t64;
t589=(-1).*t18.*t24.*t29.*t64;
t590=t585 + t586 + t587 + t588 + t589;
t591=t285.*t544;
t592=t550.*t77;
t593=t186.*t547;
t594=t591 + t592 + t593;
t595=(-1).*t12.*t13.*t300.*t8;
t596=t13.*t199.*t45;
t597=t13.*t29.*t62;
t598=t595 + t596 + t597;
t599=t320.*t529;
t600=t129.*t535;
t601=t532.*t80;
t602=t599 + t600 + t601;
t603=t297.*t529;
t604=t205.*t532;
t605=t239.*t535;
t606=(-1).*t36.*t558;
t607=t26.*t566;
t608=(-1).*t26.*t514.*t74;
t609=(-1).*t36.*t511.*t74;
t610=t606 + t607 + t608 + t609;
t611=t320.*t610;
t612=(-1).*t36.*t584;
t613=t26.*t590;
t614=(-1).*t26.*t526.*t74;
t615=(-1).*t36.*t523.*t74;
t616=t612 + t613 + t614 + t615;
t617=t616.*t80;
t618=(-1).*t36.*t572;
t619=t26.*t578;
t620=(-1).*t26.*t520.*t74;
t621=(-1).*t36.*t517.*t74;
t622=t618 + t619 + t620 + t621;
t623=t129.*t622;
t624=t603 + t604 + t605 + t611 + t617 + t623;
t625=t305.*t544;
t626=t253.*t547;
t627=t183.*t550;
t628=t26.*t558;
t629=t36.*t566;
t630=t26.*t511.*t74;
t631=(-1).*t36.*t514.*t74;
t632=t628 + t629 + t630 + t631;
t633=t285.*t632;
t634=t26.*t572;
t635=t36.*t578;
t636=t26.*t517.*t74;
t637=(-1).*t36.*t520.*t74;
t638=t634 + t635 + t636 + t637;
t639=t186.*t638;
t640=t26.*t584;
t641=t36.*t590;
t642=t26.*t523.*t74;
t643=(-1).*t36.*t526.*t74;
t644=t640 + t641 + t642 + t643;
t645=t644.*t77;
t646=t625 + t626 + t627 + t633 + t639 + t645;
t647=t13.*t300.*t52.*t6.*t8;
t648=(-1).*t12.*t13.*t300.*t5.*t63;
t649=t13.*t141.*t62;
t650=t13.*t159.*t199;
t651=t12.*t18.*t300.*t53.*t8;
t652=(-1).*t18.*t199.*t45.*t53;
t653=(-1).*t18.*t29.*t53.*t62;
t654=(-1).*t12.*t13.*t331.*t8;
t655=t13.*t213.*t29;
t656=t13.*t277.*t45;
t657=t647 + t648 + t649 + t650 + t651 + t652 + t653 + t654 + t655 +  ...
  t656;
t658=t11.*t26.*t320;
t659=(-1).*t24.*t320.*t36;
t660=t658 + t659;
t661=t11.*t26.*t80;
t662=(-1).*t24.*t36.*t80;
t663=t661 + t662;
t664=t11.*t129.*t26;
t665=(-1).*t129.*t24.*t36;
t666=t664 + t665;
t667=t24.*t26.*t320;
t668=t11.*t320.*t36;
t669=t667 + t668;
t670=t129.*t24.*t26;
t671=t11.*t129.*t36;
t672=t670 + t671;
t673=t24.*t26.*t80;
t674=t11.*t36.*t80;
t675=t673 + t674;
t676=(-1).*t13.*t6;
t677=(-1).*t12.*t18.*t5;
t678=t676 + t677;
t679=t12.*t13.*t7;
t680=(-1).*t18.*t33;
t681=t679 + t680;
t682=(-1).*t18.*t49;
t683=t14 + t682;
t684=t285.*t669;
t685=t675.*t77;
t686=t186.*t672;
t687=t684 + t685 + t686;
t688=t300.*t678;
t689=t199.*t683;
t690=t62.*t681;
t691=t688 + t689 + t690;
t692=t129.*t666;
t693=t663.*t80;
t694=t320.*t660;
t695=t692 + t693 + t694;
t696=t297.*t660;
t697=t205.*t663;
t698=t239.*t666;
t699=t11.*t239.*t26;
t700=(-1).*t239.*t24.*t36;
t701=(-1).*t129.*t24.*t26.*t64;
t702=(-1).*t11.*t129.*t36.*t64;
t703=(-1).*t129.*t24.*t26.*t74;
t704=(-1).*t11.*t129.*t36.*t74;
t705=t699 + t700 + t701 + t702 + t703 + t704;
t706=t129.*t705;
t707=t11.*t205.*t26;
t708=(-1).*t205.*t24.*t36;
t709=(-1).*t24.*t26.*t64.*t80;
t710=(-1).*t11.*t36.*t64.*t80;
t711=(-1).*t24.*t26.*t74.*t80;
t712=(-1).*t11.*t36.*t74.*t80;
t713=t707 + t708 + t709 + t710 + t711 + t712;
t714=t713.*t80;
t715=t11.*t26.*t297;
t716=(-1).*t24.*t297.*t36;
t717=(-1).*t24.*t26.*t320.*t64;
t718=(-1).*t11.*t320.*t36.*t64;
t719=(-1).*t24.*t26.*t320.*t74;
t720=(-1).*t11.*t320.*t36.*t74;
t721=t715 + t716 + t717 + t718 + t719 + t720;
t722=t320.*t721;
t723=t696 + t697 + t698 + t706 + t714 + t722;
t724=t239.*t24.*t26;
t725=t11.*t239.*t36;
t726=t11.*t129.*t26.*t64;
t727=(-1).*t129.*t24.*t36.*t64;
t728=t11.*t129.*t26.*t74;
t729=(-1).*t129.*t24.*t36.*t74;
t730=t724 + t725 + t726 + t727 + t728 + t729;
t731=t186.*t730;
t732=t205.*t24.*t26;
t733=t11.*t205.*t36;
t734=t11.*t26.*t64.*t80;
t735=(-1).*t24.*t36.*t64.*t80;
t736=t11.*t26.*t74.*t80;
t737=(-1).*t24.*t36.*t74.*t80;
t738=t732 + t733 + t734 + t735 + t736 + t737;
t739=t738.*t77;
t740=t24.*t26.*t297;
t741=t11.*t297.*t36;
t742=t11.*t26.*t320.*t64;
t743=(-1).*t24.*t320.*t36.*t64;
t744=t11.*t26.*t320.*t74;
t745=(-1).*t24.*t320.*t36.*t74;
t746=t740 + t741 + t742 + t743 + t744 + t745;
t747=t285.*t746;
t748=t305.*t669;
t749=t253.*t672;
t750=t183.*t675;
t751=t731 + t739 + t747 + t748 + t749 + t750;
t752=(-1).*t153.*t18;
t753=(-1).*t13.*t49.*t53;
t754=t115 + t116 + t125 + t752 + t753;
t755=t199.*t754;
t756=t108.*t12.*t13.*t3;
t757=(-1).*t13.*t52.*t6.*t7;
t758=(-1).*t135.*t18;
t759=(-1).*t13.*t33.*t53;
t760=(-1).*t12.*t18.*t53.*t7;
t761=t756 + t757 + t758 + t759 + t760;
t762=t62.*t761;
t763=(-1).*t12.*t13.*t52;
t764=t18.*t5.*t52.*t6;
t765=t12.*t18.*t63.*t8;
t766=(-1).*t12.*t13.*t5.*t53;
t767=t18.*t53.*t6;
t768=t763 + t764 + t765 + t766 + t767;
t769=t300.*t768;
t770=t331.*t678;
t771=t213.*t681;
t772=t277.*t683;
t773=t755 + t762 + t769 + t770 + t771 + t772;
t774=t11.*t12.*t8;
t775=(-1).*t24.*t73;
t776=t774 + t775;
t777=(-1).*t11.*t45;
t778=(-1).*t24.*t51;
t779=t777 + t778;
t780=(-1).*t11.*t29;
t781=(-1).*t24.*t35;
t782=t780 + t781;
t783=t36.*t776;
t784=t283 + t783;
t785=t36.*t779;
t786=t184 + t785;
t787=t36.*t782;
t788=t75 + t787;
t789=t26.*t776;
t790=(-1).*t101.*t36;
t791=t789 + t790;
t792=t26.*t782;
t793=(-1).*t36.*t42;
t794=t792 + t793;
t795=t26.*t779;
t796=(-1).*t36.*t59;
t797=t795 + t796;
t798=(-1).*t11.*t52.*t6.*t8;
t799=t11.*t12.*t5.*t63;
t800=(-1).*t24.*t70;
t801=(-1).*t11.*t64.*t73;
t802=(-1).*t12.*t24.*t64.*t8;
t803=t798 + t799 + t800 + t801 + t802;
t804=(-1).*t11.*t141;
t805=(-1).*t147.*t24;
t806=(-1).*t11.*t35.*t64;
t807=t24.*t29.*t64;
t808=t804 + t805 + t806 + t807;
t809=(-1).*t11.*t159;
t810=(-1).*t165.*t24;
t811=(-1).*t11.*t51.*t64;
t812=t24.*t45.*t64;
t813=t809 + t810 + t811 + t812;
t814=t285.*t784;
t815=t77.*t788;
t816=t186.*t786;
t817=t814 + t815 + t816;
t818=t320.*t791;
t819=t129.*t797;
t820=t794.*t80;
t821=t818 + t819 + t820;
t822=t36.*t803;
t823=t26.*t74.*t776;
t824=t302 + t304 + t822 + t823;
t825=t285.*t824;
t826=t305.*t784;
t827=t36.*t813;
t828=t26.*t74.*t779;
t829=t250 + t252 + t827 + t828;
t830=t186.*t829;
t831=t253.*t786;
t832=t36.*t808;
t833=t26.*t74.*t782;
t834=t180 + t182 + t832 + t833;
t835=t77.*t834;
t836=t183.*t788;
t837=t825 + t826 + t830 + t831 + t835 + t836;
t838=t297.*t791;
t839=t205.*t794;
t840=t239.*t797;
t841=t26.*t803;
t842=(-1).*t36.*t98;
t843=(-1).*t101.*t26.*t74;
t844=(-1).*t36.*t74.*t776;
t845=t841 + t842 + t843 + t844;
t846=t320.*t845;
t847=t26.*t808;
t848=(-1).*t179.*t36;
t849=(-1).*t26.*t42.*t74;
t850=(-1).*t36.*t74.*t782;
t851=t847 + t848 + t849 + t850;
t852=t80.*t851;
t853=t26.*t813;
t854=(-1).*t223.*t36;
t855=(-1).*t26.*t59.*t74;
t856=(-1).*t36.*t74.*t779;
t857=t853 + t854 + t855 + t856;
t858=t129.*t857;
t859=t838 + t839 + t840 + t846 + t852 + t858;
t860=t285.^2;
t861=t77.^2;
t862=t186.^2;
t863=(-1).*t104.*t26;
t864=t790 + t863;
t865=(-1).*t26.*t39;
t866=t793 + t865;
t867=(-1).*t26.*t56;
t868=t796 + t867;
t869=t860 + t861 + t862;
t870=t320.*t864;
t871=t129.*t868;
t872=t80.*t866;
t873=t870 + t871 + t872;
t874=2.*t285.*t305;
t875=2.*t186.*t253;
t876=2.*t183.*t77;
t877=t874 + t875 + t876;
t878=t297.*t864;
t879=t205.*t866;
t880=t239.*t868;
t881=(-1).*t26.*t92;
t882=t104.*t36.*t74;
t883=t842 + t843 + t881 + t882;
t884=t320.*t883;
t885=(-1).*t173.*t26;
t886=t36.*t39.*t74;
t887=t848 + t849 + t885 + t886;
t888=t80.*t887;
t889=(-1).*t218.*t26;
t890=t36.*t56.*t74;
t891=t854 + t855 + t889 + t890;
t892=t129.*t891;
t893=t878 + t879 + t880 + t884 + t888 + t892;
x_dJw_world_fourBarALeft=[0,0,0,0,0,0,0,0,0,t279.*t285 + t226.*t297 + t248.*t300 + t229.* ...
  t305 + t263.*t320 + t232.*t331,t205.*t226 + t183.*t229 + t213.* ...
  t232 + t248.*t62 + t279.*t77 + t263.*t80,t226.*t239 + t199.*t248 + ...
   t229.*t253 + t129.*t263 + t232.*t277 + t186.*t279,t297.*t424 +  ...
  t305.*t428 + t331.*t432 + t300.*t454 + t320.*t476 + t285.*t505, ...
  t205.*t424 + t183.*t428 + t213.*t432 + t454.*t62 + t505.*t77 +  ...
  t476.*t80,t239.*t424 + t253.*t428 + t277.*t432 + t199.*t454 +  ...
  t129.*t476 + t186.*t505,t297.*t594 + t305.*t598 + t331.*t602 +  ...
  t300.*t624 + t320.*t646 + t285.*t657,t205.*t594 + t183.*t598 +  ...
  t213.*t602 + t62.*t624 + t657.*t77 + t646.*t80,t239.*t594 + t253.* ...
  t598 + t277.*t602 + t199.*t624 + t129.*t646 + t186.*t657,0,0,0,0, ...
  0,0,0,0,0,0,0,0,0,0,0,t297.*t687 + t305.*t691 + t331.*t695 +  ...
  t300.*t723 + t320.*t751 + t285.*t773,t205.*t687 + t183.*t691 +  ...
  t213.*t695 + t62.*t723 + t77.*t773 + t751.*t80,t239.*t687 + t253.* ...
  t691 + t277.*t695 + t199.*t723 + t129.*t751 + t186.*t773,t297.* ...
  t817 + t331.*t821 + t320.*t837 + t300.*t859,t205.*t817 + t213.* ...
  t821 + t80.*t837 + t62.*t859,t239.*t817 + t277.*t821 + t129.*t837  ...
  + t199.*t859,0,0,0,t297.*t869 + t331.*t873 + t320.*t877 + t300.* ...
  t893,t205.*t869 + t213.*t873 + t80.*t877 + t62.*t893,t239.*t869 +  ...
  t277.*t873 + t129.*t877 + t199.*t893,0,0,0];

end %function