## Assignment 7

>

    Name : Ravish Ranjan
    Course : MCA
    Semester : 2nd Semester
    RollNO. : 45

## Question

List of Practicals: Introduction to MATLAB Interface and Basic Commands: Using command window, editor, and workspace, Arithmetic operations, using help, clc, clear, who, whos. Variable Assignment and Data Types: Creating scalars, vectors, complex numbers, Type conversion, and precision handling, Matrix Creation and Manipulation: Defining matrices, transposition, reshaping, Indexing, slicing, concatenation, Matrix multiplication, inversion, determinant, eigenvalues.
Assignments:

1. Use MATLAB interface commands such as clc, clear, who, whos, and help, and create variables including a scalar, vectors, and a complex number, performing type conversion (double, single, int32) and comparing precision.
2. Construct a 5×6 matrix A with defined patterns (first row as multiples of 3, last row as squares, remaining rows as random integers), and reshape it into different valid dimensions while preserving the total number of elements.
3. Apply advanced indexing and slicing techniques to extract submatrices, select specific rows/columns, and modify elements using logical conditions; also perform horizontal and vertical concatenation with another compatible matrix.
4. Extract a square submatrix from A and perform matrix operations including transpose, determinant, inverse (if it exists), and eigenvalue computation, and determine whether the matrix is singular or non-singular.
5. Create a new 5×7 matrix with distinct row-wise patterns (arithmetic progression, geometric progression, Fibonacci sequence, prime numbers, alternating signs), reshape it if possible into a square matrix, compute eigenvalues, and compare them with those obtained earlier.

## Answers

### 1

```m
clc;
clear;

% Display help for a specific command
help whos;

%% Creating Variables
% 1. Scalar
s = 42;

% 2. Vectors (Row and Column)
v_row = [1, 2, 3, 4, 5];
v_col = [10; 20; 30];

% 3. Complex Number
z = 3 + 4i;

fprintf('\n--- Current Variables in Workspace ---\n');
who;
whos;

%% Type Conversion and Precision Comparison
% Define a value with high decimal precision
val_pi = pi;

% Convert to different types
val_double = double(val_pi);
val_single = single(val_pi);
val_int32  = int32(val_pi);

% Displaying results
fprintf('\n--- Precision and Type Conversion ---\n');
fprintf('Original (Double): %.20f\n', val_double);
fprintf('Single Precision:  %.20f\n', val_single);
fprintf('Int32 Conversion:  %d\n', val_int32);

%% Calculating Precision Error
% Comparing how much information is lost in 'single' vs 'double'
error_single = abs(val_double - double(val_single));

fprintf('\nPrecision Loss (Double vs Single): %.20e\n', error_single);

%% Using 'whos' to compare memory footprint
fprintf('\n--- Memory Usage Comparison ---\n');
whos val_double val_single val_int32
```

### Output

```bash
whos - List variables in workspace, with sizes and types
    This MATLAB function lists in alphabetical order the names, sizes, and
    types of all variables in the currently active workspace.

    Syntax
      whos
      whos -file filename
      whos global
      whos ___ var1 ... varN
      whos ___ -regexp expr1 ... exprN
      S = whos(___)

    Input Arguments
      var1 ... varN - Variables to display
        character vectors | string scalars
      expr1 ... exprN - Regular expressions
        character vectors | string scalars
      filename - Name of MAT-file
        character vector | string scalar

    Output Arguments
      S - Variable information
        nested structure array

    Examples
      Display Workspace Variable Information
      Display Information on Variables Stored in a MAT-File
      Store Variable Information in a Structure Array
      Display Variable Attribute Information
      List Workspace Variables Within Nested or Anonymous Function

    See also clear, exist, what, who

    Introduced in MATLAB before R2006a
    Documentation for whos
    Other uses of whos


--- Current Variables in Workspace ---

Your variables are:

s      v_col  v_row  z

  Name       Size            Bytes  Class     Attributes

  s          1x1                 8  double
  v_col      3x1                24  double
  v_row      1x5                40  double
  z          1x1                16  double    complex


--- Precision and Type Conversion ---
Original (Double): 3.14159265358979311600
Single Precision:  3.14159274101257324219
Int32 Conversion:  3

Precision Loss (Double vs Single): 8.74227801261895365315e-08

--- Memory Usage Comparison ---
  Name            Size            Bytes  Class     Attributes

  val_double      1x1                 8  double
  val_int32       1x1                 4  int32
  val_single      1x1                 4  single


```

---

### 2

```m
%% 1. Matrix Construction
A = zeros(5, 6);

% Row 1: Multiples of 3
A(1, :) = 3:3:18;

% Row 5 (Last Row): Squares
A(5, :) = (1:6).^2;

% Rows 2, 3, and 4: Random integers
A(2:4, :) = randi([1, 50], 3, 6);

fprintf('--- Original 5x6 Matrix A ---\n');
disp(A);

%% 2. Reshaping the Matrix
% Total elements = 30. Valid dimensions: (1,30), (2,15), (3,10), (5,6), (6,5), (10,3), (15,2), (30,1)

% Reshape to 3x10
A_3x10 = reshape(A, 3, 10);

% Reshape to 15x2
A_15x2 = reshape(A, 15, 2);

% Reshape to a 1D Row Vector (1x30)
A_vector = reshape(A, 1, []);

%% 3. Displaying Reshaped Results
fprintf('\n--- Reshaped to 3x10 ---\n');
disp(A_3x10);

fprintf('\n--- Reshaped to 15x2 ---\n');
disp(A_15x2);

% Verification of total elements
fprintf('\nTotal number of elements: %d\n', numel(A_3x10));
```

### Output

```bash
--- Original 5x6 Matrix A ---
     3     6     9    12    15    18
    41    46    14    49    48     8
    46    32    28     8    25    22
     7     5    48    49    41    46
     1     4     9    16    25    36


--- Reshaped to 3x10 ---
     3     7    46     4    28    12    49    48    25    22
    41     1    32     9    48    49    16    25    18    46
    46     6     5    14     9     8    15    41     8    36


--- Reshaped to 15x2 ---
     3    12
    41    49
    46     8
     7    49
     1    16
     6    15
    46    48
    32    25
     5    41
     4    25
     9    18
    14     8
    28    22
    48    46
     9    36


Total number of elements: 30
```

---

### 3

```m
%% 1. Advanced Slicing and Submatrices
% Extract a submatrix from the center
sub_matrix = A(2:4, 3:5);

% Select specific non-contiguous rows
odd_rows = A([1, 3, 5], :);

% Reverse the column order using slicing
A_reversed = A(:, end:-1:1);

fprintf('--- Submatrix (Center 3x3) ---\n');
disp(sub_matrix);

%% 2. Logical Indexing and Modification
A_modified = A;
mask = A_modified > 20;
A_modified(mask) = -1;

% Extract only the elements that are multiples of 3
multiples_of_3 = A(mod(A, 3) == 0);

fprintf('\n--- Matrix modified by Logical Condition (>20 set to -1) ---\n');
disp(A_modified);

%% 3. Concatenation (Stitching Matrices)
% Create a compatible matrix B
B_horiz = ones(5, 2) * 100;
B_vert  = zeros(2, 6);

% Horizontal Concatenation: [A, B]
% Dimension 2 must match
A_wide = [A, B_horiz]; % Or use: horzcat

% Vertical Concatenation: [A; B]
% Dimension 1 must match (the number of columns)
A_tall = [A; B_vert];  % Or use: vertcat

fprintf('\n--- Horizontally Concatenated Matrix (5x8) ---\n');
disp(A_wide);

fprintf('\n--- Vertically Concatenated Matrix (7x6) ---\n');
disp(A_tall);
```

### Output

```bash
--- Submatrix (Center 3x3) ---
    14    49    48
    28     8    25
    48    49    41


--- Matrix modified by Logical Condition (>20 set to -1) ---
     3     6     9    12    15    18
    -1    -1    14    -1    -1     8
    -1    -1    -1     8    -1    -1
     7     5    -1    -1    -1    -1
     1     4     9    16    -1    -1


--- Horizontally Concatenated Matrix (5x8) ---
  Columns 1 through 7

     3     6     9    12    15    18   100
    41    46    14    49    48     8   100
    46    32    28     8    25    22   100
     7     5    48    49    41    46   100
     1     4     9    16    25    36   100

  Column 8

   100
   100
   100
   100
   100


--- Vertically Concatenated Matrix (7x6) ---
     3     6     9    12    15    18
    41    46    14    49    48     8
    46    32    28     8    25    22
     7     5    48    49    41    46
     1     4     9    16    25    36
     0     0     0     0     0     0
     0     0     0     0     0     0

```

---

### 4

```m
%% 1. Extract a Square Submatrix
S = A(:, 1:5);

fprintf('--- Square Submatrix S (5x5) ---\n');
disp(S);

%% 2. Transpose
S_transpose = S';

%% 3. Determinant and Singularity
det_S = det(S);

fprintf('Determinant of S: %.4f\n', det_S);

% A matrix is singular if its determinant is 0 (or very close to it)
if abs(det_S) < 1e-10
    fprintf('The matrix is SINGULAR (it has no inverse).\n');
    is_singular = true;
else
    fprintf('The matrix is NON-SINGULAR (it is invertible).\n');
    is_singular = false;
end

%% 4. Matrix Inverse
if ~is_singular
    S_inv = inv(S);
    fprintf('\n--- Inverse of S ---\n');
    disp(S_inv);

    % Verification: S * S_inv should be Identity matrix I
    disp(S * S_inv);
else
    fprintf('\nInverse cannot be calculated because the matrix is singular.\n');
end

%% 5. Eigenvalues and Eigenvectors
eigenvalues = eig(S);

fprintf('\n--- Eigenvalues of S ---\n');
disp(eigenvalues);
[V, D] = eig(S);

fprintf('--- Eigenvector Matrix (V) ---\n');
disp(V);

fprintf('--- Diagonal Eigenvalue Matrix (D) ---\n');
disp(D);

%% 6. Summary Table
% Displaying some results in a formatted way
whos S S_transpose S_inv eigenvalues
```

### Output

```bash
--- Square Submatrix S (5x5) ---
     3     6     9    12    15
    40     2    34    20    36
    48    43    38    33     2
    33    47    38     9    14
     1     4     9    16    25

Determinant of S: -2061336.0000
The matrix is NON-SINGULAR (it is invertible).

--- Inverse of S ---
   -0.4191    0.0087    0.0325    0.0034    0.2344
   -0.2398   -0.0252    0.0157    0.0245    0.1652
    0.7380    0.0257   -0.0534   -0.0063   -0.4720
    0.0884   -0.0094    0.0240   -0.0308   -0.0242
   -0.2671    0.0005    0.0001    0.0179    0.1896

    1.0000    0.0000   -0.0000    0.0000   -0.0000
    0.0000    1.0000   -0.0000    0.0000   -0.0000
    0.0000    0.0000    1.0000    0.0000   -0.0000
    0.0000    0.0000   -0.0000    1.0000   -0.0000
   -0.0000    0.0000   -0.0000    0.0000    1.0000


--- Eigenvalues of S ---
   1.0e+02 *

   1.0815 + 0.0000i
   0.1234 + 0.0000i
  -0.2033 + 0.1161i
  -0.2033 - 0.1161i
  -0.0282 + 0.0000i

--- Eigenvector Matrix (V) ---
  Columns 1 through 2

   0.1728 + 0.0000i   0.2273 + 0.0000i
   0.4464 + 0.0000i   0.2506 + 0.0000i
   0.6556 + 0.0000i  -0.7315 + 0.0000i
   0.5486 + 0.0000i  -0.1235 + 0.0000i
   0.2001 + 0.0000i   0.5789 + 0.0000i

  Columns 3 through 4

  -0.1315 - 0.0436i  -0.1315 + 0.0436i
  -0.2720 + 0.4801i  -0.2720 - 0.4801i
  -0.0294 - 0.3227i  -0.0294 + 0.3227i
   0.7241 + 0.0000i   0.7241 + 0.0000i
  -0.2146 - 0.0323i  -0.2146 + 0.0323i

  Column 5

   0.4687 + 0.0000i
   0.2667 + 0.0000i
  -0.8087 + 0.0000i
  -0.0430 + 0.0000i
   0.2312 + 0.0000i

--- Diagonal Eigenvalue Matrix (D) ---
   1.0e+02 *

  Columns 1 through 2

   1.0815 + 0.0000i   0.0000 + 0.0000i
   0.0000 + 0.0000i   0.1234 + 0.0000i
   0.0000 + 0.0000i   0.0000 + 0.0000i
   0.0000 + 0.0000i   0.0000 + 0.0000i
   0.0000 + 0.0000i   0.0000 + 0.0000i

  Columns 3 through 4

   0.0000 + 0.0000i   0.0000 + 0.0000i
   0.0000 + 0.0000i   0.0000 + 0.0000i
  -0.2033 + 0.1161i   0.0000 + 0.0000i
   0.0000 + 0.0000i  -0.2033 - 0.1161i
   0.0000 + 0.0000i   0.0000 + 0.0000i

  Column 5

   0.0000 + 0.0000i
   0.0000 + 0.0000i
   0.0000 + 0.0000i
   0.0000 + 0.0000i
  -0.0282 + 0.0000i

  Name             Size            Bytes  Class     Attributes

  S                5x5               200  double
  S_inv            5x5               200  double
  S_transpose      5x5               200  double
  eigenvalues      5x1                80  double    complex

```

---

### 5

```m
%% 1. Construct the 5x7 Matrix with Specific Patterns
B = zeros(5, 7);

% Row 1: Arithmetic Progression
B(1, :) = 2 + (0:6)*3;

% Row 2: Geometric Progression
B(2, :) = 2 .^ (1:7);

% Row 3: Fibonacci Sequence
fib = zeros(1, 7); fib(1:2) = [1, 1];
for i = 3:7, fib(i) = fib(i-1) + fib(i-2); end
B(3, :) = fib;

% Row 4: Prime Numbers
% primes(20) gives primes up to 20; we take the first 7
p = primes(20);
B(4, :) = p(1:7);

% Row 5: Alternating Signs
B(5, :) = (1:7) .* (-1).^(0:6);

fprintf('--- New 5x7 Patterned Matrix B ---\n');
disp(B);

%% 2. Reshaping to Square
% Total elements = 35. Closest square is 25 (5x5).
B_square = B(:, 1:5);

fprintf('\n--- Reshaped/Truncated Square Matrix (5x5) ---\n');
disp(B_square);

%% 3. Eigenvalue Computation
eig_B = eig(B_square);

% Recall eig_S from previous task
% eig_S = eig(A(:, 1:5));

fprintf('\n--- Eigenvalues of Patterned Matrix B ---\n');
disp(eig_B);

%% 4. Comparison with Previous Matrix
mean_eig_B = mean(abs(eig_B));
mean_eig_S = mean(abs(eigenvalues));

fprintf('\n--- Comparison Analysis ---\n');
fprintf('Mean Magnitude (Previous Matrix S): %.2f\n', mean_eig_S);
fprintf('Mean Magnitude (New Patterned B):   %.2f\n', mean_eig_B);

if mean_eig_B > mean_eig_S
    fprintf('The patterned matrix has higher "spectral energy" (larger eigenvalues).\n');
else
    fprintf('The original matrix has higher "spectral energy".\n');
end
```

### Output

```bash
--- New 5x7 Patterned Matrix B ---
     2     5     8    11    14    17    20
     2     4     8    16    32    64   128
     1     1     2     3     5     8    13
     2     3     5     7    11    13    17
     1    -2     3    -4     5    -6     7


--- Reshaped/Truncated Square Matrix (5x5) ---
     2     5     8    11    14
     2     4     8    16    32
     1     1     2     3     5
     2     3     5     7    11
     1    -2     3    -4     5


--- Eigenvalues of Patterned Matrix B ---
   9.8035 + 4.1467i
   9.8035 - 4.1467i
   1.9332 + 0.0000i
  -0.7701 + 0.6123i
  -0.7701 - 0.6123i


--- Comparison Analysis ---
Mean Magnitude (Previous Matrix S): 34.03
Mean Magnitude (New Patterned B):   5.04
The original matrix has higher "spectral energy".
```
