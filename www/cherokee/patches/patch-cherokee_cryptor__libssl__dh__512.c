$NetBSD: patch-cherokee_cryptor__libssl__dh__512.c,v 1.1 2020/04/15 22:38:19 joerg Exp $

Use OpenSSL 1.1 interface.

--- cherokee/cryptor_libssl_dh_512.c.orig	2020-04-13 20:12:04.828129889 +0000
+++ cherokee/cryptor_libssl_dh_512.c
@@ -18,9 +18,10 @@ static DH *get_dh512()
 	DH *dh;
 
 	if ((dh=DH_new()) == NULL) return(NULL);
-	dh->p=BN_bin2bn(dh512_p,sizeof(dh512_p),NULL);
-	dh->g=BN_bin2bn(dh512_g,sizeof(dh512_g),NULL);
-	if ((dh->p == NULL) || (dh->g == NULL))
+	BIGNUM *p = BN_bin2bn(dh512_p,sizeof(dh512_p),NULL);
+	BIGNUM *g = BN_bin2bn(dh512_g,sizeof(dh512_g),NULL);
+	DH_set0_pqg(dh, p, NULL, g);
+	if (p == NULL || g == NULL)
 		{ DH_free(dh); return(NULL); }
 	return(dh);
 	}
