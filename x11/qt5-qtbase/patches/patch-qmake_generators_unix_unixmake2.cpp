$NetBSD: patch-qmake_generators_unix_unixmake2.cpp,v 1.6 2020/09/14 20:08:26 adam Exp $

Append external variables.

--- qmake/generators/unix/unixmake2.cpp.orig	2020-09-02 10:15:07.000000000 +0000
+++ qmake/generators/unix/unixmake2.cpp
@@ -191,12 +191,12 @@ UnixMakefileGenerator::writeMakeParts(QT
     t << "####### Compiler, tools and options\n\n";
     t << "CC            = " << var("QMAKE_CC") << Qt::endl;
     t << "CXX           = " << var("QMAKE_CXX") << Qt::endl;
-    t << "DEFINES       = "
+    t << "DEFINES      += "
       << varGlue("PRL_EXPORT_DEFINES","-D"," -D"," ")
       << varGlue("DEFINES","-D"," -D","") << Qt::endl;
-    t << "CFLAGS        = " << var("QMAKE_CFLAGS") << " $(DEFINES)\n";
-    t << "CXXFLAGS      = " << var("QMAKE_CXXFLAGS") << " $(DEFINES)\n";
-    t << "INCPATH       =";
+    t << "CFLAGS       += " << var("QMAKE_CFLAGS") << " $(DEFINES)\n";
+    t << "CXXFLAGS     += " << var("QMAKE_CXXFLAGS") << " $(DEFINES)\n";
+    t << "INCPATH      +=";
     {
         const ProStringList &incs = project->values("INCLUDEPATH");
         for(int i = 0; i < incs.size(); ++i) {
@@ -215,8 +215,8 @@ UnixMakefileGenerator::writeMakeParts(QT
 
     if(!project->isActiveConfig("staticlib")) {
         t << "LINK          = " << var("QMAKE_LINK") << Qt::endl;
-        t << "LFLAGS        = " << var("QMAKE_LFLAGS") << Qt::endl;
-        t << "LIBS          = $(SUBLIBS) " << fixLibFlags("LIBS").join(' ') << ' '
+        t << "LFLAGS       += " << var("QMAKE_LFLAGS") << Qt::endl;
+        t << "LIBS         += $(SUBLIBS) " << fixLibFlags("LIBS").join(' ') << ' '
                                            << fixLibFlags("LIBS_PRIVATE").join(' ') << ' '
                                            << fixLibFlags("QMAKE_LIBS").join(' ') << ' '
                                            << fixLibFlags("QMAKE_LIBS_PRIVATE").join(' ') << Qt::endl;
