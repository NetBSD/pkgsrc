$NetBSD: patch-src_ylocale.cc,v 1.2 2019/10/25 10:21:32 kamil Exp $

--- src/ylocale.cc.orig	2017-07-30 08:53:35.524267864 +0000
+++ src/ylocale.cc
@@ -28,6 +28,14 @@
 #include "ylib.h"
 #include "yprefs.h"
 
+#if defined(__NetBSD__)
+#include <sys/param.h>
+#if __NetBSD_Prereq__(9,99,17)
+#define NETBSD_POSIX_ICONV 1
+#else
+#define NETBSD_POSIX_ICONV 0
+#endif
+#endif
 
 #ifdef CONFIG_I18N
 YLocale * YLocale::instance(NULL);
@@ -55,6 +63,8 @@ YLocale::YLocale(char const * localeName
     int const codesetItems[] = {
 #ifdef CONFIG_NL_CODESETS
 	CONFIG_NL_CODESETS
+#elif !defined(__GLIBC__)
+	CODESET, 0
 #else
 	CODESET, _NL_CTYPE_CODESET_NAME, 0
 #endif
@@ -159,7 +169,11 @@ YUChar *YLocale::unicodeString(const YLC
     char * inbuf((char *) lStr), * outbuf((char *) uStr);
     size_t inlen(lLen), outlen(4 * lLen);
 
+#if (defined(__NetBSD__) && !NETBSD_POSIX_ICONV) || defined(__sun)
+    if (0 > (int) iconv(instance->toUnicode, const_cast<const char **>(&inbuf), &inlen, &outbuf, &outlen))
+#else
     if (0 > (int) iconv(instance->toUnicode, &inbuf, &inlen, &outbuf, &outlen))
+#endif
         warn(_("Invalid multibyte string \"%s\": %s"), lStr, strerror(errno));
 
     *((YUChar *) outbuf) = 0;
