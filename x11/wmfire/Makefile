# $NetBSD: Makefile,v 1.5 2001/05/10 13:19:27 agc Exp $
#

DISTNAME=	wmfire-0.0.3.8
CATEGORIES=	x11
MASTER_SITES=	http://www.zebra.net/~dm/wmfire/

MAINTAINER=	hubertf@netbsd.org
COMMENT=	Displays generated fire according to system load

USE_X11=	YES
USE_XPM=	YES
GNU_CONFIGURE=	YES
CONFIGURE_ENV+=	CPPFLAGS=-I${X11BASE}/include
MAKE_ENV+=	XPMDIR=${XPMDIR}
EVAL_PREFIX=	XPMDIR=xpm

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/wmfire
	${INSTALL_DATA} ${WRKSRC}/README  ${PREFIX}/share/doc/wmfire
	${INSTALL_DATA} ${WRKSRC}/AUTHORS ${PREFIX}/share/doc/wmfire
	${INSTALL_DATA} ${WRKSRC}/COPYING ${PREFIX}/share/doc/wmfire
	${INSTALL_DATA} ${WRKSRC}/CREDITS ${PREFIX}/share/doc/wmfire
	${INSTALL_DATA} ${WRKSRC}/INSTALL ${PREFIX}/share/doc/wmfire

.include "../../mk/bsd.pkg.mk"
