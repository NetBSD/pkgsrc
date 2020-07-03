$NetBSD: patch-Qt4Qt5_qsciapis.cpp,v 1.1.2.2 2020/07/03 10:29:50 bsiegert Exp $

Search in qt5/qsci*/api/.../*.api.

--- Qt4Qt5/qsciapis.cpp.orig	2019-06-25 12:49:27.000000000 +0000
+++ Qt4Qt5/qsciapis.cpp
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
