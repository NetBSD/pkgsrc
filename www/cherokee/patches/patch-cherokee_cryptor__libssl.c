$NetBSD: patch-cherokee_cryptor__libssl.c,v 1.1 2020/04/15 22:38:19 joerg Exp $

Use OpenSSL 1.1 interface. Drop renegotation option, it doesn't exist in
TLS 1.1 and newer.

--- cherokee/cryptor_libssl.c.orig	2020-04-13 20:05:38.835019312 +0000
+++ cherokee/cryptor_libssl.c
@@ -238,13 +238,13 @@ cherokee_cryptor_libssl_find_vserver (SS
 	/* SSL_set_SSL_CTX() only change certificates. We need to
 	 * changes more options by hand.
 	 */
-	SSL_set_options(ssl, SSL_CTX_get_options(ssl->ctx));
+	SSL_set_options(ssl, SSL_CTX_get_options(SSL_get_SSL_CTX(ssl)));
 
 	if ((SSL_get_verify_mode(ssl) == SSL_VERIFY_NONE) ||
 	    (SSL_num_renegotiations(ssl) == 0)) {
 
-		SSL_set_verify(ssl, SSL_CTX_get_verify_mode(ssl->ctx),
-		               SSL_CTX_get_verify_callback(ssl->ctx));
+		SSL_set_verify(ssl, SSL_CTX_get_verify_mode(SSL_get_SSL_CTX(ssl)),
+		               SSL_CTX_get_verify_callback(SSL_get_SSL_CTX(ssl)));
 	}
 
 	return ret_ok;
@@ -672,12 +672,6 @@ _socket_init_tls (cherokee_cryptor_socke
 	}
 #endif
 
-	/* Disable Ciphers renegotiation (CVE-2009-3555)
-	 */
-	if (cryp->session->s3) {
-		cryp->session->s3->flags |= SSL3_FLAGS_NO_RENEGOTIATE_CIPHERS;
-	}
-
 	return ret_ok;
 }
 
