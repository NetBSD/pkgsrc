# $NetBSD: Makefile,v 1.15 1999/08/18 09:16:40 agc Exp $

DISTNAME=	wmthemes-0.60
CATEGORIES=	x11
MASTER_SITES=	http://wm.themes.org/WMThemes/
DIST_SUBDIR=	wmthemes
DISTFILES=	${THEME_FILES}

MAINTAINER=	tron@netbsd.org
HOMEPAGE=	http://wm.themes.org/

DEPENDS+=	windowmaker-0.60.0:../../x11/windowmaker

USE_X11BASE=	yes
NO_BUILD=	yes
NO_CONFIGURE=	yes
NO_CHECKSUM=	yes
NO_PATCH=	yes
NO_WRKSUBDIR=	yes

PLIST_SRC=	${WRKDIR}/PLIST
THEME_SUBDIRS=	Backgrounds IconSets Icons Pixmaps Sounds Styles Themes
WM_DATADIR=	share/WindowMaker

BUILD_DEFS+=	WINDOWMAKER_THEMES

.include "../../mk/bsd.prefs.mk"

WINDOWMAKER_THEMES?=	FreeBSD-theme

do-install:
	@${RM} -f ${PLIST_SRC}
	@${TOUCH} ${PLIST_SRC}
.for DIR in ${THEME_SUBDIRS}
	@if [ -d ${WRKSRC}/${DIR} ] && [ -n "`ls ${WRKSRC}/${DIR}`" ]; then \
	  ${ECHO} "Installing files in directory ${DIR}."; \
	  cd ${WRKSRC}/${DIR}; \
	  for FILE in *; do \
	    ${INSTALL_DATA} "$$FILE" ${PREFIX}/${WM_DATADIR}/${DIR}; \
	    ${ECHO} "${WM_DATADIR}/${DIR}/$$FILE" >>${PLIST_SRC}; \
	  done; \
	fi
.endfor

.include "../../mk/bsd.pkg.mk"

THEME_FILES=
.for FILE in ${WINDOWMAKER_THEMES}
THEME_FILES+=	${FILE}${EXTRACT_SUFX}
.endfor
