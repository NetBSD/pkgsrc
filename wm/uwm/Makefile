# $NetBSD: Makefile,v 1.1.1.1 2000/12/12 02:03:49 wiz Exp $

DISTNAME=	X.V11R3uwm
PKGNAME=	uwm-19881027
CATEGORIES=	x11 wm
MASTER_SITES=	${MASTER_SITE_LOCAL}

MAINTAINER=	packages@netbsd.org
#HOMEPAGE=	http://www.x.org/

WRKSRC=		${WRKDIR}/X.V11R3/clients/uwm
USE_IMAKE=	yes

post-patch:
	if [ ! -f ${WRKSRC}/uwm.man.src ]; then			\
		${MV} ${WRKSRC}/uwm.man ${WRKSRC}/uwm.man.src;	\
	fi
	${SED} -e 's#/usr/lib/X11#${PREFIX}/lib/X11#g' <${WRKSRC}/uwm.man.src \
		>${WRKSRC}/uwm.man

post-install:
	${MKDIR} ${PREFIX}/lib/X11/uwm
	${INSTALL_DATA} ${WRKSRC}/default.uwmrc ${PREFIX}/lib/X11/uwm/system.uwmrc

.include "../../mk/bsd.pkg.mk"
