$NetBSD: patch-extensions_auth_nsAuthGSSAPI.cpp,v 1.3 2014/02/20 13:19:03 ryoon Exp $

--- extensions/auth/nsAuthGSSAPI.cpp.orig	2013-05-11 19:19:29.000000000 +0000
+++ extensions/auth/nsAuthGSSAPI.cpp
@@ -39,6 +39,9 @@ typedef KLStatus (*KLCacheHasValidTicket
 #endif
 
 #if defined(HAVE_RES_NINIT)
+#include <sys/types.h>
+#include <netinet/in.h>
+#include <arpa/nameser.h>
 #include <resolv.h>
 #endif
 
