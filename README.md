# lib_util
*lib_util* is a general utility library, written in C and C++,
intended primarily for personal
computer and server *Windows* and _*nix_ platforms.  (However, many modules
may work correctly on many embedded platforms.  Dynamic memory allocation
and stream I/O statements are the major factor that would prevent some of
these modules from working correctly on embedded platforms.)

Although some components of this library may be useful to the Internet
community at large, the primary role of this library is to allow me
(Dave Ashley) to remove common functionality from various small programs
I've written.

This library is made available under _The Unlicense_.  Please see the 
_LICENSE_ file in the root directory of this repository.

The mnemonic for the repository name is *lib*rary, *util*ity.

## Overview
*lib_util* is a collection of C and C++ modules that I tend to re-use across
various programs I've written.  (In good humor, my C++ programming
skills are marginal enough that it is hard to tell the difference
between my C source files and my C++ source files.)

I use "source file" and "module" interchangeably here, because each
_.c_ or _.cpp_ file is meant to be compiled into a software module.

The source files in this repository are meant to be incorporated directly
into a _Visual Studio_ or other project, rather than being combined
into a proper library.

In order for the source files in this repository to be usable
in a wide variety of applications, certain design and documentation
rules have to be documented and followed.  Those 
rules are described in the next two sections.

## Design Rules

### C Versus C++ File Naming Conventions
C files have a _.c_ extension, and the associated header files
have a _.h_ extension.  C++ files have a _.cpp_ extension, and
the associated header files have a _.hpp_ extension.  In all cases,
a header file has the same base name as the associated C or C++ source
file.

### File Name Uniqueness
No two source/header files, anywhere in this repository, have the same base name.

### File Name, Function, Class, and Constant Prefixes
All files, function names, class names, and constants are prefixed with _Lu_, _LU_, *LU_*, or
something similar to make library membership apparent, and to lower the probability of
naming collisions with other parts of the program in which the library is being
used.

### Threading Rules
All of the functions and classes in this module are thread-safe, unless otherwise noted,
subject to
the following qualifications and restrictions:

* The caller/client is responsible for ensuring that the memory or objects
on which the functions operate are used in a thread-safe way.
* Thread-safe versions of library functions (_printf()_, _malloc()_, etc.) must
be linked into the program.

Thread safety generally requires that no state persists outside the variable or
object being operated on; or that if such state exists it is stored in
thread-local storage.

### Command-Line Preprocessor Switches
The command-line preprocessor switches are commonized among everything I (Dave Ashley)
work on.  This endeavor (_lib_util_) is authoritative, and the switches are
documented here only.  To lower the probability of naming collisions, all of the preprocessor
switches are prefixed with *LU_*.

The C standard indicates that preprocessor symbols defined without a value test as
numerical zero.  So, it is made clear from context below whether the
symbol is designed to be defined (and tested) as being defined or not defined
versus tested as an integer numerical value.

LU_PFORM_UNSPECIFIED<br>
LU_PFORM_WIN<br>
LU_PFORM_NIX<br>
LU_PFORM_WIN32<br>
LU_PFORM_NIX32<br>
LU_PFORM_WIN64<br>
LU_PFORM_NIX64<br>
Exactly one of these preprocessor symbols must be defined.





## Documentation Rules

### Doxygen is Used for Documentation
_Doxygen_ is used as the documentation tool for this library, and comments
in the source code are formatted accordingly.

