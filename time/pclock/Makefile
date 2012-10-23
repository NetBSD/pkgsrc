# $NetBSD: Makefile,v 1.16 2012/10/23 10:24:11 wiz Exp $
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

INSTALLATION_DIRS=	bin share/pclock share/doc/pclock

post-install:
		${INSTALL_DATA} ${WRKSRC}/XPM/* ${DESTDIR}${PREFIX}/share/pclock/
		${INSTALL_DATA} ${WRKSRC}/CREDITS ${DESTDIR}${PREFIX}/share/doc/pclock
		${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/pclock

.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
