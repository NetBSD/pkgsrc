$NetBSD: patch-lib_neon_ne__auth.c,v 1.1 2020/04/25 13:47:31 nia Exp $

Fix build with newer gnutls.

--- lib/neon/ne_auth.c.orig	2009-12-02 21:27:34.000000000 +0000
+++ lib/neon/ne_auth.c
@@ -46,7 +46,7 @@
 #ifdef HAVE_OPENSSL
 #include <openssl/rand.h>
 #elif defined(HAVE_GNUTLS)
-#include <gcrypt.h>
+#include <gnutls/crypto.h>
 #endif
 
 #include <errno.h>
@@ -316,7 +316,7 @@ static char *get_cnonce(void) 
 
 #ifdef HAVE_GNUTLS
     if (1) {
-        gcry_create_nonce(data, sizeof data);
+        gnutls_rnd(GNUTLS_RND_NONCE, data, sizeof data);
         ne_md5_process_bytes(data, sizeof data, hash);
     }
     else
