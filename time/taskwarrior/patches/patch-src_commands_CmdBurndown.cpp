$NetBSD$

Call of overloaded 'log10(unsigned int)' is ambiguous

--- src/commands/CmdBurndown.cpp.orig	2016-02-24 22:18:11.000000000 +0000
+++ src/commands/CmdBurndown.cpp
@@ -902,7 +902,7 @@ unsigned Chart::burndown_size (unsigned
 
   // Choose the number from here rounded up to the nearest 10% of the next
   // highest power of 10 or half of power of 10.
-  const unsigned count = (unsigned) log10 (std::numeric_limits<unsigned>::max ());
+  const unsigned count = (unsigned) log10 ((double)std::numeric_limits<unsigned>::max ());
   unsigned half = 500;
   unsigned full = 1000;
 
