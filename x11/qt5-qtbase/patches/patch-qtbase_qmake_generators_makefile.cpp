$NetBSD: patch-qtbase_qmake_generators_makefile.cpp,v 1.1 2013/12/13 14:38:35 ryoon Exp $

* Libtoolized

--- qtbase/qmake/generators/makefile.cpp.orig	2013-11-27 01:01:10.000000000 +0000
+++ qtbase/qmake/generators/makefile.cpp
@@ -3296,7 +3296,7 @@ MakefileGenerator::writePkgConfigFile()
             bundle = bundle.left(suffix);
         pkgConfiglibName = "-framework " + bundle + " ";
     } else {
-        pkgConfiglibDir = "-L${libdir}";
+	pkgConfiglibDir = "-Wl,-R${libdir} -L${libdir}";
         pkgConfiglibName = "-l" + fileInfo(fname).completeBaseName();
         if (project->isActiveConfig("shared"))
             pkgConfiglibName += project->first("TARGET_VERSION_EXT").toQString();
