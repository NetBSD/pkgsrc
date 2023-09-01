$NetBSD: patch-switchuser.cpp,v 1.1 2023/09/01 09:37:09 nia Exp $

Include correct headers for errno and strerror definitions.

--- switchuser.cpp.orig	2023-01-19 21:00:48.000000000 +0000
+++ switchuser.cpp
@@ -11,6 +11,8 @@
  *  (at your option) any later version.
  */
 
+#include <errno.h>
+#include <string.h>
 #include <unistd.h>
 #include <cstdio>
 #include "const.h"
