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
- Example : Say that X $\isin$ {0, 1} & can take value 0 with probability p, while 1 has a probability of 1 - p. X can be any quatity that represents a choice we care about. X is technically called a random variable.
If probability of a certain event is occuring is low or the occurence of that event is highly unlikely, then X denoting the occurence of that event is said to have large information content.

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

Now, if $X_1, X_2$ are NOT independent, we define a probabiltiy measure called conditional probability.

$P(X_2 = x_2|X_1 = x_1) = P(X_2 = x_2, X_1 = x_1)/P(X_1 = x_1)$
where $P(X_1 = x_1) \neq 0$

Note that $P(X_2 = x_2|X_1 = x_1) = P(X_2 = x_2)$ for independent events.

So, we can say that

$\displaystyle\sum_{x_2 \in \mathcal{X_2}} P(X_2 = x_2|X_1 = x_1) = 1$

So, conditional probability can be considered a probability distribution in itself.

So conditional entropy could be defined as,

$H(X_2|X_1) = \displaystyle\sum_{x_1 \in \mathcal{X_1}} P(X_1 = x_1)\cdot H(X_2|X_1 = x_1)$

while, $H(X_2|X_1 = x_1)$ is deinfed as,

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

---

## 7 June 2021

---

No class today =P

---
