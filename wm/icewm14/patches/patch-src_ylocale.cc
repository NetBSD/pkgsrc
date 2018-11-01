$NetBSD: patch-src_ylocale.cc,v 1.1 2018/11/01 09:25:29 bsiegert Exp $

--- src/ylocale.cc.orig	2017-07-30 08:53:35.000000000 +0000
+++ src/ylocale.cc
@@ -55,6 +55,8 @@ YLocale::YLocale(char const * localeName
     int const codesetItems[] = {
 #ifdef CONFIG_NL_CODESETS
 	CONFIG_NL_CODESETS
+#elif !defined(__GLIBC__)
+	CODESET, 0
 #else
 	CODESET, _NL_CTYPE_CODESET_NAME, 0
 #endif
@@ -159,7 +161,11 @@ YUChar *YLocale::unicodeString(const YLC
     char * inbuf((char *) lStr), * outbuf((char *) uStr);
     size_t inlen(lLen), outlen(4 * lLen);
 
+#if defined(__NetBSD__) || defined(__sun)
+    if (0 > (int) iconv(instance->toUnicode, const_cast<const char **>(&inbuf), &inlen, &outbuf, &outlen))
+#else
     if (0 > (int) iconv(instance->toUnicode, &inbuf, &inlen, &outbuf, &outlen))
+#endif
         warn(_("Invalid multibyte string \"%s\": %s"), lStr, strerror(errno));
 
     *((YUChar *) outbuf) = 0;
