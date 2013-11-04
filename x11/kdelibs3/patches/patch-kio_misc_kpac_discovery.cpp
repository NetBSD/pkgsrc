$NetBSD: patch-kio_misc_kpac_discovery.cpp,v 1.1 2013/11/04 09:38:26 jperkin Exp $

Support arpa/nameser_compat.h for OSX.

--- kio/misc/kpac/discovery.cpp.orig	2005-10-10 15:05:43.000000000 +0000
+++ kio/misc/kpac/discovery.cpp
@@ -29,6 +29,9 @@
 #include <netinet/in.h>
 #endif
 #include <arpa/nameser.h>
+#ifdef HAVE_ARPA_NAMESER_COMPAT_H 
+#include <arpa/nameser_compat.h> 
+#endif 
 #ifdef HAVE_ARPA_NAMESER8_COMPAT_H
 #include <arpa/nameser8_compat.h>
 #endif
