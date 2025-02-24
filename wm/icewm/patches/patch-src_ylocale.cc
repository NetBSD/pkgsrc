$NetBSD: patch-src_ylocale.cc,v 1.2 2025/02/24 18:05:08 gutteridge Exp $

Fix building on older NetBSD and SunOS, which don't have a POSIX-
compliant iconv(3) signature.

--- src/ylocale.cc.orig	2025-02-22 20:47:00.000000000 +0000
+++ src/ylocale.cc
@@ -27,6 +27,15 @@
 #include <iconv.h>
 #include <ctype.h>
 
+#if defined(__NetBSD__)
+#include <sys/param.h>
+#if __NetBSD_Prereq__(9,99,17)
+#define NETBSD_POSIX_ICONV 1
+#else
+#define NETBSD_POSIX_ICONV 0
+#endif
+#endif
+
 const iconv_t invalid = iconv_t(-1);
 
 class YConverter {
@@ -192,6 +201,9 @@ char* YLocale::localeString(const wchar_
 
     size_t lSize = 4 * uLen;
     char* lStr = new char[lSize + 1];
+#if (defined(__NetBSD__) && !NETBSD_POSIX_ICONV) || defined(__sun)
+    const
+#endif
     char* inbuf = (char *) uStr;
     char* outbuf = lStr;
     size_t inlen = uLen * sizeof(wchar_t);
@@ -225,6 +237,9 @@ wchar_t* YLocale::unicodeString(const ch
     iconv(instance->converter->unicode(), nullptr, nullptr, nullptr, nullptr);
 
     wchar_t* uStr(new wchar_t[lLen + 1]);
+#if (defined(__NetBSD__) && !NETBSD_POSIX_ICONV) || defined(__sun)
+    const
+#endif
     char* inbuf(const_cast<char *>(lStr));
     char* outbuf(reinterpret_cast<char *>(uStr));
     size_t inlen(lLen), outlen(4 * lLen);
