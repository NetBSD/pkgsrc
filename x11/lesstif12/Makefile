# $NetBSD: Makefile,v 1.2 2000/10/23 19:45:26 jlam Exp $

PKGNAME=		lesstif12-${LESSTIF_VERSION}

CONFLICTS+=		lesstif-0.[0-8]*
CONFLICTS+=		lesstif-0.90*
CONFLICTS+=		lesstif-0.91 lesstif-0.91.[0-3]

CONFIGURE_ARGS+=	--enable-build-12
CONFIGURE_ARGS+=	--disable-build-20
CONFIGURE_ARGS+=	--enable-default-12

post-install:
	${RMDIR} -p ${PREFIX}/share/doc/html/lesstif 2> /dev/null || ${TRUE}
	${RMDIR} -p ${PREFIX}/share/doc/lesstif 2> /dev/null || ${TRUE}

.include "../../x11/lesstif/Makefile.common"
