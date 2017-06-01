load output.txt
T = output(:,1);
m = output(:,2);
m2 = output(:,3);
e = output(:,4);
e2 = output(:,5);

C = (e2-e.^2)./(T.^2);
X = (m2-m.^2)./T;
