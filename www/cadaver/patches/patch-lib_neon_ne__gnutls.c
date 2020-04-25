$NetBSD: patch-lib_neon_ne__gnutls.c,v 1.1 2020/04/25 13:47:31 nia Exp $

Fix build with newer gnutls.

--- lib/neon/ne_gnutls.c.orig	2009-12-02 21:40:41.000000000 +0000
+++ lib/neon/ne_gnutls.c
@@ -33,15 +33,13 @@
 #include <errno.h>
 
 #include <gnutls/gnutls.h>
+#include <gnutls/abstract.h>
 #include <gnutls/pkcs12.h>
 
 #ifdef NE_HAVE_TS_SSL
 #include <errno.h>
 #include <pthread.h>
-#include <gcrypt.h>
 GCRY_THREAD_OPTION_PTHREAD_IMPL;
-#else
-#include <gcrypt.h>
 #endif
 
 #ifdef HAVE_ICONV
@@ -67,30 +65,30 @@ struct ne_ssl_dname_s {
     gnutls_x509_dn_t dn;
 #else
     int subject; /* non-zero if this is the subject DN object */
-    gnutls_x509_crt cert;
+    gnutls_x509_crt_t cert;
 #endif
 };
 
 struct ne_ssl_certificate_s {
     ne_ssl_dname subj_dn, issuer_dn;
-    gnutls_x509_crt subject;
+    gnutls_x509_crt_t subject;
     ne_ssl_certificate *issuer;
     char *identity;
 };
 
 struct ne_ssl_client_cert_s {
-    gnutls_pkcs12 p12;
+    gnutls_pkcs12_t p12;
     int decrypted; /* non-zero if successfully decrypted. */
     int keyless;
     ne_ssl_certificate cert;
-    gnutls_x509_privkey pkey;
+    gnutls_x509_privkey_t pkey;
     char *friendly_name;
 };
 
 /* Returns the highest used index in subject (or issuer) DN of
  * certificate CERT for OID, or -1 if no RDNs are present in the DN
  * using that OID. */
-static int oid_find_highest_index(gnutls_x509_crt cert, int subject, const char *oid)
+static int oid_find_highest_index(gnutls_x509_crt_t cert, int subject, const char *oid)
 {
     int ret, idx = -1;
 
@@ -113,7 +111,7 @@ static int oid_find_highest_index(gnutls
 
 #ifdef HAVE_ICONV
 static void convert_dirstring(ne_buffer *buf, const char *charset, 
-                              gnutls_datum *data)
+                              gnutls_datum_t *data)
 {
     iconv_t id = iconv_open("UTF-8", charset);
     size_t inlen = data->size, outlen = buf->length - buf->used;
@@ -150,7 +148,7 @@ static void convert_dirstring(ne_buffer 
 #define TAG_UNIVERSAL (28)
 #define TAG_BMP (30)
 
-static void append_dirstring(ne_buffer *buf, gnutls_datum *data, unsigned long tag)
+static void append_dirstring(ne_buffer *buf, gnutls_datum_t *data, unsigned long tag)
 {
     switch (tag) {
     case TAG_UTF8:
@@ -240,7 +238,7 @@ char *ne_ssl_readable_dname(const ne_ssl
 
 /* Appends the value of RDN with given oid from certitifcate x5
  * subject (if subject is non-zero), or issuer DN to buffer 'buf': */
-static void append_rdn(ne_buffer *buf, gnutls_x509_crt x5, int subject, const char *oid)
+static void append_rdn(ne_buffer *buf, gnutls_x509_crt_t x5, int subject, const char *oid)
 {
     int idx, top, ret;
     char rdn[50];
@@ -353,7 +351,7 @@ void ne_ssl_cert_validity_time(const ne_
  * If 'identity' is non-NULL, store the malloc-allocated identity in
  * *identity.  If 'server' is non-NULL, it must be the network address
  * of the server in use, and identity must be NULL. */
-static int check_identity(const ne_uri *server, gnutls_x509_crt cert,
+static int check_identity(const ne_uri *server, gnutls_x509_crt_t cert,
                           char **identity)
 {
     char name[255];
@@ -460,7 +458,7 @@ static int check_identity(const ne_uri *
  * that x5 is owned by returned cert object and must not be otherwise
  * freed by the caller.  */
 static ne_ssl_certificate *populate_cert(ne_ssl_certificate *cert,
-                                         gnutls_x509_crt x5)
+                                         gnutls_x509_crt_t x5)
 {
 #ifdef HAVE_NEW_DN_API
     gnutls_x509_crt_get_subject(x5, &cert->subj_dn.dn);
@@ -479,12 +477,12 @@ static ne_ssl_certificate *populate_cert
 }
 
 /* Returns a copy certificate of certificate SRC. */
-static gnutls_x509_crt x509_crt_copy(gnutls_x509_crt src)
+static gnutls_x509_crt_t x509_crt_copy(gnutls_x509_crt_t src)
 {
     int ret;
     size_t size;
-    gnutls_datum tmp;
-    gnutls_x509_crt dest;
+    gnutls_datum_t tmp;
+    gnutls_x509_crt_t dest;
     
     if (gnutls_x509_crt_init(&dest) != 0) {
         return NULL;
@@ -547,10 +545,10 @@ dup_error:
 }    
 
 /* Callback invoked when the SSL server requests a client certificate.  */
-static int provide_client_cert(gnutls_session session,
-                               const gnutls_datum *req_ca_rdn, int nreqs,
-                               const gnutls_pk_algorithm *sign_algos,
-                               int sign_algos_length, gnutls_retr_st *st)
+static int provide_client_cert(gnutls_session_t session,
+                               const gnutls_datum_t *req_ca_rdn, int nreqs,
+                               const gnutls_pk_algorithm_t *sign_algos,
+                               int sign_algos_length, gnutls_retr2_st *st)
 {
     ne_session *sess = gnutls_session_get_ptr(session);
     
@@ -606,11 +604,11 @@ static int provide_client_cert(gnutls_se
     }
 
     if (sess->client_cert) {
-        gnutls_certificate_type type = gnutls_certificate_type_get(session);
+        gnutls_certificate_type_t type = gnutls_certificate_type_get(session);
         if (type == GNUTLS_CRT_X509) {
             NE_DEBUG(NE_DBG_SSL, "Supplying client certificate.\n");
 
-            st->type = type;
+            st->cert_type = type;
             st->ncerts = 1;
             st->cert.x509 = &sess->client_cert->cert.subject;
             st->key.x509 = sess->client_cert->pkey;
@@ -639,8 +637,7 @@ ne_ssl_context *ne_ssl_context_create(in
     ne_ssl_context *ctx = ne_calloc(sizeof *ctx);
     gnutls_certificate_allocate_credentials(&ctx->cred);
     if (flags == NE_SSL_CTX_CLIENT) {
-        gnutls_certificate_client_set_retrieve_function(ctx->cred,
-                                                        provide_client_cert);
+        gnutls_certificate_set_retrieve_function(ctx->cred, provide_client_cert);
     }
     gnutls_certificate_set_verify_flags(ctx->cred, 
                                         GNUTLS_VERIFY_ALLOW_X509_V1_CA_CRT);
@@ -689,9 +686,9 @@ void ne_ssl_context_destroy(ne_ssl_conte
 #ifdef HAVE_GNUTLS_CERTIFICATE_GET_X509_CAS
 /* Return the issuer of the given certificate, or NULL if none can be
  * found. */
-static gnutls_x509_crt find_issuer(gnutls_x509_crt *ca_list,
+static gnutls_x509_crt_t find_issuer(gnutls_x509_crt_t *ca_list,
                                    unsigned int num_cas,
-                                   gnutls_x509_crt cert)
+                                   gnutls_x509_crt_t cert)
 {
     unsigned int n;
 
@@ -705,11 +702,11 @@ static gnutls_x509_crt find_issuer(gnutl
 #endif
 
 /* Return the certificate chain sent by the peer, or NULL on error. */
-static ne_ssl_certificate *make_peers_chain(gnutls_session sock,
-                                            gnutls_certificate_credentials crd)
+static ne_ssl_certificate *make_peers_chain(gnutls_session_t sock,
+                                            gnutls_certificate_credentials_t crd)
 {
     ne_ssl_certificate *current = NULL, *top = NULL;
-    const gnutls_datum *certs;
+    const gnutls_datum_t *certs;
     unsigned int n, count;
     ne_ssl_certificate *cert;
 
@@ -721,7 +718,7 @@ static ne_ssl_certificate *make_peers_ch
     NE_DEBUG(NE_DBG_SSL, "ssl: Got %u certs in peer chain.\n", count);
     
     for (n = 0; n < count; n++) {
-        gnutls_x509_crt x5;
+        gnutls_x509_crt_t x5;
 
         if (gnutls_x509_crt_init(&x5) ||
             gnutls_x509_crt_import(x5, &certs[n], GNUTLS_X509_FMT_DER)) {
@@ -746,8 +743,8 @@ static ne_ssl_certificate *make_peers_ch
      * in the Certificate list during the handshake.  Fill in the
      * complete chain manually against the certs we trust: */
     if (current->issuer == NULL) {
-        gnutls_x509_crt issuer;
-        gnutls_x509_crt *ca_list;
+        gnutls_x509_crt_t issuer;
+        gnutls_x509_crt_t *ca_list;
         unsigned int num_cas;
         
         gnutls_certificate_get_x509_cas(crd, &ca_list, &num_cas);
@@ -849,7 +846,7 @@ static int check_chain_expiry(ne_ssl_cer
 }
 
 /* Verifies an SSL server certificate. */
-static int check_certificate(ne_session *sess, gnutls_session sock,
+static int check_certificate(ne_session *sess, gnutls_session_t sock,
                              ne_ssl_certificate *chain)
 {
     int ret, failures;
@@ -911,7 +908,7 @@ int ne__negotiate_ssl(ne_session *sess)
 {
     ne_ssl_context *const ctx = sess->ssl_context;
     ne_ssl_certificate *chain;
-    gnutls_session sock;
+    gnutls_session_t sock;
 
     NE_DEBUG(NE_DBG_SSL, "Negotiating SSL connection.\n");
 
@@ -980,7 +977,7 @@ const char *ne_ssl_cert_identity(const n
 
 void ne_ssl_context_trustcert(ne_ssl_context *ctx, const ne_ssl_certificate *cert)
 {
-    gnutls_x509_crt certs = cert->subject;
+    gnutls_x509_crt_t certs = cert->subject;
     gnutls_certificate_set_x509_trust(ctx->cred, &certs, 1);
 }
 
@@ -994,7 +991,7 @@ void ne_ssl_trust_default_ca(ne_session 
 }
 
 /* Read the contents of file FILENAME into *DATUM. */
-static int read_to_datum(const char *filename, gnutls_datum *datum)
+static int read_to_datum(const char *filename, gnutls_datum_t *datum)
 {
     FILE *f = fopen(filename, "r");
     ne_buffer *buf;
@@ -1026,11 +1023,11 @@ static int read_to_datum(const char *fil
 /* Parses a PKCS#12 structure and loads the certificate, private key
  * and friendly name if possible.  Returns zero on success, non-zero
  * on error. */
-static int pkcs12_parse(gnutls_pkcs12 p12, gnutls_x509_privkey *pkey,
-                        gnutls_x509_crt *x5, char **friendly_name,
+static int pkcs12_parse(gnutls_pkcs12_t p12, gnutls_x509_privkey_t *pkey,
+                        gnutls_x509_crt_t *x5, char **friendly_name,
                         const char *password)
 {
-    gnutls_pkcs12_bag bag = NULL;
+    gnutls_pkcs12_bag_t bag = NULL;
     int i, j, ret = 0;
 
     for (i = 0; ret == 0; ++i) {
@@ -1045,8 +1042,8 @@ static int pkcs12_parse(gnutls_pkcs12 p1
         gnutls_pkcs12_bag_decrypt(bag, password);
 
         for (j = 0; ret == 0 && j < gnutls_pkcs12_bag_get_count(bag); ++j) {
-            gnutls_pkcs12_bag_type type;
-            gnutls_datum data;
+            gnutls_pkcs12_bag_type_t type;
+            gnutls_datum_t data;
 
             if (friendly_name && *friendly_name == NULL) {
                 char *name = NULL;
@@ -1113,12 +1110,12 @@ static int pkcs12_parse(gnutls_pkcs12 p1
 ne_ssl_client_cert *ne_ssl_clicert_read(const char *filename)
 {
     int ret;
-    gnutls_datum data;
-    gnutls_pkcs12 p12;
+    gnutls_datum_t data;
+    gnutls_pkcs12_t p12;
     ne_ssl_client_cert *cc;
     char *friendly_name = NULL;
-    gnutls_x509_crt cert = NULL;
-    gnutls_x509_privkey pkey = NULL;
+    gnutls_x509_crt_t cert = NULL;
+    gnutls_x509_privkey_t pkey = NULL;
 
     if (read_to_datum(filename, &data))
         return NULL;
@@ -1162,8 +1159,8 @@ ne_ssl_client_cert *ne__ssl_clicert_exke
                                                  size_t der_len)
 {
     ne_ssl_client_cert *cc;
-    gnutls_x509_crt x5;
-    gnutls_datum datum;
+    gnutls_x509_crt_t x5;
+    gnutls_datum_t datum;
 
     datum.data = (unsigned char *)der;
     datum.size = der_len;    
@@ -1190,8 +1187,8 @@ int ne_ssl_clicert_encrypted(const ne_ss
 int ne_ssl_clicert_decrypt(ne_ssl_client_cert *cc, const char *password)
 {
     int ret;
-    gnutls_x509_crt cert = NULL;
-    gnutls_x509_privkey pkey = NULL;
+    gnutls_x509_crt_t cert = NULL;
+    gnutls_x509_privkey_t pkey = NULL;
 
     if (gnutls_pkcs12_verify_mac(cc->p12, password) != 0) {
         return -1;
@@ -1228,8 +1225,8 @@ const char *ne_ssl_clicert_name(const ne
 ne_ssl_certificate *ne_ssl_cert_read(const char *filename)
 {
     int ret;
-    gnutls_datum data;
-    gnutls_x509_crt x5;
+    gnutls_datum_t data;
+    gnutls_x509_crt_t x5;
 
     if (read_to_datum(filename, &data))
         return NULL;
@@ -1300,8 +1297,8 @@ ne_ssl_certificate *ne_ssl_cert_import(c
     int ret;
     size_t len;
     unsigned char *der;
-    gnutls_datum buffer = { NULL, 0 };
-    gnutls_x509_crt x5;
+    gnutls_datum_t buffer = { NULL, 0 };
+    gnutls_x509_crt_t x5;
 
     if (gnutls_x509_crt_init(&x5) != 0)
         return NULL;
@@ -1369,10 +1366,6 @@ int ne_ssl_cert_digest(const ne_ssl_cert
 
 int ne__ssl_init(void)
 {
-#ifdef NE_HAVE_TS_SSL
-    gcry_control(GCRYCTL_SET_THREAD_CBS, &gcry_threads_pthread);
-#endif
-    gcry_control(GCRYCTL_ENABLE_QUICK_RANDOM, 0);
     return gnutls_global_init();
 }
 
