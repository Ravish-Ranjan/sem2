## Assignment 7

>

    Name : Ravish Ranjan
    Course : MCA
    Semester : 2nd Semester
    RollNO. : 45

### Question 1 : Write a program to compute the sum of the following series. [use for loop]

$$
S = 1 + \frac{1}{2} + \frac{1}{3} + \dots + \frac{1}{n}
$$

```m
% Q1: Sum of harmonic series using for loop
n = input('Enter n: ');
S = 0;
for i = 1:n
    S = S + 1/i;
end
fprintf('Sum = %.4f\n', S);
```

```
>> pract2a
Enter n: 10
Sum = 2.9290
>>
```

### Question 2 : Write a program to generate Fibonacci series up to n terms using while loop.

```m
% Q2: Fibonacci series using while loop
n = input('Enter number of terms: ');
a = 0; b = 1; count = 1;
fprintf('Fibonacci Series: ');
while count <= n
    fprintf('%d ', a);
    temp = a + b;
    a = b;
    b = temp;
    count = count + 1;
end
fprintf('\n');
```

```
>> pract2b
Enter number of terms: 10
Fibonacci Series: 0 1 1 2 3 5 8 13 21 34
>>
```

### Question 3 : Write a program to find the sum of all even numbers from 1 to n.

```m
% Q3: Sum of even numbers from 1 to n
n = input('Enter n: ');
S = 0;
for i = 2:2:n
    S = S + i;
end
fprintf('Sum of even numbers = %d\n', S);
```

```
>> pract2c
Enter n: 13
Sum of even numbers = 42
>>
```

### Question 4 : Write a program to accept a number from the user and check whether it is a prime number or not.

```m
% Q4: Prime number check
num = input('Enter a number: ');
isPrime = true;
if num < 2
    isPrime = false;
end
for i = 2:floor(sqrt(num))
    if mod(num, i) == 0
        isPrime = false;
        break;
    end
end
if isPrime
    fprintf('%d is a prime number.\n', num);
else
    fprintf('%d is not a prime number.\n', num);
end
```

```
>> pract2d
Enter a number: 593
593 is a prime number.
>> pract2d
Enter a number: 567
567 is not a prime number.
>>
```

### Question 5 : Write a program to find the largest among three numbers.

```m
% Q5: Find largest of three numbers
a = input('Enter first number: ');
b = input('Enter second number: ');
c = input('Enter third number: ');
if a >= b && a >= c
    fprintf('Largest number is %d\n', a);
elseif b >= a && b >= c
    fprintf('Largest number is %d\n', b);
else
    fprintf('Largest number is %d\n', c);
end
```

```
>> pract2e
Enter first number: 53
Enter second number: 55
Enter third number: 57
Largest number is 57
>>
```

### Question 6 : Write a program to accept year from the user and check whether it is a leap year or not.

```m
% Q6: Leap year check
year = input('Enter a year: ');
if (mod(year, 400) == 0) || (mod(year, 4) == 0 && mod(year, 100) ~= 0)
    fprintf('%d is a leap year.\n', year);
else
    fprintf('%d is not a leap year.\n', year);
end
```

```
>> pract2f
Enter a year: 1857
1857 is not a leap year.
>> pract2f
Enter a year: 1860
1860 is a leap year.
>>
```

### Question 7 : Write a function that returns the sum of digits of a number.

```
Sample input : 236
Sample output : 11
```

```m
% Q7: Sum of digits function (save as sumOfDigits.m)
function total = sumOfDigits(n)
    n = abs(n);  % handle negative numbers
    total = 0;
    while n > 0
        total = total + mod(n, 10);
        n = floor(n / 10);
    end
end

% calling it with custm input:
num = input("Enter number to get it's digit's sum : ");
result = sumOfDigits(num);
fprintf("Sum of digits of %d is : %d\n",num,result);
```

```
>> pract2g
Enter number to get it's digit's sum : 1024
Sum of digits of 1024 is : 7
>> pract2g
Enter number to get it's digit's sum : 1947
Sum of digits of 1947 is : 21
>>
```

### Question 8 : Create a user-defined function to compute factorial of a number.

```m
% Q8: Factorial function (save as myFactorial.m)
function result = myFactorial(n)
    if n == 0 || n == 1
        result = 1;
    else
        result = n * myFactorial(n - 1);
    end
end

% calling the function:
num = input("Enter a number to get nth factorial number : ");
res = myFactorial(num);
fprintf("Result : %d\n",res);
```

```
>> pract2h
Enter a number to get nth factorial number : 10
Result : 3628800
>> pract2h
Enter a number to get nth factorial number : 6
Result : 720
>>
```

### Question 9 : Write a function that returns the reverse of a given number.

```m
% Q9: Reverse a number (save as reverseNumber.m)
function rev = reverseNumber(n)
    rev = 0;
    n = abs(n);
    while n > 0
        rev = rev * 10 + mod(n, 10);
        n = floor(n / 10);
    end
end

% calling:
num = input("Enter a number to reverse : ");
res = reverseNumber(num);
fprintf("Result : %d\n",res);
```

```
>> pract2i
Enter a number to reverse : 1024
Result : 4201
>> pract2i
Enter a number to reverse : 1857
Result : 7581
>>
```

### Question 10 : Write a program to compute the sum of the following series:

$$
S = a + \frac{a}{2} - \frac{a}{3} + \dots + n
$$

```m
% Q10: Alternating series sum
a = input('Enter value of a: ');
n = input('Enter number of terms: ');
S = 0;
for i = 1:n
    if mod(i, 2) == 0
        S = S - a/i;   % even terms are subtracted
    else
        S = S + a/i;   % odd terms are added
    end
end
fprintf('Sum of series = %.4f\n', S);
```

```
>> pract2j
Enter value of a: 2
Enter number of terms: 5
Sum of series = 1.5667
>> pract2j
Enter value of a: 10
Enter number of terms: 10
Sum of series = 6.4563
>>
```
