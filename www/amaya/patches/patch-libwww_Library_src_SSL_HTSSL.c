$NetBSD: patch-libwww_Library_src_SSL_HTSSL.c,v 1.1 2016/04/03 12:44:13 joerg Exp $

--- libwww/Library/src/SSL/HTSSL.c.orig	2016-04-02 21:54:25.281411017 +0000
+++ libwww/Library/src/SSL/HTSSL.c
@@ -214,9 +214,6 @@ PUBLIC BOOL HTSSL_init (void)
 
 	/* select the protocol method */
 	switch (ssl_prot_method) {
-	case HTSSL_V2:
-	  meth = SSLv2_client_method();
-	  break;
 	case HTSSL_V3:
 	  meth = SSLv3_client_method();
 	  break;
