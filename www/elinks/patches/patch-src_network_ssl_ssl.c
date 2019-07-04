$NetBSD: patch-src_network_ssl_ssl.c,v 1.1 2019/07/04 12:15:04 nia Exp $

Build on newer OpenSSL without RAND_egd.

Derived from upstream:

https://repo.or.cz/elinks.git/blobdiff/6eba447e8ae12cacac3b479c7148d189bea3e8ea..f4a58ba3b574a478fd5954ba2c5b29e8b809ff9b:/src/network/ssl/ssl.c

--- src/network/ssl/ssl.c.orig	2012-10-28 12:57:15.000000000 +0000
+++ src/network/ssl/ssl.c
@@ -50,11 +50,16 @@ init_openssl(struct module *module)
 	 * cannot initialize the PRNG and so every attempt to use SSL fails.
 	 * It's actually an OpenSSL FAQ, and according to them, it's up to the
 	 * application coders to seed the RNG. -- William Yodlowsky */
-	if (RAND_egd(RAND_file_name(f_randfile, sizeof(f_randfile))) < 0) {
+	RAND_file_name(f_randfile, sizeof(f_randfile));
+#ifndef OPENSSL_NO_EGD
+	if (RAND_egd(f_randfile) < 0) {
+#endif
 		/* Not an EGD, so read and write to it */
 		if (RAND_load_file(f_randfile, -1))
 			RAND_write_file(f_randfile);
+#ifndef OPENSSL_NO_EGD
 	}
+#endif
 
 	SSLeay_add_ssl_algorithms();
 	context = SSL_CTX_new(SSLv23_client_method());
