$NetBSD: patch-qttools_src_assistant_clucene_qclucene-config__p.h,v 1.1 2013/12/13 14:38:35 ryoon Exp $

* Add NetBSD support

--- qttools/src/assistant/clucene/qclucene-config_p.h.orig	2013-11-27 01:01:52.000000000 +0000
+++ qttools/src/assistant/clucene/qclucene-config_p.h
@@ -94,7 +94,7 @@ configure.
 #define _CL_HAVE_FCNTL_H  1
 #endif
 
-#if !defined(__xlC__) && !defined(__xlc__) && !defined (__MINGW32__) && \
+#if !defined(__xlC__) && !defined(__xlc__) && !defined (__MINGW32__) && !defined(__NetBSD) && \
     !defined(__HP_aCC) && !defined(__SUNPRO_C) && !defined(__SUNPRO_CC) || \
     defined(__SUNPRO_CC) && (__SUNPRO_CC > 0x550) || (defined(__HP_aCC) && defined(__ia64))
     /* Define to 1 if the system has the type `float_t'. */
@@ -430,7 +430,7 @@ configure.
 #   endif
 #endif
 
-#if defined(__SUNPRO_CC) || defined(__SUNPRO_C) || defined(__HP_aCC)
+#if defined(__SUNPRO_CC) || defined(__SUNPRO_C) || defined(__HP_aCC) || defined(__NetBSD__)
     /* Define to 1 if you have a functioning <wchar.h> header file. */
 #   ifndef _CL_HAVE_WCTYPE_H
 #   define _CL_HAVE_WCTYPE_H
