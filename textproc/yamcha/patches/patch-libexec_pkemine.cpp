$NetBSD: patch-libexec_pkemine.cpp,v 1.1 2012/10/03 14:40:23 marino Exp $

Fix segfault bug - "is" equals std::cin when infile == "-".  This delete
command was intended for allocated std::instream object.

--- libexec/pkemine.cpp.orig	2004-03-12 17:12:13.000000000 +0000
+++ libexec/pkemine.cpp
@@ -250,7 +250,7 @@ int main (int argc, char **argv)
   PKEMine pkemine (sigma, minsup, maxpat);
   pkemine.run  (*is, os);
    
-  if (infile == "-") delete is; 
+  if (infile != "-") delete is; 
 
   return 0;
 }
