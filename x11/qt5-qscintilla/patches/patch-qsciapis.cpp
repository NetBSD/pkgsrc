$NetBSD: patch-qsciapis.cpp,v 1.1 2020/01/26 12:54:15 rhialto Exp $

Search in qt5/qsci*/api/.../*.api.

--- qsciapis.cpp.orig	2019-06-25 12:49:27.000000000 +0000
+++ qsciapis.cpp
@@ -982,6 +982,7 @@ QString QsciAPIs::prepName(const QString
 // Return installed API files.
 QStringList QsciAPIs::installedAPIFiles() const
 {
+#if 0
     QString qtdir = QLibraryInfo::location(QLibraryInfo::DataPath);
 
     QDir apidir = QDir(QString("%1/qsci/api/%2").arg(qtdir).arg(lexer()->lexer()));
@@ -996,4 +997,32 @@ QStringList QsciAPIs::installedAPIFiles(
         filenames << fi.absoluteFilePath();
 
     return filenames;
+#endif
+
+    QString datapath = QLibraryInfo::location(QLibraryInfo::DataPath);
+    QString lexerdir = lexer()->lexer();
+
+    QStringList filenames;
+
+    QStringList filters;
+    filters << "*.api";
+
+    QStringList qscifilters;
+    qscifilters << "qsci*";
+
+    // Find QTDIR/qsci*/api/LEXER/*.api
+    QDir datadir = QDir(datapath);
+    QFileInfoList dlist = datadir.entryInfoList(qscifilters, QDir::AllDirs, QDir::IgnoreCase);
+
+    foreach (QFileInfo di, dlist) {
+	QString qscidir = di.absoluteFilePath();
+	QDir apidir = QDir(QString("%1/api/%2").arg(qscidir).arg(lexerdir));
+
+	QFileInfoList flist = apidir.entryInfoList(filters, QDir::Files, QDir::IgnoreCase);
+
+	foreach (QFileInfo fi, flist)
+	    filenames << fi.absoluteFilePath();
+    }
+
+    return filenames;
 }
