# Borel Cantelli Lemma

## Part 1

If $A_1, A_2,.....$ is a sequence of events such that

$\displaystyle\sum_{n = 1}^{\infty} P(A_n) < \infty$

i.e., sum of probabilities of those events is finite, then we can say that almost surely only finitely many of the events will occur.

## Part 2

If $A_1, A_2,.....$ is a sequence of **INDEPENDENT** events such that

$\displaystyle\sum_{n = 1}^{\infty} P(A_n) = \infty$

i.e., sum of probabilities of those events is finite, then we can say that almost surely infinitely many of the events will occur.

The first part can be understood by thinking of it as an infinite sum that sums up to a finite value, which directly implies that the terms will decrease and tend to 0 after a certain n, because the sum has to be finite.

So this can be thought of as a sequence of events with each event being more unlikely than the previous. So we can say that **ALMOST SURELY** not all of them will occur, and hence only finite number of events will occur.

The event that infinitely many $A_i$ events occur can be denoted by

$\displaystyle \bigcap_{n = 1}^{\infty}\bigcup_{i = n}^{\infty}A_i$

which can be denoted by the shorthand notation $A_{n \ i.o}$

It must be noted that $A_{n \ i.o}$ is itself an event, as it is the intersection and union of multiple events.

Now, part 1 states that $P(A_{n \ i.o}) = 0$, while part 2 states that $P(A_{n \ i.o}) = 1$ when the rest of their conditions are satisfied.

## Proof for part 1

Let $B_n = \displaystyle\bigcup_{i = n}^{\infty}A_i$, which is called the n-th tail event, as it is the union of all events from $A_n$ to $A_\infty$.

So now, we can shorten $A_{n \ i.o}$ to

$\displaystyle \bigcap_{n = 1}^{\infty}B_n$.

Now,

$P(\displaystyle \bigcap_{n = 1}^{\infty}B_n) = 0$

is what we need to prove. By continuity of probability, we can simplify that expression to,

$\displaystyle\lim_{n \to \infty}P(B_n)$, because $B_n$ are nested decreasing events.

Now, if we substitue $B_n$, we get

$\displaystyle\lim_{n \to \infty}P(\bigcup_{i = n}^{\infty}A_i)$

From here, we can say that $\displaystyle\bigcup_{i = n}^{\infty}A_i$ is always lesser than or equal to $\displaystyle\sum_{i = n}^{\infty}P(A_i)$.

Now as $n \to \infty$, we can see that the summation will tend to 0 as it is a set of events that continuously decrease in likelihood. So,

$\displaystyle\bigcup_{i = n}^{\infty}A_i \leq 0$

and as union cannot be lesser than 0, we can say that it will ALMOST SURELY be 0.

## Proof for part 2

We will be using another lemma here, which is,

Lemma: If $0 \leq P_i \leq 1$ such that  $\displaystyle\sum_{i = 1}^{\infty}P_i = \infty$, then $\displaystyle\Pi_{i = 1}^{\infty}(1-P_i) = 0$.

Proof for the lemma:

If we take log over the multiplication in the equation,

$log(\displaystyle \lim_{n \to \infty}\Pi_{i = 1}^{n}(1-P_i))$

Now we can say that this is always less than the product upto some finite k.

$log(\displaystyle \lim_{n \to \infty}\Pi_{i = 1}^{n}(1-P_i)) \leq log(\displaystyle\Pi_{i = 1}^{k}(1-P_i)) \ \forall \ k \geq 1$

Now, we can split the RHS into a summation instead of a product.

$log(\displaystyle \lim_{n \to \infty}\Pi_{i = 1}^{n}(1-P_i)) \leq \sum_{i = 1}^{k}log(1-P_i)$.

Now RHS is always less than or equal to $\displaystyle\sum_{i = 1}^{k} -P_i$ by definition of log, so now, if we make $k \to \infty$, the RHS will tend to $-\infty$.

So, now we have

$log(\displaystyle \lim_{n \to \infty}\Pi_{i = 1}^{n}(1-P_i)) \leq -\infty$

Taking antilog, we get,

$\displaystyle \lim_{n \to \infty}\Pi_{i = 1}^{n}(1-P_i) \leq 0$.

As product of positive terms cannot be negative, we can conclude that the product is 0.

Now, we use this lemma to prove the second part.

We will show that

$P(A_{n \ i.o})' = 0$, which is the same as what we need to prove.

So now, we can shorten $A_{n \ i.o}'$ to

$\displaystyle \bigcup_{n = 1}^{\infty}B_n'$.   (DeMorgan's laws).

Now,

$1 - P(A_{n \ i.o}) = P(\displaystyle \bigcup_{n = 1}^{\infty}B_n')$

Now, since the RHS is a union of events, we can say that

$RHS \leq \displaystyle\sum_{n = 1}^{\infty} P(B_n')$ \........... (Main equation)
We will show that $P(B_n') = 0 \forall n \geq 1$.
We can take

$P(\displaystyle\bigcap_{i = n}^{m} A_i')$

As $A_i$ are independent events, we can convert that union into a multiplication.

$P(\displaystyle\bigcap_{i = n}^{m} A_i') = \Pi_{i = n}^{m}P(A_i')$

Now, if we let $m \to \infty$, the RHS becomes $P(B_n')$,

$P(B_n') = \displaystyle\lim_{m\to\infty}P(\displaystyle\bigcap_{i = n}^{m} A_i') = \lim_{m\to\infty}\Pi_{i = n}^{m}(1 - P(A_i))$

Now, from the lemma, we can say that the RRHS is equal to 0 for all $n \geq 1$.

So, now we can say that,

$P(B_n') = 0 \forall \ n \geq 1$.

Substituing this in the main equation from before, we get

$RHS \leq 0$

As union of probabilities cannot be negative, it is equal to 0.

So now, we can finally say that

$1 - P(A_{n \ i.o}) = 0$

And hence,

$P(A_{n \ i.o}) = 1$

Hence, proved.

---