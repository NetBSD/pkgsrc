$NetBSD: patch-src_ylocale.cc,v 1.1 2024/06/13 22:24:46 gutteridge Exp $

Fix building on older NetBSD and SunOS, which don't have a POSIX-
compliant iconv(3) signature.

--- src/ylocale.cc.orig	2024-05-20 14:51:49.000000000 +0000
+++ src/ylocale.cc
@@ -26,6 +26,15 @@
 #include <X11/Xlib.h>
 #include <iconv.h>
 
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
@@ -194,6 +203,9 @@ char* YLocale::localeString(const wchar_
 
     size_t lSize = 4 * uLen;
     char* lStr = new char[lSize + 1];
+#if (defined(__NetBSD__) && !NETBSD_POSIX_ICONV) || defined(__sun)
+    const
+#endif
     char* inbuf = (char *) uStr;
     char* outbuf = lStr;
     size_t inlen = uLen * sizeof(wchar_t);
@@ -227,6 +239,9 @@ wchar_t* YLocale::unicodeString(const ch
     iconv(instance->converter->unicode(), nullptr, nullptr, nullptr, nullptr);
 
     wchar_t* uStr(new wchar_t[lLen + 1]);
+#if (defined(__NetBSD__) && !NETBSD_POSIX_ICONV) || defined(__sun)
+    const
+#endif
     char* inbuf(const_cast<char *>(lStr));
     char* outbuf(reinterpret_cast<char *>(uStr));
     size_t inlen(lLen), outlen(4 * lLen);
