# $NetBSD: Makefile,v 1.1.1.1 2000/12/12 02:03:49 wiz Exp $

DISTNAME=	wmx-5
PKGNAME=	wmx-5.0
CATEGORIES=	x11 wm
MASTER_SITES=	http://www.all-day-breakfast.com/wmx/

MAINTAINER=	kuebart@mathematik.uni-ulm.de
HOMEPAGE=	http://www.all-day-breakfast.com/wmx/

USE_X11BASE=	YES
USE_XPM=	YES
EVAL_PREFIX=	XPMDIR=xpm

MAKE_ENV+=	XPMDIR=${XPMDIR}

do-configure:
	cd ${WRKSRC}; \
	  ${MV} Config.h Config.h.dist; \
	  ${SED} '/SYSTEM_COMMAND_MENU/s|/usr/local/lib/wmx/menu|${PREFIX}/etc/wmx|' \
	    < Config.h.dist > Config.h; \
	  ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} ${MAKE_FLAGS} depend

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wmx ${PREFIX}/bin
	${MKDIR} ${PREFIX}/share/doc/wmx
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/wmx
	${INSTALL_DATA} ${WRKSRC}/README.contrib ${PREFIX}/share/doc/wmx
	${MKDIR} ${PREFIX}/etc/wmx

.include "../../mk/bsd.pkg.mk"
