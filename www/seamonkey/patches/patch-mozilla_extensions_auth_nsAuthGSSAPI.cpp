$NetBSD: patch-mozilla_extensions_auth_nsAuthGSSAPI.cpp,v 1.1 2013/05/23 13:25:30 ryoon Exp $

--- mozilla/extensions/auth/nsAuthGSSAPI.cpp.orig	2013-05-03 03:07:54.000000000 +0000
+++ mozilla/extensions/auth/nsAuthGSSAPI.cpp
@@ -39,6 +39,9 @@ typedef KLStatus (*KLCacheHasValidTicket
 #endif
 
 #if defined(HAVE_RES_NINIT)
+#include <sys/types.h>
+#include <netinet/in.h>
+#include <arpa/nameser.h>
 #include <resolv.h>
 #endif
 
