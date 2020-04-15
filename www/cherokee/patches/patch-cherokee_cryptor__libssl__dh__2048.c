$NetBSD: patch-cherokee_cryptor__libssl__dh__2048.c,v 1.1 2020/04/15 22:38:19 joerg Exp $

Use OpenSSL 1.1 interface.

--- cherokee/cryptor_libssl_dh_2048.c.orig	2020-04-13 20:11:21.574212142 +0000
+++ cherokee/cryptor_libssl_dh_2048.c
@@ -34,9 +34,10 @@ static DH *get_dh2048()
 	DH *dh;
 
 	if ((dh=DH_new()) == NULL) return(NULL);
-	dh->p=BN_bin2bn(dh2048_p,sizeof(dh2048_p),NULL);
-	dh->g=BN_bin2bn(dh2048_g,sizeof(dh2048_g),NULL);
-	if ((dh->p == NULL) || (dh->g == NULL))
+	BIGNUM *p = BN_bin2bn(dh2048_p,sizeof(dh2048_p),NULL);
+	BIGNUM *g = BN_bin2bn(dh2048_g,sizeof(dh2048_g),NULL);
+	DH_set0_pqg(dh, p, NULL, g);
+	if (p == NULL || g == NULL)
 		{ DH_free(dh); return(NULL); }
 	return(dh);
 	}
