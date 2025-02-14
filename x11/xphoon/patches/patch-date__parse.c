$NetBSD: patch-date__parse.c,v 1.1 2025/02/14 08:07:18 vins Exp $

Field `tm_gmtoff' is a BSD extension.

--- date_parse.c.orig	2025-02-14 07:52:15.250712065 +0000
+++ date_parse.c
@@ -117,7 +117,7 @@ date_parse( char* str )
     ** non-portability, and it's only used for local times that don't
     ** specify a zone - those don't occur in email and netnews.
     */
-#ifdef OS_SYSV
+#if defined(OS_SYSV) || defined(__sun)
     tzset();
     gmtoff = -timezone;
 #else /* OS_SYSV */
