# RSA_Project
A. Crack the Code
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
Alice and Bob like sending each other secret quotes. Today is Bob's turn and he's planning on sending Alice a quote from a famous person.

Bob also learned about the RSA encryption scheme in his CS111 class and he decided to try it out. He first chooses a number to start with x and converts his quote by assigning numbers to the letters as such:

A=x,B=x+1,...,Z=x+25
Blanks = x+26
Quotation = x+27
Comma = x+28
Period = x+29
Apostrophe = x+30
This time, he chooses x to be 5. He then encoded his message and gave Alice the public key P=(e,n).

Can you help Alice crack the code?

Input
The first line will have two values, e,n which represent the public key pair needed to decrypt the code.

The second line will have one value m which is the length of the encoded message.

The next m integers will represent the encoded message.

Take all the input in using standard input for the programming language you are using (i.e. for C++ it's cin).

Output
Output p, q, phi(n), and d. Note that it should be that p < q, p*q = n and phi(n) = (p-1)*(q-1).

Output the decoded message in integers.

Output the decoded message in characters. If the characters are in the English alphabet, make sure to print them out uppercase.

Output your solution using standard output for the programming language you are using (i.e. for C++ it's cout).
