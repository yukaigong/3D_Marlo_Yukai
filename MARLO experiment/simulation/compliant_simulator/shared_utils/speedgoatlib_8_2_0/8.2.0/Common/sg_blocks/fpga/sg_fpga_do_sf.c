/* Copyright 2006-2013 Speedgoat GmbH. */
#define 	S_FUNCTION_LEVEL 	(0x123+8187-0x211c)
#undef 		S_FUNCTION_NAME
#define 	S_FUNCTION_NAME 	sg_fpga_do_sf
#include 	<stddef.h>
#include 	<stdlib.h>
#include 	"simstruc.h" 
#ifdef 		MATLAB_MEX_FILE
#include 	"mex.h"
#endif
#ifndef         MATLAB_MEX_FILE
#include        <windows.h>
#include        "io_xpcimport.h"
#include        "pci_xpcimport.h"
#include        "time_xpcimport.h"
#include        "ioext_xpcimport.h"
#include        "util_xpcimport.h"
#endif
#define zdf24515981          ((0xd6+1935-0x860))
#define z533b11d03f           ssGetSFcnParam(S,(0xb76+5080-0x1f4e))
#define z2cc9a52544            ssGetSFcnParam(S,(0xe71+5362-0x2362))
#define ze072c43310               ssGetSFcnParam(S,(0x1476+1208-0x192c))
#define z3832b85a32           ssGetSFcnParam(S,(0x6b0+7276-0x2319))
#define z702a26a5e9                ssGetSFcnParam(S,(0x1e5+488-0x3c9))
#define z2e6483d505              ((0x7a5+4362-0x18ad))
#define z6a0da049de         ((0x70a+6561-0x20ab))
#define zc2f3e0cbc0        ((0x1858+1173-0x1cec))
#define zc5ce4cb81a              ((0x8c4+7332-0x2568))
#define z2b17e2ee3b              ((0xa55+3590-0x185b))
#define THRESHOLD               0.5
static char_T zea4cd01646[(0x98a+6294-0x2120)];static void mdlInitializeSizes(SimStruct*S){uint16_T i;uint16_T z5c3a9b25b9;uint32_T z78caf1ba61;
#ifndef MATLAB_MEX_FILE
#include "io_xpcimport.c"
#include "pci_xpcimport.c"
#include "time_xpcimport.c"
#include "util_xpcimport.c"
#endif
ssSetNumSFcnParams(S,zdf24515981);if(ssGetNumSFcnParams(S)!=ssGetSFcnParamsCount(S)){sprintf(zea4cd01646,"\x57\x72\x6f\x6e\x67\x20\x6e\x75\x6d\x62\x65\x72\x20\x6f\x66\x20\x69\x6e\x70\x75\x74\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x70\x61\x73\x73\x65\x64\x2e" "\n" "\x25\x64\x20\x61\x72\x67\x75\x6d\x65\x6e\x74\x73\x20\x61\x72\x65\x20\x65\x78\x70\x65\x63\x74\x65\x64" "\n",zdf24515981);ssSetErrorStatus(S,zea4cd01646);return;}ssSetNumContStates(S,(0x113c+1758-0x181a));ssSetNumDiscStates(S,(0xcc2+4395-0x1ded));ssSetNumOutputPorts(S,(0x127d+2841-0x1d96));z78caf1ba61=(uint32_T)mxGetPr(z533b11d03f)[(0x1aa1+828-0x1ddd)];if(z78caf1ba61==(0x59d+6232-0x1cc8)||z78caf1ba61==(0x536+8676-0x25e3)||z78caf1ba61==(0x5cd+6794-0x1f16)){if((int_T)mxGetPr(ze072c43310)[(0x450+1178-0x8ea)]==(0x1979+1319-0x1e9f)){z5c3a9b25b9=(0x5cc+5999-0x1d1b);}else{z5c3a9b25b9=(0x7f+5179-0x149a);}switch((uint8_T)mxGetPr(z2cc9a52544)[(0x197c+1970-0x212e)]){case(0x66b+667-0x905):ssSetNumInputPorts(S,z5c3a9b25b9);for(i=(0x1093+5426-0x25c5);i<z5c3a9b25b9;i++){ssSetInputPortWidth(S,i,(0x810+554-0xa39));ssSetInputPortRequiredContiguous(S,i,(0xf37+2644-0x198a));ssSetInputPortDirectFeedThrough(S,i,(0xcb1+3772-0x1b6c));}break;case(0x3f9+4505-0x1590):ssSetNumInputPorts(S,z5c3a9b25b9);for(i=(0x11e9+625-0x145a);i<z5c3a9b25b9;i++){ssSetInputPortWidth(S,i,(0x4bf+2369-0xdff));ssSetInputPortDataType(S,i,SS_BOOLEAN);ssSetInputPortRequiredContiguous(S,i,(0x5c7+3659-0x1411));ssSetInputPortDirectFeedThrough(S,i,(0xb9d+1069-0xfc9));}break;case(0xc27+5278-0x20c2):ssSetNumInputPorts(S,(0xc4c+5122-0x204d));ssSetInputPortWidth(S,(0xb36+4555-0x1d01),z5c3a9b25b9);ssSetInputPortRequiredContiguous(S,(0x677+3422-0x13d5),(0x1a4+4666-0x13dd));ssSetInputPortDirectFeedThrough(S,(0x12b2+1470-0x1870),(0x133f+1171-0x17d1));break;case(0x12aa+286-0x13c4):ssSetNumInputPorts(S,(0x167+8851-0x23f9));ssSetInputPortWidth(S,(0x5e0+4586-0x17ca),z5c3a9b25b9);ssSetInputPortDataType(S,(0xc81+5652-0x2295),SS_BOOLEAN);ssSetInputPortRequiredContiguous(S,(0x280+6063-0x1a2f),(0x22d1+544-0x24f0));ssSetInputPortDirectFeedThrough(S,(0x182b+88-0x1883),(0xfea+714-0x12b3));break;case(0x1ba+4339-0x12a8):ssSetNumInputPorts(S,(0x1b93+1844-0x22c6));ssSetInputPortWidth(S,(0x5a+6121-0x1843),(0x4d1+2833-0xfe1));ssSetInputPortDataType(S,(0x111d+1111-0x1574),SS_UINT32);ssSetInputPortRequiredContiguous(S,(0x7a8+1751-0xe7f),(0x11+8293-0x2075));ssSetInputPortDirectFeedThrough(S,(0x202b+808-0x2353),(0x9d0+6254-0x223d));break;}}if(z78caf1ba61==(0x20a2+1441-0x2514)||z78caf1ba61==(0x1a31+326-0x1a3e)){if((int_T)mxGetPr(ze072c43310)[(0x5ac+1048-0x9c4)]==(0x3cf+1495-0x9a5)){z5c3a9b25b9=(0x1471+2811-0x1f5c);}else{z5c3a9b25b9=(0x6c5+1470-0xc6b);}switch((uint8_T)mxGetPr(z2cc9a52544)[(0x585+3536-0x1355)]){case(0x1ca+1599-0x808):ssSetNumInputPorts(S,z5c3a9b25b9);for(i=(0xf6c+597-0x11c1);i<z5c3a9b25b9;i++){ssSetInputPortWidth(S,i,(0x24d7+480-0x26b6));ssSetInputPortRequiredContiguous(S,i,(0x1746+375-0x18bc));}break;case(0x18c1+308-0x19f3):ssSetNumInputPorts(S,z5c3a9b25b9);for(i=(0x15c9+1749-0x1c9e);i<z5c3a9b25b9;i++){ssSetInputPortWidth(S,i,(0x4ea+4107-0x14f4));ssSetInputPortDataType(S,i,SS_BOOLEAN);ssSetInputPortRequiredContiguous(S,i,(0x2069+691-0x231b));}break;case(0x698+4415-0x17d4):ssSetNumInputPorts(S,(0x40a+7488-0x2149));ssSetInputPortWidth(S,(0x106+8595-0x2299),z5c3a9b25b9);ssSetInputPortRequiredContiguous(S,(0xde6+6151-0x25ed),(0x97a+5465-0x1ed2));break;case(0x33f+3461-0x10c0):ssSetNumInputPorts(S,(0x1a0b+3164-0x2666));ssSetInputPortWidth(S,(0x866+1014-0xc5c),z5c3a9b25b9);ssSetInputPortDataType(S,(0x3c9+4768-0x1669),SS_BOOLEAN);ssSetInputPortRequiredContiguous(S,(0x2468+408-0x2600),(0x1ac+1036-0x5b7));break;case(0x151f+2545-0x1f0b):ssSetNumInputPorts(S,(0xdd1+4682-0x201a));ssSetInputPortWidth(S,(0x198+2943-0xd17),(0xcff+3211-0x1989));ssSetInputPortDataType(S,(0x763+1415-0xcea),SS_UINT32);ssSetInputPortRequiredContiguous(S,(0xa1+6020-0x1825),(0x77f+7537-0x24ef));break;}}if(z78caf1ba61==(0x221f+726-0x23c5)||z78caf1ba61==(0xb88+1848-0x1186)||z78caf1ba61==(0x2c2+1542-0x79a)||z78caf1ba61==(0xe22+1448-0x1292)){if((int_T)mxGetPr(ze072c43310)
[(0x1433+3177-0x209c)]==(0xa46+6634-0x242f)){z5c3a9b25b9=(0x1804+2853-0x2309);}else{z5c3a9b25b9=(0xf3+5390-0x15e1);}switch((uint8_T)mxGetPr(z2cc9a52544)[(0x3d3+2341-0xcf8)]){case(0x16f3+1458-0x1ca4):ssSetNumInputPorts(S,z5c3a9b25b9);for(i=(0x993+6840-0x244b);i<z5c3a9b25b9;i++){ssSetInputPortWidth(S,i,(0xad+4352-0x11ac));ssSetInputPortRequiredContiguous(S,i,(0x16ea+2498-0x20ab));}break;case(0x1921+3273-0x25e8):ssSetNumInputPorts(S,z5c3a9b25b9);for(i=(0x2055+641-0x22d6);i<z5c3a9b25b9;i++){ssSetInputPortWidth(S,i,(0x245+7829-0x20d9));ssSetInputPortDataType(S,i,SS_BOOLEAN);ssSetInputPortRequiredContiguous(S,i,(0x97f+5656-0x1f96));}break;case(0x10ef+3735-0x1f83):ssSetNumInputPorts(S,(0x194c+2045-0x2148));ssSetInputPortWidth(S,(0x1090+3406-0x1dde),z5c3a9b25b9);ssSetInputPortRequiredContiguous(S,(0xdb3+1939-0x1546),(0xdbd+1226-0x1286));break;case(0x1837+3026-0x2405):ssSetNumInputPorts(S,(0x71f+5942-0x1e54));ssSetInputPortWidth(S,(0x15e1+4264-0x2689),z5c3a9b25b9);ssSetInputPortDataType(S,(0x12d+6368-0x1a0d),SS_BOOLEAN);ssSetInputPortRequiredContiguous(S,(0x22e0+451-0x24a3),(0x2477+286-0x2594));break;case(0x43a+5387-0x1940):ssSetNumInputPorts(S,(0x32c+5135-0x173a));ssSetInputPortWidth(S,(0x221+59-0x25c),(0x392+7783-0x21f8));ssSetInputPortDataType(S,(0xe76+1457-0x1427),SS_UINT32);ssSetInputPortRequiredContiguous(S,(0x6d9+1167-0xb68),(0x2f+1319-0x555));break;}}ssSetNumSampleTimes(S,(0x236+4196-0x1299));ssSetNumRWork(S,zc5ce4cb81a);ssSetNumIWork(S,z2e6483d505);ssSetNumPWork(S,z2b17e2ee3b);ssSetNumModes(S,(0x8b8+5757-0x1f35));ssSetNumNonsampledZCs(S,(0x1298+3817-0x2181));for(i=(0xe47+4583-0x202e);i<zdf24515981;i++){ssSetSFcnParamTunable(S,i,(0x1457+3859-0x236a));}ssSetOptions(S,SS_OPTION_EXCEPTION_FREE_CODE|SS_OPTION_PLACE_ASAP);}static void mdlInitializeSampleTimes(SimStruct*S){if(mxGetPr(z3832b85a32)[(0xa16+6713-0x244f)]==-1.0){ssSetSampleTime(S,(0x1997+2415-0x2306),INHERITED_SAMPLE_TIME);ssSetOffsetTime(S,(0x313+120-0x38b),FIXED_IN_MINOR_STEP_OFFSET);}else{ssSetSampleTime(S,(0x70c+2685-0x1189),mxGetPr(z3832b85a32)[(0x1093+5605-0x2678)]);ssSetOffsetTime(S,(0x41f+6932-0x1f33),0.0);}}
#define MDL_START
static void mdlStart(SimStruct*S){
#ifndef MATLAB_MEX_FILE
PCIDeviceInfo zeccbadd9b3;void*zef529fae4a;void*ze2370ae9b9;volatile uint32_T*z3e5b8e05d8;void*zdfcb1da404;void*zf2db5722bf;volatile uint32_T*z27fd94ac66;uint_T i;uint32_T out;uint8_T z16ba527520[(0xf13+2822-0x1a05)];uint16_T z6f813cde47,za4a2434e08;uint32_T z78caf1ba61;z78caf1ba61=(uint32_T)mxGetPr(z533b11d03f)[(0xb28+5847-0x21ff)];switch(z78caf1ba61){case(0x670+2485-0xef8):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x30\x31");z6f813cde47=(0x200c+4510-0x1ad5);za4a2434e08=17232;break;case(0x7d4+3359-0x13c5):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x30\x32");z6f813cde47=5845;za4a2434e08=17239;break;case(0x1c12+1377-0x2044):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x30\x33");z6f813cde47=(0x16f6+8708-0x2225);za4a2434e08=16979;break;case(0x18e8+3185-0x2429):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x30\x34");z6f813cde47=(0x1a46+5237-0x17e6);za4a2434e08=(0xb91+2467-0x1030);break;case(0x433+3126-0xf32):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x31\x31");z6f813cde47=(0x1ebb+2072-0xffe);za4a2434e08=21069;break;case(0x1c1a+2392-0x243a):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x31\x32");z6f813cde47=(0x1df1+3490-0x14be);za4a2434e08=16971;break;case(0xcc3+819-0xebd):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x31\x33");z6f813cde47=(0x1c98+1286-0xac9);za4a2434e08=17235;break;case(0xfbd+3090-0x1a95):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x31\x34");z6f813cde47=(0x19d9+6149-0x1b09);za4a2434e08=8196;break;case(0x165c+635-0x1796):strcpy(z16ba527520,"\x53\x70\x65\x65\x64\x67\x6f\x61\x74\x20\x49\x4f\x33\x32\x31");z6f813cde47=5845;za4a2434e08=19520;break;}if((int_T)mxGetPr(z702a26a5e9)[(0x929+7260-0x2585)]<(0x801+4814-0x1acf)){if(rl32eGetPCIInfo(z6f813cde47,za4a2434e08,&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",z16ba527520);ssSetErrorStatus(S,zea4cd01646);return;}}else{uint16_T z366b2f03bf,z441f9e6d1b;if(mxGetN(z702a26a5e9)==(0x197d+2071-0x2193)){z366b2f03bf=(0xaf9+1289-0x1002);z441f9e6d1b=(uint16_T)mxGetPr(z702a26a5e9)[(0x1341+2173-0x1bbe)];}else{z366b2f03bf=(uint16_T)mxGetPr(z702a26a5e9)[(0x59+2187-0x8e4)];z441f9e6d1b=(uint16_T)mxGetPr(z702a26a5e9)[(0x205d+1234-0x252e)];}if(rl32eGetPCIInfoAtSlot(z6f813cde47,za4a2434e08,(z441f9e6d1b&(0x959+5888-0x1f5a))|((z366b2f03bf&(0x1864+3611-0x2580))<<(0x101d+3981-0x1fa2)),&zeccbadd9b3)){sprintf(zea4cd01646,"\x25\x73\x20\x28\x62\x75\x73\x20\x25\x64\x2c\x20\x73\x6c\x6f\x74\x20\x25\x64\x29\x3a\x20\x62\x6f\x61\x72\x64\x20\x6e\x6f\x74\x20\x70\x72\x65\x73\x65\x6e\x74",z16ba527520,z366b2f03bf,z441f9e6d1b);ssSetErrorStatus(S,zea4cd01646);return;}}

zef529fae4a=(void*)zeccbadd9b3.BaseAddress[(0x17b0+1944-0x1f46)];ze2370ae9b9=rl32eGetDevicePtr(zef529fae4a,2097152,RT_PG_USERREADWRITE);z3e5b8e05d8=(volatile uint32_T*)ze2370ae9b9;
ssSetIWorkValue(S,z6a0da049de,(uint32_T)z3e5b8e05d8);
#endif
}static void mdlOutputs(SimStruct*S,int_T z27c0327a06){
#ifndef MATLAB_MEX_FILE
uint32_T base=ssGetIWorkValue(S,z6a0da049de);volatile uint32_T*z3e5b8e05d8;uint32_T i,output;real_T*y1;boolean_T*y2;uint32_T*z671e76e748;uint16_T z5c3a9b25b9;uint32_T z78caf1ba61;z3e5b8e05d8=(void*)base;z78caf1ba61=(uint32_T)mxGetPr(z533b11d03f)[(0x20c+2102-0xa42)];if(z78caf1ba61==(0x789+6643-0x204f)||z78caf1ba61==(0x2d9+6481-0x1af3)){if((int_T)mxGetPr(ze072c43310)[(0x10cd+1930-0x1857)]==(0x1878+3435-0x25e2)){z5c3a9b25b9=(0x2197+1288-0x267f);}else{z5c3a9b25b9=(0xefc+2466-0x187e);}switch((uint8_T)mxGetPr(z2cc9a52544)[(0x1a4b+956-0x1e07)]){case(0x1578+3695-0x23e6):output=(0x7f+157-0x11c);for(i=(0x1dc1+1186-0x2263);i<z5c3a9b25b9;i++){y1=(real_T*)ssGetInputPortSignal(S,i);if(y1[(0xcf2+5716-0x2346)]>=THRESHOLD){output|=(0x77a+1724-0xe35)<<i;}}break;case(0x15da+2464-0x1f78):output=(0xd71+5020-0x210d);for(i=(0x253+2289-0xb44);i<z5c3a9b25b9;i++){y2=(boolean_T*)ssGetInputPortSignal(S,i);if(y2[(0x4e3+1528-0xadb)]){output|=(0x1777+2120-0x1fbe)<<i;}}break;case(0x1148+2125-0x1992):output=(0x9a9+7087-0x2558);y1=(real_T*)ssGetInputPortSignal(S,(0xa51+736-0xd31));for(i=(0x1a6c+3091-0x267f);i<z5c3a9b25b9;i++){if(y1[i]>=THRESHOLD){output|=(0x1239+2544-0x1c28)<<i;}}break;case(0x830+7383-0x2503):output=(0xb29+783-0xe38);y2=(boolean_T*)ssGetInputPortSignal(S,(0xba+2297-0x9b3));for(i=(0x7e3+5078-0x1bb9);i<z5c3a9b25b9;i++){if(y2[i]){output|=(0x1fbf+524-0x21ca)<<i;}}break;case(0x487+3401-0x11cb):z671e76e748=(uint32_T*)ssGetInputPortSignal(S,(0x1256+3968-0x21d6));output=z671e76e748[(0x15bd+1667-0x1c40)];break;}if(((uint8_T)mxGetPr(ze072c43310)[(0xe70+5441-0x23b1)])==(0x363+4751-0x15f1)){z3e5b8e05d8[8194]=output;}else{z3e5b8e05d8[8195]=output;}}if(z78caf1ba61==(0x155+7074-0x1bc8)||z78caf1ba61==(0x1207+206-0x119c)){if((int_T)mxGetPr(ze072c43310)[(0x5bf+5341-0x1a9c)]==(0x9d5+3239-0x167b)){z5c3a9b25b9=(0x3ec+4742-0x1662);}else{z5c3a9b25b9=(0x1625+1123-0x1a70);}switch((uint8_T)mxGetPr(z2cc9a52544)[(0x2c1+3969-0x1242)]){case(0x363+7117-0x1f2f):output=(0x22d+3429-0xf92);for(i=(0x1cff+1228-0x21cb);i<z5c3a9b25b9;i++){y1=(real_T*)ssGetInputPortSignal(S,i);if(y1[(0x132f+4812-0x25fb)]>=THRESHOLD){output|=(0x49b+1228-0x966)<<i;}}break;case(0x1306+2517-0x1cd9):output=(0xcaa+4678-0x1ef0);for(i=(0x1015+598-0x126b);i<z5c3a9b25b9;i++){y2=(boolean_T*)ssGetInputPortSignal(S,i);if(y2[(0x126c+2310-0x1b72)]){output|=(0x47+1131-0x4b1)<<i;}}break;case(0xbb+1809-0x7c9):output=(0x16a4+2355-0x1fd7);y1=(real_T*)ssGetInputPortSignal(S,(0x165d+27-0x1678));for(i=(0x67a+1483-0xc45);i<z5c3a9b25b9;i++){if(y1[i]>=THRESHOLD){output|=(0x11f9+2368-0x1b38)<<i;}}break;case(0x4c9+3380-0x11f9):output=(0x1a4+6555-0x1b3f);y2=(boolean_T*)ssGetInputPortSignal(S,(0x11fd+2223-0x1aac));for(i=(0xf+8786-0x2261);i<z5c3a9b25b9;i++){if(y2[i]){output|=(0x318+1982-0xad5)<<i;}}break;case(0x15f9+612-0x1858):z671e76e748=(uint32_T*)ssGetInputPortSignal(S,(0x1be7+1484-0x21b3));output=z671e76e748[(0x1746+2557-0x2143)];break;}if(((uint8_T)mxGetPr(ze072c43310)[(0x9c3+2163-0x1236)])==(0xc0+6-0xc5)){z3e5b8e05d8[8194]=output;}else{z3e5b8e05d8[(0x249c+1423-0xa28)]=output;}

}if(z78caf1ba61==(0x8da+2927-0x1319)||z78caf1ba61==(0xa3f+2211-0x11a8)||z78caf1ba61==(0x38c+5276-0x16fa)||z78caf1ba61==(0x1871+368-0x18a9)){if((int_T)mxGetPr(ze072c43310)[(0xa50+581-0xc95)]==(0xb1+1993-0x879)){z5c3a9b25b9=(0x8ed+3567-0x16bc);}else{z5c3a9b25b9=(0x32a+2184-0xb92);}switch((uint8_T)mxGetPr(z2cc9a52544)[(0x1167+2411-0x1ad2)]){case(0x114c+1626-0x17a5):output=(0x22a+9435-0x2705);for(i=(0x536+3326-0x1234);i<z5c3a9b25b9;i++){y1=(real_T*)ssGetInputPortSignal(S,i);if(y1[(0x150b+2227-0x1dbe)]>=THRESHOLD){output|=(0xcbc+950-0x1071)<<i;}}break;case(0x63a+374-0x7ae):output=(0x10a0+4370-0x21b2);for(i=(0x8df+6376-0x21c7);i<z5c3a9b25b9;i++){y2=(boolean_T*)ssGetInputPortSignal(S,i);if(y2[(0xff9+2239-0x18b8)]){output|=(0x10a3+4081-0x2093)<<i;}}break;case(0x805+7304-0x248a):output=(0x1776+2217-0x201f);y1=(real_T*)ssGetInputPortSignal(S,(0x10bf+866-0x1421));for(i=(0x1521+3215-0x21b0);i<z5c3a9b25b9;i++){if(y1[i]>=THRESHOLD){output|=(0x8c9+6556-0x2264)<<i;}}break;case(0xd53+2469-0x16f4):output=(0x31f+2994-0xed1);y2=(boolean_T*)ssGetInputPortSignal(S,(0xb02+1751-0x11d9));for(i=(0xa48+2167-0x12bf);i<z5c3a9b25b9;i++){if(y2[i]){output|=(0xa30+1241-0xf08)<<i;}}break;case(0x20a0+174-0x2149):z671e76e748=(uint32_T*)ssGetInputPortSignal(S,(0x1b43+2700-0x25cf));output=z671e76e748[(0x92b+4964-0x1c8f)];break;}if(((uint8_T)mxGetPr(ze072c43310)[(0x7+4084-0xffb)])==(0x11f5+1320-0x171c)){z3e5b8e05d8[8194]=output;}else{z3e5b8e05d8[8194]=output;}}if(z78caf1ba61==(0xff3+3148-0x1afe)){if((int_T)mxGetPr(ze072c43310)[(0x1a0f+3079-0x2616)]==(0x16a2+1073-0x1ad2)){z5c3a9b25b9=(0x112a+4722-0x237c);}else{z5c3a9b25b9=(0x7d6+5130-0x1bc0);}switch((uint8_T)mxGetPr(z2cc9a52544)[(0x5b1+6474-0x1efb)]){case(0xf23+5732-0x2586):output=(0x3e3+1556-0x9f7);for(i=(0x354+4851-0x1647);i<z5c3a9b25b9;i++){y1=(real_T*)ssGetInputPortSignal(S,i);if(y1[(0x49d+3238-0x1143)]>=THRESHOLD){output|=(0x1acd+3126-0x2702)<<i;}}break;case(0x175f+3693-0x25ca):output=(0x533+1325-0xa60);for(i=(0x1e0+7277-0x1e4d);i<z5c3a9b25b9;i++){y2=(boolean_T*)ssGetInputPortSignal(S,i);if(y2[(0xcb5+3013-0x187a)]){output|=(0x1685+3289-0x235d)<<i;}}break;case(0x19f3+1457-0x1fa1):output=(0xb83+3396-0x18c7);y1=(real_T*)ssGetInputPortSignal(S,(0x1981+1822-0x209f));for(i=(0x788+6876-0x2264);i<z5c3a9b25b9;i++){if(y1[i]>=THRESHOLD){output|=(0xb7a+3197-0x17f6)<<i;}}break;case(0xc4b+1580-0x1273):output=(0x1880+2826-0x238a);y2=(boolean_T*)ssGetInputPortSignal(S,(0x104b+1211-0x1506));for(i=(0x1018+2089-0x1841);i<z5c3a9b25b9;i++){if(y2[i]){output|=(0xb06+95-0xb64)<<i;}}break;case(0x12d8+2760-0x1d9b):z671e76e748=(uint32_T*)ssGetInputPortSignal(S,(0x776+4773-0x1a1b));output=z671e76e748[(0x1256+996-0x163a)];break;}if(((uint8_T)mxGetPr(ze072c43310)[(0x1562+2818-0x2064)])==(0x8f2+1485-0xebe)){z3e5b8e05d8[9600]=output;}else{z3e5b8e05d8[9601]=output;}}
#endif
}static void mdlTerminate(SimStruct*S){}
#ifdef MATLAB_MEX_FILE  
#include "simulink.c"   
#else
#include "cg_sfun.h"    
#endif

