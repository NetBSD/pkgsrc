$NetBSD: patch-proxy_CoreUtils.h,v 1.1 2020/05/14 18:59:48 joerg Exp $

--- proxy/CoreUtils.h.orig	2020-05-14 00:03:04.489956140 +0000
+++ proxy/CoreUtils.h
@@ -56,7 +56,7 @@ struct core_stack_state {
 };
 #endif // linux check
 
-#if defined(darwin) || defined(freebsd) || defined(solaris) || defined(openbsd) // FIXME: solaris x86
+#if defined(darwin) || defined(freebsd) || defined(solaris) || defined(openbsd) || defined(__NetBSD__) // FIXME: solaris x86
 #include <stdio.h>
 #include <unistd.h>
 #include <stdlib.h>
