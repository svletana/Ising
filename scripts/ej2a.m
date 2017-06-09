load outputej2a.txt
m = outputej2a(:,1);
e = outputej2a(:,2);
e = e./1024;

% para plotear no considero la parte de termalización

newe = e(4000:end);
newm = m(4000:end);
e2 = newe.^2;
m2 = newm.^2;
T = 0.5;

C = 1024*(mean(e2) - mean(newe)^2)/(T^2);
trueC = 4*(sech(2))^2;

X = 1024*(mean(m2)-mean(newm)^2)/T;
trueX = 2*(sech(2))^2;

plot(e,'.b')
hold on
plot(m,'.r')
h = legend({'energia'},'magnetizacion')
set(h,'fontsize',15)
legend(h,'location','east')
legend('boxoff')

L = [0:100:10000];
Y = repmat(tanh(2),length(L));

plot(L,Y,'.k','markersize',7)
plot(L,-Y,'.k','markersize',7)

xlabel("paso",'fontsize',15)
ylabel('energia/magnetizacion','fontsize',15)
