# $NetBSD: Makefile,v 1.3 2002/12/20 06:41:17 salo Exp $
#

DISTNAME=	pclock-0.13.1
CATEGORIES=	time x11
MASTER_SITES=	http://bnt.kourakos.com/~awk/programs/ \
		ftp://ftp.kourakos.com/pub/pclock/
EXTRACT_SUFX=	.tgz

MAINTAINER=	salo@netbsd.org
HOMEPAGE=	http://bnt.kourakos.com/~awk/programs/pclock/
COMMENT=	Simple analog clock designed for WindowMaker

USE_BUILDLINK2=		YES
USE_X11BASE=		YES

MAKE_ENV+=	LN=${LN}

post-install:
		${INSTALL_DATA_DIR} ${PREFIX}/share/pclock
		${INSTALL_DATA} ${WRKSRC}/XPM/* ${PREFIX}/share/pclock/
		${INSTALL_DATA_DIR} ${PREFIX}/share/doc/pclock
		${INSTALL_DATA} ${WRKSRC}/CHANGES ${PREFIX}/share/doc/pclock
		${INSTALL_DATA} ${WRKSRC}/CREDITS ${PREFIX}/share/doc/pclock
		${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/pclock

.include "../../graphics/xpm/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
