---
title: Signal Processing Project Report - Analog to Digital Compression
author: 
- Ananya Sane - 2020102007
  
- L Lakshmanan - 2020112024
---

---
geometry:
- top=25mm
- left=25mm
- right=25mm
- heightrounded
...

## Project summary

This paper discusses an efficient alternative for the consistent sampling and reconstruction of a signal.

The major criterion here for reconstruction of signals is consistency. This refers to the reconstruction having the same measurements as the original when measured using the same sampling functions.

The sampling functions and reconstruction fucntions are considered to be linearly independent.

In this paper, the case where we have the same number of sampling functions and reconstruction functions is discussed.

The coefficients of the reconstruction functions are traditionally obtained from the samples by using inner products. This process involves matrix inversion.

The process of inverting a matrix with large amounts of data can be very troublesome and complex. This paper proposes an efficient method to compute the coefficients of consistent reconstruction without involving matrix inversion when we are dealing with shift invariant sampling and shift invariant functions. This method uses the FFT, which is an $O(NlogN)$ operation to achieve a lower complexity.

The signals considered here belong to the Hilbert space $H = L^2(0, l)$.

This Hilbert space limits the functions to the Domain (0, l). For $L^2(R)$, we have
$$\displaystyle\int_{-\infty}^{\infty} |f(x)|^2 < \infty$$

In the paper,

- $f \to signal$

- $l \to length \ of \ signal$

Inner product is defined as
$$\langle f, g\rangle = \frac{1}{l} \displaystyle\int_{0}^{l} f(x)\cdot \overline{g(x)}$$

where $\overline{g(x)}$ is the complex conjugate of $g(x)$.
The measurements of the signal f are represented by
$\{d_n\}_{n = 0}^{N-1} \in H$

They are modeled in the space by the inner product with the sampling functions $\{\psi_n\}_{n = 0}^{N-1}$ as,

$$d_n = \langle f, \psi_n\rangle$$

The subspace spanned by the sampling functions $\{\psi_n\}_{n = 0}^{N-1}$ is called the sampling space. The sampling space is denoted by $V_s$. Sampling is assumed to be shift invariant as,
$$\psi_n(x) = \psi_l(x - x_n)$$

Where

$$\psi_l(x) = \displaystyle\sum_m \psi(x - ml)$$
(Expressing $\psi_l$ as a summation of the kernel $1\psi(x)$) and,

$$x_n = \frac{nl}{N} \ \ \ (n = 0, 1, ..., N-1)$$

The kernel $\psi(x)$ is COMPACTLY SUPPORTED on $[\frac{-r}{2}, \frac{r}{2}]$ with $0 < r < l/N$.

$\hat\psi(\omega)$ is the fourier transform of $\psi(x)$.

Similarly, $\{\varphi_k\}_{k=0}^{N-1}$ spans the reconstruction space. The reconstruction space is denoted by $V_r$. The signal f is reconstructed by a linear combination of these functions with coefficients $c_k$.

$$\overline{f} = \displaystyle\sum_{k = 0}^{N-1}c_k \cdot \psi_k$$

where $\overline{f}$ is the reconstruction.

Now if we take the N dimensional coefficient vectors $d$ and $c$, we need an NxN square matrix to satisfy

$$X\cdot d = c$$

So now, our problem is equivalent to finding a suitable matrix X. By our consistency criterion, whatever matrix X we find must give us outputs that satisfy

$$\langle\overline{f}, \psi_n\rangle = \langle f, \psi_n\rangle \ \ \ (n = 0, 1, ..., N-1)$$

## List of objectives

- To understand an alternative method for reconstruction of signals that does not involve heavy computations like matrix inversion.

- To understand why the FFT is important in creating efficient algorithms like this.

- To take an analog signal and use the methods discussed in the paper to efficiently reconstruct it in MATLAB.

## References

- M. Unser, “Splines: A perfect fit for signal and image processing,”
IEEE Signal Process. Mag., vol. 16, no. 6, pp. 22–38, Nov. 1999.

- <https://www.youtube.com/watch?v=jgi8hbOmUmk>

- <https://www.youtube.com/watch?v=g-eNeXlZKAQ&t=323s>

- <https://www.youtube.com/watch?v=7zx3MT9FgT0>

---
