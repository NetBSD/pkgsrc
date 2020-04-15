$NetBSD: patch-cherokee_cryptor__libssl__dh__1024.c,v 1.1 2020/04/15 22:38:19 joerg Exp $

Use OpenSSL 1.1 interface.

--- cherokee/cryptor_libssl_dh_1024.c.orig	2020-04-13 20:11:32.162747627 +0000
+++ cherokee/cryptor_libssl_dh_1024.c
@@ -23,9 +23,10 @@ static DH *get_dh1024()
 	DH *dh;
 
 	if ((dh=DH_new()) == NULL) return(NULL);
-	dh->p=BN_bin2bn(dh1024_p,sizeof(dh1024_p),NULL);
-	dh->g=BN_bin2bn(dh1024_g,sizeof(dh1024_g),NULL);
-	if ((dh->p == NULL) || (dh->g == NULL))
+	BIGNUM *p = BN_bin2bn(dh1024_p,sizeof(dh1024_p),NULL);
+	BIGNUM *g = BN_bin2bn(dh1024_g,sizeof(dh1024_g),NULL);
+	DH_set0_pqg(dh, p, NULL, g);
+	if (p == NULL || g == NULL)
 		{ DH_free(dh); return(NULL); }
 	return(dh);
 	}
