# $NetBSD: Makefile,v 1.1.1.1 1999/10/01 15:10:23 fredb Exp $

DISTNAME=	wmx-5
PKGNAME=	wmx-5.0
CATEGORIES=	x11
MASTER_SITES=	http://www.all-day-breakfast.com/wmx/

MAINTAINER=	kuebart@mathematik.uni-ulm.de
HOMEPAGE=	http://www.all-day-breakfast.com/wmx/

DEPENDS=	xpm-3.4k:../../graphics/xpm

USE_X11BASE=	yes

do-configure:
	cd ${WRKSRC}; \
	  ${MV} Config.h Config.h.dist; \
	  ${SED} '/SYSTEM_COMMAND_MENU/s|/usr/local/lib/wmx/menu|${PREFIX}/etc/wmx|' \
	    < Config.h.dist > Config.h; \
	  ${MAKE} depend

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wmx ${PREFIX}/bin
	${MKDIR} ${PREFIX}/share/doc/wmx
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/wmx
	${INSTALL_DATA} ${WRKSRC}/README.contrib ${PREFIX}/share/doc/wmx
	${MKDIR} ${PREFIX}/etc/wmx

.include "../../mk/bsd.pkg.mk"
