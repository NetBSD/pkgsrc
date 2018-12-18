$NetBSD: patch-qmake_generators_unix_unixmake2.cpp,v 1.4 2018/12/18 09:57:18 adam Exp $

Append external variables.

--- qmake/generators/unix/unixmake2.cpp.orig	2018-12-03 11:15:26.000000000 +0000
+++ qmake/generators/unix/unixmake2.cpp
@@ -183,12 +183,12 @@ UnixMakefileGenerator::writeMakeParts(QT
     t << "####### Compiler, tools and options\n\n";
     t << "CC            = " << var("QMAKE_CC") << endl;
     t << "CXX           = " << var("QMAKE_CXX") << endl;
-    t << "DEFINES       = "
+    t << "DEFINES      += "
       << varGlue("PRL_EXPORT_DEFINES","-D"," -D"," ")
       << varGlue("DEFINES","-D"," -D","") << endl;
-    t << "CFLAGS        = " << var("QMAKE_CFLAGS") << " $(DEFINES)\n";
-    t << "CXXFLAGS      = " << var("QMAKE_CXXFLAGS") << " $(DEFINES)\n";
-    t << "INCPATH       =";
+    t << "CFLAGS       += " << var("QMAKE_CFLAGS") << " $(DEFINES)\n";
+    t << "CXXFLAGS     += " << var("QMAKE_CXXFLAGS") << " $(DEFINES)\n";
+    t << "INCPATH      +=";
     {
         QString isystem = var("QMAKE_CFLAGS_ISYSTEM");
         const ProStringList &incs = project->values("INCLUDEPATH");
@@ -212,8 +212,8 @@ UnixMakefileGenerator::writeMakeParts(QT
 
     if(!project->isActiveConfig("staticlib")) {
         t << "LINK          = " << var("QMAKE_LINK") << endl;
-        t << "LFLAGS        = " << var("QMAKE_LFLAGS") << endl;
-        t << "LIBS          = $(SUBLIBS) " << fixLibFlags("LIBS").join(' ') << ' '
+        t << "LFLAGS       += " << var("QMAKE_LFLAGS") << endl;
+        t << "LIBS         += $(SUBLIBS) " << fixLibFlags("LIBS").join(' ') << ' '
                                            << fixLibFlags("LIBS_PRIVATE").join(' ') << ' '
                                            << fixLibFlags("QMAKE_LIBS").join(' ') << ' '
                                            << fixLibFlags("QMAKE_LIBS_PRIVATE").join(' ') << endl;
