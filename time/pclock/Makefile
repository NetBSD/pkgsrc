# $NetBSD: Makefile,v 1.11 2006/02/05 23:11:10 joerg Exp $
#

DISTNAME=	pclock_0.13.1.orig
PKGNAME=	${DISTNAME:S/_/-/:S/.orig//}
PKGREVISION=	2
CATEGORIES=	time x11
MASTER_SITES=	${MASTER_SITE_DEBIAN:=pool/main/p/pclock/}

MAINTAINER=	salo@NetBSD.org
COMMENT=	Simple analog clock designed for Window Maker

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}.orig

MAKE_ENV+=	LN=${LN:Q}

post-install:
		${INSTALL_DATA_DIR} ${PREFIX}/share/pclock
		${INSTALL_DATA} ${WRKSRC}/XPM/* ${PREFIX}/share/pclock/
		${INSTALL_DATA_DIR} ${PREFIX}/share/doc/pclock
		${INSTALL_DATA} ${WRKSRC}/CREDITS ${PREFIX}/share/doc/pclock
		${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/pclock

.include "../../graphics/xpm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
