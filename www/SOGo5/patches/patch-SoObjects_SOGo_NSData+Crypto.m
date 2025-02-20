$NetBSD: patch-SoObjects_SOGo_NSData+Crypto.m,v 1.1 2025/02/20 14:39:37 manu Exp $

--- SoObjects/SOGo/NSData+Crypto.m.orig	2024-10-15 16:21:02.000000000 +0200
+++ SoObjects/SOGo/NSData+Crypto.m	2025-02-18 10:20:04.054287681 +0100
@@ -26,9 +26,9 @@
 #define _XOPEN_SOURCE 600
 
 #include <fcntl.h>
 #include <unistd.h>
-#if !defined(__OpenBSD__) && !defined(__FreeBSD__)
+#ifdef __sun
 #include <crypt.h>
 #endif
 
 #if defined(HAVE_GNUTLS)
