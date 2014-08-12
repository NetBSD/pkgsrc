$NetBSD: patch-hacks_memscroller.c,v 1.1 2014/08/12 15:57:14 hauke Exp $

--- hacks/memscroller.c.orig	2014-05-31 00:56:20.000000000 +0000
+++ hacks/memscroller.c
@@ -301,6 +301,11 @@ open_file (state *st)
 }
 #endif
 
+#ifdef HAVE_SBRK  /* re-get it each time through */
+#  if (__GNUC__ > 4 || (__GNUC__ == 4 && __GNUC_MINOR__ >= 2) ) /* gcc >= 4.2 */
+#   pragma GCC diagnostic ignored "-Wdeprecated-declarations"
+#  endif
+#endif
 
 static unsigned int
 more_bits (state *st, scroller *sc)
@@ -349,9 +354,6 @@ more_bits (state *st, scroller *sc)
          from earlier days before the advent of virtual memory management."
             -- sbrk(2) man page on MacOS
        */
-#  if (__GNUC__ > 4 || (__GNUC__ == 4 && __GNUC_MINOR__ >= 2)) /* gcc >= 4.2 */
-#   pragma GCC diagnostic ignored "-Wdeprecated-declarations"
-#  endif
       himem = ((unsigned char *) sbrk(0)) - (2 * sizeof(void *));
 # endif
 
