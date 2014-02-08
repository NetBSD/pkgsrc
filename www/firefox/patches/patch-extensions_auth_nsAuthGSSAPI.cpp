$NetBSD: patch-extensions_auth_nsAuthGSSAPI.cpp,v 1.2 2014/02/08 09:36:00 ryoon Exp $

--- extensions/auth/nsAuthGSSAPI.cpp.orig	2014-01-28 04:03:40.000000000 +0000
+++ extensions/auth/nsAuthGSSAPI.cpp
@@ -40,6 +40,9 @@ typedef KLStatus (*KLCacheHasValidTicket
 #endif
 
 #if defined(HAVE_RES_NINIT)
+#include <sys/types.h>
+#include <netinet/in.h>
+#include <arpa/nameser.h>
 #include <resolv.h>
 #endif
 
