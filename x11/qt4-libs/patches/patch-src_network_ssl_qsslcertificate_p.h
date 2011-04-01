$NetBSD: patch-src_network_ssl_qsslcertificate_p.h,v 1.1 2011/04/01 20:53:55 markd Exp $

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

diff --git a/src/network/ssl/qsslcertificate_p.h b/src/network/ssl/qsslcertificate_p.h
index cdceb0f..1ce33d3 100644
--- src/network/ssl/qsslcertificate_p.h
+++ src/network/ssl/qsslcertificate_p.h
@@ -96,6 +96,7 @@ public:
     static QSslCertificate QSslCertificate_from_X509(X509 *x509);
     static QList<QSslCertificate> certificatesFromPem(const QByteArray &pem, int count = -1);
     static QList<QSslCertificate> certificatesFromDer(const QByteArray &der, int count = -1);
+    static bool isBlacklisted(const QSslCertificate &certificate);
 
     friend class QSslSocketBackendPrivate;
 
