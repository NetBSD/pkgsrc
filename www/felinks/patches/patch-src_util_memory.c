$NetBSD: patch-src_util_memory.c,v 1.1 2020/06/20 15:13:56 nia Exp $

Use macro to make mremap compatible to NetBSD

--- src/util/memory.c.orig	2020-05-31 13:15:37.000000000 +0000
+++ src/util/memory.c
@@ -21,6 +21,14 @@
 #include "util/error.h"
 #include "util/memory.h"
 
+#if defined(__NetBSD__)
+# define MREMAP(p, oldsz, newsz, f)    mremap(p, oldsz, NULL, newsz, 0)
+# define MREMAP_MAYMOVE    0
+#else
+# define MREMAP(p, oldsz, newsz, f)    mremap(p, oldsz, newsz, f)
+#endif
+
+
 
 #if !defined(DEBUG_MEMLEAK) && !defined(CONFIG_FASTMEM)
 
@@ -165,7 +173,7 @@ mem_mmap_realloc(void *p, size_t old_siz
 
 	if (new_size) {
 #ifdef HAVE_MREMAP
-		void *p2 = mremap(p, round_size(old_size), round_size(new_size), MREMAP_MAYMOVE);
+		void *p2 = MREMAP(p, round_size(old_size), round_size(new_size), MREMAP_MAYMOVE);
 
 		if (p2 != MAP_FAILED)
 			return p2;
