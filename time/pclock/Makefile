# $NetBSD: Makefile,v 1.12 2006/12/15 20:33:01 joerg Exp $
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

.include "../../x11/libXpm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
