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

**Borel $\sigma$ algebra**: It is the smallest $\sigma$ algebra which contains sets of the form $(-\infty, x] \forall x \in R$.

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
