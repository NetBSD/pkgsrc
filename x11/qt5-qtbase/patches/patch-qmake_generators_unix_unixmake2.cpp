$NetBSD: patch-qmake_generators_unix_unixmake2.cpp,v 1.1 2014/12/30 17:23:46 adam Exp $

* Libtoolized

--- qmake/generators/unix/unixmake2.cpp.orig	2014-09-11 10:48:00.000000000 +0000
+++ qmake/generators/unix/unixmake2.cpp
@@ -112,12 +112,12 @@ UnixMakefileGenerator::writeMakeParts(QT
     t << "####### Compiler, tools and options\n\n";
     t << "CC            = " << var("QMAKE_CC") << endl;
     t << "CXX           = " << var("QMAKE_CXX") << endl;
-    t << "DEFINES       = "
+    t << "DEFINES       += "
       << varGlue("PRL_EXPORT_DEFINES","-D"," -D"," ")
       << varGlue("DEFINES","-D"," -D","") << endl;
-    t << "CFLAGS        = " << var("QMAKE_CFLAGS") << " $(DEFINES)\n";
-    t << "CXXFLAGS      = " << var("QMAKE_CXXFLAGS") << " $(DEFINES)\n";
-    t << "INCPATH       = -I" << specdir();
+    t << "CFLAGS        += " << var("QMAKE_CFLAGS") << " $(DEFINES)\n";
+    t << "CXXFLAGS      += " << var("QMAKE_CXXFLAGS") << " $(DEFINES)\n";
+    t << "INCPATH       += -I" << specdir();
     if(!project->isActiveConfig("no_include_pwd")) {
         QString pwd = escapeFilePath(fileFixify(qmake_getpwd()));
         if(pwd.isEmpty())
@@ -144,8 +144,8 @@ UnixMakefileGenerator::writeMakeParts(QT
 
     if(!project->isActiveConfig("staticlib")) {
         t << "LINK          = " << var("QMAKE_LINK") << endl;
-        t << "LFLAGS        = " << var("QMAKE_LFLAGS") << endl;
-        t << "LIBS          = $(SUBLIBS) " << var("QMAKE_LIBS") << " " << var("QMAKE_LIBS_PRIVATE") << endl;
+        t << "LFLAGS        += " << var("QMAKE_LFLAGS") << endl;
+        t << "LIBS          += $(SUBLIBS) " << var("QMAKE_LIBS") << " " << var("QMAKE_LIBS_PRIVATE") << endl;
     }
 
     t << "AR            = " << var("QMAKE_AR") << endl;
@@ -234,6 +234,8 @@ UnixMakefileGenerator::writeMakeParts(QT
         if(!project->isEmpty("QMAKE_BUNDLE")) {
             t << "TARGETD       = " << escapeFilePath(var("TARGET_x.y")) << endl;
             t << "TARGET0       = " << escapeFilePath(var("TARGET_")) << endl;
+        } else if(project->isActiveConfig("compile_libtool")) {
+            t << "TARGETD       = " << var("TARGET_la") << endl;
         } else if (!project->isActiveConfig("unversioned_libname")) {
             t << "TARGET0       = " << escapeFilePath(var("TARGET_")) << endl;
             if (project->isEmpty("QMAKE_HPUX_SHLIB")) {
@@ -1073,8 +1075,12 @@ void UnixMakefileGenerator::init2()
     } else if (project->isActiveConfig("staticlib")) {
         project->values("TARGET").first().prepend(project->first("QMAKE_PREFIX_STATICLIB"));
         project->values("TARGET").first() += "." + project->first("QMAKE_EXTENSION_STATICLIB");
-        if(project->values("QMAKE_AR_CMD").isEmpty())
+        if(project->values("QMAKE_AR_CMD").isEmpty()) {
+          if(project->isActiveConfig("compile_libtool"))
+            project->variables()["QMAKE_AR_CMD"].append("$(CXX) -o $(TARGET) $(OBJECTS) $(OBJMOC)");
+          else
             project->values("QMAKE_AR_CMD").append("$(AR) $(TARGET) $(OBJECTS)");
+        }
     } else {
         project->values("TARGETA").append(project->first("DESTDIR") + project->first("QMAKE_PREFIX_STATICLIB")
                 + project->first("TARGET") + "." + project->first("QMAKE_EXTENSION_STATICLIB"));
