---
title: Signal Processing Project Summaries
author:  
- L Lakshmanan – 2020112024
---

## A Graph Signal Processing Perspective on Functional Brain Imaging

## Team 38

This project was about using the concepts of Graph Signal processing to analyse brain imaging data and to structure the brain as a graph, with nodes depicting regions of the brain, and the edges denoting connections between regions. The weights of the edges were determined by the neuron density of the connection between the regions. This structural mapping can then be represented as an adjacency matrix or list.

The brain can also be mapped in another manner, called a functional mapping. This mapping uses BOLD (Blood Oxygen Level Dependent) signals and changes in the magnetic field, to get an estimate of the activity in the brain at a certain point of time. It then connects parts of the brain based on the functional connectivity between regions, which is determined by the activity in the regions when a task is performed. Graph signal Processing studies the activity at the nodes of these graphs along with the structure of the graph itself. It offers a new viewpoint to analysing the data obtained from the two above mentioned mappings.

For this analysis, we use the Laplacian matrix (also called shift operator), which is defined as

$$L = D - A$$

Where $A$ is the adjacency matrix, and $D$ is the diagonal matrix, whose elements are degrees of nodes in the graph. An experiment led us to the conclusion that when people perform tasks that they are less familiar with, the structural mapping and the functional mapping look similar, and this is said to have "low frequency", while a familiar task results in different areas of the brain working, which results in different structural and functional mappings. Different methods such as the Graph Fourier Transform and Graph signal filtering are used to interpret the imaging data obtained.

---

## The Role of Signal Processing Concepts in Genomics and Proteomics

## Team 35

This paper discusses the various signal processing methods used in gene identification. It also discusses topics like the long range correlation between base pairs in DNA sequences. Mainly, the project discussed the use of filters in identifying genes responsbile for protein synthesis and the functions of a rotein given the amino acid that it is comprised of.

They constructed fillters to detect a "period-3" property, which is symbolic of protein synthesising sequences.

The sequences were encoded as binary strings, on which a DFT was performed. The property was observed by observing the coefficients corresponding to the values at $k = pN/3$, where N is the length of the string.

An anti notch filter and a multi stage filter were implemented to observe known properties of the sequences. Multistage filters could be used obtain a better accuracy due to their stop band. Basically, protein sequences could be identified by using filters because of the distinct properties they possess, which can be singled out using filters.

---
