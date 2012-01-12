$NetBSD: patch-qmake_generators_makefile.cpp,v 1.1 2012/01/12 22:59:58 adam Exp $

--- qmake/generators/makefile.cpp.orig	2012-01-06 20:25:45.000000000 +0000
+++ qmake/generators/makefile.cpp
@@ -3256,7 +3256,7 @@ MakefileGenerator::writePkgConfigFile()
             bundle = bundle.left(suffix);
         pkgConfiglibName = "-framework " + bundle + " ";
     } else {
-        pkgConfiglibDir = "-L${libdir}";
+        pkgConfiglibDir = "-Wl,-R${libdir} -L${libdir}";
         pkgConfiglibName = "-l" + lname.left(lname.length()-Option::libtool_ext.length());
     }
     t << pkgConfiglibDir << " " << pkgConfiglibName << " " << endl;
