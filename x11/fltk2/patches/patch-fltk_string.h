$NetBSD: patch-fltk_string.h,v 1.1 2018/11/21 08:23:22 maya Exp $

Don't provide a declaration if we already detected one.

--- fltk/string.h.orig	2007-10-17 20:54:58.000000000 +0000
+++ fltk/string.h
@@ -43,6 +43,7 @@
 # include <string.h>
 # include <stdarg.h> /* for va_list */
 # include <stdio.h> /* for sprintf, vsprintf, snprintf and vsnprintf */
+# include <config.h>
 
 /* Windows has equivalent functions, but being Microsoft they added
    gratuitoius changes to the names to stop code from being portable: */
@@ -68,13 +69,17 @@ FL_API extern int strcasecmp(const char 
 FL_API extern int strncasecmp(const char *, const char *, size_t);
 #endif
 
-#if defined(DOXYGEN) || !defined(__linux) && !defined(_WIN32) && !defined(__FreeBSD__) && !defined(__APPLE__)
+#if !HAVE_SNPRINTF && defined(DOXYGEN)
 FL_API extern int snprintf(char *, size_t, const char *, ...);
+#endif
+#if !HAVE_VSNPRINTF && defined(DOXYGEN)
 FL_API extern int vsnprintf(char *, size_t, const char *, va_list ap);
 #endif
 
-#if defined(DOXYGEN) || !defined(__FreeBSD__) && !defined(__APPLE__)
+#if !HAVE_STRLCAT && defined(DOXYGEN)
 FL_API extern size_t strlcat(char *, const char *, size_t);
+#endif
+#if !HAVE_STRLCPY && defined(DOXYGEN)
 FL_API extern size_t strlcpy(char *, const char *, size_t);
 #endif
 
