function value = bezierm( afra, s )
[n, m] = size(afra);
p = length(s);
value=zeros(n,p);
M = m-1;
if M==3
    k=[1 3 3 1];
elseif M==4
    k=[1 4 6 4 1];
elseif M==5
    k=[1 5 10 10 5 1];
elseif M==6
    k=[1 6 15 20 15 6 1];
elseif M==7
    k = [1 7 21 35 35 21 7 1];
elseif M==8
    k = [1 8 28 56 70 56 28 8 1];
elseif M==9
    k = [1 9 36 84 126 126 84 36 9 1];
elseif M==20
    k = [ 1          20         190        1140        4845       15504       38760       77520      125970,...
      167960      184756      167960      125970       77520       38760       15504        4845        1140,...
         190          20           1];
else
    k = binom(M);
end
%%    
x = ones(M+1, p);
y = ones(M+1, p);
for i=1:M
    x(i+1,:)=s.*x(i,:);
    y(i+1,:)=(1-s).*y(i,:);
end
for i=1:n
   for j=1:M+1
      value(i,:) = value(i,:) + afra(i, j)*k(j)*x(j,:).*y(M+2-j,:);
   end
end


  