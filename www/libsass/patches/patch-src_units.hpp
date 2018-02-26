$NetBSD: patch-src_units.hpp,v 1.2 2018/02/26 08:09:27 adam Exp $

Avoid macro conflict on SunOS.

--- src/units.hpp.orig	2018-02-05 23:14:08.000000000 +0000
+++ src/units.hpp
@@ -6,6 +6,10 @@
 #include <sstream>
 #include <vector>
 
+#if defined(SEC)
+#undef SEC
+#endif
+
 namespace Sass {
 
   const double PI = std::acos(-1);
