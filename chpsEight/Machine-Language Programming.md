8.15 ***(Machine-Language Programming)*** Let's create a computer we'll call the Simpletron. As its
name implies, it's a simple machine, but, as we'll soon see, it's a powerful one as well.
The Simpletron runs programs written in the only language it directly understands, that is, 
Simpletron Machine Language, or SML for short.\
&nbsp; &nbsp; The Simpletron contains an **accumulator**-a "special register" in which information is put
before the Simpletron uses that information in calculations or examines it in various ways. All
information in the Simpletron is handled in terms of **words**. A word is a signed four-digit decimal
number, such as *+3364*, *-1293*, *+0007*, *-0001*, etc. The Simpletron is equipped with a 100-word
memory, and these words are referenced by their location numbers *00, 01, ... , 99.*\
&nbsp; &nbsp; Before running an SML program, we must *load*, or place, the program into memory. The first
instruction (or statement) of every SML program is always placed in location *00*. The simulator
will start executing at this location.\
&nbsp; &nbsp; Each instruction written in SML occupies one word of the Simpletron's memory; thus,
instructions are signed four-digit decimal numbers. Assume that the sign of an SML instruction is
always plus, but the sign of a data word may be either plus or minus. Each location in the Sim-
pletron's memory may contain an instruction, a data value used by a program or an unused (and
hence undefined) area of memory. The first two digits of each SML instruction are the *operation
code* that specifies the operation to be performed. SML operation codes are shown in Fig. 8.21





<img src="Fig.%208.21.png " alt="drawing" width="500"/>

##### *Fig. 8.21 | Simpletron Machine Language (SML) operation codes.*



The last two digits of an SML instruction are the *operand*-the address 
of the memory location containing the word to which the operation applies.

Now write SML programs to accomplish each of the following tasks:
- a) Use a sentinel-controlled loop to read positive numbers and compute and display their
    sum. Terminate input when a negative number is entered.
- b) Use a counter-controlled loop to read seven numbers, some positive and some negative,
    and compute and display their average.
- c) Read a series of numbers, and determine and display the largest number. The first num-
    ber read indicates how many numbers should be processed.
