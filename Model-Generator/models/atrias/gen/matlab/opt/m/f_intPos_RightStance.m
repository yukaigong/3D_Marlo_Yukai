function out1 = f_intPos_RightStance(in1,N)
%F_INTPOS_RIGHTSTANCE
%    OUT1 = F_INTPOS_RIGHTSTANCE(IN1,N)

%    This function was generated by the Symbolic Math Toolbox version 7.0.
%    26-Jan-2017 22:32:12

T = in1(:,1);
dq1_1 = in1(:,18);
dq1_2 = in1(:,19);
dq1_3 = in1(:,20);
dq1_4 = in1(:,21);
dq1_5 = in1(:,22);
dq1_6 = in1(:,23);
dq1_7 = in1(:,24);
dq1_8 = in1(:,25);
dq1_9 = in1(:,26);
dq2_1 = in1(:,34);
dq2_2 = in1(:,35);
dq2_3 = in1(:,36);
dq2_4 = in1(:,37);
dq2_5 = in1(:,38);
dq2_6 = in1(:,39);
dq2_7 = in1(:,40);
dq2_8 = in1(:,41);
dq2_9 = in1(:,42);
dq3_1 = in1(:,66);
dq3_2 = in1(:,67);
dq3_3 = in1(:,68);
dq3_4 = in1(:,69);
dq3_5 = in1(:,70);
dq3_6 = in1(:,71);
dq3_7 = in1(:,72);
dq3_8 = in1(:,73);
dq3_9 = in1(:,74);
dq1_10 = in1(:,27);
dq1_11 = in1(:,28);
dq1_12 = in1(:,29);
dq1_13 = in1(:,30);
dq1_14 = in1(:,31);
dq1_15 = in1(:,32);
dq1_16 = in1(:,33);
dq2_10 = in1(:,43);
dq2_11 = in1(:,44);
dq2_12 = in1(:,45);
dq2_13 = in1(:,46);
dq2_14 = in1(:,47);
dq2_15 = in1(:,48);
dq2_16 = in1(:,49);
dq3_10 = in1(:,75);
dq3_11 = in1(:,76);
dq3_12 = in1(:,77);
dq3_13 = in1(:,78);
dq3_14 = in1(:,79);
dq3_15 = in1(:,80);
dq3_16 = in1(:,81);
q1_1 = in1(:,2);
q1_2 = in1(:,3);
q1_3 = in1(:,4);
q1_4 = in1(:,5);
q1_5 = in1(:,6);
q1_6 = in1(:,7);
q1_7 = in1(:,8);
q1_8 = in1(:,9);
q1_9 = in1(:,10);
q3_1 = in1(:,50);
q3_2 = in1(:,51);
q3_3 = in1(:,52);
q3_4 = in1(:,53);
q3_5 = in1(:,54);
q3_6 = in1(:,55);
q3_7 = in1(:,56);
q3_8 = in1(:,57);
q3_9 = in1(:,58);
q1_10 = in1(:,11);
q1_11 = in1(:,12);
q1_12 = in1(:,13);
q1_13 = in1(:,14);
q1_14 = in1(:,15);
q1_15 = in1(:,16);
q1_16 = in1(:,17);
q3_10 = in1(:,59);
q3_11 = in1(:,60);
q3_12 = in1(:,61);
q3_13 = in1(:,62);
q3_14 = in1(:,63);
q3_15 = in1(:,64);
q3_16 = in1(:,65);
t2 = N-1.0;
t3 = 1.0./t2;
out1 = [-q1_1+q3_1-T.*t3.*(dq1_1+dq2_1.*4.0+dq3_1).*(1.0./6.0);-q1_2+q3_2-T.*t3.*(dq1_2+dq2_2.*4.0+dq3_2).*(1.0./6.0);-q1_3+q3_3-T.*t3.*(dq1_3+dq2_3.*4.0+dq3_3).*(1.0./6.0);-q1_4+q3_4-T.*t3.*(dq1_4+dq2_4.*4.0+dq3_4).*(1.0./6.0);-q1_5+q3_5-T.*t3.*(dq1_5+dq2_5.*4.0+dq3_5).*(1.0./6.0);-q1_6+q3_6-T.*t3.*(dq1_6+dq2_6.*4.0+dq3_6).*(1.0./6.0);-q1_7+q3_7-T.*t3.*(dq1_7+dq2_7.*4.0+dq3_7).*(1.0./6.0);-q1_8+q3_8-T.*t3.*(dq1_8+dq2_8.*4.0+dq3_8).*(1.0./6.0);-q1_9+q3_9-T.*t3.*(dq1_9+dq2_9.*4.0+dq3_9).*(1.0./6.0);-q1_10+q3_10-T.*t3.*(dq1_10+dq2_10.*4.0+dq3_10).*(1.0./6.0);-q1_11+q3_11-T.*t3.*(dq1_11+dq2_11.*4.0+dq3_11).*(1.0./6.0);-q1_12+q3_12-T.*t3.*(dq1_12+dq2_12.*4.0+dq3_12).*(1.0./6.0);-q1_13+q3_13-T.*t3.*(dq1_13+dq2_13.*4.0+dq3_13).*(1.0./6.0);-q1_14+q3_14-T.*t3.*(dq1_14+dq2_14.*4.0+dq3_14).*(1.0./6.0);-q1_15+q3_15-T.*t3.*(dq1_15+dq2_15.*4.0+dq3_15).*(1.0./6.0);-q1_16+q3_16-T.*t3.*(dq1_16+dq2_16.*4.0+dq3_16).*(1.0./6.0)];
