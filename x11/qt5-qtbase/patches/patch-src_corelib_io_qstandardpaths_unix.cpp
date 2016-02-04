$NetBSD: patch-src_corelib_io_qstandardpaths_unix.cpp,v 1.1 2016/02/04 10:41:13 markd Exp $

Add $LOCALBASE/share to search path

--- src/corelib/io/qstandardpaths_unix.cpp.orig	2015-10-13 04:35:31.000000000 +0000
+++ src/corelib/io/qstandardpaths_unix.cpp
@@ -255,6 +255,7 @@ static QStringList xdgDataDirs()
     // http://standards.freedesktop.org/basedir-spec/latest/
     QString xdgDataDirsEnv = QFile::decodeName(qgetenv("XDG_DATA_DIRS"));
     if (xdgDataDirsEnv.isEmpty()) {
+        dirs.append(QString::fromLatin1("@LOCALBASE@/share"));
         dirs.append(QString::fromLatin1("/usr/local/share"));
         dirs.append(QString::fromLatin1("/usr/share"));
     } else {
