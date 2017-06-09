load correlacion_1.mat
niter=100000;
term=20000;
kmax=2000;
L=43;
%g=zeros(L,2*kmax+1)
for k=(1:2:L)
g(k,:)=output((k)*kmax:(k+2)*kmax,3)
end

for i=2:22
g(i,:)=[]
end

promedio=zeros(L,kmax+1);
L=22
for j=1:L
  m=g(L,:);
  u=mean(m);
  x = m-u;
  rho=zeros(1,kmax+1);
  for k=1:kmax+1
    num=0;
    den=0;
    for i=1:kmax-1
     num = num + x(i)*x(i+k);
     den = den + x(i)*x(i);
    end
  rho(k) = num/den;
  end
  promedio(j,:)=rho
end


corr=zeros(1,kmax);
for t=1:kmax
  corr(t)=sum(promedio(:,t))/L;
end  