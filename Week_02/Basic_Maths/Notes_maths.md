================================================================
                    WEEK 02 - DSA JOURNEY NOTES
                    Basic Maths - Digits, Reverse, Palindrome,
                    Armstrong, Divisors, Prime, HCF
================================================================
  These are my personal notes. Written by me, for me.
  If something took me time to figure out, I wrote it here
  so future me doesn't have to suffer again.
================================================================


----------------------------------------------------------------
  HOW I APPROACHED BASIC MATHS
----------------------------------------------------------------

  The approach in this section was different from STL.
  Concept explained first, then a problem right after.
  Instead of just watching the solution, I started pausing
  after the concept explanation and attempting the problem
  myself first.

  If a problem felt too easy after solving it,
  I did an upgraded version that had a twist or an edge case
  that made me actually think.
  That's where the real learning happened.

----------------------------------------------------------------


----------------------------------------------------------------
  COUNTING DIGITS
----------------------------------------------------------------

  Simple idea. Extract digits one by one using %10 and /10
  and count how many times you do it.

  First version used while loop:
  while(n > 0){ count++; n = n/10; }

  Then I realized -- what if n is 0?
  The while loop never runs. count stays 0.
  But 0 is a valid number and has 1 digit.

  Fix: switched to do while so loop runs at least once.

  Then realized -- what if n is negative?
  Changed condition from n > 0 to n != 0.
  Negative numbers naturally work because n/10 on a
  negative number keeps shrinking toward 0 the same way.

  The log method -- this blew my mind a little.
  Instead of looping at all:
  int count = (int)(log10(n)) + 1;

  log10(123) = 2.something. Cast to int = 2. Add 1 = 3 digits.
  No loop. Direct answer. O(1) instead of O(log n).

  But 0 breaks log10. So handle it separately:
  if(n == 0) count = 1;
  else count = (int)(log10(abs(n))) + 1;

  Two methods. Both valid. Both worth knowing.
  Loop method is easier to explain step by step.
  Log method is faster and impresses in interviews.


----------------------------------------------------------------
  REVERSE NUMBER
----------------------------------------------------------------

  The formula: rev = rev * 10 + last digit
  Extract last digit with %10, remove it with /10, repeat.

  I had a funny idea -- what if I just print each digit
  as I extract it? That would print them in reverse order.
  Turns out that works! But there's a difference:

  Printing digits    --> you SEE the reverse but can't use it
  Storing with formula --> you HAVE the reverse as an actual number

  For palindrome check later, I needed the stored version.
  So the formula matters.

  Negative numbers -- I was worried I'd need to handle them.
  Traced through -1234 manually and realized the math
  handles it naturally. The negative sign carries through
  all the operations and the result comes out negative too.
  Don't add code you don't need. Leave it alone.

  Leading zeros -- reversing 100600 gives 6001, not 006001.
  Integers can't store leading zeros. 006001 and 6001
  are the same number to a computer.
  If you need to preserve leading zeros, you'd need strings.
  That comes later in the course.


----------------------------------------------------------------
  PALINDROME
----------------------------------------------------------------

  Reverse the number. Compare with original.
  If they're equal, it's a palindrome.

  The key thing I remembered from the reverse program:
  n gets destroyed inside the loop because I keep dividing it.
  So I need to save the original BEFORE the loop runs.
  int dup = n; -- store it first, then reverse n.

  Negative numbers are never palindromes mathematically.
  In interviews, always ask -- should I handle negatives?
  Shows you think about edge cases before coding.
  Quick fix if needed: if(n < 0) print no and return.

  UPGRADED -- palindrome range:
  This one crashed my brain for a while.
  I kept modifying the wrong variables inside the loop.
  The lesson that came out of this:

  Never modify your loop counter (i) or your boundary
  variables (a, b) inside the loop body.
  Always make a throwaway copy for calculations.
  I called mine "decoy". decoy = i at the start of each
  iteration. Do everything to decoy. Leave i alone.

  Also -- rev needs to reset to 0 at the start of each
  iteration. If it's declared outside the loop it keeps
  adding onto the previous number's value. Nasty bug.


----------------------------------------------------------------
  ARMSTRONG NUMBER
----------------------------------------------------------------

  A number where sum of each digit raised to the power of
  (total number of digits) equals the original number.
  153 = 1³ + 5³ + 3³ = 1 + 125 + 27 = 153. Armstrong.

  It's not always cube. It's power of however many digits
  the number has. 3 digit numbers = cube. 4 digit = 4th power.

  First version hardcoded the cube (ld*ld*ld).
  Works for 3 digit numbers but fails for 4 digit armstrong
  numbers like 8208.

  Fix: count digits first with log10, then use pow():
  sum += (int)pow(ld, totalDigits);

  THE POW() TRAP:
  pow() returns a double. On some compilers it returns
  something like 124.9999999 instead of a clean 125.
  When you cast that to int, it becomes 124. Off by one.
  This caused 153 to not be identified as armstrong.
  The fix: use round() before casting.
  sum += (int)round(pow(ld, totalDigits));
  round() fixes 124.999 back to 125 before int truncates it.
  This is a real floating point precision issue that trips
  up even experienced programmers. Good to find it early.


----------------------------------------------------------------
  PRINT DIVISORS
----------------------------------------------------------------

  Simple approach -- loop from 1 to n, print if n%i == 0.
  Clean, sorted output, no edge cases. O(n).

  Then I learned the optimized approach.
  Divisors always come in pairs. If 2 divides 36, then 18
  also divides 36. Both sides of the pair are on opposite
  sides of the square root.
  So loop only till √n and grab both at once. O(√n).

  For a number like 1,000,000:
  O(n)   --> 1,000,000 steps
  O(√n)  --> 1,000 steps
  That difference matters.

  The edge case with √n approach:
  When i and n/i are the same (like 6 and 6 for 36),
  print only once. Check with i != n/i, not i != sqrt(n).
  Avoid comparing int to double -- floating point problems
  again, same lesson as armstrong.

  VERSION with vectors:
  Store divisors in a vector, sort, then print.
  Had a bug -- declared vector<int> v(n) which creates
  n zeros before my actual divisors get pushed.
  Fix: vector<int> v; -- empty declaration, no size.

  SUBTLE BUG I CAUGHT:
  if(n%i==0) v.push_back(i);
  if(n/i != i) v.push_back(n/i);  // wrong!

  Second condition doesn't check if i actually divides n.
  It was pushing n/i even when i wasn't a divisor.
  Fix: nest the second if inside the first:
  if(n%i==0){
      v.push_back(i);
      if(n/i != i) v.push_back(n/i);
  }

  THE TRADEOFF I UNDERSTOOD:
  Simple loop  --> O(n), sorted automatically, no edge cases
  √n loop      --> O(√n + k log k), unsorted, needs extra care
  In interviews -- present simple first, then optimize.
  Knowing both and explaining the tradeoff is what they want.


----------------------------------------------------------------
  PRIME NUMBER
----------------------------------------------------------------

  A prime number has exactly 2 divisors -- 1 and itself.

  First version counted all divisors and checked if count == 2.
  Clean and clever. Works perfectly.

  Optimized version -- loop only till √n.
  If any number between 2 and √n divides n, it's not prime.
  If none do, it's prime.

  Used a boolean flag -- isPrime = true at the start.
  If divisor found, set isPrime = false and break immediately.
  Print once after the loop. Not inside it.

  THE MISTAKE I MADE:
  I wrote if(isPrime = true) instead of if(isPrime == true).
  Single = is assignment. Double == is comparison.
  I was accidentally changing isPrime instead of checking it.
  Every time I see a single = in an if condition now,
  I double check. This is a classic bug.

  Also had break outside the if accidentally:
  if(n%i==0)
      isPrime = false;
  break;  // this ran every iteration, not just when divisor found

  Without curly braces only the first line belongs to if.
  Always use {} when the if body has more than one line.
  Actually -- just always use {}. Period.

  Edge case -- 1 is not prime by definition.
  Loop never runs for n=1 because sqrt(1)=1 and loop
  starts at 2. So isPrime stays true incorrectly.
  Fix: if(n==1) isPrime = false; before the loop.


----------------------------------------------------------------
  HCF
----------------------------------------------------------------

  My first instinct -- find all divisors of both numbers,
  find common ones, pick the largest.
  That works! And I coded it. But it's slow.

  Simple optimized version -- loop from 1 to smaller number,
  keep updating hcf whenever i divides both a and b.
  Last value of hcf when loop ends is the answer.

  Then I learned the Euclidean algorithm.
  This was genuinely elegant. No finding divisors at all.

  while(a > 0 && b > 0){
      if(a > b) a = a % b;
      else b = b % a;
  }
  if(a == 0) hcf = b;
  else hcf = a;

  Keep taking remainder of the larger with the smaller.
  When one becomes 0, the other is the HCF.
  Time complexity: O(log(min(a,b))) -- incredibly fast.

  For numbers like 1,000,000 and 999,999:
  Simple loop  --> ~999,999 steps
  Euclidean    --> about 20 steps
  That's the power of a good algorithm.

  Understood it, implemented it myself, worked first try.


----------------------------------------------------------------
  TIME COMPLEXITY PATTERNS I NOW RECOGNIZE
----------------------------------------------------------------

  O(1)        -- no loop, direct formula (log10 digit count)
  O(log n)    -- dividing by something each step (digit loop)
  O(√n)       -- loop till square root (divisors, prime check)
  O(n)        -- single loop through n elements
  O(n log n)  -- sorting n elements
  O(n²)       -- nested loops

  When you combine operations sequentially, you ADD them.
  O(√n) + O(k log k) for the optimized divisors solution.
  The dominant term usually wins in large inputs.


----------------------------------------------------------------
  THINGS TO REMEMBER
----------------------------------------------------------------

  General:
  - Never modify loop counter (i) or boundary variables inside loop
  - Always make a throwaway copy (decoy, dup) for calculations
  - Reset variables like rev and sum inside the loop, not outside
  - Always use {} with if statements. One day it will save you.
  - Single = assigns. Double == compares. Check every if condition.

  pow() and floating point:
  - pow() returns double, not int
  - Can return 124.9999 instead of 125 on some compilers
  - Always use (int)round(pow(...)) not just (int)pow(...)
  - Avoid comparing int to sqrt() result directly
  - Use i != n/i instead of i != sqrt(n)

  Vectors:
  - vector<int> v(n) creates n zeros -- not what you want here
  - vector<int> v; creates empty vector -- push_back freely
  - Always nest the partner condition inside the divisor check

  Mindset:
  - Pause the video. Attempt first. Watch after.
  - Easy problem? Do an upgraded version.
  - When brain crashes -- slow down, trace on paper first
  - Know two approaches for every problem.
    Simple one to explain clearly. Optimized one to impress.
  - Struggling before solving = active learning.
    Watching someone else solve = passive learning.
    Only one of these actually builds skill.

----------------------------------------------------------------


================================================================
  Notes written during summer prep.
  These are my personal takeaways, not a textbook.
================================================================