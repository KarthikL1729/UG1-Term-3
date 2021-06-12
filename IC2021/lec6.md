# 4 June 2021

Jensen's inequality is satisfied with the equality condition when the function is a straight line.

For strictly concave functions like logarithm,

$f(\lambda_1x_1 + \lambda_2x_2) = \lambda_1f(x_1) +\lambda_2f(x_2)$

when $x_1 = x_2$.

In general, if $\lambda_i \not ={0}$ and $\sum_{i = 1}^{n} \lambda_i = 1$ and Jensen's holds with equality, then

$x_1 = x_2....=x_n$

Now, if we apply this condition to $H(X) \leq log|\mathcal{X}|$,

$\displaystyle\sum_{x\in sup(P_X)}\lambda_x log(1/P(x) \leq log|supp(P_X)|$

then for equality, by above claim, we have

$\frac{1}{P(x)} = Constant$

But we also know,

$\displaystyle\sum_{x\in supp(P_X)}{P(x)} = 1$.

So, we can infer that

$P(x) = \frac{1}{|supp(P_X)|} \forall x \in supp(P_X)$

This distribution is called as a uniform distribution.

**Lemma:**
So, $H(X) = log|\mathcal{X}|$ iff $P_X$ is uniform and $|supp(P_X)| = |\mathcal{X}|$. This is a necessary and sufficient condition.

---

## Relative Entropy (or) Information Divergence (or) Kullback-Leibler Divergence

Suppose there is a random variable $X$ that has two different probability distributions $p_X$ and $q_X$, then the Relative Entropy/Information Divergence/K-L Divergence can be defined as

$D(p_X||q_X) \triangleq \displaystyle\sum_{x\in supp(p_X)} p(x) log(p(x)/q(x))$

**This expression clearly depends on the order of the arguments.**

Divergence can be **intuitively** thought of as a distance measure between different probability distributions.

Claim: $D(p||q) \geq 0$

Proof:

We first manipulate the expression to use Jensen's inequality.

$D(p||q) = - \displaystyle\sum_{x\in supp(p_X)}p(x) log(q(x)/p(x))$

Now, we can say that

$-\displaystyle\sum_{x\in supp(p_X)}p(x) log(q(x)/p(x)) \geq -log(\displaystyle\sum_{x\in supp(p_X)}q(x))$

using Jensen's inequality. Now, we can say that $\displaystyle\sum_{x\in supp(p_X)}q(x) \leq 1$, and hence, the minimum value the RHS can take is zero. So,

$-\displaystyle\sum_{x\in supp(p_X)}p(x) log(q(x)/p(x)) \geq 0$

Hence, proved.

When we apply equality conditon for Jensen's, we get

$\frac{p(x)}{q(x)} = Constant$
$\implies p(x) = C\cdot q(x) \ \forall x \in supp(p_X)$

Now, if we take summation on both sides, we get 1 on the LHS and $\displaystyle\sum_{x \in supp(p_X)} C\cdot q(x)$

Now, as $p(x)/q(x) = Constant \ \forall x \in supp(p_X)$, we can say that $|supp(q_X)| \geq |supp(p_X)|$. If $|supp(q_X)| > |supp(p_X)|$, then C will have to be greater than 1, and this is impossible as

$C = \displaystyle(\sum_{x \in supp(p_X)}p(x)/\sum_{x \in supp(p_X)}q(x))$
$\implies C = 1/\displaystyle\sum_{x \in supp(p_X)}q(x)$.

But the max value that $\displaystyle\sum_{x \in supp(p_X)}q(x)$ can take is 1.

So, this is a contradiction, and hence, $|supp(q_X)| = |supp(p_X)|$

So, from this, we can say that C = 1 and hence, the two probability distributions are equal for divergence equal to 0.

$\therefore D(p||q) = 0$ iff $p_X = q_X$.

\
Going back to conditional entropy,

Claim: $0 \leq H(X|Y) \leq H(X)$

For $H(X|Y) \geq 0$, we can consider the conditional probability to be another distribution for X, and hence, the proof is the same as it was for $H(X)$.

For the upper bound,

$H(X) - H(X|Y)$

We can write this as,

$\displaystyle\sum_{x\in supp(p_X), y \in supp(p_Y)}p(x, y) log(1/p(x)) - \displaystyle\sum_{x\in supp(p_X), y \in supp(p_Y)}p(x, y) log(1/p(x|y))$

$= \displaystyle\sum_{x\in supp(p_X), y \in supp(p_Y)}p(x, y) log(p(x|y)/p(x))$

On expanding the conditional probability term, we get,

$= \displaystyle\sum_{x\in supp(p_X), y \in supp(p_Y)}p(x, y) log(p(x, y)/(p(x)\cdotp(y)))$

Here, both the terms in division in the log term can be proven to be valid joint probability distributions.

So, we can now say that

$H(X) - H(X|Y) = D(p(x, y)||p_X(x)\cdot p_Y(y)$

which is always greater than or equal to zero.

Hence, we have proved that $H(X|Y) \leq H(X)$.

---
