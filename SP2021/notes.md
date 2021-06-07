# Signal Processing Course

## 24 May 2021

---

- Intro stuff (course overview)

- What are signals? Examples? (Same definition as IC, only asked for intuition)

Signals studied will majorly include be functions of time, but time dependent signals are **NOT** the only kind, as noted in IC course notes today.

### Classification of signals

- Discrete time signals & Continuous time signals. -> Discrete time is represented as x[n], continuous time as x(t).
- Periodic and Aperiodic signals
- Even and Odd signals
- Analog and Digital signals
- Deterministic and Random signals

Discrete time and continuous time signals are differentiated according to the division of time, while analog signals and digital signals are differentiated according to the range of the values that the signal can attain. DO NOT confuse them.

**Signal Processing:** Signals are processed to extract information, represent them in different forms (transforms) and to modify signals when necessary. A system can be used to perform the required processing on a signal.

### Classification of systems

- Causal and non causal
- Linear and Non linear

---

## 26 May 2021

---

### Fourier series

- Periodic signals -> Represented as a weighted sum of sinusoids.
- Fourier series can be applied to both real and complex signals.

### Trigonometric Fourier Series representation

Synthesis equation:

 $\to x(t) = c_0 + \displaystyle \sum_{n = 1}^{\infty}(c_n \cdot cos(n\omega_0t) + b_n \cdot sin(n\omega_0t))$

where $\omega_0 = \frac{2\pi}{T}$.

Each of the terms in the infinite sum are called the harmonics, and $c_0$ is the constant/DC part of the function.\
**n = 1 IS CALLED THE FUNDAMENTAL COMPONENT AND NOT THE FIRST HARMONIC**

Called the sysnthesis equation as we can use it to *reconstruct* a signal with frequency $f_0$. If we only use a finite number of terms in the sum, then we get a function $x'(t)$ which will be an approximation of the original function.

**Reconstruction error** -> $e = x'(t) - x(t) \not ={0}$
When $e = 0$, we say that it is a *perfect reconstruction*.

- Determining coefficients for a given signal is *analysis*.
- Generating a periodic signal of frequency $f_0$ by progressively adding weighted harmonics to a sinusoid of frequency $f_0$ (Fundamental component) is *synthesis*.

### Exponential Fourier Series representation

Synthesis equation:

$\to x(t) = \displaystyle \sum_{k = -\infty}^{\infty}a_k \cdot e^{jk\omega_0t}$

To convert from exponential form, use $e^{j \theta} = \cos\theta + j\sin\theta$

Analysis equation:

$\to a_0 = c_0$ (from trigonometric series)

$\to a_k = \frac{1}{T} \cdot\displaystyle \left (\int_{<T>} x(t) \cdot e^{-jk\omega_0t}\;dt\right)$

Dot product of functions is the integral over their period in this case.

Analysis equation for $a_k$ actually comes from the logic behind projections of vectors (from NeSS), i.e.

$a_k = \frac{<x(t), e^{-jk\omega_0t}>}{<e^{-jk\omega_0t}, e^{-jk\omega_0t}>}$

 ***WORKS BECAUSE $\sin(n\theta)$ is orthogonal to $\sin(m\theta)$. Same for cosine. So every term that isn't having the same coefficient becomes 0 in the dot product, hence giving us the required component, which is the Fourier coefficient here.***

$a_k$ are the Fourier series coefficients. They are also called the spectral coefficients.

- Signal representation by orthogonal signal set (Comparison with basis decomposition of vectors, similar idea here, where sinusoids are the basis functions).
  
We represent $x(t)$ using orthogonal signals (Can be compared to basis vectors, sine and cosine functions here as mentioned above).

- Solving examples of Fourier series questions

***Fourier series is RESTRICTED TO periodic signals.***

## Fourier Transform

Consider an aperiodic signal $x(t)$.
Now consider a periodic extension $x_p(t)$ with period $T > 2T_1$ ($2T_1$ is time range of original signal)

That is,

$x_p(t) = x(t) + \displaystyle \sum_{n = 1}^{\infty}(x(t - nT) + x(t + nT))$

Now, we can find Fourier series coefficients of $x_p(t)$, as it is periodic. For this we can use the analysis equations.

Now, if we integrate from $\frac{-T}{2}$ to $\frac{T}{2}$, the only integrable portion is from $-T_1$ to $T_1$, i.e.,

$a_k = \frac{1}{T}\displaystyle \left (\int_{-\frac{T}{2}}^{\frac{T}{2}} x_p(t)\cdot e^{-jk\omega_0 t}\;dt \right)$

Here, as the function is aperiodic and the only integral part is from $-T_1$ to $T_1$, we can change the limits to $-\infty$ and $\infty$ to get $a_k$ and change $x_p$ to $x$ as well.

If we take $k\omega_0$ = $\omega$, we can define X($\omega$) as,

$X(\omega) = \displaystyle \left (\int_{-\infty}^{\infty} x(t)\cdot e^{-j\omega t}\;dt\right)$

where $\omega$ is a real continuous variable. This is the ***FOURIER TRANSFORM*** of $x(t)$. So according to this equation, we can say,

$X(\omega) = a_k\cdot T$

So, $X(\omega)$ is like the envelope of $a_k$.

Now, for the synthesis equations,

$\to x_p(t) = \displaystyle \sum_{k = -\infty}^{\infty}a_k \cdot e^{jk\omega_0t}$

Here, we can substitute $a_k$ with $\frac{X(k\omega_0)}{T}$. We can then substitute that $\frac{1}{T}$ with $\frac{\omega_0}{2\pi}$, hence resulting in the equation

$\to x_p(t) = \frac{1}{2\pi}\displaystyle \sum_{k = -\infty}^{\infty} X(k\omega_0) \cdot e^{jk\omega_0t} \cdot \omega_0$

If $T \to \infty$, $\omega_0 \to 0$. So, we can now make the summation an integration, that integration being (using $\omega = k\omega_0$),

$\to x(t) = \frac{1}{2\pi}\displaystyle \left (\int_{-\infty}^{\infty} X(\omega) \cdot e^{j\omega t} d\omega \right)$

To summarise,

- Analysis equation (Fourier Transform)
  
  $X(\omega) = \displaystyle \left (\int_{-\infty}^{\infty} x(t)\cdot e^{-j\omega t}\;dt\right)$

- Synthesis equation (Inverse Fourier Transform)

    $x(t) = \frac{1}{2\pi}\displaystyle \left (\int_{-\infty}^{\infty} X(\omega) \cdot e^{j\omega t} d\omega \right)$

- Fourier transform applies to general aperiodic signals.

---

## 28 May 2021

---

## Fourier Transform, continued

- Both time and frequency are continuous variables here, whereas frquency was discrete in Fourier series.
- Fourier transform is basically derived from a limiting case of Fourier series.
- Fourier Transform is a weighted linear combination (integration, instead of summation like in Fourier series) of complex sinusoids.
- In general, all frequencies are present in the transform, i.e., integration goes from $-\infty$ to $\infty$.
- $X(\omega)$ quantifies the contribution of $e^{j\omega t}$, similar to $a_k$ in Fourier Series.
- $X(\omega)$ is complex valued in general.
- Notation : $X(\omega) \longleftrightarrow x(t)$

What the Inverse Fourier Transform basically does is:

- Multiplies the given frequency domain signal by sinusoids($-\infty\to\infty$) according to their frequency.
- Adds them all up to give us our signal in time domain.

**Dirac delta function ($\delta(t)$) or unit impulse signal:**

- $\delta(t) = 0\  when\ t \not ={0}$
  
- $\displaystyle \left (\int_{-\infty}^{\infty}\delta(t) \ dt \right) = 1$

Main use of $\delta(t)$ is the sifting property, which is,

- $x(t)\cdot\delta(t - t_0) = x(t_0)\cdot\delta(t - t_0)$

- $\displaystyle\int_{-\infty}^{\infty}\delta(t - t_0) \cdot x(t) \ dt = x(t_0)$

**Gibbs' Phenomenon :** This phenomenon is the existence of an overshoot in the Fourier sum of a signal when there is a jump discontinuity. This error does not go away as more errors are added to the sum. However, the error does decrease in width and energy on taking more terms into consideration.

- A square wave in time has a sinc ($\frac{2\sin(\omega t)}{\omega}$) function as its Fourier transform. Graph of a sinc function is like a *single slit diffraction pattern* (Middle band is twice as big and stuff).
- Did example qs for Fourier Transform.

---

## 31 May 2021

---

Note: All double sided arrows imply FT here, or FS in a few places.

The Fourier Transform can be mapped to the Fourier series too.

Q. Consider the following Fourier Transform,

$X(\omega) = \displaystyle\sum_{k = -\infty}^{\infty}2\pi a_k\delta(\omega - k\omega_0)$

find $x(t)$.

Using the Inverse FT formula, 

$\to$ $x(t) = \frac{1}{2\pi}\displaystyle\int_{-\infty}^{\infty}X(\omega)\cdot e^{j\omega t} d\omega$

![Solution](../SP2021/Screenshot%20from%202021-06-03%2014-25-05.png)
The foruier series only exists for periodic $x(t)$.

## Properties of Fourier Transform

- Linearity:
$x(t) \longleftrightarrow X(\omega)$ ; $y(t) \longleftrightarrow Y(\omega)$

$\implies \alpha x(t) + \beta y(t) \longleftrightarrow \alpha X(\omega) + \beta Y(\omega)$

- Time shift:
$x(t) \longleftrightarrow X(\omega)$

$\implies x(t - t_0) \longleftrightarrow X(\omega)\cdot e^{-j\omega t_0}$

Basically a phase shift.

- Time and Frequency Scaling:
$x(t) \longleftrightarrow X(\omega)$
$x(at) \longleftrightarrow \frac{1}{|a|}X(\omega / a)$

Makes sense intuitively, as an increase in time should result in a decrease in frequency, and vice versa.

![Proof for scaling](Screenshot%20from%202021-06-03%2016-43-51.png)

Then a discussion about playback speeds on YT, so higher speeds imply the same voice needs to be fit into a shorter span of time, hence frequency needs to be increased. So, we get higher pitched voices and stuff (As I've noticed). Similarly, slowing down creates a lower frequency, which adds bass, hence the weird droning and hilarious playbacks at 0.25x. As for a physical representation of the constant a, the energy of a signal changes when it is compressed???? Should it not increase in frequency if I compress it in time? Will need to clarify.

---

## 2 June 2021

---

**Note:** Fourier Transform is a special case of Laplace transform.

|Laplace transform|Fourier Transform|
|---              |---              |
|$x(t) \longleftrightarrow X(s)$|$x(t) \longleftrightarrow X(\omega)$ |
|s is a complex variable.|$\omega$ is a real variable.|
|$X(s) = \displaystyle \int_{-\infty}^{\infty} x(t) \cdot e^{-st}dt$|$X(\omega) = \displaystyle \int_{-\infty}^{\infty} x(t) \cdot e^{-\omega t}dt$|
|$s =\sigma + j\omega$ | When $\sigma = 0$ in Laplace transform|
|Region of Convergence (ROC): Region of s plane where that integral converges.| Imaginary axis in s plane|

Trying to solve a known transform in reverse...

$\delta(t) \longleftrightarrow 1$. Strating from $X(\omega)$, find $x(t)$.
Using synthesis formula, we get,

$x(t) = \frac{1}{2\pi}\displaystyle\int_{-\infty}^{\infty} X(\omega)e^{j\omega t}d\omega$
$= \frac{1}{2\pi}\displaystyle\int_{-\infty}^{\infty}e^{j\omega t}d\omega$
Here we are at a fix, as we cannot simplify frther, as it would give undefined values.
So signals may not have a converging integral at all times. We must take this into consideration too.

Now, if we take the Fourier transform of $cos(\omega_0t)$, we still get $\pi[\delta(\omega - \omega_0) + \delta(\omega + \omega_0)]$. But here if we try to find the ROC, we find that the imaginary axis is not a part of it. So it does not converge. The transform will be 2 poles in the S plane. So when we try going forwards from $cos(\omega_0t)$, we get stuck.
As I understand it, any function that has a transform that contains a $\delta$ function will not cnoverge as it is not well defined.

**Continuing with properties of the Fourier Transform...**

- Parseval's theorem:
  Energy is same in time and frequency domains upto a scaling factor.
  i.e.
  $\displaystyle\int_{-\infty}^{\infty}|x(t)|^2 dt = \frac{1}{2\pi} \displaystyle\int_{-\infty}^{\infty}|X(\omega)|^2 d\omega$

- Symmetry and Conjugacy properties:
  $x(t) \longleftrightarrow X(\omega)$
  $x(-t) \longleftrightarrow X(-\omega)$  (Can be derived from scaling property too)
  $x^*(t) \longleftrightarrow X^*(-\omega)$
  From these, we can derive,
  - If $x(t)$ is real,
  $x(t) = x^*(t) \implies X(\omega) = X^*(-\omega)$ from first and third points.
  This is called conjuate symmetry.

  - If $x(t)$ is even,
  $x(t) = x(-t) \implies X(\omega) = X(-\omega)$ from first and second points.
  - If $x(t)$ is odd,
  $x(-t) = -x(t) \implies X(-\omega) = -X(\omega)$ from first and second points.
  - Differentiation in time:
    $\frac{d(x(t))}{dt} \longleftrightarrow j\omega X(\omega)$
  - Differentiation in frequency:
    $tx(t) \longleftrightarrow \frac{d(X(\omega))}{d\omega}$
  - Frequency shift (Analogous to time shift)
    $x(t)e^{j\omega_0 t} \longleftrightarrow X(\omega - \omega_0)$

---

### Linear Time Invariant (LTI) Systems

Many systems can be represented as LTI systems, like RLC circuits are LTI systems.
Any system with a differential equation representation is an LTI system.
Examples of non LTI systems:

- Transistors
- Op amps
- Diodes
- Any digital system
  
**Linearity:**
$x_1(t) \to y_1(t)$ and $x_2(t) \to y_2(t)$

$\implies \alpha x_1(t) + \beta x_2(t) \to \alpha y_1(t) + \beta y_2(t)$

**Time invariance:**
$x(t) \to y(t)$

$\implies x(t - t_0) \to y(t - t_0)$

Any LTI system can be uniquely and fully characterised by its impulse response, i.e., the response it gives when the input is an impulse.

$\delta(t) \to h(t)$, where $h(t)$ is the impulse response of the system.

Given an arbitrary input $x(t)$ to an LTI system with impulse response $h(t)$, the output of the system will be an CONVOLUTION,

$y(t) = x(t) * h(t) = \displaystyle\int_{-\infty}^{\infty}x(\tau)h(t-\tau)d\tau$  

where $x(t) * h(t)$ is $x(t)$ CONVOLVED with $h(t)$.

Intuition for convolution:

![Why convolve](Screenshot%20from%202021-06-06%2018-17-11.png)
The first $x(t)$ expression in the above image is a weighted linear representation of the given signal using shifted impulses.

---

## 4 June 2021

---

![schematic of an LTI system](Screenshot%20from%202021-06-06%2023-50-42.png)
This is what we learned about LTI systems in the previous class.

### Properties of convolution

- Commutativity
  $x_1(t) * x_2(t) = x_2(t) * x_1(t)$

- Distributivity
  $h(t)*[x_1(t) + x_2(t)] = h(t)* x_1(t) + h(t) * x_2(t)$

- Associativity
  $x_1(t)*[x_2(t) + x_3(t)] = [x_1(t)*x_2(t)] + x_3(t)$

**Frequency analysis of LTI systems:**

If we give a complex sinusoid as input to an LTI system, i.e., $x(t) = e^{j\omega_0 t}$, we get a scaled sinusoid with the same frequency.
Working shown below.
![Sol](Screenshot%20from%202021-06-07%2000-03-42.png)

So the complex sinusoid is an EIGENFUNCTION, and the Fourier transform $H(w_0)$ is the EIGENVALUE.

If we give a periodic signal as input to an LTI system, the same happens, as we can represent all periodic signals as a sum of complex sinusoids by their Fourier Series representation. If $x(t)$ is a periodic function, 

$x(t) = \displaystyle\sum_{k = -\infty}^{\infty} a_k e^{j\omega_0 kt}$

On convolving with impulse response $h(t)$, we get

$y(t) = \displaystyle\sum_{k = -\infty}^{\infty} a_k \cdot H(k\omega_0) e^{j\omega_0 kt}$

Cosine can e represented as the sum of complex sinusoids too, in the same way of course.
Working shown below
![Workingcos](Screenshot%20from%202021-06-07%2000-12-13.png)
As seen, the final function is just scaled and phase shifted.

Note, 
$|H(\omega)| \to$ Magnitude response
$\angle H(\omega) \to$ Phase response ($\theta$ in the above image)

An LTI system NEVER adds frequencies. Only propagates or removes existing frequencies. This can be used as a criteria to find LTI systems. Proof is given a few lines from now.

If we give a general aperiodic signal as input, the FT is found by...

- Convolution property Fourier transform:
  
  If $x(t)*h(t) = y(t)$, then
  $X(\omega) \cdot H(\omega) = Y(\omega)$.

  Here, a convolution is converted into a multiplication by FT. This eases calculation by a lot. Now we can apply IFT to $Y(\omega)$ and get $y(t)$ which is what we need. Proof is pretty straightforward. $H(\omega)$ is the frequency response of the LTI system.

  From here we can say that if $X(\omega)$ is zero at any frequency, $Y(\omega)$ is NECESSARILY zero there too, so an LTI system cannot add frequencies to a given signal.

Did problems on convolution.

Ex 1: A delay system, no need for properties
![Delayez](Screenshot%20from%202021-06-07%2000-29-30.png)

Ex 2: A derivative system
![deri](Screenshot%20from%202021-06-07%2011-17-58.png)

This system ~~boosts~~ SCALES the weights of the frequencies.

---

## 7 June 2021

---

LTI systems can be interpreted as ***Frequency selective filters***. Mainly because $H(\omega)$ can nullify any frequencies by having that component with zero wieght, hence excluding that frequency from the final output.
Example q to demonstrate Convolution property:
![Exq1](Screenshot%20from%202021-06-07%2011-11-19.png).
