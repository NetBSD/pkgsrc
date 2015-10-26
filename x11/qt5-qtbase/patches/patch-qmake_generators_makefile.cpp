$NetBSD: patch-qmake_generators_makefile.cpp,v 1.2 2015/10/26 19:03:59 adam Exp $

* Libtoolized

--- qmake/generators/makefile.cpp.orig	2015-06-29 20:03:22.000000000 +0000
+++ qmake/generators/makefile.cpp
@@ -3256,7 +3256,7 @@ MakefileGenerator::writePkgConfigFile()
         pkgConfiglibName = "-framework " + bundle + " ";
     } else {
         if (!project->values("QMAKE_DEFAULT_LIBDIRS").contains(libDir))
-            t << "-L${libdir} ";
+            t << "-Wl,-R${libdir} -L${libdir} ";
         pkgConfiglibName = "-l" + project->first("QMAKE_ORIG_TARGET");
         if (project->isActiveConfig("shared"))
             pkgConfiglibName += project->first("TARGET_VERSION_EXT").toQString();
