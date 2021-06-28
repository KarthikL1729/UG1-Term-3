%Q3
n = 100000;
v = rand(n, 1);
ld = 5;	%lambda
X = (-1/ld)*log(1-v);
figure;
histogram(X, 'Normalization', 'cdf')
title("CDF of exponential distribution")
xlabel("X")
ylabel("cdf(X)")

histogram(X, 'Normalization', 'pdf')
title("PDF of exponential distribution")
xlabel("X")
ylabel("pdf(X)")
