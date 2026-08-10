================================================================
                    WEEK 03 - DSA JOURNEY NOTES
                    Recursion - Basics, Two Pointers,
                    Multiple Recursion, Time Complexity
================================================================
  These are my personal notes. Written by me, for me.
  If something took me time to figure out, I wrote it here
  so future me doesn't have to suffer again.
================================================================


----------------------------------------------------------------
  HOW I APPROACHED RECURSION
----------------------------------------------------------------

  Went in knowing the theory -- function calls itself till
  base case is met. Hadn't written a single line of recursive
  code before this week though.

  Same approach as basic maths -- attempt first, watch theory
  after if I get stuck, upgrade the problem if it felt too easy.

  This week was different from basic maths in one way --
  almost every problem I solved had at least one real bug in
  it. Not typos. Actual "why is this infinite looping" or
  "why is this crashing" bugs. Good. That's where it stuck.

----------------------------------------------------------------


----------------------------------------------------------------
  PRINT N TIMES / PRINT 1 TO N / N TO 1
----------------------------------------------------------------

  Simplest possible recursion. Base case: i > n, return.
  Recursive case: print, then call yourself with i+1.

  THE MISTAKE I MADE:
  Function was declared to return int, but in the recursive
  branch I just called print(i+1,n,name) without a return
  in front of it. Compiled fine, "worked" fine. Still
  undefined behavior -- a function that promises to return
  something has to return something on EVERY path, not just
  the base case.
  Fix: either return the recursive call, or just make the
  function void since it wasn't using the return value
  for anything anyway.

  PRINT N TO 1:
  First attempt used two parameters and got confused about
  which one was moving and which one was fixed. Ended up
  printing every number twice because I was passing the
  values into the wrong slots on the recursive call.
  Realized halfway through -- I don't even need two
  parameters here. One counter counting down to 1 is enough.
  Simpler code, fewer places to make a mistake.

  Lesson: before adding more parameters to "help", check if
  you actually need them. Fewer moving parts = fewer bugs.


----------------------------------------------------------------
  BACKTRACKING STYLE (where you print matters)
----------------------------------------------------------------

  Same print-N-times type problem, but instead of printing
  BEFORE the recursive call, print AFTER it.

  This flips the order of the output. If you're counting
  UP (1,2,3...n) but printing after the recursive call, you
  actually get output in ASCENDING order despite going in
  "backwards." If you print before, you get it in the same
  order you're counting.

  THE MISTAKE I MADE:
  Wrote the base case as i > n (same as the up-counting
  version) but then in this version I was counting i DOWN,
  starting from n and going to n-1, n-2... The condition
  i > n can never become true when i is decreasing from n.
  So the recursion never stopped -- infinite loop, straight
  toward a crash.
  Fix: match your base case direction to which way your
  variable is actually moving. If i is counting down,
  your base case has to catch it going too LOW, not too high.

  Core takeaway: work before recursive call = direction
  follows how you're stepping. Work after recursive call =
  direction reverses. This is basically the whole trick
  behind backtracking-style recursion.


----------------------------------------------------------------
  SUM OF FIRST N NUMBERS -- Parameterized vs Functional
----------------------------------------------------------------

  Two ways to do the same problem. Didn't get functional
  until I tried parameterized on my own first.

  PARAMETERIZED (figured this out myself before knowing
  it had a name):
  Carry an extra "sum so far" parameter along. Update it
  BEFORE calling yourself again. Only output it at the
  base case.

  void sumP(int i, int n, int sum){
      if(i > n){ cout << sum; return; }
      sumP(i+1, n, sum+i);
  }

  FUNCTIONAL (this one actually broke my brain for a bit):
  No accumulator. Function itself RETURNS a value, and you
  build the answer using the result of calling yourself.

  int sumF(int n){
      if(n == 0) return 0;
      return n + sumF(n-1);
  }

  What actually made it click -- someone asked me, if you
  already know sum(1 to 4) = 10, how do you get sum(1 to 5)?
  I answered instantly without thinking about code: just add
  5 to it. That's literally the entire function. The "leap
  of faith" thing -- trust that sumF(n-1) already works
  correctly, don't try to trace the whole stack in your head,
  just figure out what ONE call needs to do with that trusted
  result.

  THE MISTAKE I MADE (twice actually):
  First attempt -- called sumf(n-1) on one line and threw the
  result away completely, then separately wrote n+(n-1) using
  raw numbers instead of the recursive call's actual answer.
  Confused "n-1 the number" with "the sum returned by calling
  sumf(n-1)." Those are NOT the same thing.

  Second attempt -- fixed the above but then called
  sumf(n-1) TWICE -- once into a variable I never used, and
  again inside the return line. Doubled the work for nothing.
  Fix: call it once, store it in a variable, reuse that
  variable. Same principle as not modifying loop counters
  from week 2 -- don't redo work you've already done.


----------------------------------------------------------------
  FACTORIAL
----------------------------------------------------------------

  Same functional pattern as sum, multiply instead of add.
  Base case n==0 returns 1 (not 0 -- 0! is 1 by definition,
  learned this the hard way by almost getting it wrong).

  int factorial(int n){
      if(n == 0) return 1;
      return n * factorial(n-1);
  }

  No new bugs here -- this is the one that told me the
  functional pattern had actually stuck from the sum problem.


----------------------------------------------------------------
  REVERSE AN ARRAY -- Two Pointer Recursion
----------------------------------------------------------------

  New shape of problem. Instead of one moving index, you use
  TWO pointers -- one from the left, one from the right.
  Swap what they point to, move them toward each other,
  repeat until they meet or cross.

  if(l >= r) return;
  swap(l, r);
  recurse(l+1, r-1, ...);

  THE MISTAKE I MADE (the big one this week):
  Used l == r as the base case instead of l >= r.
  Works completely fine for ODD length arrays because the
  two pointers land on the exact same middle index at some
  point. Completely BREAKS for EVEN length arrays -- the
  pointers just cross each other and skip past being equal
  entirely. So == never triggers, recursion keeps going,
  reads memory outside the array. Undefined behavior.
  Found this by manually tracing a 4-element array on paper
  and realizing l and r never actually landed on the same
  number, they just swapped places past each other.
  Fix: use >= not ==. Always, for any two-pointer recursion.

  ALSO caught this one before it became a real bug --
  wrote *++l and *--r originally, which dereferences the
  pointer (reads the value) and does nothing with it. What
  I actually wanted was just to move the pointer itself:
  ++l and --r, no dereference needed.

  Did this THREE different ways as practice:
  1. raw pointers (int*) -- moved with ++l / --r directly
  2. vector<int>& with plain int indices -- pass l+1, r-1
     into the next call instead of mutating a pointer
  3. same idea again later for palindrome check on a string

  Type mismatch bug along the way -- tried passing a plain
  C-style array (int arr[n]) into a function expecting
  vector<int>&. Those are different types even though both
  use arr[i] syntax. Compiler caught it immediately though,
  which is honestly the nice kind of bug -- fails loud
  instead of silently doing the wrong thing.

  Also broke vector usage briefly -- declared vector<int> arr;
  (empty, size 0) then tried writing directly into arr[i] in
  a loop. Doesn't work, there's nothing there yet. Needed
  either vector<int> arr(n) to preallocate, or push_back(x)
  to grow it one element at a time. Used push_back in the end.

  PERSONAL TAKEAWAY:
  Pointer version is actually easier for me to trace and
  debug logic on, even though everyone says it's the "harder"
  version. Plan going forward -- write pointer version first
  to verify my logic is right, then convert to index version
  for the actual answer, since index-based is what's expected
  in interviews and it's faster once I trust myself with it.


----------------------------------------------------------------
  PALINDROME CHECK -- same two pointer idea, but comparing
----------------------------------------------------------------

  Same skeleton as reverse array, except instead of swapping
  at l and r, you COMPARE them. Any mismatch = not a
  palindrome, return false immediately.

  bool isPalindrome(int l, int r, string &s){
      if(l >= r) return true;
      if(s[l] != s[r]) return false;
      return isPalindrome(l+1, r-1, s);
  }

  Tried this first using char* pointers on purpose, even
  though it's the "harder" way, because I wanted to actually
  understand it instead of taking the easy path immediately.

  THE MISTAKES I MADE (several, in order):
  1. Wrote n[*l] != n[*r] -- used the CHARACTER value pointed
     to by l as an INDEX into the string, instead of just
     comparing the characters directly. Should've just been
     *l != *r.
  2. Forgot the base case entirely at one point. Traced
     through "madam" and realized it was accidentally reading
     characters OUTSIDE the string once the pointers crossed,
     and just got lucky because palindromes are symmetric so
     the garbage comparisons happened to still match by
     coincidence. Scary bug -- "works" by accident, not by
     correctness.
  3. Put the base case check l>=r combined with the mismatch
     check using ||, and it returned false for EVERY input,
     no matter what. Had to think through this one --
     reaching l>=r means every pair before it already matched,
     so that case should return TRUE, and it needs to be
     checked SEPARATELY, before the mismatch check, so you
     never dereference an out of bounds pointer.
  4. Called the recursive function but discarded what it
     returned, then just hardcoded "return true" right after
     regardless of what the deeper call actually found. Tested
     with "abczba" (first and last letters match, but the
     whole thing isn't a palindrome) and it incorrectly said
     true. Fixed by writing "return isPalindrome(...)" instead
     of calling it and throwing the result away.

  Same exact category of bug as the sum/fibonacci problems --
  I keep forgetting to actually USE the recursive call's
  return value instead of ignoring it.

  Redid the whole thing with plain int indices afterward --
  s[l] and s[r] instead of *l and *r. Cleaner, same logic.


----------------------------------------------------------------
  FIBONACCI -- first time using MULTIPLE recursion
----------------------------------------------------------------

  Every problem before this made exactly ONE recursive call
  per function call. Fibonacci needs TWO.

  F(n) = F(n-1) + F(n-2)

  long long fib(long long n){
      if(n == 0) return 0;
      if(n == 1) return 1;
      return fib(n-1) + fib(n-2);
  }

  THE MISTAKE I MADE:
  Wrote fib(n-1)+fib(n-2); as its own line doing nothing,
  then separately wrote return fib(n); right after -- calling
  fib on the exact SAME n again. That's not recursion moving
  toward a base case, that's just calling the same thing
  forever. Instant infinite recursion / crash.
  Fix: return the combined expression directly, don't call
  fib(n) again afterward. Exact same mistake pattern as the
  sum problem, just showed up again in a new shape.

  THE OVERFLOW BUG:
  Tried n=50, got a random negative number back. Thought it
  was a logic bug at first -- it wasn't. The actual answer
  for fib(50) is 12,586,269,025, which is bigger than what
  a normal int can hold, so it silently overflows into
  garbage (including negative values).

  Tried to fix it and got it WRONG the first time -- changed
  the PARAMETER n to long long but left the function's
  RETURN TYPE as int. Still broke, still slow, still wrong.
  The input n (like 50) was never the problem, it's the huge
  VALUE being calculated and returned that overflows. Had to
  change the return type itself to long long, not just the
  parameter type.

  ALSO noticed without needing to fix it -- n=50 took a
  genuinely long time to actually finish running. This isn't
  a bug, it's just how naive recursive fibonacci behaves --
  it keeps recalculating the same smaller values over and
  over again instead of remembering them. Exponential time.
  This is apparently the exact reason memoization exists,
  which I'll hit later under DP. Good to feel the slowness
  firsthand before learning the fix for it.


----------------------------------------------------------------
  TIME COMPLEXITY -- clearing up my own confusion
----------------------------------------------------------------

  Order from best to worst:
  O(1) < O(log n) < O(sqrt n) < O(n) < O(n log n)
       < O(n^2) < O(2^n) < O(n!)

  Went in thinking log n might be the WORST possible
  complexity because of something my professor said. That's
  backwards -- log n is one of the BEST. Was probably a
  specific statement about one algorithm's worst case (like
  binary search) that I generalized wrong. Need to actually
  ask what the exact context was.

  log n -- halves the problem every step. log(1 billion) is
  only about 30 steps. Traced this myself by literally
  dividing a billion by 2 repeatedly on paper.

  sqrt n -- shrinks slower than log n but still way better
  than plain n. Realized I already used this without knowing
  the name -- week 2's optimized prime check and divisors
  code only looped up to sqrt(n), never all the way to n.

  n log n -- think "log n layers, and each layer does n total
  work." Merge sort is the classic example -- splits the
  array in half each time (that's the log n part, the number
  of levels), and at every level touches all n elements once
  (that's the n part). Multiply them -- n times log n.
  STL's sort() runs at this speed, which is why it's
  considered "fast" sorting.

  n^2 -- nested loop where the inner loop only shrinks by a
  constant amount each pass instead of by half. Bubble sort's
  passes are the example -- n, then n-1, then n-2... down to
  1, which adds up to roughly n^2/2, so O(n^2) overall. Tried
  connecting this to n log n at first and got corrected --
  linear shrinkage (n, n-1, n-2...) is n^2 territory, only
  HALVING shrinkage (n, n/2, n/4...) gets you to log n layers.

  General rule that finally tied it together -- outer loop
  count times inner loop count roughly equals total
  complexity. n times n = n^2. n times log n = n log n.
  log n times log n = (log n)^2.

  exponential (2^n) -- naive fibonacci. Actually watched this
  happen in real time waiting on n=50.


----------------------------------------------------------------
  THINGS TO REMEMBER
----------------------------------------------------------------

  General recursion:
  - Every recursive function needs a base case that the
    recursive case is actually moving TOWARD. Double check
    the direction your variable is moving matches what your
    base case is checking for.
  - If a function is declared to return something, it needs
    to return something on EVERY path, not just the base case.
  - If you call a recursive function and don't use what it
    returns, ask yourself why you called it at all. This bug
    showed up in sum, palindrome, AND fibonacci this week.
  - Don't call the same recursive function twice for the same
    input just to be "safe" -- store the result once, reuse it.
  - "Leap of faith" -- trust that the smaller recursive call
    already works correctly. Don't trace the whole stack in
    your head, just figure out what THIS one call needs to do.

  Two pointer recursion specifically:
  - Base case should be l >= r, never just l == r. Odd length
    inputs land exactly on the middle. Even length inputs
    CROSS without ever being equal.
  - Check the bounds/crossing condition BEFORE comparing or
    dereferencing values at those positions, or you risk
    reading garbage/out of bounds memory.

  Types:
  - Fixing overflow means fixing the RETURN TYPE, not just
    the parameter type, if it's the computed answer that's
    too big, not the input.
  - Plain C-style arrays and vector<int>& are not the same
    type even though both use arr[i] syntax. Compiler will
    catch this one loudly though, which is the good kind
    of bug.
  - vector<int> arr; is empty (size 0). Either preallocate
    with vector<int> arr(n) or grow it with push_back(x).

  Mindset:
  - The problems where I got stuck and fought through the bug
    myself are the ones that actually stuck. The one clean
    first-try problem (factorial) barely taught me anything
    NEW, it just confirmed something I'd already learned.
  - Try the harder/messier way (like char pointers) on purpose
    sometimes even when an easier way exists, if it helps
    build a deeper mental model. Convert to the clean way after.
  - One real problem solved with five bugs debugged along the
    way is worth more than five easy problems solved with zero
    bugs. Don't judge the day by the count.

----------------------------------------------------------------

