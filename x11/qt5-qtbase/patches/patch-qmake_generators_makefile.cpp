$NetBSD: patch-qmake_generators_makefile.cpp,v 1.1 2014/12/30 17:23:46 adam Exp $

* Libtoolized

--- qmake/generators/makefile.cpp.orig	2014-09-11 10:48:00.000000000 +0000
+++ qmake/generators/makefile.cpp
@@ -3299,7 +3299,7 @@ MakefileGenerator::writePkgConfigFile()
         pkgConfiglibName = "-framework " + bundle + " ";
     } else {
         if (!project->values("QMAKE_DEFAULT_LIBDIRS").contains(libDir))
-            t << "-L${libdir} ";
+            t << "-Wl,-R${libdir} -L${libdir} ";
         pkgConfiglibName = "-l" + unescapeFilePath(project->first("QMAKE_ORIG_TARGET"));
         if (project->isActiveConfig("shared"))
             pkgConfiglibName += project->first("TARGET_VERSION_EXT").toQString();
