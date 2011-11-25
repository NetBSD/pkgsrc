$NetBSD: patch-main.cc,v 1.1 2011/11/25 22:20:59 joerg Exp $

--- main.cc.orig	2011-11-25 13:56:32.000000000 +0000
+++ main.cc
@@ -6,6 +6,7 @@
  */
  
 #include "aewm.hh"
+#include <cstring>
 
 void forkExec(char *cmd)
 {
