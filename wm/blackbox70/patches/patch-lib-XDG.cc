$NetBSD: patch-lib-XDG.cc,v 1.1 2011/11/22 20:02:48 joerg Exp $

--- lib/XDG.cc.orig	2011-11-22 18:41:39.000000000 +0000
+++ lib/XDG.cc
@@ -26,7 +26,7 @@
 #include "XDG.hh"
 
 #include <stdlib.h>
-
+#include <algorithm>
 
 // make sure directory names end with a slash
 static std::string terminateDir(const std::string &string)
