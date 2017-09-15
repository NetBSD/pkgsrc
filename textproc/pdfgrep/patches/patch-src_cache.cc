$NetBSD: patch-src_cache.cc,v 1.1 2017/09/15 22:18:00 ast Exp $

* Compile with pre-2016/12/16 v1.36 dirent.h on NetBSD

--- src/cache.cc.orig	2017-01-25 09:31:18.000000000 +0100
+++ src/cache.cc	2017-09-15 22:05:44.077172709 +0200
@@ -18,6 +18,8 @@
  *   Boston, MA 02110-1301 USA.                                            *
  ***************************************************************************/
 
+#include "config.h"
+
 #include "cache.h"
 #include "output.h"
 
@@ -85,9 +87,17 @@
 
 // I feel so bad...
 static const char *cache_directory;
+#if SCANDIR_COMPAR_USES_CONST_VOID_POINTER
+static int agesort(const void *a, const void *b) {
+	std::string A = string(cache_directory) + "/"
+                               + ((const struct dirent *)a)->d_name;
+	std::string B = string(cache_directory) + "/"
+                               + ((const struct dirent *)b)->d_name;
+#else
 static int agesort(const struct dirent ** a, const struct dirent **b) {
 	std::string A = string(cache_directory) + "/" + (*a)->d_name;
 	std::string B = string(cache_directory) + "/" + (*b)->d_name;
+#endif
 
 	struct stat bufa, bufb;
 	if (stat(A.c_str(), &bufa) != 0) return 0;
