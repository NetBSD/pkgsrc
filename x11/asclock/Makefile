# $NetBSD: Makefile,v 1.1.1.1 1997/11/09 23:43:49 hubertf Exp $

DISTNAME=	asclock7
PKGNAME=	asclock-7
WRKSRC=		${WRKDIR}/asclock
CATEGORIES=	x11

MASTER_SITES=	http://apollo.gmi.edu/~kram1968/afterstep/
# asclock7.tgz
EXTRACT_SUFX=	.tgz

LIB_DEPENDS=	Xpm\\.4:${PORTSDIR}/graphics/xpm

MAINTAINER=	hubertf@netbsd.org

# Choose language from:
# 1) english [DEFAULT]
# 2) german
# 3) portuguese
# 4) dutch
# 5) norwegian
LANG=1

# Choose paneltype from:
# 1) 8bit AfterStep-colors (47 colors) [DEFAULT]
# 2) 8bit NeXTStep -colors (76 colors)
# 3) 2bit greyscale        ( 4 colors)
PANEL=1

USE_X11=	yes
INSTALL_TARGET=	install install.man
do-configure:
		cd ${WRKSRC} ; ( echo ${LANG} ; echo ${PANEL} ) | ./configure

.include <bsd.port.mk>
