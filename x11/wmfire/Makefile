# $NetBSD: Makefile,v 1.2 1999/10/05 01:27:18 hubertf Exp $
#

DISTNAME=	wmfire-0.0.3.8
CATEGORIES=	x11
MASTER_SITES=	http://www.zebra.net/~dm/wmfire/

MAINTAINER=	hubertf@netbsd.org

DEPENDS+=	xpm-3.4k:../../graphics/xpm

USE_X11=	YES
GNU_CONFIGURE=	YES
CONFIGURE_ENV+=	CPPFLAGS=-I${X11BASE}/include

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/wmfire
	${INSTALL_DATA} ${WRKSRC}/README  ${PREFIX}/share/doc/wmfire
	${INSTALL_DATA} ${WRKSRC}/AUTHORS ${PREFIX}/share/doc/wmfire
	${INSTALL_DATA} ${WRKSRC}/COPYING ${PREFIX}/share/doc/wmfire
	${INSTALL_DATA} ${WRKSRC}/CREDITS ${PREFIX}/share/doc/wmfire
	${INSTALL_DATA} ${WRKSRC}/INSTALL ${PREFIX}/share/doc/wmfire

.include "../../mk/bsd.pkg.mk"
