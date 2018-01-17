$NetBSD: patch-kio_kssl_ksslcertificate.cpp,v 1.1 2018/01/17 18:53:25 markd Exp $

Support openssl-1.1 

--- kio/kssl/ksslcertificate.cpp.orig	2016-12-08 18:44:10.000000000 +0000
+++ kio/kssl/ksslcertificate.cpp
@@ -150,7 +150,7 @@ KSSLCertificate *KSSLCertificate::fromSt
     }
 
     QByteArray qba = QByteArray::fromBase64(cert);
-    unsigned char *qbap = reinterpret_cast<unsigned char *>(qba.data());
+    const unsigned char *qbap = reinterpret_cast<unsigned char *>(qba.data());
     X509 *x5c = KOSSL::self()->d2i_X509(NULL, &qbap, qba.size());
     if (!x5c) {
         return NULL;
@@ -173,7 +173,7 @@ QString KSSLCertificate::getSubject() co
         return rc;
     }
     rc = t;
-    d->kossl->OPENSSL_free(t);
+    OPENSSL_free(t);
 #endif
     return rc;
 }
@@ -200,14 +200,28 @@ QString KSSLCertificate::getSignatureTex
     char *s;
     int n, i;
 
+#if OPENSSL_VERSION_NUMBER < 0x10100000L
     i = d->kossl->OBJ_obj2nid(d->m_cert->sig_alg->algorithm);
+#else
+    i = X509_get_signature_nid(d->m_cert);
+#endif
     rc = i18n("Signature Algorithm: ");
     rc += (i == NID_undef)?i18n("Unknown"):QString(d->kossl->OBJ_nid2ln(i));
 
     rc += '\n';
     rc += i18n("Signature Contents:");
+#if OPENSSL_VERSION_NUMBER < 0x10100000L
     n = d->m_cert->signature->length;
     s = (char *)d->m_cert->signature->data;
+#else
+    
+    const ASN1_BIT_STRING *sig;
+    const X509_ALGOR *alg;
+    X509_get0_signature(&sig, &alg, d->m_cert);
+    n = sig->length;
+    s = (char*)sig->data;
+#endif
+
     for (i = 0; i < n; ++i) {
         if (i%20 != 0) {
             rc += ':';
@@ -234,7 +248,7 @@ void KSSLCertificate::getEmails(QStringL
 
     STACK *s = d->kossl->X509_get1_email(d->m_cert);
     if (s) {
-        for(int n=0; n < s->num; n++) {
+        for(int n=0; n < OPENSSL_sk_num(s); n++) {
             to.append(d->kossl->sk_value(s,n));
         }
         d->kossl->X509_email_free(s);
@@ -317,13 +331,13 @@ QString rc = "";
     EVP_PKEY *pkey = d->kossl->X509_get_pubkey(d->m_cert);
     if (pkey) {
         #ifndef NO_RSA
-            if (pkey->type == EVP_PKEY_RSA) {
+            if (EVP_PKEY_id(pkey) == EVP_PKEY_RSA) {
                 rc = "RSA";
             }
             else
         #endif
         #ifndef NO_DSA
-            if (pkey->type == EVP_PKEY_DSA) {
+            if (EVP_PKEY_id(pkey) == EVP_PKEY_DSA) {
                 rc = "DSA";
             }
             else
@@ -347,8 +361,14 @@ char *x = NULL;
     if (pkey) {
         rc = i18nc("Unknown", "Unknown key algorithm");
         #ifndef NO_RSA
-            if (pkey->type == EVP_PKEY_RSA) {
-                x = d->kossl->BN_bn2hex(pkey->pkey.rsa->n);
+            if (EVP_PKEY_id(pkey) == EVP_PKEY_RSA) {
+#if OPENSSL_VERSION_NUMBER < 0x10100000L
+		x = d->kossl->BN_bn2hex(pkey->pkey.rsa->n);
+#else
+		const BIGNUM *n, *e;
+		RSA_get0_key(EVP_PKEY_get1_RSA(pkey), &n, &e, NULL);
+                x = d->kossl->BN_bn2hex(n);
+#endif
                 rc = i18n("Key type: RSA (%1 bit)", strlen(x)*4) + '\n';
 
                 rc += i18n("Modulus: ");
@@ -362,17 +382,27 @@ char *x = NULL;
                     rc += x[i];
                 }
                 rc += '\n';
-                d->kossl->OPENSSL_free(x);
+                ::OPENSSL_free(x);
 
-                x = d->kossl->BN_bn2hex(pkey->pkey.rsa->e);
+#if OPENSSL_VERSION_NUMBER < 0x10100000L
+		x = d->kossl->BN_bn2hex(pkey->pkey.rsa->e);
+#else
+                x = d->kossl->BN_bn2hex(e);
+#endif
                 rc += i18n("Exponent: 0x") + QLatin1String(x) +
                   QLatin1String("\n");
-                d->kossl->OPENSSL_free(x);
+                ::OPENSSL_free(x);
             }
         #endif
         #ifndef NO_DSA
-            if (pkey->type == EVP_PKEY_DSA) {
-                x = d->kossl->BN_bn2hex(pkey->pkey.dsa->p);
+            if (EVP_PKEY_id(pkey) == EVP_PKEY_DSA) {
+#if OPENSSL_VERSION_NUMBER < 0x10100000L
+		x = d->kossl->BN_bn2hex(pkey->pkey.dsa->p);
+#else
+		const BIGNUM *p, *q, *g;
+		DSA_get0_pqg(EVP_PKEY_get1_DSA(pkey), &p, &q, &g);
+                x = d->kossl->BN_bn2hex(p);
+#endif
                 // hack - this may not be always accurate
                 rc = i18n("Key type: DSA (%1 bit)", strlen(x)*4) + '\n';
 
@@ -387,9 +417,13 @@ char *x = NULL;
                     rc += x[i];
                 }
                 rc += '\n';
-                d->kossl->OPENSSL_free(x);
+                ::OPENSSL_free(x);
 
-                x = d->kossl->BN_bn2hex(pkey->pkey.dsa->q);
+#if OPENSSL_VERSION_NUMBER < 0x10100000L
+		x = d->kossl->BN_bn2hex(pkey->pkey.dsa->q);
+#else
+                x = d->kossl->BN_bn2hex(q);
+#endif
                 rc += i18n("160 bit prime factor: ");
                 for (unsigned int i = 0; i < strlen(x); i++) {
                     if (i%40 != 0 && i%2 == 0) {
@@ -401,9 +435,13 @@ char *x = NULL;
                     rc += x[i];
                 }
                 rc += '\n';
-                d->kossl->OPENSSL_free(x);
+                ::OPENSSL_free(x);
 
-                x = d->kossl->BN_bn2hex(pkey->pkey.dsa->g);
+#if OPENSSL_VERSION_NUMBER < 0x10100000L
+		x = d->kossl->BN_bn2hex(pkey->pkey.dsa->g);
+#else
+                x = d->kossl->BN_bn2hex(g);
+#endif
                 rc += QString("g: ");
                 for (unsigned int i = 0; i < strlen(x); i++) {
                     if (i%40 != 0 && i%2 == 0) {
@@ -415,9 +453,15 @@ char *x = NULL;
                     rc += x[i];
                 }
                 rc += '\n';
-                d->kossl->OPENSSL_free(x);
+                ::OPENSSL_free(x);
 
-                x = d->kossl->BN_bn2hex(pkey->pkey.dsa->pub_key);
+#if OPENSSL_VERSION_NUMBER < 0x10100000L
+		x = d->kossl->BN_bn2hex(pkey->pkey.dsa->pub_key);
+#else
+		const BIGNUM *pub;
+		DSA_get0_key(EVP_PKEY_get1_DSA(pkey), &pub, NULL);
+                x = d->kossl->BN_bn2hex(pub);
+#endif
                 rc += i18n("Public key: ");
                 for (unsigned int i = 0; i < strlen(x); i++) {
                     if (i%40 != 0 && i%2 == 0) {
@@ -429,7 +473,7 @@ char *x = NULL;
                     rc += x[i];
                 }
                 rc += '\n';
-                d->kossl->OPENSSL_free(x);
+                ::OPENSSL_free(x);
             }
         #endif
         d->kossl->EVP_PKEY_free(pkey);
@@ -452,7 +496,7 @@ QString rc = "";
     }
 
     rc = t;
-    d->kossl->OPENSSL_free(t);
+    OPENSSL_free(t);
 #endif
 
     return rc;
@@ -724,9 +768,9 @@ KSSLCertificate::KSSLValidationList KSSL
         KSSL_X509CallBack_ca = ca ? ca->d->m_cert : 0;
         KSSL_X509CallBack_ca_found = false;
 
-        certStoreCTX->error = X509_V_OK;
+        X509_STORE_CTX_set_error(certStoreCTX, X509_V_OK);
         rc = d->kossl->X509_verify_cert(certStoreCTX);
-        int errcode = certStoreCTX->error;
+        int errcode = X509_STORE_CTX_get_error(certStoreCTX);
         if (ca && !KSSL_X509CallBack_ca_found) {
             ksslv = KSSLCertificate::Irrelevant;
         } else {
@@ -739,9 +783,9 @@ KSSLCertificate::KSSLValidationList KSSL
             d->kossl->X509_STORE_CTX_set_purpose(certStoreCTX,
                                                  X509_PURPOSE_NS_SSL_SERVER);
 
-            certStoreCTX->error = X509_V_OK;
+            X509_STORE_CTX_set_error(certStoreCTX, X509_V_OK);
             rc = d->kossl->X509_verify_cert(certStoreCTX);
-            errcode = certStoreCTX->error;
+            errcode = X509_STORE_CTX_get_error(certStoreCTX);
             ksslv = processError(errcode);
         }
         d->kossl->X509_STORE_CTX_free(certStoreCTX);
@@ -1210,7 +1254,7 @@ typedef struct NETSCAPE_X509_st
 // what a piece of crap this is
 QByteArray KSSLCertificate::toNetscape() {
     QByteArray qba;
-#ifdef KSSL_HAVE_SSL
+#if defined(KSSL_HAVE_SSL) && OPENSSL_VERSION_NUMBER < 0x01001000L
     NETSCAPE_X509 nx;
     ASN1_OCTET_STRING hdr;
     KTemporaryFile ktf;
@@ -1262,7 +1306,7 @@ bool KSSLCertificate::setCert(const QStr
 #ifdef KSSL_HAVE_SSL
         QByteArray qba, qbb = cert.toLocal8Bit();
         qba = QByteArray::fromBase64(qbb);
-        unsigned char *qbap = reinterpret_cast<unsigned char *>(qba.data());
+        const unsigned char *qbap = reinterpret_cast<const unsigned char *>(qba.data());
         X509 *x5c = KOSSL::self()->d2i_X509(NULL, &qbap, qba.size());
         if (x5c) {
             setCert(x5c);
@@ -1293,7 +1337,7 @@ QStringList KSSLCertificate::subjAltName
         return rc;
     }
 
-    int cnt = d->kossl->sk_GENERAL_NAME_num(names);
+    int cnt = sk_GENERAL_NAME_num(names);
 
     for (int i = 0; i < cnt; i++) {
         const GENERAL_NAME *val = (const GENERAL_NAME *)d->kossl->sk_value(names, i);
