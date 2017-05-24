C = zeros(1,30);
X = zeros(1,30);
temp = zeros(1,30);
%calculo calor especifico y suceptibilidad
for i=1:30
  T = i*0.1;
  temp(i) = T;
  s = sprintf("/home/lusia/Documents/ising/bin/ising.e %d",T);
  system(s);
  load output.txt
  mag = output(:,1);
  ener = output(:,2);
  
  C(i) = (mean(ener.^2) - mean(ener)^2)/(T^2);
  X(i) = (mean(mag.^2) - mean(mag)^2)/T;
end