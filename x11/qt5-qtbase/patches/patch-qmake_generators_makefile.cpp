$NetBSD: patch-qmake_generators_makefile.cpp,v 1.4 2019/09/16 19:24:53 adam Exp $

Pass library path to linker.

--- qmake/generators/makefile.cpp.orig	2019-08-31 08:29:31.000000000 +0000
+++ qmake/generators/makefile.cpp
@@ -3387,7 +3387,7 @@ MakefileGenerator::writePkgConfigFile()
             pkgConfiglibName = bundle.toQString();
         } else {
             if (!project->values("QMAKE_DEFAULT_LIBDIRS").contains(libDir))
-                t << "-L${libdir} ";
+                t << "-Wl,-R${libdir} -L${libdir} ";
             pkgConfiglibName = "-l" + project->first("QMAKE_ORIG_TARGET");
             if (project->isActiveConfig("shared"))
                 pkgConfiglibName += project->first("TARGET_VERSION_EXT").toQString();
