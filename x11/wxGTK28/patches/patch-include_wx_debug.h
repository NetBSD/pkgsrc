$NetBSD: patch-include_wx_debug.h,v 1.1 2015/11/22 22:16:04 mef Exp $

with gcc-4.8.5:
(at least cross/bossa, bossa-20140109nb2, has a problem)
cross/bossa/work/.buildlink/include/wx-2.8/wx/debug.h:194:43: error: 
	typedef 'wxDummyCheckInt' locally defined but not used [-Werror=unused-local-typedefs]

--- include/wx/debug.h.orig	2011-03-22 21:16:46.000000000 +0900
+++ include/wx/debug.h	2015-11-22 22:18:12.000000000 +0900
@@ -191,7 +191,7 @@
 /*  as wxCHECK2 but with a message explaining why we fail */
 
 #ifdef __GNUC__
-    #define wxFORCE_SEMICOLON typedef int wxDummyCheckInt
+    #define wxFORCE_SEMICOLON typedef int wxDummyCheckInt __attribute__((unused))
     /* Note: old gcc versions (e.g. 2.8) give an internal compiler error */
     /*     on a simple forward declaration, when used in a template    */
     /*     function, so rather use a dummy typedef which does work...  */
