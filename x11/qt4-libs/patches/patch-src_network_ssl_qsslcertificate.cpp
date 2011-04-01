$NetBSD: patch-src_network_ssl_qsslcertificate.cpp,v 1.1 2011/04/01 20:53:55 markd Exp $

From 04e074e8d7c097295505e63565abdc7ca2b49f7b Mon Sep 17 00:00:00 2001
From: Peter Hartmann <peter.hartmann@nokia.com>
Date: Thu, 24 Mar 2011 14:42:22 +0100
Subject: [PATCH] QSslCertificate: report fraudulent certificates as invalid

There are some fraudulent certificates in the wild that are not valid;
this patch introduces a blacklist of serial numbers of those
certificates.

Reviewed-by: Richard J. Moore
Reviewed-by: Markus Goetz
Task-number: QTBUG-18338
---

diff --git a/src/network/ssl/qsslcertificate.cpp b/src/network/ssl/qsslcertificate.cpp
index 618ac79..a5cdf01 100644
--- src/network/ssl/qsslcertificate.cpp
+++ src/network/ssl/qsslcertificate.cpp
@@ -219,17 +219,19 @@ bool QSslCertificate::isNull() const
     Returns true if this certificate is valid; otherwise returns
     false.
 
-    Note: Currently, this function only checks that the current
+    Note: Currently, this function checks that the current
     data-time is within the date-time range during which the
-    certificate is considered valid. No other checks are
-    currently performed.
+    certificate is considered valid, and checks that the
+    certificate is not in a blacklist of fraudulent certificates.
 
     \sa isNull()
 */
 bool QSslCertificate::isValid() const
 {
     const QDateTime currentTime = QDateTime::currentDateTime();
-    return currentTime >= d->notValidBefore && currentTime <= d->notValidAfter;
+    return currentTime >= d->notValidBefore &&
+            currentTime <= d->notValidAfter &&
+            ! QSslCertificatePrivate::isBlacklisted(*this);
 }
 
 /*!
@@ -798,6 +800,30 @@ QList<QSslCertificate> QSslCertificatePrivate::certificatesFromDer(const QByteAr
     return certificates;
 }
 
+// These certificates are known to be fraudulent and were created during the comodo
+// compromise. See http://www.comodo.com/Comodo-Fraud-Incident-2011-03-23.html
+static const char *certificate_blacklist[] = {
+    "04:7e:cb:e9:fc:a5:5f:7b:d0:9e:ae:36:e1:0c:ae:1e",
+    "f5:c8:6a:f3:61:62:f1:3a:64:f5:4f:6d:c9:58:7c:06",
+    "d7:55:8f:da:f5:f1:10:5b:b2:13:28:2b:70:77:29:a3",
+    "39:2a:43:4f:0e:07:df:1f:8a:a3:05:de:34:e0:c2:29",
+    "3e:75:ce:d4:6b:69:30:21:21:88:30:ae:86:a8:2a:71",
+    "e9:02:8b:95:78:e4:15:dc:1a:71:0a:2b:88:15:44:47",
+    "92:39:d5:34:8f:40:d1:69:5a:74:54:70:e1:f2:3f:43",
+    "b0:b7:13:3e:d0:96:f9:b5:6f:ae:91:c8:74:bd:3a:c0",
+    "d8:f3:5f:4e:b7:87:2b:2d:ab:06:92:e3:15:38:2f:b0",
+    0
+};
+
+bool QSslCertificatePrivate::isBlacklisted(const QSslCertificate &certificate)
+{
+    for (int a = 0; certificate_blacklist[a] != 0; a++) {
+        if (certificate.serialNumber() == certificate_blacklist[a])
+            return true;
+    }
+    return false;
+}
+
 #ifndef QT_NO_DEBUG_STREAM
 QDebug operator<<(QDebug debug, const QSslCertificate &certificate)
 {
