# $NetBSD: Makefile,v 1.10.2.2 2002/06/21 23:05:53 jlam Exp $

PKGNAME=	lesstif12-${LESSTIF_VERSION}
COMMENT=	API compatible clone of the OSF/Motif toolkit, version 1.2

CONFLICTS+=	lesstif-0.[0-8]*
CONFLICTS+=	lesstif-0.90*
CONFLICTS+=	lesstif-0.91 lesstif-0.91.[0-3]

USE_BUILDLINK2=	# defined

.include "../lesstif/Makefile.common"

CONFIGURE_ARGS+=	--enable-build-12
CONFIGURE_ARGS+=	--disable-build-20
CONFIGURE_ARGS+=	--disable-build-21
CONFIGURE_ARGS+=	--enable-default-12

# We don't install any documentation, but the installation process creates
# this directory anyway, so remove it if it's empty.
#
post-install:
	${RMDIR} -p ${PREFIX}/share/doc/html/lesstif 2> /dev/null || ${TRUE}

.include "../../mk/bsd.pkg.mk"
