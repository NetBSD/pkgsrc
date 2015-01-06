$NetBSD: patch-qmake_generators_unix_unixmake.cpp,v 1.2 2015/01/06 23:00:16 joerg Exp $

* fix install target so that destdir is added when installing QMAKE_TARGET

--- qmake/generators/unix/unixmake.cpp.orig	2014-12-05 16:24:30.000000000 +0000
+++ qmake/generators/unix/unixmake.cpp
@@ -353,27 +353,29 @@ UnixMakefileGenerator::init()
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
@@ -729,7 +731,6 @@ UnixMakefileGenerator::defaultInstall(co
     QString targetdir = Option::fixPathToTargetOS(project->first("target.path").toQString(), false);
     if(!destdir.isEmpty() && destdir.right(1) != Option::dir_sep)
         destdir += Option::dir_sep;
-    targetdir = fileFixify(targetdir, FileFixifyAbsolute);
     if(targetdir.right(1) != Option::dir_sep)
         targetdir += Option::dir_sep;
 
@@ -769,10 +770,18 @@ UnixMakefileGenerator::defaultInstall(co
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
+        if(project->first("TEMPLATE") == "app") {
+	    ret += "-$(LIBTOOL) --mode=install cp \"" + Option::fixPathToTargetOS(destdir + src_targ, false) + "\" \"" + filePrefixRoot(root, dst_dir) + "\"";
+	} else {
+	    ret += "-$(LIBTOOL) --mode=install cp \"" + src_targ + "\" \"" + filePrefixRoot(root, dst_dir) + "\"";
+	}
+        if(!uninst.isEmpty())
+            uninst.append("\n\t");
         uninst.append("-$(LIBTOOL) --mode=uninstall \"" + src_targ + "\"");
     } else {
         QString src_targ = target;
