# $NetBSD: Makefile,v 1.1.1.1 2002/10/04 16:10:15 hubertf Exp $
#

DISTNAME=	pclock-0.13.1
CATEGORIES=	time x11
MASTER_SITES=	http://bnt.kourakos.com/~awk/programs/
EXTRACT_SUFX=	.tgz

MAINTAINER=	salo@Xtrmntr.org
HOMEPAGE=	http://www.kourakos.com/~awk/programs/pclock/
COMMENT=	Simple analog clock designed for WindowMaker

USE_X11BASE=		YES
USE_BUILDLINK_ONLY=	YES

MAKE_ENV+=	LN=${LN}

post-install:
		${INSTALL_DATA_DIR} ${PREFIX}/share/pclock
		${INSTALL_DATA} ${WRKSRC}/XPM/* ${PREFIX}/share/pclock/
		${INSTALL_DATA_DIR} ${PREFIX}/share/doc/pclock
		${INSTALL_DATA} ${WRKSRC}/CHANGES ${PREFIX}/share/doc/pclock
		${INSTALL_DATA} ${WRKSRC}/CREDITS ${PREFIX}/share/doc/pclock
		${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/pclock

.include "../../graphics/xpm/buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
