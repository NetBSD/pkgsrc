$NetBSD: patch-qmake_generators_makefile.cpp,v 1.3 2012/05/24 08:07:33 adam Exp $

--- qmake/generators/makefile.cpp.orig	2012-05-24 05:03:21.000000000 +0000
+++ qmake/generators/makefile.cpp
@@ -3256,7 +3256,7 @@ MakefileGenerator::writePkgConfigFile()
             bundle = bundle.left(suffix);
         pkgConfiglibName = "-framework " + bundle + " ";
     } else {
-        pkgConfiglibDir = "-L${libdir}";
+        pkgConfiglibDir = "-Wl,-R${libdir} -L${libdir}";
         pkgConfiglibName = "-l" + lname.left(lname.length()-Option::libtool_ext.length());
         if (project->isActiveConfig("shared"))
             pkgConfiglibName += project->first("TARGET_VERSION_EXT");
