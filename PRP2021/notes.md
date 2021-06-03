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

  - $F = \{\phi, S\}$ is the smallest possible event space.
  - If $E_1 \isin F$ and $E_2 \isin F$, then $E_1 \cup E_2 \isin F$.
  **Proof :**
  As $E_1 \isin F$, $E_1' \isin F$. Same for $E_2$ WLOG. Now, as $E_1' \isin F$ and $E_2' \isin F$, $E_1' \cup E_2 \isin F$ (By the third axiom).
  So now, as $E_1' \cup E_2' \isin F$, we can say $(E_1' \cup E_2')' \isin F$ (first axiom), which is the same as saying $E_1 \cup E_2 \isin F$.
  Hence proved.

- $P$ is known as probability measure. It is a set function defined from $F \to [0, 1]$.
- $P(E)$ has to satisfy three axioms:
  - $P(E) \ge 0$
  - $P(S) = 1$
  - If $E_1, E_2,.....$ is a collection of mutually disjoint events,
  $P(\cup_{i = 1}^{\infty}E_i) = \displaystyle \sum_{i = 1}^{\infty} P(E_i)$
  - Proof that P($\phi$) = 0:
    $S = S \cup \phi \implies P(S) = P(S) + P(\phi) \implies 1 = 1 + P(\phi) \implies P(\phi) = 0$