load histogram.txt;
[n,x] = hist(histogram,100);

%me fijo que todos los sitios hayan sido elegidos al menos una vez
a = unique(histogram);
b = [0:99]';
sum(a==b)/length(a); %asumiendo long. de a = long. de b. Igual si eso no pasa tira error.

%me fijo que en promedio todos los sitios hayan sido elegidos un numero igual de veces
Niter = size(histogram)(1);
L = [1:100];
k = length(L);
P = sum(L);
expected = Niter*P/k;

res = sum(n.*L);

res/expected %cuanto mas cercano a 1 sea este numero, mejor