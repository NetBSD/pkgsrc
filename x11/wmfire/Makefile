#$NetBSD: Makefile,v 1.10 2001/10/24 22:11:15 jlam Exp $
#

DISTNAME=	wmfire-0.0.3.8
CATEGORIES=	x11
MASTER_SITES=	http://www.zebra.net/~dm/wmfire/

MAINTAINER=	hubertf@netbsd.org
COMMENT=	Displays generated fire according to system load

USE_BUILDLINK_ONLY=	YES
GNU_CONFIGURE=		YES

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/wmfire
	${INSTALL_DATA} ${WRKSRC}/README  ${PREFIX}/share/doc/wmfire
	${INSTALL_DATA} ${WRKSRC}/AUTHORS ${PREFIX}/share/doc/wmfire
	${INSTALL_DATA} ${WRKSRC}/COPYING ${PREFIX}/share/doc/wmfire
	${INSTALL_DATA} ${WRKSRC}/CREDITS ${PREFIX}/share/doc/wmfire
	${INSTALL_DATA} ${WRKSRC}/INSTALL ${PREFIX}/share/doc/wmfire

.include "../../graphics/xpm/buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
