$NetBSD: patch-src_main.cpp,v 1.1 2011/11/25 22:21:28 joerg Exp $

--- src/main.cpp.orig	2011-11-25 17:00:21.000000000 +0000
+++ src/main.cpp
@@ -21,7 +21,7 @@
 // DEALINGS IN THE SOFTWARE.
 
 // E_O_H_VR
-
+#include <cstring>
 #include "KeyClient.h"
 #include "version.h"
 
