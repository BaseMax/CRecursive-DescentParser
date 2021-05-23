# C Recursive-Descent Parser

A simple recursive-descent parser for evaluating mathematical formulae using pure C.

## Using

```bash
gcc main.c -o calc
./calc
```

### Examples

```bash
calc> 5+4
9.000000
calc> 5-4
1.000000
calc> 5*4
20.000000
calc> 5/2
2.500000
calc> 5/0
runtime math error: cannot divide by zero
5.000000
calc> (5+4)
9.000000
calc> 5*(4-2)
10.000000
```

