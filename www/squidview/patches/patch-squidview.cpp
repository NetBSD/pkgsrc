$NetBSD: patch-squidview.cpp,v 1.1 2016/12/23 22:30:50 joerg Exp $

fopen returns NULL on error.

--- squidview.cpp.orig	2016-12-23 00:11:45.178070224 +0000
+++ squidview.cpp
@@ -1002,7 +1002,7 @@ int SaveWords()
   FILE* fOutput;
 
   fOutput = fopen (sWordFile.c_str(), "w");
-  if (fOutput <= 0)
+  if (fOutput == 0)
     return 0;
 
   iIndex = 0;
