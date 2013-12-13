$NetBSD: patch-qtbase_src_corelib_codecs_qiconvcodec.cpp,v 1.1 2013/12/13 14:38:35 ryoon Exp $

* Add DragonFly support
* Add NetBSD support

--- qtbase/src/corelib/codecs/qiconvcodec.cpp.orig	2013-11-27 01:01:15.000000000 +0000
+++ qtbase/src/corelib/codecs/qiconvcodec.cpp
@@ -52,9 +52,14 @@
 #include <stdio.h>
 #include <dlfcn.h>
 
+// for __DragonFly_version
+#if defined(__DragonFly__)
+#include <sys/param.h>
+#endif
+
 // unistd.h is needed for the _XOPEN_UNIX macro
 #include <unistd.h>
-#if defined(_XOPEN_UNIX) && !defined(Q_OS_QNX) && !defined(Q_OS_OSF)
+#if defined(_XOPEN_UNIX) && !defined(Q_OS_QNX) && !defined(Q_OS_OSF) || defined(Q_OS_NETBSD) || defined(__DragonFly__)
 #  include <langinfo.h>
 #endif
 
@@ -71,6 +76,9 @@
 #  else
 #    define UTF16 "UTF-16LE"
 #  endif
+#elif defined(__DragonFly__) && __DragonFly_version__ < 197700
+#  define NO_BOM
+#  define UTF16 "UTF-16"
 #else
 #  define UTF16 "UTF-16"
 #endif
@@ -223,7 +231,7 @@ QString QIconvCodec::convertToUnicode(co
     IconvState *state = *pstate;
     size_t inBytesLeft = len;
     // best case assumption, each byte is converted into one UTF-16 character, plus 2 bytes for the BOM
-#ifdef GNU_LIBICONV
+#if defined(GNU_LIBICONV) || defined(__NetBSD__)
     // GNU doesn't disagree with POSIX :/
     const char *inBytes = chars;
 #else
@@ -322,7 +330,7 @@ static bool setByteOrder(iconv_t cd)
     size_t outBytesLeft = sizeof buf;
     size_t inBytesLeft = sizeof bom;
 
-#if defined(GNU_LIBICONV)
+#if defined(GNU_LIBICONV) || defined(__NetBSD__)
     const char **inBytesPtr = const_cast<const char **>(&inBytes);
 #else
     char **inBytesPtr = &inBytes;
@@ -342,7 +350,7 @@ QByteArray QIconvCodec::convertFromUnico
     char *outBytes;
     size_t inBytesLeft;
 
-#if defined(GNU_LIBICONV)
+#if defined(GNU_LIBICONV) || defined(__NetBSD__)
     const char **inBytesPtr = const_cast<const char **>(&inBytes);
 #else
     char **inBytesPtr = &inBytes;
@@ -482,11 +490,13 @@ iconv_t QIconvCodec::createIconv_t(const
 #endif
     const char *codeset = empty_codeset;
     cd = iconv_open(to ? to : codeset, from ? from : codeset);
+#elif defined(__NetBSD)
+    const char *codeset = 0;
 #else
     char *codeset = 0;
 #endif
 
-#if defined(_XOPEN_UNIX) && !defined(Q_OS_QNX) && !defined(Q_OS_OSF)
+#if (defined(_XOPEN_UNIX) && !defined(Q_OS_QNX) && !defined(Q_OS_OSF)) || defined(Q_OS_NETBSD) || defined(__DragonFly__)
     if (cd == (iconv_t) -1) {
         codeset = nl_langinfo(CODESET);
         if (codeset)
