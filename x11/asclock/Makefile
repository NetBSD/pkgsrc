# $NetBSD: Makefile,v 1.5 1998/04/15 10:38:52 agc Exp $
#

DISTNAME=		asclock
PKGNAME=		asclock-10
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	X11/clocks
EXTRACT_SUFX=		.tgz

MAINTAINER=		hubertf@netbsd.org

LIB_DEPENDS=		Xpm.4:${PORTSDIR}/graphics/xpm

# Choose language from:
# 1) english [DEFAULT]
# 2) german
# 3) portuguese
# 4) dutch
# 5) norwegian
# 6) italian
# 7) swedish
# 8) spanish
# 9) hungarian
# 0) breton
# a) french
# b) czech
LANG?=1

# Choose paneltype from:
# 1) 8bit AfterStep-colors (47 colors) [DEFAULT]
# 2) 8bit NeXTStep -colors (76 colors)
# 3) 2bit greyscale        ( 4 colors)
PANEL?=1

USE_X11=	yes
INSTALL_TARGET=	install install.man
do-configure:
		cd ${WRKSRC} ; ( ${ECHO} ${LANG} ; ${ECHO} ${PANEL} ) | ./configure

.include "../../mk/bsd.pkg.mk"
