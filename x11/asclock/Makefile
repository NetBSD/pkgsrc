# $NetBSD: Makefile,v 1.11 1999/01/30 23:18:55 agc Exp $
#

DISTNAME=		asclock
PKGNAME=		asclock-11
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	X11/clocks

MAINTAINER=		hubertf@netbsd.org

DEPENDS+=		xpm-3.4k:../../graphics/xpm

CONFLICTS=		asclock-10

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
# c) russian
# d) ukrainian
# e) slovene
# f) indonesian
# g) danish
LANG?=1

# Choose paneltype from:
# 1) 8bit AfterStep-colors (47 colors) [DEFAULT]
# 2) 8bit NeXTStep -colors (76 colors)
# 3) 2bit greyscale        ( 4 colors)
PANEL?=1

USE_X11BASE=	yes
INSTALL_TARGET=	install install.man

do-configure:
	cd ${WRKSRC} ; ( ${ECHO} ${LANG} ; ${ECHO} ${PANEL} ) | ./configure

.include "../../mk/bsd.pkg.mk"
