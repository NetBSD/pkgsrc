# $NetBSD: Makefile,v 1.1.1.1 1999/12/23 03:10:58 itohy Exp $

DISTNAME=	X.V11R3
PKGNAME=	uwm-19881027
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.x.org/pub/R3/

MAINTAINER=	packages@netbsd.org
#HOMEPAGE=	http://www.x.org/

EXTRACT_ELEMENTS= X.V11R3/clients/uwm X.V11R3/X11
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
