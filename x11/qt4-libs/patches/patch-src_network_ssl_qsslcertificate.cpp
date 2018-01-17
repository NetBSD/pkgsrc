$NetBSD: patch-src_network_ssl_qsslcertificate.cpp,v 1.3 2018/01/17 18:37:34 markd Exp $

Compile with openssl-1.1.0 http://bugs.debian.org/828522 via archlinux

--- src/network/ssl/qsslcertificate.cpp.orig	2015-05-07 14:14:44.000000000 +0000
+++ src/network/ssl/qsslcertificate.cpp
@@ -259,10 +259,10 @@ void QSslCertificate::clear()
 QByteArray QSslCertificate::version() const
 {
     QMutexLocker lock(QMutexPool::globalInstanceGet(d.data()));
-    if (d->versionString.isEmpty() && d->x509)
+    if (d->versionString.isEmpty() && d->x509) {
         d->versionString =
-            QByteArray::number(qlonglong(q_ASN1_INTEGER_get(d->x509->cert_info->version)) + 1);
-
+	    QByteArray::number(qlonglong(q_X509_get_version(d->x509)) + 1);
+    }
     return d->versionString;
 }
 
@@ -276,7 +276,7 @@ QByteArray QSslCertificate::serialNumber
 {
     QMutexLocker lock(QMutexPool::globalInstanceGet(d.data()));
     if (d->serialNumberString.isEmpty() && d->x509) {
-        ASN1_INTEGER *serialNumber = d->x509->cert_info->serialNumber;
+        ASN1_INTEGER *serialNumber = q_X509_get_serialNumber(d->x509);
         // if we cannot convert to a long, just output the hexadecimal number
         if (serialNumber->length > 4) {
             QByteArray hexString;
@@ -489,24 +489,33 @@ QSslKey QSslCertificate::publicKey() con
     QSslKey key;
 
     key.d->type = QSsl::PublicKey;
+#if OPENSSL_VERSION_NUMBER < 0x10100000L
     X509_PUBKEY *xkey = d->x509->cert_info->key;
+#else
+    X509_PUBKEY *xkey = q_X509_get_X509_PUBKEY(d->x509);
+#endif
     EVP_PKEY *pkey = q_X509_PUBKEY_get(xkey);
     Q_ASSERT(pkey);
 
-    if (q_EVP_PKEY_type(pkey->type) == EVP_PKEY_RSA) {
+    int key_id;
+#if OPENSSL_VERSION_NUMBER < 0x10100000L
+    key_id = q_EVP_PKEY_type(pkey->type);
+#else
+    key_id = q_EVP_PKEY_base_id(pkey);
+#endif
+    if (key_id == EVP_PKEY_RSA) {
         key.d->rsa = q_EVP_PKEY_get1_RSA(pkey);
         key.d->algorithm = QSsl::Rsa;
         key.d->isNull = false;
-    } else if (q_EVP_PKEY_type(pkey->type) == EVP_PKEY_DSA) {
+    } else if (key_id == EVP_PKEY_DSA) {
         key.d->dsa = q_EVP_PKEY_get1_DSA(pkey);
         key.d->algorithm = QSsl::Dsa;
         key.d->isNull = false;
-    } else if (q_EVP_PKEY_type(pkey->type) == EVP_PKEY_DH) {
+    } else if (key_id == EVP_PKEY_DH) {
         // DH unsupported
     } else {
         // error?
     }
-
     q_EVP_PKEY_free(pkey);
     return key;
 }
@@ -687,7 +696,7 @@ static QMap<QString, QString> _q_mapFrom
         unsigned char *data = 0;
         int size = q_ASN1_STRING_to_UTF8(&data, q_X509_NAME_ENTRY_get_data(e));
         info[QString::fromUtf8(obj)] = QString::fromUtf8((char*)data, size);
-        q_CRYPTO_free(data);
+        q_OPENSSL_free(data);
     }
     return info;
 }
