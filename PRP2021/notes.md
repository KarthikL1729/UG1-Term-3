# Probability and Random Processes course

---

## 24 May 2021

---

No class today ggwp

---

## 26 May 2021

---

- Course overview and syllabus discussion (was death, read Ananya's pic)

### Probability spaces

- Various approaches to probability
  - Experiments $\to$ observations are termed as outcomes.
- Classical approach
  
    $P(E) = \frac{n(E)}{n(Total)}$

- Disadvantages of classical approach
  - Does not model biases
  - Number of outcomes is infinity, probability may not be convergent.
- Relative frequency approach (Based on experiments)
  - Perform the experiment N times and see how many times E occurs ($f_E$)
  
    $P(E) = \displaystyle \lim_{N \to \infty}\frac{f_E}{N}$

- Disadvantages of relative frequency approach
  - Based on observations
  - It does not capture belief factor

- Axiomatic Approach (Thought experiments)
  - Probability space is entirely defined here.
  - Three quantities, $S$, $F$ and $P$.
  - $S$ is the sample space. It is the set of all possible outcomes of  an experiment. Can be of three types:
    - Finite
    - Countably infinite
    - Uncountably infinite

Note: A set is said to be countable if a bijection exists between it and the set of Natural numbers

---

## 28 May 2021

---
Continuing from the previous class...

- $F$ is known as the Event Space. It is a collection of events. An event is any subset of the sample space $S$. A collection of events is called an event space.
- An event space has to be a "Sigma field".
- A sigma field is a collection of subsets of $S$ which satisfies the following properties.
  - $S \isin F$, where S is the sample space.
  - If $E \isin F$, then $E'\isin F$ as well.
  - If $E_1, E_2.... \isin F$(infinite collection of events), then $\cup_{i = 1}^{\infty} E_i \isin F$.

  We cannot afford to take F as the power set of the sample space when the sample space is uncountably infinite.
  $F = \{\phi, S\}$ is the smallest possible event space.
  - If $E_1 \isin F$ and $E_2 \isin F$, then $E_1 \cap E_2 \isin F$.
  **Proof :**
  As $E_1 \isin F$, $E_1' \isin F$. Same for $E_2$ WLOG. Now, as $E_1' \isin F$ and $E_2' \isin F$, $E_1' \cup E_2' \isin F$ (By the third axiom).
  So now, as $E_1' \cup E_2' \isin F$, we can say $(E_1' \cup E_2')' \isin F$ (first axiom), which is the same as saying $E_1 \cap E_2 \isin F$.
  Hence proved.

- $P$ is known as probability measure. It is a set function defined from $F \to [0, 1]$.
- $P(E)$ has to satisfy three axioms:
  - $P(E) \ge 0$
  - $P(S) = 1$
  - If $E_1, E_2,.....$ is a collection of mutually disjoint events,
  $P(\cup_{i = 1}^{\infty}E_i) = \displaystyle \sum_{i = 1}^{\infty} P(E_i)$
  - Proof that P($\phi$) = 0:
    $S = S \cup \phi \implies P(S) = P(S) + P(\phi) \implies 1 = 1 + P(\phi) \implies P(\phi) = 0$

---

## 31 May 2021

---

### Conditional probability and Bayes' theorem

**Conditonal probability:**
Given that an event A has occured, the (S, F, P) of the original probability space need to be suitably modified according to given data.

Ex: $S = \{1, 2, 3, 4, 5, 6\}$, all equally likely.

Let $E_1 = \{1, 2\}$ and $E_2 = \{3, 4\}$.
$F = \{\phi, S, E_1, E_2, E_1', E_2', E_1 \cup E_
2, E_1' \cup E_2'\}$

Let event $A$ be $E_1'$. If A has occured,
Modified probability space is
$\to S_A = A$
$\to F_A = \{(E \cap A | E \in F\}$

It can be shown that $F_A$ is an event space satisfying the axioms.

Now, $F_A$ can be defined as,
$F_A = \{\phi, A, \{3, 4\}, \{5, 6\}\}$
The new probability measure will be,

$\to P(E|A) = P(E \cap A)/P(A)$

This new definition must satisfy the three probabilty axioms too, which it does.

**Total Probability Theorem:**
Let events $A_1, A_2....A_n$ be mutually exclusive and exhaustive, i.e,

$A_i \cap A_j = \phi$ and

$\bigcup_{i = 1}^n A_i = S$

So, if we have an event $B$, we can say that

$P(B) = \displaystyle\sum_{i = 1}^n P(B \cap A_i) = \displaystyle\sum_{i = 1}^n P(B|A_i) \cdot P(A_i)$

This is true as $A_i$s are exhaustive, hence their union forms the sample space, and we are taking their intersections with B and summing them up as they are mutually exclusive (Like an OR).

---

## 2 June 2021

---

### Bayes' theorem and independent events

**Bayes' Theorem**
Let events $A_1, A_2....A_n$ be mutually exclusive and exhaustive, i.e,

$A_i \cap A_j = \phi$ and

$\bigcup_{i = 1}^n A_i = S$

If B is an arbitrary event,

$P(A_i|B) = P(B|A_i)\cdot P(A_i)/(\displaystyle\sum_{i = 1}^{n}P(B|A_i)\cdot P(A_i))$

Here,
$P(A_i) \to$ Prior probabilities
$P(B|A_i) \to$ Likelihood
$P(A_i|B) \to$ Posterior probabilities
In experiments where all $P(A_i)$ are same, on simplification, we get

$P(A_i|B) \propto P(B|A_i)$

This situation is called uniform prior.
Notice that the denominator is total probability.

**Independent events**
Events $A$ and $B$ are said to be independent iff,

$P(A\cap B) = P(A)\cdot P(B)$
In therms of conditional probability,
$P(B|A) = P(B)$

Note: If $A$ and $B$ are independent events, then $A$ and $B'$ are independent too. Can be proved by directly applying definition.

$\to P(A|B) \gtreqqless P(A)$

If events are mutually exclusive, they are not independent. Can be proved intuitively, because if their intersction has probability zero, and both have non zero probabilities, then they cannot be independent by definition.
Examples of Independent or Mutually exclusive events.

**Conditionally independent events**
Events $A$ and $B$ are conditionally independent given $C$ if,

$P((A \cap B)|C) = P(A|C)\cdot P(B|C)$

---

## 4 June 2021

---

**Independence of a collection of events**
A set of events $A_1, A_2,...A_n$ are said to be independent if

$P(\bigcap_{i = 1}^{n} A_i) = \Pi_{i = 1}^{n}P(A_i)$

This must be satisfied for all combinations of events that can be formed. If all are satisfied, then the set of events is said to be independent.

Chain rule of probability:

$P(\bigcap_{i = 1}^{n} A_i) = P(A_1)\cdot\Pi_{i = 2}^{n}P(A_i|\bigcap_{j = 1}^{i-1}A_j)$

### Continuity of Probability

Consider a probability space (S, F, P).
Events $E_i \in F$.
Let $E_1 \subset E_2 \subset.....$ be a countably infinite increasing sequence of events.
Then,

$P(\bigcup_{i = 1}^{\infty} E_i) = \displaystyle\lim_{i\to\infty}P(E_i)$

We are pushing the limit from inside the expression to the outside. So, exchanging limits with probability here is a non trivial operation (We need a proof). This may not work for anything other than an increasing sequence of events.

Similarly, if $E_1 \supset E_2 \supset.....$ be a countably infinite decreasing sequence of events, then,

$P(\bigcap_{i = 1}^{\infty} E_i) = \displaystyle\lim_{i\to\infty}P(E_i)$

Did a weird q that used some integration type logic to construct a triangle as a intersection of events that were unions of rectangles.

---

## 7 June 2021

---

### Intro to random variables

Based on experiments, probability spaces vary a lot. They pose a hindrance to constucting a general theory. So we use a new concept called random variables to develop a theory of probability which is independent of the experiment.

A random variable is a function that maps the entities like follows,

$S \to R$ (Real line)
$F \to Borel-\sigma \ algebra$

**Borel $\sigma$ algebra**: It is the smallest $\sigma$ algebra which contains sets of the form $(-\infty, x] \forall x \in R$. Basically a smaller sigma algebra

So we can take all these sets and apply the $\sigma$ algebra axioms to construct it. The smallest possible set of this sort will be the Borel $\sigma$ algebra.

If we take a generic set,

$B = \{R, (-\infty, x], (x, \infty), \phi\}$

Now, we can get $(x, y]$ in the set too,, by intersecting $(x, \infty)$ and $(-\infty, y]$.

After this, to get ${x}$ as an element, we can use

$E_i = (-\infty, x_i]; x_i = x - 1/i$
$\displaystyle\bigcup_{i \in N} (-\infty, x_i] = (-\infty, x)$ (**VERY IMPORTANT**)
Now, this union is a part of the algebra too. So then it's complement is part of the algebra as well, because of the axioms. Our algebra right now is

$B = \{R, (-\infty, x], (x, \infty), (x, y], (-\infty, x), [x, \infty), \phi\}$

So now, $[x, \infty) \cap (-\infty, x] = \{x\}$ which is also a part of the algebra now. So we can generate an algebra like this.

![Borel](Screenshot%20from%202021-06-15%2000-17-54.png)

This is the counterpart of our event space.

Random variable $X:S \to R$

X has to be a measurable function. A function X is said to be measurable if inverse image of $(-\infty, x] \forall x \in R$ is in the event space. Pretty weird bs, not sure what that means.

Basically this in summary,
![wot](Screenshot%20from%202021-06-15%2000-26-45.png)

Did an example, that kind of clarified the issue, not entirely comfortable yet ig =/

---

## 9 June 2021

---

A random variable is a map from the sample space to the real line such that X is a measurable function which satisfies the mentioned conditions.

### Cumulative distribution function

$F_X(x) = P(X \leq x) = P((-\infty, x])$

Or more precisely,

$F_X(x) = P(X^{-1}(-\infty, x])$

Since, the interval needs to be mapped back to the event space from the algebra and only then can we calculate probability. The previously menioned two are just notational.

**Properties of CDF**

- $F_X()$ is a non decreasing function of x.
  Proof:
  $F_X(x_2) = P(X \leq x_2) = P(X \leq x_1) + P(x_1 < X \leq x_2)$
  This can be done as they are disjoint, assuming $x_1 \leq x_2$
  So, $F_X(x_2) \geq F_X(x_1)$

- $\displaystyle\lim_{x \to -\infty} F_X(x) = 0$
  Can be proving by taking nested decreasing sets that go towards $-\infty$, and then using continuity of probability. Decreasing events can be of the form
  $A_i = (-\infty, -i]$
  $B_i = X^{-1}(A_i)$
  $\displaystyle\bigcap_{i\in N} B_i = \phi$
  $P(\displaystyle\bigcap_{i\in N} B_i) = \lim_{i \to \infty} P(B_i) = 0$

  As it is nested decreasing, the probability will also be monotonically decreasing, so probability will converge to 0.

- $\displaystyle\lim_{x \to \infty} F_X(x) = 1$
  Proved in a similar manner as the previous one, except it's union here.

**Indicator random variable**

$\mathcal{I}_A(\omega) = 1 \ \forall \ (\omega \in A), 0 \ otherwise$ for $A \in F$.

![rand](Screenshot%20from%202021-06-15%2022-14-01.png)
Hard to explain, see image.

---

## 11 June 2021

---

Continuing with properties of CDF...

- $F_X()$ is a **right continuous** function.
  $\displaystyle\lim_{x \to x_{0}^{+}} F_X(x) = F_X(x_0)$
  Proof: If we take a decreasing sequence of events,
  $B_i = \{X \leq x + 1/i\}$
  The infinite intersection of these events gives us
  $\displaystyle\bigcap_{i = 1}^{\infty}B_i = \{X \leq x\}$
  So, now $P(\displaystyle\bigcap_{i = 1}^{\infty}B_i) = P(\{X \leq x\}) = F_X(x)$
  RHS can now be simplified using continuity of probability.

Example qs

![exqs](Screenshot%20from%202021-06-20%2020-29-02.png)

---

## 14 June 2021

---

Lemma : For any $x \in R$

$P(X = x) = P(X \leq x) - P(X < x)$

Corollary : $F_X()$ is left continuous iff $P(X = x) = 0 \forall x \in R$

This implies $F_X()$ is continuous iff $P(X = x) = 0 \forall x \in R$

### Types of random variables

- Continuous Random Variable
- Discrete Random Variable
- Mixed Random Variable
  
**Continuous Random variables**

  A random variable X with cdf $F_X()$ is said to be continuous if $F_X()$ is continuous. In the context of continuous RVs, probabilities of intervals give useful info, as probabilities of points are always 0. Kind of like measure theory stuff.

  If $F_X()$ is a differentiable function, then we can find another function for the continuous RV, which is defined as,
  $$f_X(x) = \frac{dF_X(x)}{dx}$$

  which is called the **probability density function**. We can integrate this function from $-\infty$ to whatever value we want to get the cdf.

  So we can say that
  $P(a \leq x \leq b) = \displaystyle\int_{a}^{b}f_X(x)\cdot dx$

  And from this, if we find $P(x \leq X \leq x + \Delta x)$ and make $\Delta x \to 0$, we can approximate it to a rectangle with area $f_X(x) \cdot \Delta x$.

Properties of a pdf

- $f_X(x) \geq 0$ (Because cdf is monotonically non decreasing)
- $\displaystyle\int_{-\infty}^{\infty}f_X(x)\cdot dx = 1$

*pdf by itself does not indicate any probability.*

**Discrete Random Variables**

X is said to be a discrete random variable if the range of X is either finite or countably infinite in R.

The cdf of a discrete random variable will look like a staircase, constant everywhere, with jumps at certain points.

Here, $P(X = x_i) > 0$, not necessarily, but possible.
CDF for this would be

$$F_X(a) = \displaystyle\sum_{x_i \leq a} P(X = x_i)$$

Now, $P(X = x_i) = P_X(x_i)$ for $x_i$ in the range of X.

$P_X()$ is called the **probability mass function**.

![pmf](Screenshot%20from%202021-06-21%2000-28-08.png)

Properties of pmf:

- $P_X(x_i) \geq 0$
- $\displaystyle\sum_{x_i \in range} P_X(x_i) = 1$
  
---

## 17 June 2021

---

### Mixed RVS

As the name implies, it is continuous in some intervals, but also has jumps at some points. Y here is an example.

$\to Y = \alpha X_1 + \beta X_2$

### Functions of RVs

$Y = g(X)$

Here, X is an RV. So,  

$X:S \to R$
$g:R \to R$

Y is an RV when g satisfies some conditions, i.e., when g is a measurable function. Y is an RV basically when

$Y^{-1}((-\infty, y]) \in F$

Basically, the preimage of the generating class of the borel sigma algebra has to be in the event space, basic criteria for RV.
This also implies,

$X^{-1} [g^{-1} ((-\infty, y])] \in F$

Now, $X^{-1}$ of any Borel set will satisfy that condition.

So, we can say that $g^{-1} ((-\infty, y]) \in \mathcal{B}$, where $\mathcal{B}$ is the Borel sigma algebra.

This is the condition for Y to be an RV.

If X is a discrete random variable, and g is a function, then Y formed by these two is also a discrete RV.

The pmfs of Y and X, and the function g are related by

$P_Y(y) = P(Y = y)$
$= P(\{x_i|g(x_i) = y\})$
$=\displaystyle\sum_{x_i|g(x_i) = y}P_X(x_i)$

![exqd](Screenshot%20from%202021-06-27%2022-52-43.png)

If X is a continuous random vairable and g is a function, Y's nature depends on g, i.e., it can be either discrete or continuous.

Example:
When X is continuous and Y is also continuous

$Y = aX + b$

Let $F_X()$ be cdf and $f_X()$ be pdf of X.

$F_Y(y) = P(Y \leq y)$
$\{Y \leq y \} = \{aX + b \leq y\}$

So, if $a > 0$ then $X \leq (y-b)/a$
Else, $X \geq (y-b)/a$

SO the cdf and pdf (USE CHAIN RULE) of X applies here.

In one expression, we can say that

$f_Y(y) = \frac{1}{|a|}f_X(\frac{y-b}{a})$

---

## 18 June 2021

---

Continuing from yesterday with another example of when X and Y are both continuous.

$Y = X^2$

Here, $y \geq 0$ because of obvious reasons.

- CDF
  $F_Y(y) = P(Y \leq y)$
  $= P(X^2 \leq y)$
  $= P(-\sqrt{y} \leq X \leq \sqrt{y})$
  which can be written as
  $F_X(\sqrt{y}) - F_X(\sqrt{y}) + P(X = -\sqrt{y})$
  $=F_X(\sqrt{y}) - F_X(\sqrt{y})$

- PDF
  $f_Y(y) = \frac{dF_Y(y)}{dy}$

Example 3

![exq3p1](Screenshot%20from%202021-06-27%2023-48-49.png)
![exq3p2](Screenshot%20from%202021-06-27%2023-58-02.png)

Cannot relate much after this point, just got more confusing, check probabilitycourse.com for a nice explanation =P

---