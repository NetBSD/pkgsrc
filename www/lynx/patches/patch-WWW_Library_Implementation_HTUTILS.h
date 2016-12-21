$NetBSD: patch-WWW_Library_Implementation_HTUTILS.h,v 1.1 2016/12/21 11:25:25 sevan Exp $

Fix CVE-2016-9179
https://hg.java.net/hg/solaris-userland~gate/file/0a979060f73b/components/lynx/patches/05-fix-CVE-2016-9179.patch

--- WWW/Library/Implementation/HTUtils.h.orig	2016-12-21 10:08:13.000000000 +0000
+++ WWW/Library/Implementation/HTUtils.h
@@ -801,6 +801,8 @@ extern "C" {
 
     extern FILE *TraceFP(void);
 
+    extern void strip_userid(char *host, int warn);
+
 #ifdef USE_SSL
     extern SSL *HTGetSSLHandle(void);
     extern void HTSSLInitPRNG(void);
