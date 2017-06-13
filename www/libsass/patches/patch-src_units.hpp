$NetBSD: patch-src_units.hpp,v 1.1 2017/06/13 12:44:07 fhajny Exp $

Avoid macro conflict on SunOS.

--- src/units.hpp.orig	2017-03-05 04:57:36.000000000 +0000
+++ src/units.hpp
@@ -5,6 +5,10 @@
 #include <string>
 #include <sstream>
 
+#if defined(SEC)
+#undef SEC
+#endif
+
 namespace Sass {
 
   const double PI = std::acos(-1);
