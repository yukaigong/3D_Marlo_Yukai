function [x_dJp_RightFourBarConnect] = dJp_RightFourBarConnect(x)
%dJp_RightFourBarConnect
%    x_dJp_RightFourBarConnect = dJp_RightFourBarConnect(x)

% This function was generated by Mathematica Common 
% Subexpression Eliminating Package (CseOptimization)
% Thu 26 Jan 2017 21:34:20

t1=x(4);
t2=x(5);
t3=x(7);
t4=sin(t3);
t5=sin(t1);
t6=sin(t2);
t7=x(20);
t8=cos(t1);
t9=x(6);
t10=cos(t2);
t11=cos(t9);
t12=x(21);
t13=sin(t9);
t14=x(22);
t15=cos(t3);
t16=x(23);
t17=x(8);
t18=(-1).*t11.*t5.*t6.*t7;
t19=(-1).*t13.*t7.*t8;
t20=t10.*t11.*t12.*t8;
t21=(-1).*t11.*t14.*t5;
t22=(-1).*t13.*t14.*t6.*t8;
t23=t18 + t19 + t20 + t21 + t22;
t24=t11.*t6.*t8;
t25=(-1).*t13.*t5;
t26=t24 + t25;
t27=cos(t17);
t28=sin(t17);
t29=x(24);
t30=x(10);
t31=(-1).*t11.*t7.*t8;
t32=t13.*t5.*t6.*t7;
t33=(-1).*t10.*t12.*t13.*t8;
t34=(-1).*t11.*t14.*t6.*t8;
t35=t13.*t14.*t5;
t36=t31 + t32 + t33 + t34 + t35;
t37=t10.*t15.*t5.*t7;
t38=t12.*t15.*t6.*t8;
t39=t23.*t4;
t40=t15.*t16.*t26;
t41=t10.*t16.*t4.*t8;
t42=t37 + t38 + t39 + t40 + t41;
t43=(-1).*t11.*t5;
t44=(-1).*t13.*t6.*t8;
t45=t43 + t44;
t46=(-1).*t10.*t15.*t8;
t47=t26.*t4;
t48=t46 + t47;
t49=cos(t30);
t50=sin(t30);
t51=x(26);
t52=t27.*t36;
t53=t28.*t42;
t54=t27.*t29.*t48;
t55=(-1).*t28.*t29.*t45;
t56=t52 + t53 + t54 + t55;
t57=(-1).*t28.*t36;
t58=t27.*t42;
t59=(-1).*t27.*t29.*t45;
t60=(-1).*t28.*t29.*t48;
t61=t57 + t58 + t59 + t60;
t62=t27.*t45;
t63=t28.*t48;
t64=t62 + t63;
t65=t27.*t48;
t66=(-1).*t28.*t45;
t67=t65 + t66;
t68=t11.*t6.*t7.*t8;
t69=(-1).*t13.*t5.*t7;
t70=t10.*t11.*t12.*t5;
t71=t11.*t14.*t8;
t72=(-1).*t13.*t14.*t5.*t6;
t73=t68 + t69 + t70 + t71 + t72;
t74=t11.*t5.*t6;
t75=t13.*t8;
t76=t74 + t75;
t77=(-1).*t49;
t78=1 + t77;
t79=(-1).*t11.*t5.*t7;
t80=(-1).*t13.*t6.*t7.*t8;
t81=(-1).*t10.*t12.*t13.*t5;
t82=(-1).*t11.*t14.*t5.*t6;
t83=(-1).*t13.*t14.*t8;
t84=t79 + t80 + t81 + t82 + t83;
t85=(-1).*t10.*t15.*t7.*t8;
t86=t12.*t15.*t5.*t6;
t87=t4.*t73;
t88=t15.*t16.*t76;
t89=t10.*t16.*t4.*t5;
t90=t85 + t86 + t87 + t88 + t89;
t91=t11.*t8;
t92=(-1).*t13.*t5.*t6;
t93=t91 + t92;
t94=(-1).*t10.*t15.*t5;
t95=t4.*t76;
t96=t94 + t95;
t97=t27.*t84;
t98=t28.*t90;
t99=t27.*t29.*t96;
t100=(-1).*t28.*t29.*t93;
t101=t100 + t97 + t98 + t99;
t102=(-1).*t28.*t84;
t103=t27.*t90;
t104=(-1).*t27.*t29.*t93;
t105=(-1).*t28.*t29.*t96;
t106=t102 + t103 + t104 + t105;
t107=t27.*t93;
t108=t28.*t96;
t109=t107 + t108;
t110=t27.*t96;
t111=(-1).*t28.*t93;
t112=t110 + t111;
t113=(-1).*t12.*t15.*t6;
t114=(-1).*t10.*t11.*t12.*t4;
t115=t13.*t14.*t4.*t6;
t116=(-1).*t11.*t15.*t16.*t6;
t117=(-1).*t10.*t16.*t4;
t118=t113 + t114 + t115 + t116 + t117;
t119=t10.*t15;
t120=(-1).*t11.*t4.*t6;
t121=t119 + t120;
t122=t10.*t12.*t13.*t27;
t123=t11.*t14.*t27.*t6;
t124=t118.*t28;
t125=t121.*t27.*t29;
t126=(-1).*t13.*t28.*t29.*t6;
t127=t122 + t123 + t124 + t125 + t126;
t128=(-1).*t10.*t12.*t13.*t28;
t129=(-1).*t11.*t14.*t28.*t6;
t130=t118.*t27;
t131=(-1).*t13.*t27.*t29.*t6;
t132=(-1).*t121.*t28.*t29;
t133=t128 + t129 + t130 + t131 + t132;
t134=t13.*t27.*t6;
t135=t121.*t28;
t136=t134 + t135;
t137=t121.*t27;
t138=(-1).*t13.*t28.*t6;
t139=t137 + t138;
t140=t15.*t6.*t7.*t8;
t141=t10.*t11.*t4.*t7.*t8;
t142=t10.*t12.*t15.*t5;
t143=(-1).*t11.*t12.*t4.*t5.*t6;
t144=(-1).*t10.*t13.*t14.*t4.*t5;
t145=t10.*t11.*t15.*t16.*t5;
t146=(-1).*t16.*t4.*t5.*t6;
t147=t140 + t141 + t142 + t143 + t144 + t145 + t146;
t148=t15.*t5.*t6;
t149=t10.*t11.*t4.*t5;
t150=t148 + t149;
t151=(-1).*t10.*t13.*t27.*t7.*t8;
t152=t12.*t13.*t27.*t5.*t6;
t153=(-1).*t10.*t11.*t14.*t27.*t5;
t154=t147.*t28;
t155=t150.*t27.*t29;
t156=t10.*t13.*t28.*t29.*t5;
t157=t151 + t152 + t153 + t154 + t155 + t156;
t158=t10.*t13.*t28.*t7.*t8;
t159=(-1).*t12.*t13.*t28.*t5.*t6;
t160=t10.*t11.*t14.*t28.*t5;
t161=t147.*t27;
t162=t10.*t13.*t27.*t29.*t5;
t163=(-1).*t150.*t28.*t29;
t164=t158 + t159 + t160 + t161 + t162 + t163;
t165=(-1).*t10.*t13.*t27.*t5;
t166=t150.*t28;
t167=t165 + t166;
t168=t150.*t27;
t169=t10.*t13.*t28.*t5;
t170=t168 + t169;
t171=t15.*t5.*t6.*t7;
t172=t10.*t11.*t4.*t5.*t7;
t173=(-1).*t10.*t12.*t15.*t8;
t174=t11.*t12.*t4.*t6.*t8;
t175=t10.*t13.*t14.*t4.*t8;
t176=(-1).*t10.*t11.*t15.*t16.*t8;
t177=t16.*t4.*t6.*t8;
t178=t171 + t172 + t173 + t174 + t175 + t176 + t177;
t179=(-1).*t15.*t6.*t8;
t180=(-1).*t10.*t11.*t4.*t8;
t181=t179 + t180;
t182=(-1).*t10.*t13.*t27.*t5.*t7;
t183=(-1).*t12.*t13.*t27.*t6.*t8;
t184=t10.*t11.*t14.*t27.*t8;
t185=t178.*t28;
t186=t181.*t27.*t29;
t187=(-1).*t10.*t13.*t28.*t29.*t8;
t188=t182 + t183 + t184 + t185 + t186 + t187;
t189=t10.*t13.*t28.*t5.*t7;
t190=t12.*t13.*t28.*t6.*t8;
t191=(-1).*t10.*t11.*t14.*t28.*t8;
t192=t178.*t27;
t193=(-1).*t10.*t13.*t27.*t29.*t8;
t194=(-1).*t181.*t28.*t29;
t195=t189 + t190 + t191 + t192 + t193 + t194;
t196=t10.*t13.*t27.*t8;
t197=t181.*t28;
t198=t196 + t197;
t199=t181.*t27;
t200=(-1).*t10.*t13.*t28.*t8;
t201=t199 + t200;
t202=t11.*t12.*t27.*t6;
t203=t12.*t13.*t28.*t4.*t6;
t204=t10.*t13.*t14.*t27;
t205=(-1).*t10.*t11.*t14.*t28.*t4;
t206=(-1).*t10.*t13.*t15.*t16.*t28;
t207=(-1).*t10.*t13.*t27.*t29.*t4;
t208=t10.*t11.*t28.*t29;
t209=t202 + t203 + t204 + t205 + t206 + t207 + t208;
t210=t12.*t13.*t27.*t4.*t6;
t211=(-1).*t11.*t12.*t28.*t6;
t212=(-1).*t10.*t11.*t14.*t27.*t4;
t213=(-1).*t10.*t13.*t14.*t28;
t214=(-1).*t10.*t13.*t15.*t16.*t27;
t215=t10.*t11.*t27.*t29;
t216=t10.*t13.*t28.*t29.*t4;
t217=t210 + t211 + t212 + t213 + t214 + t215 + t216;
t218=(-1).*t10.*t11.*t27;
t219=(-1).*t10.*t13.*t28.*t4;
t220=t218 + t219;
t221=(-1).*t10.*t13.*t27.*t4;
t222=t10.*t11.*t28;
t223=t221 + t222;
t224=(-1).*t11.*t6.*t7.*t8;
t225=t13.*t5.*t7;
t226=(-1).*t10.*t11.*t12.*t5;
t227=(-1).*t11.*t14.*t8;
t228=t13.*t14.*t5.*t6;
t229=t224 + t225 + t226 + t227 + t228;
t230=(-1).*t11.*t5.*t6;
t231=(-1).*t13.*t8;
t232=t230 + t231;
t233=t28.*t4.*t84;
t234=t229.*t27;
t235=t15.*t16.*t28.*t93;
t236=t27.*t29.*t4.*t93;
t237=(-1).*t232.*t28.*t29;
t238=t233 + t234 + t235 + t236 + t237;
t239=t27.*t4.*t84;
t240=(-1).*t229.*t28;
t241=t15.*t16.*t27.*t93;
t242=(-1).*t232.*t27.*t29;
t243=(-1).*t28.*t29.*t4.*t93;
t244=t239 + t240 + t241 + t242 + t243;
t245=t232.*t27;
t246=t28.*t4.*t93;
t247=t245 + t246;
t248=t27.*t4.*t93;
t249=(-1).*t232.*t28;
t250=t248 + t249;
t251=t11.*t7.*t8;
t252=(-1).*t13.*t5.*t6.*t7;
t253=t10.*t12.*t13.*t8;
t254=t11.*t14.*t6.*t8;
t255=(-1).*t13.*t14.*t5;
t256=t251 + t252 + t253 + t254 + t255;
t257=t11.*t5;
t258=t13.*t6.*t8;
t259=t257 + t258;
t260=t256.*t28.*t4;
t261=t23.*t27;
t262=t15.*t16.*t259.*t28;
t263=t259.*t27.*t29.*t4;
t264=(-1).*t26.*t28.*t29;
t265=t260 + t261 + t262 + t263 + t264;
t266=t256.*t27.*t4;
t267=(-1).*t23.*t28;
t268=t15.*t16.*t259.*t27;
t269=(-1).*t26.*t27.*t29;
t270=(-1).*t259.*t28.*t29.*t4;
t271=t266 + t267 + t268 + t269 + t270;
t272=t26.*t27;
t273=t259.*t28.*t4;
t274=t272 + t273;
t275=t259.*t27.*t4;
t276=(-1).*t26.*t28;
t277=t275 + t276;
t278=(-1).*t11.*t12.*t15.*t6;
t279=(-1).*t10.*t12.*t4;
t280=(-1).*t10.*t13.*t14.*t15;
t281=(-1).*t15.*t16.*t6;
t282=(-1).*t10.*t11.*t16.*t4;
t283=t278 + t279 + t280 + t281 + t282;
t284=t10.*t11.*t15;
t285=(-1).*t4.*t6;
t286=t284 + t285;
t287=t10.*t4.*t7.*t8;
t288=(-1).*t12.*t4.*t5.*t6;
t289=t15.*t73;
t290=t10.*t15.*t16.*t5;
t291=(-1).*t16.*t4.*t76;
t292=t287 + t288 + t289 + t290 + t291;
t293=t15.*t76;
t294=t10.*t4.*t5;
t295=t293 + t294;
t296=t11.*t5.*t6.*t7;
t297=t13.*t7.*t8;
t298=(-1).*t10.*t11.*t12.*t8;
t299=t11.*t14.*t5;
t300=t13.*t14.*t6.*t8;
t301=t296 + t297 + t298 + t299 + t300;
t302=(-1).*t11.*t6.*t8;
t303=t13.*t5;
t304=t302 + t303;
t305=t10.*t4.*t5.*t7;
t306=t12.*t4.*t6.*t8;
t307=t15.*t301;
t308=(-1).*t10.*t15.*t16.*t8;
t309=(-1).*t16.*t304.*t4;
t310=t305 + t306 + t307 + t308 + t309;
t311=t15.*t304;
t312=(-1).*t10.*t4.*t8;
t313=t311 + t312;
t314=t10.*t12.*t15;
t315=(-1).*t11.*t12.*t4.*t6;
t316=(-1).*t10.*t13.*t14.*t4;
t317=t10.*t11.*t15.*t16;
t318=(-1).*t16.*t4.*t6;
t319=t314 + t315 + t316 + t317 + t318;
t320=t15.*t6;
t321=t10.*t11.*t4;
t322=t320 + t321;
t323=(-1).*t12.*t13.*t27.*t6;
t324=t10.*t11.*t14.*t27;
t325=(-1).*t28.*t319;
t326=(-1).*t27.*t29.*t322;
t327=(-1).*t10.*t13.*t28.*t29;
t328=t323 + t324 + t325 + t326 + t327;
t329=(-1).*t12.*t13.*t28.*t6;
t330=t10.*t11.*t14.*t28;
t331=t27.*t319;
t332=t10.*t13.*t27.*t29;
t333=(-1).*t28.*t29.*t322;
t334=t329 + t330 + t331 + t332 + t333;
t335=t27.*t322;
t336=t10.*t13.*t28;
t337=t335 + t336;
t338=t10.*t13.*t27;
t339=(-1).*t28.*t322;
t340=t338 + t339;
t341=(-1).*t27.*t84;
t342=(-1).*t28.*t90;
t343=(-1).*t27.*t29.*t96;
t344=t28.*t29.*t93;
t345=t341 + t342 + t343 + t344;
t346=(-1).*t27.*t93;
t347=(-1).*t28.*t96;
t348=t346 + t347;
t349=(-1).*t10.*t15.*t5.*t7;
t350=(-1).*t12.*t15.*t6.*t8;
t351=t301.*t4;
t352=t15.*t16.*t304;
t353=(-1).*t10.*t16.*t4.*t8;
t354=t349 + t350 + t351 + t352 + t353;
t355=t10.*t15.*t8;
t356=t304.*t4;
t357=t355 + t356;
t358=(-1).*t256.*t27;
t359=(-1).*t28.*t354;
t360=(-1).*t27.*t29.*t357;
t361=t259.*t28.*t29;
t362=t358 + t359 + t360 + t361;
t363=(-1).*t256.*t28;
t364=t27.*t354;
t365=(-1).*t259.*t27.*t29;
t366=(-1).*t28.*t29.*t357;
t367=t363 + t364 + t365 + t366;
t368=t27.*t357;
t369=(-1).*t259.*t28;
t370=t368 + t369;
t371=(-1).*t259.*t27;
t372=(-1).*t28.*t357;
t373=t371 + t372;
t374=(2/5).*t334.*t50;
t375=(2/5).*t337.*t49.*t51;
t376=t12.*t13.*t27.*t6;
t377=(-1).*t10.*t11.*t14.*t27;
t378=t28.*t319;
t379=t27.*t29.*t322;
t380=t10.*t13.*t28.*t29;
t381=t376 + t377 + t378 + t379 + t380;
t382=(-1).*t334.*t50;
t383=(-1).*t337.*t49.*t51;
t384=(-1).*t10.*t13.*t27;
t385=t28.*t322;
t386=t384 + t385;
t387=(2/5).*t106.*t50;
t388=(2/5).*t112.*t49.*t51;
t389=(-1).*t106.*t50;
t390=(-1).*t112.*t49.*t51;
t391=(2/5).*t367.*t50;
t392=(2/5).*t370.*t49.*t51;
t393=t256.*t27;
t394=t28.*t354;
t395=t27.*t29.*t357;
t396=(-1).*t259.*t28.*t29;
t397=t393 + t394 + t395 + t396;
t398=(-1).*t367.*t50;
t399=(-1).*t370.*t49.*t51;
t400=t259.*t27;
t401=t28.*t357;
t402=t400 + t401;
x_dJp_RightFourBarConnect=[0,0,0,0,0,0,0,0,0,0,(2/5).*t50.*t56 + (2/5).*t49.*t51.*t64 + ( ...
  2/5).*t50.*t51.*t67 + 0.9.*((-1).*t50.*t56 + t49.*t61 + (-1).* ...
  t49.*t51.*t64 + (-1).*t50.*t51.*t67) + (2/5).*t61.*t78 + ( ...
  1831/10000).*(t15.*t23 + (-1).*t16.*t26.*t4 + (-1).*t10.*t4.*t5.* ...
  t7 + t10.*t15.*t16.*t8 + (-1).*t12.*t4.*t6.*t8),(1831/10000).* ...
  t292 + (2/5).*t101.*t50 + (2/5).*t109.*t49.*t51 + (2/5).*t112.* ...
  t50.*t51 + 0.9.*(t106.*t49 + (-1).*t101.*t50 + (-1).*t109.*t49.* ...
  t51 + (-1).*t112.*t50.*t51) + (2/5).*t106.*t78,(2/5).*t127.*t50 +  ...
  (2/5).*t136.*t49.*t51 + (2/5).*t139.*t50.*t51 + 0.9.*(t133.*t49 +  ...
  (-1).*t127.*t50 + (-1).*t136.*t49.*t51 + (-1).*t139.*t50.*t51) + ( ...
  1831/10000).*((-1).*t10.*t11.*t12.*t15 + (-1).*t10.*t15.*t16 +  ...
  t13.*t14.*t15.*t6 + t12.*t4.*t6 + t11.*t16.*t4.*t6) + (2/5).* ...
  t133.*t78,(2/5).*t157.*t50 + (2/5).*t167.*t49.*t51 + (2/5).*t170.* ...
  t50.*t51 + 0.9.*(t164.*t49 + (-1).*t157.*t50 + (-1).*t167.*t49.* ...
  t51 + (-1).*t170.*t50.*t51) + (2/5).*t164.*t78 + (1831/10000).*(( ...
  -1).*t10.*t13.*t14.*t15.*t5 + (-1).*t10.*t12.*t4.*t5 + (-1).*t10.* ...
  t11.*t16.*t4.*t5 + (-1).*t11.*t12.*t15.*t5.*t6 + (-1).*t15.*t16.* ...
  t5.*t6 + t10.*t11.*t15.*t7.*t8 + (-1).*t4.*t6.*t7.*t8),(2/5).* ...
  t188.*t50 + (2/5).*t198.*t49.*t51 + (2/5).*t201.*t50.*t51 + 0.9.*( ...
  t195.*t49 + (-1).*t188.*t50 + (-1).*t198.*t49.*t51 + (-1).*t201.* ...
  t50.*t51) + (2/5).*t195.*t78 + (1831/10000).*(t10.*t11.*t15.*t5.* ...
  t7 + (-1).*t4.*t5.*t6.*t7 + t10.*t13.*t14.*t15.*t8 + t10.*t12.* ...
  t4.*t8 + t10.*t11.*t16.*t4.*t8 + t11.*t12.*t15.*t6.*t8 + t15.* ...
  t16.*t6.*t8),(-1831/10000).*t10.*t11.*t14.*t15 + (1831/10000).* ...
  t10.*t13.*t16.*t4 + (2/5).*t209.*t50 + (2/5).*t220.*t49.*t51 + ( ...
  2/5).*t223.*t50.*t51 + 0.9.*(t217.*t49 + (-1).*t209.*t50 + (-1).* ...
  t220.*t49.*t51 + (-1).*t223.*t50.*t51) + (1831/10000).*t12.*t13.* ...
  t15.*t6 + (2/5).*t217.*t78,(2/5).*t238.*t50 + (2/5).*t247.*t49.* ...
  t51 + (2/5).*t250.*t50.*t51 + 0.9.*(t244.*t49 + (-1).*t238.*t50 +  ...
  (-1).*t247.*t49.*t51 + (-1).*t250.*t50.*t51) + (2/5).*t244.*t78 +  ...
  (1831/10000).*t15.*t84 + (-1831/10000).*t16.*t4.*t93,(1831/10000) ...
  .*t15.*t256 + (-1831/10000).*t16.*t259.*t4 + (2/5).*t265.*t50 + ( ...
  2/5).*t274.*t49.*t51 + (2/5).*t277.*t50.*t51 + 0.9.*(t271.*t49 + ( ...
  -1).*t265.*t50 + (-1).*t274.*t49.*t51 + (-1).*t277.*t50.*t51) + ( ...
  2/5).*t271.*t78,(2/5).*t28.*t283.*t50 + (2/5).*t27.*t286.*t29.* ...
  t50 + (2/5).*t28.*t286.*t49.*t51 + (2/5).*t27.*t286.*t50.*t51 +  ...
  0.9.*(t27.*t283.*t49 + (-1).*t28.*t286.*t29.*t49 + (-1).*t28.* ...
  t283.*t50 + (-1).*t27.*t286.*t29.*t50 + (-1).*t28.*t286.*t49.*t51  ...
  + (-1).*t27.*t286.*t50.*t51) + (1831/10000).*((-1).*t10.*t12.*t15  ...
  + (-1).*t10.*t11.*t15.*t16 + t10.*t13.*t14.*t4 + t11.*t12.*t4.*t6  ...
  + t16.*t4.*t6) + (2/5).*t27.*t283.*t78 + (-2/5).*t28.*t286.*t29.* ...
  t78,(2/5).*t28.*t292.*t50 + (2/5).*t27.*t29.*t295.*t50 + (2/5).* ...
  t28.*t295.*t49.*t51 + (2/5).*t27.*t295.*t50.*t51 + 0.9.*(t27.* ...
  t292.*t49 + (-1).*t28.*t29.*t295.*t49 + (-1).*t28.*t292.*t50 + ( ...
  -1).*t27.*t29.*t295.*t50 + (-1).*t28.*t295.*t49.*t51 + (-1).*t27.* ...
  t295.*t50.*t51) + (2/5).*t27.*t292.*t78 + (-2/5).*t28.*t29.*t295.* ...
  t78 + (1831/10000).*((-1).*t10.*t16.*t4.*t5 + (-1).*t12.*t15.*t5.* ...
  t6 + (-1).*t4.*t73 + (-1).*t15.*t16.*t76 + t10.*t15.*t7.*t8),( ...
  1831/10000).*((-1).*t15.*t16.*t304 + t37 + t38 + (-1).*t301.*t4 +  ...
  t41) + (2/5).*t28.*t310.*t50 + (2/5).*t27.*t29.*t313.*t50 + (2/5) ...
  .*t28.*t313.*t49.*t51 + (2/5).*t27.*t313.*t50.*t51 + 0.9.*(t27.* ...
  t310.*t49 + (-1).*t28.*t29.*t313.*t49 + (-1).*t28.*t310.*t50 + ( ...
  -1).*t27.*t29.*t313.*t50 + (-1).*t28.*t313.*t49.*t51 + (-1).*t27.* ...
  t313.*t50.*t51) + (2/5).*t27.*t310.*t78 + (-2/5).*t28.*t29.*t313.* ...
  t78,t374 + t375 + (2/5).*t340.*t50.*t51 + 0.9.*(t382 + t383 +  ...
  t328.*t49 + (-1).*t340.*t50.*t51) + (2/5).*t328.*t78,t387 + t388 + ...
   (2/5).*t348.*t50.*t51 + 0.9.*(t389 + t390 + t345.*t49 + (-1).* ...
  t348.*t50.*t51) + (2/5).*t345.*t78,t391 + t392 + (2/5).*t373.* ...
  t50.*t51 + 0.9.*(t398 + t399 + t362.*t49 + (-1).*t373.*t50.*t51) + ...
   (2/5).*t362.*t78,0,0,0,t374 + t375 + (2/5).*t381.*t49 + (-2/5).* ...
  t386.*t50.*t51 + 0.9.*(t382 + t383 + (-1).*t381.*t49 + t386.*t50.* ...
  t51),t387 + t388 + (2/5).*t101.*t49 + (-2/5).*t109.*t50.*t51 +  ...
  0.9.*(t389 + t390 + (-1).*t101.*t49 + t109.*t50.*t51),t391 + t392  ...
  + (2/5).*t397.*t49 + (-2/5).*t402.*t50.*t51 + 0.9.*(t398 + t399 +  ...
  (-1).*t397.*t49 + t402.*t50.*t51),0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, ...
  0,0];

end %function