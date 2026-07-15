================================================================
                    WEEK 02 - DSA JOURNEY NOTES
                    STL - Vectors, Pairs, Iterators & Algorithms
                    RIMT University | BCA | Summer Prep
================================================================
  These are my personal notes. Written by me, for me.
  If something took me time to figure out, I wrote it here
  so future me doesn't have to suffer again.
================================================================


----------------------------------------------------------------
  WHY STL?
----------------------------------------------------------------

  Okay so before this week I was doing everything the hard way.
  Manual arrays, manual sizes, writing everything from scratch.

  STL is basically C++ saying — hey, here are some tools.
  Stop reinventing the wheel.

  The thing that scared me at first was I thought STL meant
  learning a completely different way to write C++.
  But no. The structure is EXACTLY the same.
  Same #include, same main(), same cin and cout.
  You just get new, smarter tools to use inside that
  same structure you already know.

  That realization alone made it less scary.

----------------------------------------------------------------


----------------------------------------------------------------
  VECTORS
----------------------------------------------------------------

  Okay so theoretically vectors made sense from the start.
  They are arrays that can grow and shrink. Got it.

  But I had one problem — I knew what they were,
  I just didn't know where to START writing the program.
  New concepts do that. They freeze you before you even begin.

  What helped me was this:
  I already knew how to write an array program.
  So I just imagined the array version in my head first,
  wrote that structure, and then replaced the array parts
  with vector parts.

  int arr[n]        -->  vector<int> v(n)
  That's literally it. Everything else stayed the same.

  The more programs I wrote, the more natural it got.
  By the third or fourth program I stopped thinking
  about arrays entirely. Vectors just made sense on their own.

  Key operations I learned:

  vector<int> v(n);              // declare with size n
  vector<int> v2(v1);            // copy v1 into v2
  v.pop_back();                  // remove last element
  v.erase(v.begin() + i);        // remove single element at index i
  v.erase(v.begin()+1, v.begin()+4);  // remove index 1, 2, 3
  v.clear();                     // wipe everything
  v.size();                      // how many elements are there

  The copy thing I want to remember:
  When you do vector<int> v2(v1), v2 is its own separate thing.
  Changing v2 will NOT change v1.
  They don't share anything. Full independent copy.

  The range based for loop with vectors:

  for(int &x : v)    // taking INPUT -- & is mandatory here
  for(int x : v)     // printing OUTPUT -- no & needed

  Why does & matter for input?
  Without & you are editing a copy of the element.
  The original vector never actually receives the value.
  With & you are editing the real thing directly.
  Took me a moment but once it clicked it made total sense.

  THE MISTAKE I MADE WITH ERASE:
  v.erase(v.begin()+1, v.begin()+4)
  I thought this deletes index 1, 2, 3, 4.
  It actually deletes 1, 2, 3 only. 4 is excluded.
  The end index is ALWAYS excluded in erase.
  To delete up to and including index i, write i+1 at the end.
  One character difference. Wrong answer if you forget this.

  ANOTHER MISTAKE -- initializing before input:
  I declared a variable and set it to v[0] before
  the user had even entered anything.
  The vector existed but had no real values yet.
  v[0] was just garbage.
  Always initialize AFTER taking input. Not before.

----------------------------------------------------------------


----------------------------------------------------------------
  PAIRS
----------------------------------------------------------------

  Pairs are simple honestly. Theoretically you get them
  right away. Two slots, any data type, done.

  pair<int, int> p = {1, 2};
  pair<string, int> p = {"Alice", 95};

  p.first    // first slot
  p.second   // second slot

  You cannot do cin >> p directly by the way.
  Pairs don't work like that.
  Always input each slot separately:
  cin >> p.first >> p.second;

  Where it gets genuinely confusing is when you start
  combining pairs with vectors and different data types.
  Especially when the problem involves something real
  like student names and scores.

  Like the student score problem we did today.
  I had names as strings and scores as integers sitting
  together in a vector of pairs and I had to find
  the student with the highest score.
  That one made me use my brain properly.
  Not because the syntax was hard,
  but because I had to think about how everything
  connects together at once.

  Nested pairs also look scarier than they are:
  pair<int, pair<int,int>> p = {1, {2, 3}};
  p.first          // 1
  p.second.first   // 2
  p.second.second  // 3

  Just keep following the dots and it makes sense.

  THE MISTAKE I MADE WITH RANGE BASED LOOPS:
  I wrote v[i].first inside a range based for loop.
  That's wrong and it threw an error immediately.
  In a range based loop, the variable you declare
  IS the element itself, not an index number.
  v[i] belongs in index based loops.
  p.first belongs in range based loops.
  Mixing the two up = instant error. Don't do it.

----------------------------------------------------------------


----------------------------------------------------------------
  ITERATORS
----------------------------------------------------------------

  Striver said this himself and it's true --
  iterators are similar to pointers.
  They don't hold the value directly.
  They point to the memory address where the value lives.

  So to actually GET the value, you need *.
  Same as pointers. * means go to that address and give me
  what's sitting there.

  Full way to write an iterator:
  vector<int>::iterator it = v.begin();

  Shorter way using auto:
  auto it = v.begin();

  Both do exactly the same thing.
  auto just figures out the type on its own so you don't
  have to type vector<int>::iterator every single time.
  In real code and competitive programming, auto is
  almost always what you'll see.

  How to traverse using an iterator:
  for(auto it = v.begin(); it != v.end(); it++){
      cout << *it << " ";
  }

  v.begin() points to the first element.
  v.end() points to AFTER the last element. Not the last one.
  This matters because the loop condition is it != v.end()
  so it stops before going past the end.

  With vector of pairs, this is how you access values:
  it->first    // same as (*it).first
  it->second   // same as (*it).second

  The arrow -> is just a shorthand.
  Dereference and access in one step instead of two.

  THE MISTAKE I MADE:
  I wrote cout << &v thinking it would print my vector.
  &v is the memory address of the entire vector object.
  It printed some random memory address number.
  & gives address. * gives value.
  To print values from a vector, always loop through it.
  Always.

----------------------------------------------------------------


----------------------------------------------------------------
  ALGORITHMS
----------------------------------------------------------------

  SORT
  ----
  sort(v.begin(), v.end());                  // ascending
  sort(v.begin(), v.end(), greater<int>());  // descending
  sort(a, a + n);                            // for arrays

  greater<int>() is called a comparator.
  It just tells sort to flip the order.

  THE MISTAKE I MADE:
  I wrote greater<int> without the () at the end.
  That threw an error immediately.
  It needs to be called as a function object.
  The () is not optional. greater<int>(). Always.


  MIN AND MAX ELEMENT
  -------------------
  *min_element(v.begin(), v.end());
  *max_element(v.begin(), v.end());

  These return iterators not values.
  That's why * is needed in front.
  Same logic as everything above with iterators.
  Without * you get a memory address. With * you get the number.


  NEXT PERMUTATION
  ----------------
  This one confused me in two different ways.

  First confusion -- where does next_permutation even go?
  I had just done min and max element where you write
  *min_element() directly inside cout.
  So I thought next_permutation works the same way.
  It doesn't. It doesn't print anything.
  It rearranges the vector and returns true or false.
  True means it found a next arrangement.
  False means it's already at the largest arrangement.
  So it goes in the condition of a loop, not in a cout.

  Second confusion -- I froze inside the do while loop
  trying to figure out how to print the vector.
  I got so focused on the new syntax that I completely
  forgot I already knew how to print a vector.
  Ten programs in and my brain went blank on a for loop.

  The lesson I took from this:
  When something new shows up, find the ONE new thing.
  Handle that. Everything else use what you already know.
  The do while was new. Printing a vector was not.

  do {
      for(int x : v){        // this part I already knew
          cout << x << " ";
      }
      cout << endl;
  } while(next_permutation(v.begin(), v.end()));

  Use do while because you want the first arrangement
  to print BEFORE the condition gets checked.
  If you use a regular while loop, the first arrangement
  gets rearranged before it ever prints.

  For ALL permutations to show correctly, sort the vector
  in ascending order first. That's the starting point.
  next_permutation only goes forward, never backward.

----------------------------------------------------------------


----------------------------------------------------------------
  THE BIG REALIZATION FROM TODAY
----------------------------------------------------------------

  Vectors clicked for me not when I learned the syntax.
  They clicked when I started using them with pairs.
  That's when I saw how flexible they really are.
  An array of ints is one thing.
  A vector of pairs with strings and ints and scores?
  That's when it stopped feeling like a syntax exercise
  and started feeling like actual problem solving.

  The other thing I realized today --
  knowing syntax and understanding something are different.
  After the first vector program I knew the syntax.
  After the mixed problems I actually understood it.
  Always do the mixed problems. Don't skip them.

----------------------------------------------------------------


----------------------------------------------------------------
  THINGS TO REMEMBER
----------------------------------------------------------------

  Vectors:
  - Freeze on where to start? Imagine the array version first.
    Then replace the array parts with vector parts.
  - & in range based loop = reference = value saves to vector
  - No & = copy = value disappears after loop ends
  - erase() end index is excluded. Write i+1 to include it.
  - Always initialize variables AFTER taking input
  - Don't name variables max or min. Built in conflict waiting.

  Pairs:
  - Can't cin >> p directly. Always use .first and .second
  - Range based loop variable IS the element, not an index
  - v[i] in a range based loop = instant error

  Iterators:
  - Similar to pointers. & gives address. * gives value.
  - v.end() is AFTER the last element, not the last element
  - auto and full iterator declaration do the same thing
  - -> is shorthand for (*it). cleaner, same result.

  Algorithms:
  - greater<int>() needs the (). Without () it won't compile.
  - min/max element return iterators. Need * to get value.
  - next_permutation goes in the loop condition, not in cout
  - Sort ascending before using next_permutation for all perms
  - do while prints first arrangement before checking condition

  Mindset:
  - New concept freezing you? Connect it to something you know.
  - Syntax knowledge and real understanding are not the same.
    Mixed problems are where real understanding comes from.
  - When stuck on something new, find the ONE new thing.
    Use everything you already know for the rest.
  - Tunnel vision on new syntax makes you forget old knowledge.
    Step back. Breathe. You probably already know that part.

----------------------------------------------------------------


================================================================
  Notes written during summer prep.
  These are my personal takeaways, not a textbook.
================================================================