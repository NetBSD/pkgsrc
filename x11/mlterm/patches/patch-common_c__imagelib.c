$NetBSD: patch-common_c__imagelib.c,v 1.3 2022/12/12 17:51:22 tsutsui Exp $

- pull upstream fix:
 https://github.com/arakiken/mlterm/commit/ddc9a846a198216cc065901d8a81d8d2801bd70e
 > * c_imagelib.c: Fix buffer over-read.

--- common/c_imagelib.c.orig	2022-01-16 15:20:31.000000000 +0000
+++ common/c_imagelib.c
@@ -43,7 +43,7 @@ static char *is_otf_emoji(const char *pa
 
       return p + 5;
     }
-    path = p + 5;
+    path = p + 1;
   }
 
   return NULL;
