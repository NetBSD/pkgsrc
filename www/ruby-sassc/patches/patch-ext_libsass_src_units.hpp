$NetBSD: patch-ext_libsass_src_units.hpp,v 1.1 2019/10/01 15:34:50 ryoon Exp $

Avoid macro conflict on SunOS.

--- ext/libsass/src/units.hpp.orig	2019-09-27 11:16:16.834608204 +0000
+++ ext/libsass/src/units.hpp
@@ -6,6 +6,10 @@
 #include <sstream>
 #include <vector>
 
+#if defined(SEC)
+#undef SEC
+#endif
+
 namespace Sass {
 
   const double PI = std::acos(-1);
