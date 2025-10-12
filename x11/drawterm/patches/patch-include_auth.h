$NetBSD: patch-include_auth.h,v 1.1 2025/10/12 13:42:33 vins Exp $

Prevent redefinition of MAXNAMELEN on SunOS.

--- include/auth.h.orig	2024-07-03 15:30:56.000000000 +0000
+++ include/auth.h
@@ -17,7 +17,7 @@ typedef struct	AuthRpc		AuthRpc;
 enum
 {
 	MAXCHLEN=	256,		/* max challenge length	*/
-	MAXNAMELEN=	256,		/* maximum name length */
+	MAXNMLEN=	256,		/* maximum name length */
 	MD5LEN=		16,
 
 	ARok = 0,			/* rpc return values */
@@ -63,7 +63,7 @@ struct Chalstate
 /* for implementation only */
 	int	afd;			/* to factotum */
 	AuthRpc	*rpc;			/* to factotum */
-	char	userbuf[MAXNAMELEN];	/* temp space if needed */
+	char	userbuf[MAXNMLEN];	/* temp space if needed */
 	int	userinchal;		/* user was sent to obtain challenge */
 };
 
