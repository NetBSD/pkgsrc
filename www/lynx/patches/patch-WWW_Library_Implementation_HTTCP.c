$NetBSD$

Fix CVE-2016-9179
https://hg.java.net/hg/solaris-userland~gate/file/0a979060f73b/components/lynx/patches/05-fix-CVE-2016-9179.patch

--- WWW/Library/Implementation/HTTCP.c.orig	2016-12-21 10:03:58.000000000 +0000
+++ WWW/Library/Implementation/HTTCP.c
@@ -1792,7 +1792,6 @@ int HTDoConnect(const char *url,
     int status = 0;
     char *line = NULL;
     char *p1 = NULL;
-    char *at_sign = NULL;
     char *host = NULL;
 
 #ifdef INET6
@@ -1814,14 +1813,8 @@ int HTDoConnect(const char *url,
      * Get node name and optional port number.
      */
     p1 = HTParse(url, "", PARSE_HOST);
-    if ((at_sign = StrChr(p1, '@')) != NULL) {
-	/*
-	 * If there's an @ then use the stuff after it as a hostname.
-	 */
-	StrAllocCopy(host, (at_sign + 1));
-    } else {
 	StrAllocCopy(host, p1);
-    }
+    strip_userid(host, FALSE);
     FREE(p1);
 
     HTSprintf0(&line, "%s%s", WWW_FIND_MESSAGE, host);
