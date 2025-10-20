$NetBSD: patch-src_rxvt.h,v 1.2 2025/10/20 18:32:10 vins Exp $

* Rxvt UTMP log files are not defined elsewhere.
* Ignore __attribute__ outside of GCC.

--- src/rxvt.h.orig	2003-03-07 01:17:18.000000000 +0000
+++ src/rxvt.h
@@ -804,15 +804,18 @@ enum {
 #define rxvt_Gr_ButtonRelease(x,y)	rxvt_Gr_ButtonReport (r, 'R',(x),(y))
 
 #ifdef UTMP_SUPPORT
-# if !defined(RXVT_UTMPX_FILE) || !defined(HAVE_STRUCT_UTMPX)
-#  undef HAVE_UTMPX_H
-#  undef HAVE_STRUCT_UTMPX
-# endif
-# if !defined(RXVT_UTMP_FILE) || !defined(HAVE_STRUCT_UTMP)
-#  undef HAVE_UTMP_H
-#  undef HAVE_STRUCT_UTMP
+# if !defined(RXVT_UTMPX_FILE)
+#  define RXVT_UTMPX_FILE "@VARBASE@/log/utmpx" 
+# endif
+# if !defined(RXVT_UTMP_FILE) 
+#  define RXVT_UTMP_FILE "@VARBASE@/log/utmp"
+# endif
+# if !defined(RXVT_WTMPX_FILE) 
+#  define RXVT_WTMPX_FILE "@VARBASE@/log/wtmpx"
+# endif
+# if !defined(RXVT_WTMP_FILE) 
+#  define RXVT_WTMP_FILE "@VARBASE@/log/wtmp"
 # endif
-
 # ifdef HAVE_UTMPX_H
 #  include <utmpx.h>
 # endif
@@ -1097,8 +1100,9 @@ struct rxvt_hidden {
 #  if (__GNUC__ == 2 && __GNUC_MINOR__ < 5) || (__GNUC__ < 2)
 #   define __attribute__(x)
 #  endif
-# endif
+# else
 # define __attribute__(x)
+# endif
 #endif
 
 /*
