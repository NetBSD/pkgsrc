$NetBSD: patch-mozilla_nsprpub_pr_include_md_prosdep.h,v 1.2 2012/03/19 10:36:00 ryoon Exp $

--- mozilla/nsprpub/pr/include/md/prosdep.h.orig	2012-03-13 05:33:05.000000000 +0000
+++ mozilla/nsprpub/pr/include/md/prosdep.h
@@ -66,7 +66,7 @@ PR_BEGIN_EXTERN_C
 #if defined(AIX)
 #include "md/_aix.h"
 
-#elif defined(FREEBSD)
+#elif defined(FREEBSD) || defined(__DragonFly__)
 #include "md/_freebsd.h"
 
 #elif defined(NETBSD)
