$NetBSD: patch-WWW_Library_Implementation_HTTP.c,v 1.1 2016/12/21 11:25:25 sevan Exp $

Mitigate POODLE vulnerability
https://hg.java.net/hg/solaris-userland~gate/file/bc5351dcb9ac/components/lynx/patches/02-init-openssl.patch
Fix CVE-2016-9179
https://hg.java.net/hg/solaris-userland~gate/file/0a979060f73b/components/lynx/patches/05-fix-CVE-2016-9179.patch

--- WWW/Library/Implementation/HTTP.c.orig	2014-01-11 19:06:15.000000000 +0000
+++ WWW/Library/Implementation/HTTP.c
@@ -105,6 +105,8 @@ static int HTSSLCallback(int preverify_o
 
 SSL *HTGetSSLHandle(void)
 {
+    char *ciphers;
+
 #ifdef USE_GNUTLS_INCL
     static char *certfile = NULL;
 #endif
@@ -119,7 +121,12 @@ SSL *HTGetSSLHandle(void)
 #else
 	SSLeay_add_ssl_algorithms();
 	ssl_ctx = SSL_CTX_new(SSLv23_client_method());
-	SSL_CTX_set_options(ssl_ctx, SSL_OP_ALL | SSL_OP_NO_SSLv2);
+	/* Always disable SSLv2 & SSLv3 to "mitigate POODLE vulnerability". */
+	SSL_CTX_set_options(ssl_ctx, SSL_OP_ALL | SSL_OP_NO_SSLv2 | SSL_OP_NO_SSLv3);
+
+	ciphers = (char *)DEFAULT_CIPHER_SELECTION;
+	SSL_CTX_set_cipher_list(ssl_ctx, ciphers);
+
 #ifdef SSL_OP_NO_COMPRESSION
 	SSL_CTX_set_options(ssl_ctx, SSL_OP_NO_COMPRESSION);
 #endif
@@ -419,7 +426,7 @@ int ws_netread(int fd, char *buf, int le
 /*
  * Strip any username from the given string so we retain only the host.
  */
-static void strip_userid(char *host)
+void strip_userid(char *host, int parse_only)
 {
     char *p1 = host;
     char *p2 = StrChr(host, '@');
@@ -432,7 +439,8 @@ static void strip_userid(char *host)
 
 	    CTRACE((tfp, "parsed:%s\n", fake));
 	    HTSprintf0(&msg, gettext("Address contains a username: %s"), host);
-	    HTAlert(msg);
+	    if (msg !=0 && !parse_only)
+		HTAlert(msg);
 	    FREE(msg);
 	}
 	while ((*p1++ = *p2++) != '\0') {
@@ -1074,7 +1082,7 @@ static int HTLoadHTTP(const char *arg,
 	char *host = NULL;
 
 	if ((host = HTParse(anAnchor->address, "", PARSE_HOST)) != NULL) {
-	    strip_userid(host);
+	    strip_userid(host, TRUE);
 	    HTBprintf(&command, "Host: %s%c%c", host, CR, LF);
 	    FREE(host);
 	}
