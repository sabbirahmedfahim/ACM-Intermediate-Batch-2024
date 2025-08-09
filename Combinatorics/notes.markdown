## Permutations vs Combinations

- **Order matters** → **Permutations**
- **Order doesn't matter** → **Combinations**

---

### 🔢 Formula:

**choice<sup>box</sup> = permutation**

---
permutation:
10 10 10 10

=> 10E4

Number of permutations: `n!`

Example:

{1, 2, 3, 4, 5}
5 4 3 2 1 --> choice

---

### 👥 Combinations:

- Number of ways we can group
- When number of choices **do not reduce**:

a^b

---


// add some tasks

### MOD

```cpp
a + b = ((a % mod) + (b % mod)) % mod

a - b = (((a % mod) - (b % mod)) + mod) % mod

a × b = ((a % mod) × (b % mod)) % mod
```

### Modular Division

```cpp
a / b = a × (b^-1)

(a / b) % mod = ((a % mod) * ((b^-1) % mod)) % mod
```

modular inverse of b = b^-1 <br>
= Pow(b, m-2)
= b^(m-2)

```cpp
(A / B) = ((A % Mod) * ( BinExp(B , Mod - 2) % Mod)) % Mod;
```

nCr

nCr = n! / r! (n - r)! <br>
=> ((n! * ((r!)^mod-2)) % mod) * ((n - r)!)^mod-2

### Fast Inverse of Factorial

1 / n! <br>
=> 1 / n * (n - 1)! <br>
=> 1 / (n - 1)!

if we know the fact of n, then can find 1 to n-1 at O(1)

2^n = nC0 + nC1 + ..... + nCn


