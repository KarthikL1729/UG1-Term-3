%Q1
%part a
n = 100000;
v = rand(n, 1);
v2 = randn(n, 1);

%part b
figure;
histogram(v, 'Normalization', 'pdf')
title("PDF of a Uniform distribution")
xlabel("X")
ylabel("pdf(X)")
histogram(v2, 'Normalization', 'pdf')
title("PDF of a Normal distribution")
xlabel("X")
ylabel("pdf(X)")