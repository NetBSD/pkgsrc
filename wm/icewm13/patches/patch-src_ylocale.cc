$NetBSD: patch-src_ylocale.cc,v 1.1 2014/01/05 12:33:26 ryoon Exp $

--- src/ylocale.cc.orig	2013-11-17 16:54:39.000000000 +0000
+++ src/ylocale.cc
@@ -152,7 +152,11 @@ YUChar *YLocale::unicodeString(const YLC
     char * inbuf((char *) lStr), * outbuf((char *) uStr);
     size_t inlen(lLen), outlen(4 * lLen);
 
+#if defined(__NetBSD__) || defined(__sun)
+    if (0 > (int) iconv(instance->toUnicode, const_cast<const char **>(&inbuf), &inlen, &outbuf, &outlen))
+#else
     if (0 > (int) iconv(instance->toUnicode, &inbuf, &inlen, &outbuf, &outlen))
+#endif
         warn(_("Invalid multibyte string \"%s\": %s"), lStr, strerror(errno));
 
     *((YUChar *) outbuf) = 0;
