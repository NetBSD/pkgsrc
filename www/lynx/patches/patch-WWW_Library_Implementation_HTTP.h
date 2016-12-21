$NetBSD: patch-WWW_Library_Implementation_HTTP.h,v 1.1 2016/12/21 11:25:25 sevan Exp $

Drop the use of weak ciphers
https://hg.java.net/hg/solaris-userland~gate/file/bc5351dcb9ac/components/lynx/patches/03-weak-ciphers-by-default.patch

--- WWW/Library/Implementation/HTTP.h.orig	2016-12-21 03:04:50.000000000 +0000
+++ WWW/Library/Implementation/HTTP.h
@@ -21,6 +21,8 @@ extern "C" {
     GLOBALREF HTProtocol HTTPS;
 #endif				/* GLOBALREF_IS_MACRO */
 
+#define DEFAULT_CIPHER_SELECTION "ALL!EXPORT!EXPORT40!EXPORT56!aNULL!LOW!RC4"
+
 #define URL_GET_METHOD  1
 #define URL_POST_METHOD 2
 #define URL_MAIL_METHOD 3
