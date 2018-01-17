$NetBSD: patch-qmake_generators_makefile.cpp,v 1.3 2018/01/17 19:30:47 markd Exp $

Pass library path to linker.

--- qmake/generators/makefile.cpp.orig	2016-06-10 06:48:56.000000000 +0000
+++ qmake/generators/makefile.cpp
@@ -3297,7 +3297,7 @@ MakefileGenerator::writePkgConfigFile()
         pkgConfiglibName = bundle.toQString();
     } else {
         if (!project->values("QMAKE_DEFAULT_LIBDIRS").contains(libDir))
-            t << "-L${libdir} ";
+            t << "-Wl,-R${libdir} -L${libdir} ";
         pkgConfiglibName = "-l" + project->first("QMAKE_ORIG_TARGET");
         if (project->isActiveConfig("shared"))
             pkgConfiglibName += project->first("TARGET_VERSION_EXT").toQString();
