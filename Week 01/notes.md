================================================================
                    WEEK 01 - DSA JOURNEY NOTES
                    Arrays, Time Complexity & Patterns
                    RIMT University | BCA | Summer Prep
================================================================
  These are my personal notes. Written by me, for me.
  If something took me time to figure out, I wrote it here
  so future me doesn't have to suffer again.
================================================================


----------------------------------------------------------------
  TIME COMPLEXITY
----------------------------------------------------------------

  This was honestly the most confusing thing at first.
  Like why do we even care how many steps a program takes?

  Then it clicked. If your program works fine for 10 elements
  but freezes for 10 million, that's a time complexity problem.
  So we need to think about this from day one.

  The main thing I learned - we always simplify.
  If a loop runs 3 steps each time for n elements, that's 3n.
  But in Big-O we just call it O(n).
  The constant doesn't matter. We only care about HOW IT GROWS.

  Two loops one after another?
  O(n) + O(n) = O(2n) = still just O(n)
  That surprised me at first but makes sense.
  Both loops are still linear. Nothing is multiplying.

  Nested loops though - that's O(n²).
  Because for every step of the outer loop,
  the inner loop runs n times. So it's n x n.

  The tricky one - when loop goes i = i * 2 instead of i++
  That's O(log n). Haven't fully dived into this yet but
  the idea is the loop reaches n way faster because i keeps
  doubling. Will come back to this later.

  Quick reference:
  - One loop                -->  O(n)
  - Two loops one after     -->  O(n)    (still linear)
  - Nested loops            -->  O(n²)
  - Loop doubles each time  -->  O(log n)
  - No loop, direct access  -->  O(1)

----------------------------------------------------------------


----------------------------------------------------------------
  ARRAYS - The Basics
----------------------------------------------------------------

  I already knew arrays before this week but never really
  thought about WHY they work the way they do.

  The big thing I learned:
  The reason we can access any element instantly (arr[100]
  takes the same time as arr[0]) is because all elements sit
  next to each other in memory. The computer does a quick math
  calculation to jump straight to the right address.
  That's why it's O(1) access.

  Why index starts from 0 - never thought about this before.
  Turns out the index is an OFFSET, not a count.
  How far from the start. So the first element is 0 steps
  away from the beginning. Makes total sense now.

  Important gotcha - local variables in C++ don't get a
  default value. They hold whatever garbage was sitting in
  that memory before. Global variables get 0 by default.
  Got caught off guard by this. Now I always initialize.

----------------------------------------------------------------


----------------------------------------------------------------
  ARRAYS - Problems I Solved
----------------------------------------------------------------

  PROBLEM 1: Finding the Largest Element
  ---------------------------------------
  Approach: Store first element as current largest.
  Keep updating when something bigger is found.

  Why start from arr[0] and not 0?
  Because what if all elements are negative?
  Starting from 0 would give a wrong answer.
  Starting from arr[0] is always safe.

  Time complexity: O(n) - one loop through the array.


  PROBLEM 2: Check if Array is Sorted
  -------------------------------------
  Approach: Compare neighbouring elements.
  If any pair is out of order, it's not sorted.

  The thing I liked about my solution - using break the moment
  I find an unsorted pair. No point checking the rest of the
  array once you already know it's not sorted.

  Time complexity:
  - Worst case  -->  O(n)   (fully sorted, check everything)
  - Best case   -->  O(1)   (first pair is already wrong)


  PROBLEM 3: Second Largest Element (most interesting one)
  ---------------------------------------------------------
  Approach: Find the largest first. Then find the largest
  element that is strictly less than the largest.

  The condition I figured out myself:
  arr[i] > secondlargest && arr[i] < largest
  Felt good when this worked.

  The tricky part was duplicates.
  What if array is [5, 5, 5]? There is no second largest.

  Fix: Initialize secondlargest to INT_MIN instead of arr[0].
  Then check at the end if it was ever updated.
  If it's still INT_MIN, there is no second largest.

  Time complexity: O(n) - two separate loops = O(2n) = O(n)

  One loop version - want to try this next.
  The idea: when you find a new largest, the old largest
  naturally becomes the second largest. Haven't coded it yet
  but the logic makes sense in my head.

----------------------------------------------------------------


----------------------------------------------------------------
  PATTERN PROBLEMS - How I Think About Them Now
----------------------------------------------------------------

  When I started, I kept trying to connect everything to i and j.
  Like, i and j MUST be the answer. But that's wrong.

  The real way to think about it:
  - Outer loop = how many ROWS
  - Inner loop = how many times something happens PER ROW
  - What gets printed inside = totally independent, can be anything

  Once I understood this, patterns became much easier.
  The loops are just counters. What I print is my choice.

----------------------------------------------------------------


----------------------------------------------------------------
  THE < vs <= MISTAKE - I made this so many times
----------------------------------------------------------------

  j < i    means the loop runs i-1 times
  j <= i   means the loop runs i times

  One character difference. Massive impact on output.

  I kept getting empty first rows or missing last rows because
  of this. Now I always trace the first iteration manually
  before running the code.

  Rule I made for myself:
  If row 1 should print something, use <=
  If the first iteration should be skipped, use <

----------------------------------------------------------------


----------------------------------------------------------------
  TWO INNER LOOPS IN ONE OUTER LOOP
----------------------------------------------------------------

  This was the unlock for equilateral triangle patterns.
  I was trying to do it in one inner loop and failing.

  The trick - two inner loops can sit side by side inside
  the same outer loop. First prints spaces, second prints stars.
  Same row, different jobs.

  for(int i = 1; i <= n; i++){
      for(int j = 1; j <= n-i; j++)    // spaces
          cout << " ";
      for(int j = 1; j <= 2*i-1; j++)  // stars
          cout << "*";
      cout << endl;
  }

  Formulas I use:
  - Stars in equilateral triangle at row i  -->  2*i - 1
  - Spaces before stars                     -->  n - i

----------------------------------------------------------------


----------------------------------------------------------------
  THE INDEPENDENT COUNTER TRICK - Pattern 13
----------------------------------------------------------------

  Pattern 13 looks like this:
  1
  2 3
  4 5 6
  7 8 9 10

  I was going crazy trying to find a formula using i and j.
  Spent a long time on it.

  Then I realized - the numbers are just 1 2 3 4 5 6...
  They have nothing to do with i and j directly.
  I just needed a separate variable that keeps incrementing.

  int num = 1;
  for(int i = 1; i <= n; i++){
      for(int j = 1; j <= i; j++){
          cout << num << " ";
          num++;
      }
      cout << endl;
  }

  num doesn't reset. It just keeps going up on its own.
  The loops only control the shape. num controls the value.
  This was a big mindset shift for me.

----------------------------------------------------------------


----------------------------------------------------------------
  THE MIDDLE ROW REPEATING BUG - Pattern 9 and 17
----------------------------------------------------------------

  When I combined top triangle + bottom triangle to make
  a diamond shape, the middle row was printing twice.

  Why? Because both loops ran n times.
  Top half last row = middle row
  Bottom half first row = same middle row again

  Fix: change second loop from i <= n to i < n
  Now it runs n-1 times and skips that repeated middle row.

  Same bug showed up in Pattern 17 with alphabets.
  Same fix worked there too.

----------------------------------------------------------------


----------------------------------------------------------------
  PATTERN 17 - The Alphabet Triangle (hardest one today)
----------------------------------------------------------------

  Pattern looks like this:
      A
     ABA
    ABCBA
   ABCDCBA

  I had to manage ONE char variable across THREE loops
  in the same row. That's what made it hard.

  Here's what happens for row i=3:

  Loop 1 prints A B C --- after this, a is sitting at D

  Now I need to print B A (mirror, without repeating C)
  But a is at D, so I need to step back to B first.

  The fix:
  - Decrement a ONCE before the second loop (skips C)
  - Then decrement inside the loop (goes B then A)

  a--;                          // skip the middle character
  for(int j = 1; j < i; j++){
      cout << --a;              // prints B, then A
  }

  Why not just do a -= 2 inside the loop?
  Because that would skip every other character each step.
  The one decrement outside specifically skips the middle.
  The decrements inside handle the actual mirror printing.

----------------------------------------------------------------


----------------------------------------------------------------
  PATTERN 22 - The Number Rectangle (the scary looking one)
----------------------------------------------------------------

  Pattern looks like this for n=4:
  4444444
  4333334
  4322234
  4321234
  4322234
  4333334
  4444444

  When I first saw this I had no idea where to start.
  My brain just stopped.

  The unlock was changing how I thought about the problem.
  Instead of "how do I print this row by row"
  I asked "what is the VALUE at position (i, j)?"

  Answer: it's the distance from the nearest edge.
  Outer border is farthest from center --> value 4
  One layer in --> value 3. And so on.

  Formula for value at any cell (i, j):
  n - min(i, j, (2n-1)-i+1, (2n-1)-j+1) + 1

  Also - grid size is 2*n-1, not n.
  For n=4, grid is 7x7. I missed this at first.

  Full code:
  for(int i = 1; i <= 2*n-1; i++){
      for(int j = 1; j <= 2*n-1; j++){
          cout << n - min({i, j, (2*n-1)-i+1, (2*n-1)-j+1}) + 1;
      }
      cout << endl;
  }

  One formula, two loops. That's the entire pattern.

----------------------------------------------------------------


----------------------------------------------------------------
  TERNARY OPERATOR - What I Learned the Hard Way
----------------------------------------------------------------

  I tried using ternary instead of if/else to save lines.
  It broke because of a type mismatch I didn't expect.

  The bug:
  cout << (j <= i ? j : ' ');
  j is int, ' ' is char. C++ converts char to its ASCII value
  (32) and prints 32 instead of a space.

  The fixes:

  // Works but only when j is single digit (j <= 9)
  cout << (j <= i ? (char)('0' + j) : ' ');

  // Works for any size of n
  cout << (j <= i ? to_string(j) : " ");

  // Always works, most readable
  if(j <= i) cout << j;
  else cout << " ";

  The rule I learned:
  Both sides of a ternary must be the same type. Always.

  When to use which:
  - Small n, no spaces  -->  ternary with char cast is fine
  - Spaces involved     -->  to_string() or just use if/else
  - Large n             -->  never use '0'+j, use to_string()

  Honest takeaway: shorter code is not always better code.
  My if/else was longer but worked perfectly.
  The ternary looked cleaner but had a hidden bug.

----------------------------------------------------------------


----------------------------------------------------------------
  THINGS TO REMEMBER
----------------------------------------------------------------

  Arrays:
  - Always initialize local variables. Never trust garbage values.
  - When finding largest/second largest, start from arr[0] or
    INT_MIN, not from 0. Think about negative number edge cases.
  - Use break early when you already have your answer.

  Patterns:
  - Always trace row 1 and row n manually before running
  - Two inner loops side by side is valid and often the answer
  - Independent variables are not tied to i and j
  - Middle row repeating = one loop is running one extra time
  - For grid problems, ask what value goes at (i,j) first
  - Both sides of ternary must be same type, always

  Mindset:
  - Struggling before watching = active learning
    Watching first = passive learning
  - Shorter code is not always better code
  - When you freeze on a complex pattern, ask
    "What is the value at position (i,j)?"
    not "How do I print this?"

----------------------------------------------------------------


----------------------------------------------------------------
  WHAT'S NEXT
----------------------------------------------------------------

  - Two pointer technique
  - Sliding window
  - More array problems
  - Then Linked Lists

================================================================
  Notes written during summer prep.
  These are my personal takeaways, not a textbook.
================================================================