# $NetBSD: Makefile,v 1.8 2004/01/20 12:27:35 agc Exp $

DISTNAME=	X.V11R3uwm
PKGNAME=	uwm-19881027
PKGREVISION=	1
CATEGORIES=	x11 wm
MASTER_SITES=	${MASTER_SITE_LOCAL}

MAINTAINER=	tech-pkg@NetBSD.org
#HOMEPAGE=	http://www.x.org/
COMMENT=	X11R3 window manager

WRKSRC=		${WRKDIR}/X.V11R3/clients/uwm
USE_IMAKE=	yes

post-patch:
	if [ ! -f ${WRKSRC}/uwm.man.src ]; then			\
		${MV} ${WRKSRC}/uwm.man ${WRKSRC}/uwm.man.src;	\
	fi
	${SED} -e 's#/usr/lib/X11#${PREFIX}/lib/X11#g' <${WRKSRC}/uwm.man.src \
		>${WRKSRC}/uwm.man

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/lib/X11/uwm
	${INSTALL_DATA} ${WRKSRC}/default.uwmrc ${PREFIX}/lib/X11/uwm/system.uwmrc

.include "../../mk/bsd.pkg.mk"
