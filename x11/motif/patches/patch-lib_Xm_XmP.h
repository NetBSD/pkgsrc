$NetBSD: patch-lib_Xm_XmP.h,v 1.1 2013/09/08 07:23:56 ryoon Exp $

* Fix build under OS X 10.8.4 with clang.
  http://bugs.motifzone.net/show_bug.cgi?id=1625

--- lib/Xm/XmP.h.orig	2012-10-22 14:50:35.000000000 +0000
+++ lib/Xm/XmP.h
@@ -1444,7 +1444,11 @@ extern void _XmDestroyParentCallback( 
 
 #if __GNUC__
 #  define XM_DEPRECATED  __attribute__((__deprecated__))
+#  ifdef NO_WEAK_ALIASES
+#    define XM_ALIAS(sym)
+#  else
 #  define XM_ALIAS(sym)  __attribute__((__weak__,alias(#sym)))
+#  endif
 #else
 #  define XM_DEPRECATED
 #  define XM_ALIAS(sym)
