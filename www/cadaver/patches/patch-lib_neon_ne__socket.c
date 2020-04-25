$NetBSD: patch-lib_neon_ne__socket.c,v 1.1 2020/04/25 13:47:31 nia Exp $

Fix build with newer gnutls.

--- lib/neon/ne_socket.c.orig	2009-12-02 21:27:34.000000000 +0000
+++ lib/neon/ne_socket.c
@@ -1608,14 +1608,14 @@ void ne_sock_connect_timeout(ne_socket *
  * session. */
 
 /* Copy datum 'src' to 'dest'. */
-static void copy_datum(gnutls_datum *dest, gnutls_datum *src)
+static void copy_datum(gnutls_datum_t *dest, gnutls_datum_t *src)
 {
     dest->size = src->size;
     dest->data = memcpy(gnutls_malloc(src->size), src->data, src->size);
 }
 
 /* Callback to store a session 'data' with id 'key'. */
-static int store_sess(void *userdata, gnutls_datum key, gnutls_datum data)
+static int store_sess(void *userdata, gnutls_datum_t key, gnutls_datum_t data)
 {
     ne_ssl_context *ctx = userdata;
 
@@ -1631,17 +1631,17 @@ static int store_sess(void *userdata, gn
 }
 
 /* Returns non-zero if d1 and d2 are the same datum. */
-static int match_datum(gnutls_datum *d1, gnutls_datum *d2)
+static int match_datum(gnutls_datum_t *d1, gnutls_datum_t *d2)
 {
     return d1->size == d2->size
         && memcmp(d1->data, d2->data, d1->size) == 0;
 }
 
 /* Callback to retrieve a session of id 'key'. */
-static gnutls_datum retrieve_sess(void *userdata, gnutls_datum key)
+static gnutls_datum_t retrieve_sess(void *userdata, gnutls_datum_t key)
 {
     ne_ssl_context *ctx = userdata;
-    gnutls_datum ret = { NULL, 0 };
+    gnutls_datum_t ret = { NULL, 0 };
 
     if (match_datum(&ctx->cache.server.key, &key)) {
         copy_datum(&ret, &ctx->cache.server.data);
@@ -1652,7 +1652,7 @@ static gnutls_datum retrieve_sess(void *
 
 /* Callback to remove a session of id 'key'; stub needed but
  * implementation seems unnecessary. */
-static int remove_sess(void *userdata, gnutls_datum key)
+static int remove_sess(void *userdata, gnutls_datum_t key)
 {
     return -1;
 }
@@ -1678,6 +1678,8 @@ int ne_sock_accept_ssl(ne_socket *sock, 
         NE_DEBUG(NE_DBG_SSL, "ssl: Server reused session.\n");
     }
 #elif defined(HAVE_GNUTLS)
+    unsigned int verify_status;
+
     gnutls_init(&ssl, GNUTLS_SERVER);
     gnutls_credentials_set(ssl, GNUTLS_CRD_CERTIFICATE, ctx->cred);
     gnutls_set_default_priority(ssl);
@@ -1689,15 +1691,15 @@ int ne_sock_accept_ssl(ne_socket *sock, 
     gnutls_db_set_ptr(ssl, ctx);
 
     if (ctx->verify)
-        gnutls_certificate_server_set_request(ssl, GNUTLS_CERT_REQUEST);
+        gnutls_certificate_server_set_request(ssl, GNUTLS_CERT_REQUIRE);
 
     sock->ssl = ssl;
-    gnutls_transport_set_ptr(sock->ssl, (gnutls_transport_ptr)(long)sock->fd);
+    gnutls_transport_set_ptr(sock->ssl, (gnutls_transport_ptr_t)(long)sock->fd);
     ret = gnutls_handshake(ssl);
     if (ret < 0) {
         return error_gnutls(sock, ret);
     }
-    if (ctx->verify && gnutls_certificate_verify_peers(ssl)) {
+    if (ctx->verify && (gnutls_certificate_verify_peers2(ssl, &verify_status) || verify_status)) {
         set_error(sock, _("Client certificate verification failed"));
         return NE_SOCK_ERROR;
     }
@@ -1774,7 +1776,7 @@ int ne_sock_connect_ssl(ne_socket *sock,
                                strlen(ctx->hostname));
     }                               
 
-    gnutls_transport_set_ptr(sock->ssl, (gnutls_transport_ptr)(long)sock->fd);
+    gnutls_transport_set_ptr(sock->ssl, (gnutls_transport_ptr_t)(long)sock->fd);
 
     if (ctx->cache.client.data) {
 #if defined(HAVE_GNUTLS_SESSION_GET_DATA2)
