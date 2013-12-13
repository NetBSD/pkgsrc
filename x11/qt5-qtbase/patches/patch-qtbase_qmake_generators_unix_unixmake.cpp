$NetBSD: patch-qtbase_qmake_generators_unix_unixmake.cpp,v 1.1 2013/12/13 14:38:35 ryoon Exp $

* First chunk, add a whitespace after -rpath.

--- qtbase/qmake/generators/unix/unixmake.cpp.orig	2013-11-27 01:01:10.000000000 +0000
+++ qtbase/qmake/generators/unix/unixmake.cpp
@@ -156,7 +156,7 @@ UnixMakefileGenerator::init()
         const ProStringList &rpathdirs = project->values("QMAKE_RPATHDIR");
         for(int i = 0; i < rpathdirs.size(); ++i) {
             if(!project->isEmpty("QMAKE_LFLAGS_RPATH"))
-                project->values("QMAKE_LFLAGS") += var("QMAKE_LFLAGS_RPATH") + escapeFilePath(QFileInfo(rpathdirs[i].toQString()).absoluteFilePath());
+                project->values("QMAKE_LFLAGS") += var("QMAKE_LFLAGS_RPATH") + " " + escapeFilePath(QFileInfo(rpathdirs[i].toQString()).absoluteFilePath());
         }
     }
     if (!project->isEmpty("QMAKE_RPATHLINKDIR")) {
@@ -346,27 +346,29 @@ UnixMakefileGenerator::init()
                 if (!strncmp(libtoolify[i], "QMAKE_LINK", 10) || !strcmp(libtoolify[i], "QMAKE_AR_CMD")) {
                     libtool_flags += " --mode=link";
                     if(project->isActiveConfig("staticlib")) {
-                        libtool_flags += " -static";
+                        comp_flags += " -static";
                     } else {
                         if(!project->isEmpty("QMAKE_LIB_FLAG")) {
+                          if(project->isActiveConfig("plugin"))
+                            comp_flags += " -avoid-version";
+                          else {
                             int maj = project->first("VER_MAJ").toInt();
                             int min = project->first("VER_MIN").toInt();
                             int pat = project->first("VER_PAT").toInt();
-                            comp_flags += " -version-info " + QString::number(10*maj + min) +
-                                          ":" + QString::number(pat) + ":0";
+                            comp_flags += " -version-info " + QString::number(maj + min) +
+                                          ":" + QString::number(pat) +
+                                          ":" + QString::number(min);
+                          }
                             if (strcmp(libtoolify[i], "QMAKE_AR_CMD")) {
-                                QString rpath = Option::output_dir;
-                                if(!project->isEmpty("DESTDIR")) {
-                                    rpath = project->first("DESTDIR").toQString();
-                                    if(QDir::isRelativePath(rpath))
-                                        rpath.prepend(Option::output_dir + Option::dir_sep);
-                                }
+                                 QString rpath = Option::fixPathToTargetOS(project->first("target.path").toQString(), false);
+                                 if(rpath.right(1) != Option::dir_sep)
+                                     rpath += Option::dir_sep;
                                 comp_flags += " -rpath " + Option::fixPathToTargetOS(rpath, false);
                             }
                         }
                     }
                     if(project->isActiveConfig("plugin"))
-                        libtool_flags += " -module";
+                        comp_flags += " -module";
                 } else {
                     libtool_flags += " --mode=compile";
                 }
@@ -722,7 +724,6 @@ UnixMakefileGenerator::defaultInstall(co
     QString targetdir = Option::fixPathToTargetOS(project->first("target.path").toQString(), false);
     if(!destdir.isEmpty() && destdir.right(1) != Option::dir_sep)
         destdir += Option::dir_sep;
-    targetdir = fileFixify(targetdir, FileFixifyAbsolute);
     if(targetdir.right(1) != Option::dir_sep)
         targetdir += Option::dir_sep;
 
@@ -760,10 +761,14 @@ UnixMakefileGenerator::defaultInstall(co
         QString src_targ = target;
         if(src_targ == "$(TARGET)")
             src_targ = "$(TARGETL)";
-        QString dst_dir = fileFixify(targetdir, FileFixifyAbsolute);
+        QString dst_dir = targetdir;
         if(QDir::isRelativePath(dst_dir))
-            dst_dir = Option::fixPathToTargetOS(Option::output_dir + Option::dir_sep + dst_dir);
-        ret = "-$(LIBTOOL) --mode=install cp \"" + src_targ + "\" \"" + filePrefixRoot(root, dst_dir) + "\"";
+            dst_dir = Option::fixPathToTargetOS(dst_dir);
+        if(!ret.isEmpty())
+            ret += "\n\t";
+        ret += "-$(LIBTOOL) --mode=install cp \"" + src_targ + "\" \"" + filePrefixRoot(root, dst_dir) + "\"";
+        if(!uninst.isEmpty())
+            uninst.append("\n\t");
         uninst.append("-$(LIBTOOL) --mode=uninstall \"" + src_targ + "\"");
     } else {
         QString src_targ = target;
