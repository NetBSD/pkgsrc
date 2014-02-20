$NetBSD: patch-gfx_graphite2_src_Bidi.cpp,v 1.3 2014/02/20 13:19:03 ryoon Exp $

--- gfx/graphite2/src/Bidi.cpp.orig	2013-05-11 19:19:30.000000000 +0000
+++ gfx/graphite2/src/Bidi.cpp
@@ -30,6 +30,11 @@ of the License or (at your option) any l
 
 using namespace graphite2;
 
+#ifdef __sun
+#undef CS
+#undef ES
+#endif
+
 enum DirCode {  // Hungarian: dirc
         Unk        = -1,
         N          =  0,   // other neutrals (default) - ON
