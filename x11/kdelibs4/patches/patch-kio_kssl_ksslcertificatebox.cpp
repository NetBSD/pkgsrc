$NetBSD: patch-kio_kssl_ksslcertificatebox.cpp,v 1.1 2011/11/20 02:08:10 markd Exp $

don't interpret html tags. KDE Security Advisory 20111003-1

--- kio/kssl/ksslcertificatebox.cpp.orig	2008-05-21 11:08:14.000000000 +0000
+++ kio/kssl/ksslcertificatebox.cpp
@@ -36,6 +36,10 @@ KSslCertificateBox::KSslCertificateBox(Q
    d(new KSslCertificateBoxPrivate())
 {
     d->ui.setupUi(this);
+    // No fooling us with html tags
+    Q_FOREACH(QLabel* label, qFindChildren<QLabel *>(this)) {
+        label->setTextFormat(Qt::PlainText);
+    }
 }
 
 
