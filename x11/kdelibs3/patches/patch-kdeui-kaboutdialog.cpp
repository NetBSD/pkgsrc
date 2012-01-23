$NetBSD: patch-kdeui-kaboutdialog.cpp,v 1.1 2012/01/23 08:12:40 joerg Exp $

--- kdeui/kaboutdialog.cpp.orig	2012-01-22 17:37:33.000000000 +0000
+++ kdeui/kaboutdialog.cpp
@@ -703,7 +703,7 @@ void KAboutContainerBase::setProduct( co
 
   const QString msg1 = i18n("%1 %2 (Using KDE %3)").arg(appName).arg(version).
     arg(QString::fromLatin1(KDE_VERSION_STRING));
-  const QString msg2 = !year.isEmpty() ? i18n("%1 %2, %3").arg('©').arg(year).
+  const QString msg2 = !year.isEmpty() ? i18n("%1 %2, %3").arg((char)0xa9).arg(year).
     arg(author) : QString::fromLatin1("");
 
   //if (!year.isEmpty())
