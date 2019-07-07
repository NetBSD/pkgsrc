$NetBSD: patch-digcalc.c,v 1.1 2019/07/07 18:13:23 nia Exp $

Support OpenSSL 1.1.

--- digcalc.c.orig	2009-09-17 06:44:27.000000000 +0000
+++ digcalc.c
@@ -27,30 +27,32 @@ void DigestCalcHA1(
     OUT HASHHEX SessionKey
     )
 {
-	EVP_MD_CTX mdctx;
+	EVP_MD_CTX *mdctx;
 	unsigned char md_value[EVP_MAX_MD_SIZE];
 	unsigned int md_len;
 	int i;
 	HASH HA1;
 	
-	EVP_DigestInit(&mdctx, EVP_md5());
-	EVP_DigestUpdate(&mdctx, pszUserName, strlen(pszUserName));
-	EVP_DigestUpdate(&mdctx, ":", 1);
-	EVP_DigestUpdate(&mdctx, pszRealm, strlen(pszRealm));
-	EVP_DigestUpdate(&mdctx, ":", 1);
-	EVP_DigestUpdate(&mdctx, pszPassword, strlen(pszPassword));
-	EVP_DigestFinal_ex(&mdctx, md_value, &md_len);
-	EVP_MD_CTX_cleanup(&mdctx);
+	mdctx = EVP_MD_CTX_new();
+	EVP_DigestInit(mdctx, EVP_md5());
+	EVP_DigestUpdate(mdctx, pszUserName, strlen(pszUserName));
+	EVP_DigestUpdate(mdctx, ":", 1);
+	EVP_DigestUpdate(mdctx, pszRealm, strlen(pszRealm));
+	EVP_DigestUpdate(mdctx, ":", 1);
+	EVP_DigestUpdate(mdctx, pszPassword, strlen(pszPassword));
+	EVP_DigestFinal_ex(mdctx, md_value, &md_len);
+	EVP_MD_CTX_free(mdctx);
 	
 	if (strcmp(pszAlg, "md5-sess") == 0) {
-		EVP_DigestInit(&mdctx, EVP_md5());
-		EVP_DigestUpdate(&mdctx, HA1, HASHLEN);
-		EVP_DigestUpdate(&mdctx, ":", 1);
-		EVP_DigestUpdate(&mdctx, pszNonce, strlen(pszNonce));
-		EVP_DigestUpdate(&mdctx, ":", 1);
-		EVP_DigestUpdate(&mdctx, pszCNonce, strlen(pszCNonce));
-		EVP_DigestFinal_ex(&mdctx, md_value, &md_len);
-		EVP_MD_CTX_cleanup(&mdctx);
+		mdctx = EVP_MD_CTX_new();
+		EVP_DigestInit(mdctx, EVP_md5());
+		EVP_DigestUpdate(mdctx, HA1, HASHLEN);
+		EVP_DigestUpdate(mdctx, ":", 1);
+		EVP_DigestUpdate(mdctx, pszNonce, strlen(pszNonce));
+		EVP_DigestUpdate(mdctx, ":", 1);
+		EVP_DigestUpdate(mdctx, pszCNonce, strlen(pszCNonce));
+		EVP_DigestFinal_ex(mdctx, md_value, &md_len);
+		EVP_MD_CTX_free(mdctx);
 	};
 	
 	for (i = 0; i < md_len; i++) {
@@ -71,45 +73,47 @@ void DigestCalcResponse(
     OUT HASHHEX Response      /* request-digest or response-digest */
     )
 {
-	EVP_MD_CTX mdctx;
+	EVP_MD_CTX *mdctx;
 	HASHHEX HA2Hex;
 	unsigned char md_value[EVP_MAX_MD_SIZE];
 	unsigned int md_len;
 	int i;
 	
 	/* calculate H(A2) */
-	EVP_DigestInit(&mdctx, EVP_md5());
-	EVP_DigestUpdate(&mdctx, pszMethod, strlen(pszMethod));
-	EVP_DigestUpdate(&mdctx, ":", 1);
-	EVP_DigestUpdate(&mdctx, pszDigestUri, strlen(pszDigestUri));
+	mdctx = EVP_MD_CTX_new();
+	EVP_DigestInit(mdctx, EVP_md5());
+	EVP_DigestUpdate(mdctx, pszMethod, strlen(pszMethod));
+	EVP_DigestUpdate(mdctx, ":", 1);
+	EVP_DigestUpdate(mdctx, pszDigestUri, strlen(pszDigestUri));
 	if (strcmp(pszQop, "auth-int") == 0) {
-		EVP_DigestUpdate(&mdctx, ":", 1);
-		EVP_DigestUpdate(&mdctx, HEntity, HASHHEXLEN);
+		EVP_DigestUpdate(mdctx, ":", 1);
+		EVP_DigestUpdate(mdctx, HEntity, HASHHEXLEN);
 	};
-	EVP_DigestFinal_ex(&mdctx, md_value, &md_len);
-	EVP_MD_CTX_cleanup(&mdctx);
+	EVP_DigestFinal_ex(mdctx, md_value, &md_len);
+	EVP_MD_CTX_free(mdctx);
 	
 	for (i = 0; i < md_len; i++) {
 		sprintf(&HA2Hex[2*i], "%02x", md_value[i]);
 	}
 	
 	/* calculate response */
-	EVP_DigestInit(&mdctx, EVP_md5());
-	EVP_DigestUpdate(&mdctx, HA1, HASHHEXLEN);
-	EVP_DigestUpdate(&mdctx, ":", 1);
-	EVP_DigestUpdate(&mdctx, pszNonce, strlen(pszNonce));
-	EVP_DigestUpdate(&mdctx, ":", 1);
+	mdctx = EVP_MD_CTX_new();
+	EVP_DigestInit(mdctx, EVP_md5());
+	EVP_DigestUpdate(mdctx, HA1, HASHHEXLEN);
+	EVP_DigestUpdate(mdctx, ":", 1);
+	EVP_DigestUpdate(mdctx, pszNonce, strlen(pszNonce));
+	EVP_DigestUpdate(mdctx, ":", 1);
 	if (*pszQop) {
-		EVP_DigestUpdate(&mdctx, pszNonceCount, strlen(pszNonceCount));
-		EVP_DigestUpdate(&mdctx, ":", 1);
-		EVP_DigestUpdate(&mdctx, pszCNonce, strlen(pszCNonce));
-		EVP_DigestUpdate(&mdctx, ":", 1);
-		EVP_DigestUpdate(&mdctx, pszQop, strlen(pszQop));
-		EVP_DigestUpdate(&mdctx, ":", 1);
+		EVP_DigestUpdate(mdctx, pszNonceCount, strlen(pszNonceCount));
+		EVP_DigestUpdate(mdctx, ":", 1);
+		EVP_DigestUpdate(mdctx, pszCNonce, strlen(pszCNonce));
+		EVP_DigestUpdate(mdctx, ":", 1);
+		EVP_DigestUpdate(mdctx, pszQop, strlen(pszQop));
+		EVP_DigestUpdate(mdctx, ":", 1);
 	};
-	EVP_DigestUpdate(&mdctx, HA2Hex, HASHHEXLEN);
-	EVP_DigestFinal_ex(&mdctx, md_value, &md_len);
-	EVP_MD_CTX_cleanup(&mdctx);
+	EVP_DigestUpdate(mdctx, HA2Hex, HASHHEXLEN);
+	EVP_DigestFinal_ex(mdctx, md_value, &md_len);
+	EVP_MD_CTX_free(mdctx);
 	
 	for (i = 0; i < md_len; i++) {
 		sprintf(&Response[2*i], "%02x", md_value[i]);
