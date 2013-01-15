$NetBSD: patch-config.cpp,v 1.2 2013/01/15 15:32:59 joerg Exp $

--- config.cpp.orig	2005-06-20 11:20:44.000000000 +0000
+++ config.cpp
@@ -19,6 +19,7 @@
 //  the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.
 //
 
+#include <string.h>
 #include "config.hpp"
 
 static void 
@@ -64,7 +65,7 @@ get_boolean (char *value) 
 }
 
 
-Options::Options(char *n = NULL) 
+Options::Options(char *n) 
 {
 
     if (n)
