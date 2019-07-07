$NetBSD: patch-conversions.c,v 1.1 2019/07/07 18:13:23 nia Exp $

Support OpenSSL 1.1.

--- conversions.c.orig	2009-09-17 06:44:27.000000000 +0000
+++ conversions.c
@@ -618,20 +618,21 @@ char * Hashify (const char * url) {
 
 char * genItemHash (char ** hashitems, int items) {
 	int i;
-	EVP_MD_CTX mdctx;
+	EVP_MD_CTX *mdctx;
 	unsigned char md_value[EVP_MAX_MD_SIZE];
 	unsigned int md_len;
 	char md5_hex[33];
-
-	EVP_DigestInit(&mdctx, EVP_md5());
+	
+	mdctx = EVP_MD_CTX_new();
+	EVP_DigestInit(mdctx, EVP_md5());
 	
 	for (i = 0; i < items; i++) {
 		if (hashitems[i] != NULL)
-			EVP_DigestUpdate(&mdctx, hashitems[i], (size_t) strlen(hashitems[i]));
+			EVP_DigestUpdate(mdctx, hashitems[i], (size_t) strlen(hashitems[i]));
 	}
 	
-	EVP_DigestFinal_ex(&mdctx, md_value, &md_len);
-	EVP_MD_CTX_cleanup(&mdctx);
+	EVP_DigestFinal_ex(mdctx, md_value, &md_len);
+	EVP_MD_CTX_free(mdctx);
 	
 	for (i = 0; i < md_len; i++) {
 		sprintf(&md5_hex[2*i], "%02x", md_value[i]);
