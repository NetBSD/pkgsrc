$NetBSD: patch-src_corelib_global_qrandom.cpp,v 1.1 2020/05/03 11:41:45 wiedi Exp $

No getauxval on SunOS

--- src/corelib/global/qrandom.cpp.orig	2020-03-27 09:49:31.000000000 +0000
+++ src/corelib/global/qrandom.cpp
@@ -277,7 +277,7 @@ static void fallback_fill(quint32 *ptr,
     if (quint32 v = seed.loadRelaxed())
         *end++ = v; // 6
 
-#if QT_CONFIG(getauxval)
+#if QT_CONFIG(getauxval) && !defined(Q_OS_SOLARIS)
     // works on Linux -- all modern libc have getauxval
 #  ifdef AT_RANDOM
     // ELF's auxv AT_RANDOM has 16 random bytes
