# $NetBSD: Makefile,v 1.14 1999/10/07 17:22:59 jlam Exp $
#

DISTNAME=	asclock-classic-1.0
PKGNAME=	asclock-1.0
CATEGORIES=	x11
MASTER_SITES=	http://www.asclock.org/tar/

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://www.asclock.org/

DEPENDS+=	xpm-3.4k:../../graphics/xpm

CONFLICTS=	asclock-xlib-* asclock-gtk-*

USE_IMAKE=	yes

LANGUAGES=	english german portuguese dutch norwegian italian swedish \
		spanish hungarian breton french czech russian ukrainian \
		slovene indonesian danish

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

WRKSRC=		${WRKDIR}/asclock1.0
PLIST_SRC=	${WRKDIR}/.PLIST_SRC

do-configure:
	cd ${WRKSRC} ; ( ${ECHO} ${LANG} ; ${ECHO} ${PANEL} ) | ./configure

post-install:
	${RM} -rf ${WRKSRC}/french/french2
	${CAT} ${PKGDIR}/PLIST > ${PLIST_SRC}
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/asclock
.for LANGUAGE in ${LANGUAGES}
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/asclock/${LANGUAGE}
	cd ${WRKSRC}/${LANGUAGE}; ${INSTALL_DATA} month.xpm weekday.xpm \
		${PREFIX}/share/examples/asclock/${LANGUAGE}
	@${ECHO} share/examples/asclock/${LANGUAGE}/month.xpm >> ${PLIST_SRC}
	@${ECHO} share/examples/asclock/${LANGUAGE}/weekday.xpm >> ${PLIST_SRC}
	@${ECHO} @dirrm share/examples/asclock/${LANGUAGE} >> ${PLIST_SRC}
.endfor
	@${ECHO} @dirrm share/examples/asclock >> ${PLIST_SRC}

.include "../../mk/bsd.pkg.mk"
