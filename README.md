A simple implementation of a random character generator and selector that creates randomized output for cryptographic applications.

Overview
This project consists of two main components:

Random Character Matrix Generator - Creates a 100x100 matrix of random printable ASCII characters
Random Character Selector - Selects one random character from each row to create a 100-character output

How It Works
Generator (CSPRNG.c)
The generator creates a file called input.txt containing a 100x100 matrix of random printable ASCII characters (from the range 33-126 in the ASCII table). Each character in the matrix is followed by a space, and each row is terminated with a newline character.

Selector (ThePicker.c)
The selector reads the generated input.txt file and selects one random character from each of the 100 lines. These selected characters are then written to an output file called output.txt, creating a 100-character random string.

Compilation and Usage

To compile the Generator:
clang -o CSPRNG CSPRNG.c     

Run generator: 
./CSPRNG


To compile the Selector: 
clang -o ThePicker ThePicker.c  

Run selector:
./ThePicker


Applications
This tool can be used for:

Generating random keys for cryptographic applications
Creating randomized test data
Simulating random processes
Educational purposes in learning about randomization techniques

Notes on Randomization
While this implementation uses the standard C library's rand() function seeded with time(NULL), for true cryptographic security in production environments, consider using specialized cryptographic libraries that provide higher-quality randomness.
License

