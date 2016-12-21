$NetBSD: patch-src_LYUtils.c,v 1.1 2016/12/21 11:25:25 sevan Exp $

Fix CVE-2016-9179
https://hg.java.net/hg/solaris-userland~gate/file/0a979060f73b/components/lynx/patches/05-fix-CVE-2016-9179.patch

--- src/LYUtils.c.orig	2016-12-21 10:09:24.000000000 +0000
+++ src/LYUtils.c
@@ -4693,6 +4693,7 @@ BOOLEAN LYExpandHostForURL(char **Alloca
      * Do a DNS test on the potential host field as presently trimmed.  - FM
      */
     StrAllocCopy(host, Str);
+    strip_userid(host, FALSE);
     HTUnEscape(host);
     if (LYCursesON) {
 	StrAllocCopy(MsgStr, WWW_FIND_MESSAGE);
