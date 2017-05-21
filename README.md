# Basic Syntax Checker
A C++ program to test the "balance" of certain syntax features of C++ programs. This is a task that is done by C++ compilers. The technique used is similar to the technique used by a typical C++ compiler.

There are many features in this C++ program checks for that must be balanced and syntactically correct. For example, every `(` must be balanced by a corresponding `)`. Similarly for `{}` and `[]`. Along with these, the program also checks for balance between block comments (each `/*` must be balanced by a `*/`), single quotes `'  '` and double quotes `"  "`.  I have also made sure to be careful to not abuse or overcompensate for cases which should not be comped for (i.e., a `*` can still be used for multiplication, or as a pointer - not necessarily as a precursor to a closing comment brace).

I used the standard template library stack data structure to create this program.

There are 3 pre-given test cases which you can try out: balanced.txt, unbalanced.txt, and unbalanced2.txt. however, Feel free to make your own and test it out!
