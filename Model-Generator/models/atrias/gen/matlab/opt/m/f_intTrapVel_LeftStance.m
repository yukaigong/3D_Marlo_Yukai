function out1 = f_intTrapVel_LeftStance(in1,N)
%F_INTTRAPVEL_LEFTSTANCE
%    OUT1 = F_INTTRAPVEL_LEFTSTANCE(IN1,N)

%    This function was generated by the Symbolic Math Toolbox version 7.0.
%    26-Jan-2017 22:33:23

T = in1(:,1);
ddq1_1 = in1(:,18);
ddq1_2 = in1(:,19);
ddq1_3 = in1(:,20);
ddq1_4 = in1(:,21);
ddq1_5 = in1(:,22);
ddq1_6 = in1(:,23);
ddq1_7 = in1(:,24);
ddq1_8 = in1(:,25);
ddq1_9 = in1(:,26);
ddq2_1 = in1(:,50);
ddq2_2 = in1(:,51);
ddq2_3 = in1(:,52);
ddq2_4 = in1(:,53);
ddq2_5 = in1(:,54);
ddq2_6 = in1(:,55);
ddq2_7 = in1(:,56);
ddq2_8 = in1(:,57);
ddq2_9 = in1(:,58);
ddq1_10 = in1(:,27);
ddq1_11 = in1(:,28);
ddq1_12 = in1(:,29);
ddq1_13 = in1(:,30);
ddq1_14 = in1(:,31);
ddq1_15 = in1(:,32);
ddq1_16 = in1(:,33);
ddq2_10 = in1(:,59);
ddq2_11 = in1(:,60);
ddq2_12 = in1(:,61);
ddq2_13 = in1(:,62);
ddq2_14 = in1(:,63);
ddq2_15 = in1(:,64);
ddq2_16 = in1(:,65);
dq1_1 = in1(:,2);
dq1_2 = in1(:,3);
dq1_3 = in1(:,4);
dq1_4 = in1(:,5);
dq1_5 = in1(:,6);
dq1_6 = in1(:,7);
dq1_7 = in1(:,8);
dq1_8 = in1(:,9);
dq1_9 = in1(:,10);
dq2_1 = in1(:,34);
dq2_2 = in1(:,35);
dq2_3 = in1(:,36);
dq2_4 = in1(:,37);
dq2_5 = in1(:,38);
dq2_6 = in1(:,39);
dq2_7 = in1(:,40);
dq2_8 = in1(:,41);
dq2_9 = in1(:,42);
dq1_10 = in1(:,11);
dq1_11 = in1(:,12);
dq1_12 = in1(:,13);
dq1_13 = in1(:,14);
dq1_14 = in1(:,15);
dq1_15 = in1(:,16);
dq1_16 = in1(:,17);
dq2_10 = in1(:,43);
dq2_11 = in1(:,44);
dq2_12 = in1(:,45);
dq2_13 = in1(:,46);
dq2_14 = in1(:,47);
dq2_15 = in1(:,48);
dq2_16 = in1(:,49);
t2 = N-1.0;
t3 = 1.0./t2;
out1 = [-dq1_1+dq2_1-T.*t3.*(ddq1_1+ddq2_1).*(1.0./2.0);-dq1_2+dq2_2-T.*t3.*(ddq1_2+ddq2_2).*(1.0./2.0);-dq1_3+dq2_3-T.*t3.*(ddq1_3+ddq2_3).*(1.0./2.0);-dq1_4+dq2_4-T.*t3.*(ddq1_4+ddq2_4).*(1.0./2.0);-dq1_5+dq2_5-T.*t3.*(ddq1_5+ddq2_5).*(1.0./2.0);-dq1_6+dq2_6-T.*t3.*(ddq1_6+ddq2_6).*(1.0./2.0);-dq1_7+dq2_7-T.*t3.*(ddq1_7+ddq2_7).*(1.0./2.0);-dq1_8+dq2_8-T.*t3.*(ddq1_8+ddq2_8).*(1.0./2.0);-dq1_9+dq2_9-T.*t3.*(ddq1_9+ddq2_9).*(1.0./2.0);-dq1_10+dq2_10-T.*t3.*(ddq1_10+ddq2_10).*(1.0./2.0);-dq1_11+dq2_11-T.*t3.*(ddq1_11+ddq2_11).*(1.0./2.0);-dq1_12+dq2_12-T.*t3.*(ddq1_12+ddq2_12).*(1.0./2.0);-dq1_13+dq2_13-T.*t3.*(ddq1_13+ddq2_13).*(1.0./2.0);-dq1_14+dq2_14-T.*t3.*(ddq1_14+ddq2_14).*(1.0./2.0);-dq1_15+dq2_15-T.*t3.*(ddq1_15+ddq2_15).*(1.0./2.0);-dq1_16+dq2_16-T.*t3.*(ddq1_16+ddq2_16).*(1.0./2.0)];
