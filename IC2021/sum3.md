---

## 9 June 2021

---

Joint entropy in two variables,

$H(X, Y) = \displaystyle\sum_{x, y \in sup(P_{X,Y})} P(x, y) log(1/P(x, y))$

$P_{X,Y} : \mathcal{X}*\mathcal{Y} \to [0, 1]$, indicating CARTESIAN PRODUCT, including the set of all possible ordered pairs, forming a distribution.

This can be extended to n variables easily,

$H(X_1, ... X_n) = \displaystyle\sum_{x_1,... x_n \in sup(P_{X_1, ... X_n})} P(x_1,...x_n) log(1/P(x_1,...x_n))$

If $X = Y$,

$H(X, Y) = H(X) = H(Y)$, this is cmplete dependence.

If they are independent on the other hand, we get

$H(X, Y) = H(X) + H(Y)$

Chain rule of Joint entropy

$H(X_1, ... X_n) = H(X_1) + \displaystyle\sum_{i = 2}^{n} H(X_i|X_1,...X_i-1)$

where,

$H(X,Y | V,U) = \displaystyle\sum_{u, v \in sup(P_{U, V})}P_{U, V}(u, v) H(X, Y | U= u, V=v)$

where,

$H(X, Y | U= u, V=v) = \displaystyle\sum_{x, y \in sup(P_{X, Y|U=u, V=v})} P(x, y| u, v)log(1/P(x, y| u, v))$

Now, this can be extended to any number of variables, before and after the conditioning.

Note:

$P(x_1, x_2, x_3|y_1, y_2) = P(x_1, x_2, x_3, y_1, y_2)/P(y_1, y_2)$

Some other way of writing it?

IMPORTANT:

$P(x, y|z) = P(x|z)\cdot P(y|x, z)$

Mainly because it forms it's own probability distribution ig?
This can be used to write the above expression in another way. It can be written as,

$P(x_1, x_2, x_3|y_1, y_2) = P(x_1|y_1, y_2) + P(x_2|x_1, y_1, y_2) + P(x_3|x_2, x_1, y_1, y_2)$

or,

$P(x_1, x_2, x_3|y_1, y_2) = P(x_1, x_2| y_1, y_2) + P(x_3|x_2, x_1, y_1, y_2)$

or,

$(P(x_3, y_2|y_1)\cdot P(x_1, x_2|x_3, y_1, y_2))/P(y_2|y_1)$

$x_1, x_2, x_3$ can be thought of as a random VECTOR here.

Proof for chain rule:

$P(x_1, ...x_n) = P(x_1) \cdot P(x_2, x_3....x_n|x_1)$
$= P(x_1) \cdot P(x_2|x_1) \cdot P(x_3....x_n|x_1, x_2)$

and keep splitting, same as chain rule in PRP.
We finally get,

$P(x_1, ...x_n) = P(x_1) \cdot \Pi_{i = 2}^{n} P(x_i | x_1,...x_{i-1})$

Use definition of joint entropy to finish entire proof.
