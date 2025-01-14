/*
   The imprecision of floating-point arithmetic can have disastrous
effects. On Feburary 25, 1991, during the first Gulf War, an American
Patriot Missile battery in Dharna, Saudi Arabia, failed to intercept
an incoming Iraqi Scud missile. The Scud struck an American Army barracks
and killed 28 soldiers. The US General Accounting Office(GAO) conducted
a detailed analysis of the failure and determined that the underlying 
cause was an imprecision in a numeric calculation.
   The Patriot system contains an internal clock, implemented as a
counter that is incremeented every 0.1 seconds. To determine the time
in seconds, the program would multiply the value of this counter by a
24-bit quantitiy that was a fractional binary approximation to 1/10.
In particular, the binary representation of 1/10 it sht nonterminating
sequence. The program approximated 0.1, as a value of x, by considering
just the first 23 bits of the sequence to the right of the binary point
x = 0.00011001100110011001100

A. What is the binary representation of 0.1 - x?
Ans) 0.00000000000000000000000[1100]

B. What is the appoximate deciaml value of 0.1 - x?
Ans) 2^(-20) * 0.1 ~= 9.54 * 10^(-8) (s/0.1s)

C. The clock starts at 0 when the system is first powered up and
keeps counting up from there. In this case, the system had been
running for around 100 hours. What was the difference between the
actual time and the time computered by the software?

Ans) (9.54 * 10 ^ (-8))(s/0.1s) * 36000(0.1s) * 100 ~= 0.343s

D. The system prdicts where an incoming missile will appear based on
its velocity and the time of the last radar detection. Given that a
Scud travels at around 2,000 meter per second, how far off was its
prediction?

Ans) 0.343 s * 2000 m/s = 686 m
*/
