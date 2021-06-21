# Information and Communication Course

## 24 May 2021

---

- Introductory stuff (bs)

### Communication Theory

- Real world communication systems
- Structured (rigourous) mathematics

Math to system -> Synthesis \
System to math -> Analysis (Needs rigour)

Basically you need math and intuition to make something constructive and interface with the real world.

**Signals**: A function that conveys information about a phenomenon. Any function that transmits information (useful, hence information) is a signal. Information can be considered as something we are "interested" in.

Signals **NEED NOT** be time dependent alone. Example:

- RGB values of a certain point if we consider colours to be time invariant.
- A video is a combination of space and time variance.
- Text/Documents are not time variant too, but are signals as they convey information. It is a discrete signal as it can be quantised into specific characters (discrete elements) that can be picked out of a countable set. An example of the set can be the set of characters on a keyboard, which form a countable set. DO NOT consider sets like the natural numbers, as they can be broken down into individual digits and characters, and will still be discrete, as we can interpret them in any way we want (As Aftab sir would say, "They are nothing but symbols in sand").

---

## 26 May 2021

---

**Communication:** Can be broken into three steps:

- Transmission
- Reception
- Reconstruction of received information

### Point to point communication system

Source -> Transmitter -> Channel -> Receiver -> Reconstruction/Processing

The channel is one part of this system that is not completely under our control and we will have to account for it in our design as it will be imperfect.

We may assume the channel as an ideal channel (No disturbance/noise) for analysis.

### Transmitter side

- Source (Sending information)
- Transmitter (Modulation, amplification, and channel coding (Repeating the signal to minimise loss of information) to make the information appropriate for travelling in the channel)
- Transmission of data

### Receiver end

- Received signal
- Detect, Estimate, demodulate and decode the transmitted signal (Because of noise in the channel, the signal will no be identical to the one generated at the transmitter)
- Extract information
- An estimate of the information that was transmitted (Because we don't know EXACTLY what was transmitted)

What does the end user want from the communication system?

- Low probability of error, High fidelity
- High rate of communication

In digital communication, these two happen via channel coding and modulation.
In analog communication, this can be done via intelligent modulation and amplification.

- High range -> This is captured in the channel (Already done because of the choice of channel)
- Low latency in communication (Time delay between transmission and decoding)

Other communication systems

- Point to point
- Single transmitter to multiple receivers
- One transmitter, multiple receivers (Like a broadcast)
- Multiple transmitters, one receiver (Multiple phones connecting to one tower)

---

## 28 May 2021

---

- What is information? (Handwavy answers about usefulness)
- Information of any outcome has to do with the uncertainity of the outcome.
- Example : Say that X $\isin$ {0, 1} & can take value 0 with probability p, while 1 has a probability of 1 - p. X can be any quantity that represents a choice we care about. X is technically called a random variable.
If probability of a certain event occuring is low or the occurence of that event is highly unlikely, then X denoting the occurence of that event is said to have large information content.

$Information\ content\ in\ a\ particular\ event \ \alpha \ \frac{1}{Probability\ of\ the\ event}$

For two independent events with Probabilities $P_1$ and $P_2$, we multiply them to find the probability of both occuring together, while the net information content of both at th same time is the algebraic sum of their individual information contents. So, if we define X, we can say,

The Information content in an event X = x (where x is the event and X = x denotes it happening, X being a random variable) is

$Information\ content\ in\ an\ event\ X = \log \frac{1}{P(X = x)}$

So the average information content (or the "expected information content") would be,

$H(X) = \displaystyle \sum_{i = 1}^{n} P(X = x_i) * \log \frac{1}{P(X = x_i)}$

This expression is defined as the *ENTROPY* in random variable X, denoted by $H(X)$.

Lemma $\to$ Suppose $X_1 \isin x_1$ and $X_2 \isin x_2$ are independent random variables, then

$H(X_1, X_2) = H(X_1) + H(X_2)$

Where, $H(X_1, X_2)$ is the joint entropy of $X_1$ and $X_2$. We will be using $log_2$ as default in the course.

---

## 31 May 2021

---

Proof for $H(X_1, X_2) = H(X_1) + H(X_2)$ where $X_1, X_2$ are independent random variables.
Independent random variables can be defined as two variables that are always independent for all events.

$H(X_1, X_2) = \displaystyle \sum_{x_1 \in \mathcal{X_1}, x_2 \in \mathcal{X_2}}P(X_1 = x_1, X_2 = x_2)\cdot log(1/P(X_1 = x_1, X_2 = x_2))$
by definition.
Now, we can split that summation into a double summation (Like a nested for loop, one over $X_1$ and one over $X_2$) and we can split the log term too. We can split them into two separate terms and sum them over their respective summations. After manipulation and using total probability theorem, that gives us

![p1](Screenshot%20from%202021-06-07%2021-30-57.png)
After this, we can just use total probability theorem on the inner summation, and we have our result.

Now, if $X_1, X_2$ are NOT independent, we define a probability measure called conditional probability.

$P(X_2 = x_2|X_1 = x_1) = P(X_2 = x_2, X_1 = x_1)/P(X_1 = x_1)$
where $P(X_1 = x_1) \neq 0$

Note that $P(X_2 = x_2|X_1 = x_1) = P(X_2 = x_2)$ for independent events.

So, we can say that

$\displaystyle\sum_{x_2 \in \mathcal{X_2}} P(X_2 = x_2|X_1 = x_1) = 1$

So, conditional probability can be considered a probability distribution in itself.

So conditional entropy could be defined as,

$H(X_2|X_1) = \displaystyle\sum_{x_1 \in \mathcal{X_1}} P(X_1 = x_1)\cdot H(X_2|X_1 = x_1)$

while, $H(X_2|X_1 = x_1)$ is defined as,

$H(X_2|X_1 = x_1) = \displaystyle\sum_{x_2 \in \mathcal{X_2}} P(X_2 = x_2|X_1 = x_1)\cdot log(1/(X_2 = x_2|X_1 = x_1))$

Intuitively makes sense.

A more general equation now would be,

$H(X_2, X_1) = H(X_1) + H(X_2|X_1)$ or shuffle the order accordingly, shouldn't make a difference. Oh lol confirmed in the next class.

---

## 2 June 2021

---

If f is a function, then Support(f) or sup(f) is all the inputs in its domain that give a non zero output.

Proof for $H(X, Y) = H(X) + H(Y|X)$

$H(X|Y) = \displaystyle\sum_{y \in sup(P_y)} P_Y(y)\cdot H(X|Y = y)$ 

where

$H(X|Y = y) = \displaystyle\sum_{x\in sup(P_X)}P(x|y) \cdot log(1/P(x|y))$
Now, if we expand the RHS, in the main eqn, we get

![P2](Screenshot%20from%202021-06-07%2022-56-00.png)
This is what we need, as the final expression is $H(X, Y)$.

### Some properties of entropy

Can we bind $H(X)$ from above and below?

Claim : $0 \leq H(X) \leq log|\mathcal{X}|$

- Proof for $H(X) \geq 0$
  Trivial, as $P(x) = 0 \ \forall\  x \in sup(P_x)$
  Exactly 0 when $|sup(P_x)| = 1$.

- Proof for $H(X) \leq log|\mathcal{X}|$
  As we know, log is a concave function.
  So, $log(\lambda_1a + \lambda_2b) \geq \lambda_1 log(a) + \lambda_2log(b)$. This is **Jensen's inequality** in short. $\lambda_1 + \lambda_2 = 1, both\ \geq 0$. This combination is called a convex combination.
  It's the reverse for a convex function. Image below explains it in detail.
  ![p3](Screenshot%20from%202021-06-08%2000-16-30.png)

  Now, we can write $H(X)$ as

  $H(X) = \displaystyle\sum_{x \in sup(P_x)}P(x)log(1/P(x))$

  This resembles a convex combination. So we can say that,

  $H(X) \leq\displaystyle log(\sum_{x \in sup(P_x)}P(x)\cdot(1/P(x))$

  Which gives us $H(X) \leq log(|sup(P_x)|)$ which also implies,

  $H(X) \leq log|\mathcal{X}|$
  Hence, proved.

---

## 4 June 2021

---

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

### Relative Entropy (or) Information Divergence (or) Kullback-Leibler Divergence

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

## 7 June 2021

---

No class today =P

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

or this beauty,

![amaze](Screenshot%20from%202021-06-09%2009-53-52.png)

$x_1, x_2, x_3$ can be thought of as a random VECTOR here.

Proof for chain rule:

$P(x_1, ...x_n) = P(x_1) \cdot P(x_2, x_3....x_n|x_1)$
$= P(x_1) \cdot P(x_2|x_1) \cdot P(x_3....x_n|x_1, x_2)$

and keep splitting, same as chain rule in PRP.
We finally get,

$P(x_1, ...x_n) = P(x_1) \cdot \Pi_{i = 2}^{n} P(x_i | x_1,...x_{i-1})$

Use definition of joint entropy to finish entire proof.

---

## 11 June 2021

---

Entropy $H(X)$ -> Avg uncertainty about X.
So,

$H(X|X)$ denotes uncertainty in X AFTER OBSERVING X, which is 0.
Reduction in avg uncertainty of X achieved by observing X is $H(X) - H(X|X) = H(X)$.
This is if $P_X$ is known.
Now, if we have two vairables represented by their joint probability distribution, we can say that if a variable Y is observed before X,

Remaining uncertainty in X is $H(X) - H(X|Y)$, because Y may give certain info about X which reduces its uncertainty.

This can be called "Information gained about X after observing Y" or, more technically "MUTUAL INFORMATION BETWEEN X AND Y" and is denoted by $I(X;Y) = H(X) - H(X|Y)$.

It can be shown that $H(X) - H(X|Y) = H(Y) - H(Y|X)$. This can be proven by taking the conditional terms to opposite sides and making them joint entropies, which are equal.

So, $I(X;Y) = I(Y;X)$.
We can also say that $I(X;Y) \leq min(H(X), H(Y))$, the proof being trivial.

$\to I(X;Y) \geq 0$ represent this using divergence/relative entropy.

![newst](Screenshot%20from%202021-06-11%2009-45-17.png)
Stuff that we WILL be doing.

## Overview of Source Coding

Suppose we have $X \in {a, b}$ which is a binary source with probability distribution $P_X$.
If the observer observes one instance of X, then wants to store/communicate it through a noise free medium, which can carry only ${0, 1}$ bits. We will only need one bit to convey this information with 2 choices.

If receiver knows $P_X(a) = 0, P_X(b) = 1$ then reciever need not even receive the signal and hence, we need 0 bits to convey this info. This information has no chance of error too, but kind of pointless. This is basically an example to show that the probability can decrease the number of required bits I guess?

Now, if we have a margin of error $\epsilon$, then if any one of the events have a probability $\leq \epsilon$, then we can make do with no bits, as we cxan always declare the other event to be true (as it is within the bounds of error).

Basically, tolerating some amount of error, can give huge advantages.

---

## 14 June 2021

---

- Toleration of small errors can lead to us being able to compress the information better.

- Decoder is assumed to know the probability distribution of the source, so the decoder can interpret the data accordingly.

- We can club multiple random variables together, to get a lower probability of error. Individual distributions that we get from joint distributions are called marginal distributions. We can get joint distribution from marginal distribution if the random variables are independent. The picture below shows this idea.

![id2](Screenshot%20from%202021-06-18%2007-53-42.png)

We can code this accordingly, one such example being coding them with one bit and concatenating them together, which will give us the same amount of error as one bit at a time.

In the case of encoding one symbol, we only have two posible code lengths, which are 0 and 1. In this case however, we have 0, 1, 2 or 3 length strings.

A 1 length code could be very useful when a single tuple has a very high probability and the total probability of all other distributions is within our error limit.

In summary, this idea detials the logic of combining multiple source symbols and encoding them together into some fixed length binary string (length chosen according to the dirstribution), which gives us a more efficient source code (smaller normalized length, where normalized length is the length of the compressed binary string divided by the length of the  actual string).

Did an example to depict this idea. Only using fixed length binary strings here, though variable length seems to have a lot more potential in compression.
![id2](Screenshot%20from%202021-06-18%2008-26-12.png)

If a group of random variables have the same distribution and are independent, they are said to be independently and identically distributed. Like in the above case, the source string can be thought of as a string of random variables that have the same distribution and are independent.

Suppose we have a large length binary string, how many a's and b's do we expect to see in the random source string?

Number of a's $\to n\cdot p(a)$
Number of b's $\to n\cdot(1-p(a))$
Total number of such strings $\to$ $n\choose {n\cdot p(a)}$

For all such sequences, we will use unique strings. For EVERYTHING else, we will use ONLY ONE CODEWORD.
This can increase our efficiency by A LOT, depending on our probability distribution.

---

## 16 June 2021

---

In last class we said,

Total number of such strings $\to$ $n\choose {n\cdot p(a)}$

A better term for this would be "Typical sequences".

Atypical sequences are sequences where the distribution is very different from the expected distribution. We can conclude with high probability that any n-length sequence from the source is going to be a typical sequence.

As $n \to \infty$, the probability of atypical sequences tends to zero.

**Block to block source coding**

Assign a unique codeword of length 'l'to each typical sequence.

Assign some "Same" codeword of length l, different from all other codewords that represents all atypical sequences.

We can now deduce that we will need

$l = \log_{2} {n\choose n\cdotp(a)} + 1$

to represent all these words. On simplifying the expression in the log (using massive amounts of approximation like in time complexity analysis) we get

$l = n\log_{2}n - np\log_{2}(np) - n(1-p)\log_{2}(n(1-p)) - C$

where C is comparitively a very small quantity. On simplifying that expression, we get,

$l = n[p\log(1/p) + (1-p)\log(1/(1-p)) - smallnum/n]$

This is clearly the entropy of the random variable X (source string).

So, we get,

$l = n\cdot H(X)$

---

## 18 June 2021

---

### Fixed to variable length source coding

If we have 4 symbols, {A, B, C, D}, and a code,

$A \to 0$
$B \to 1$
$C \to 10$
$D \to 11$

Here, the source sequences 'BA' and 'C' are not uniquely deecodable. This has a non zero probability of error which we are not okay with.

One solution is to use a PREFIX-FREE CODE.

Clarification in Terminology:

- Codeword: The string resulting from a particular input.
- Code: Set of all codewords.

Both refer to the mapping. Not the source signal or input.

Continuing...

A code C is called a Prefix free code if no Codeword in C is a prefix of another codeword, i.e., 
the example shown above shouldn't happen. In the example above, 1 is a prefix of the code words 11 and 10. So, it is not a prefix free code.

Example of a Prefix free code $\to$ {10, 01, 11, 00}

Note: A variable length code does not mean that the length of the codewords are different. It just means that when we design the code, we are free to choose the length of the codewords, whereas in a fixed length code, all codewords must be of the same length.

Example of a variable length prefix free code $\to$ {0, 10, 110, 1110}

If we think of the code as a binary tree

![bt](Screenshot%20from%202021-06-18%2009-33-38.png)

If we represent the code like this, we can see that successor node of any code word will not be part of a prefix free code, as the predecessor node is a prefix code word. This is a necessary and sufficient condition. So, our code will be a set of nodes which are neither successors nor predecessors of each other.

More terminology:

- Leaves of the binary tree are nodes in the tree with no children.

If we have $X \in \mathcal{X}$, where X is the source string random variable, and we have $|supp(P_X)| = s$, then we can have $l_i$, where each represents the length of the binary code words associated to the ith symbol in $|supp(P_X)|$.

So, we can now say that the expected length of the codeword will be,

$$Expected\ length (\overline{L}) = \displaystyle\sum_{i = 0}^{|supp(P_X)|} P_i\cdot l_i$$

Now, we want to find a code that minimises this expected length.

Did an example to show this formula in use.

The goal of Prefix free variable length source coding is to reduce expected length.

This is error free as EACH SEQUENCE of source symbols will have a UNIQUE codeword sequence. The decoder will start from the leftmost end of the codeword sequence, traverse the tree, and when it finds a sequence corressponding to a codeword, it declares the codewords' corressponding source symbol and restarts from the beginning. This will always work, as the code is prefix free.

The minimum possible $\overline{L}$ among all codes is denoted as $\overline{L}^{*}$.

---

## 21 June 2021

---

Some mad discussion about achievability and converse.

### Channel coding

We give input, which is then translated and passed through a channel to give an output in a different language.

We say that a channel is noisy when we have a many one relation from input to output. The different one one relationshipps won't matter because we'll still have unique relations between input and output, which can be decoded by some decoder. Will be discussed later apparently.

If we have a many one relation, then we only choose one of the many words that map to one codeword, and we omit the rest from our vocabulary, which is called the set of all transmittable sequences... Seems like a pretty scammy workaround?

This subset of transmittable sequences is called channel code, or just code. Denoted by $\mathcal{C}$. Note that $\mathcal{C} \subseteq \mathcal{X}^{n}$ where $\mathcal{X}^{n}$ is the input vocabulary. Each vector in the input vocabulary requires the channel to be used n times, because n characters. Each vector in $\mathcal{C}$ is a codeword.

Number of bits that is required to represent $|\mathcal{C}|$ codewords is $log_{2}\mathcal{|\mathcal{C}|}$

Now, the rate of the code is defined as,

$$Rate \ of \ \mathcal{C} = \frac{log_{2}|\mathcal{C}|}{n}$$

Higher the rate, more the chance of error, as there is more chance of a many one system forming.

**Probabilistically noisy channel (or) Random channel**

Same input can give many different outputs with different probabilities. We use conditional probability here.