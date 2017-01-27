function out1 = f_holConstrPosition_fourBar(in1)
%F_HOLCONSTRPOSITION_FOURBAR
%    OUT1 = F_HOLCONSTRPOSITION_FOURBAR(IN1)

%    This function was generated by the Symbolic Math Toolbox version 7.0.
%    27-Jan-2017 08:49:35

h1 = in1(:,17);
h2 = in1(:,18);
h3 = in1(:,19);
h4 = in1(:,20);
q8 = in1(:,8);
q9 = in1(:,9);
q10 = in1(:,10);
q11 = in1(:,11);
q13 = in1(:,13);
q14 = in1(:,14);
q15 = in1(:,15);
q16 = in1(:,16);
out1 = [-h1+q8-q9+q10;-h2-q8+q9+q11;-h3+q13-q14+q15;-h4-q13+q14+q16];