
6. 14 ***(Rounding Numbers)*** Function floor can be used to round a number to a specific decimal place. The statement
``` C++
y = floor(x * 10 + 0.5) / 10;
```
rounds x to the tenths position (the first position to the right of the decimal point). The statement
``` C++
y = floor(x * 100 + 0.5) / 100;
```
rounds x to the hundredths position (the second position to the right of the decimal point). Write
a program that defines four functions to round a number x in various ways:
- a) *roundToInteger(number)*
- b) *roundToTenths(number)*
- c) *roundToHundredths(number)*
- d) *roundToThousandths(number)*

&emsp; For each value read, your program should print the original value, the number rounded to the
nearest integer, the number rounded to the nearest tenth, the number rounded to the nearest hundredth and the number rounded to the nearest thousandth.

