$NetBSD: patch-src_corelib_io_qstandardpaths__unix.cpp,v 1.1 2023/04/07 18:28:05 nros Exp $

Add ${PREFIX}/share to search path
Add ${PKG_SYSCONFBASE}/xdg to search path

--- src/corelib/io/qstandardpaths_unix.cpp.orig	2023-03-14 08:29:43.000000000 +0000
+++ src/corelib/io/qstandardpaths_unix.cpp
@@ -369,7 +369,7 @@ static QStringList xdgDataDirs()
 
     QStringList dirs = dirsList(xdgDataDirsEnv);
     if (dirs.isEmpty())
-        dirs = QStringList{u"/usr/local/share"_s, u"/usr/share"_s};
+        dirs = QStringList{u"@PREFIX@/share"_s, u"/usr/local/share"_s, u"/usr/share"_s};
 
     return dirs;
 }
@@ -381,7 +381,7 @@ static QStringList xdgConfigDirs()
 
     QStringList dirs = dirsList(xdgConfigDirs);
     if (dirs.isEmpty())
-        dirs.push_back(u"/etc/xdg"_s);
+        dirs = QStringList{u"@PKG_SYSCONFBASE@/xdg"_s, u"/etc/xdg"_s};
 
     return dirs;
 }
