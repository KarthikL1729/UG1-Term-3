%Q2
n = 100000;
v = rand(n, 1);
v2 = randn(n, 1);
%mean
m1 = 0;
m2 = 0;
for i = 1:n
    m1 = m1 + v(i);
    m2 = m2 + v2(i);
end

mean_uniform = m1/n
mean_normal = m2/n

%variance
var1 = 0;
var2 = 0;

for i = 1:n
    var1 = var1 + (v(i) - mean_uniform)*(v(i) - mean_uniform);
    var2 = var2 + (v2(i) - mean_normal)*(v2(i) - mean_normal);
end

variance_uniform = var1/n
variance_normal = var2/n