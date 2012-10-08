# $NetBSD: Makefile,v 1.15 2012/10/08 12:42:24 asau Exp $

DISTNAME=	X.V11R3uwm
PKGNAME=	uwm-19881027
PKGREVISION=	2
CATEGORIES=	x11 wm
MASTER_SITES=	${MASTER_SITE_LOCAL}

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://www.x.org/
COMMENT=	X11R3 window manager

WRKSRC=		${WRKDIR}/X.V11R3/clients/uwm
USE_IMAKE=	yes
USE_TOOLS+=	lex yacc

post-patch:
	if [ ! -f ${WRKSRC}/uwm.man.src ]; then			\
		${MV} ${WRKSRC}/uwm.man ${WRKSRC}/uwm.man.src;	\
	fi
	${SED} -e 's#/usr/lib/X11#${PREFIX}/lib/X11#g' <${WRKSRC}/uwm.man.src \
		>${WRKSRC}/uwm.man

INSTALLATION_DIRS=	lib/X11/uwm

post-install:
	${INSTALL_DATA} ${WRKSRC}/default.uwmrc ${DESTDIR}${PREFIX}/lib/X11/uwm/system.uwmrc

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
