# $NetBSD: Makefile,v 1.27 2009/06/14 22:58:09 joerg Exp $

#
# There is no distinfo file because users can specify alternate themes
# via the "WINDOWMAKER_THEMES" variable.
#

DISTNAME=	wmthemes-0.80.0
PKGREVISION=	2
CATEGORIES=	x11 wm windowmaker
MASTER_SITES=	http://download.themes.org/wm/
DISTFILES=	${THEME_FILES}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://wm.themes.org/
COMMENT=	Themes for the window manager WindowMaker

DEPENDS+=	windowmaker>=0.80.0nb1:../../wm/windowmaker

WRKSRC=		${WRKDIR}
DIST_SUBDIR=	wmthemes

USE_X11BASE=	yes
NO_BUILD=	yes
NO_CHECKSUM=	yes

PLIST_SRC=	${WRKDIR}/PLIST
THEME_SUBDIRS=	Backgrounds IconSets Icons Pixmaps Sounds Styles Themes
WM_DATADIR=	share/WindowMaker

.include "../../mk/bsd.prefs.mk"

BUILD_DEFS+=	WINDOWMAKER_THEMES

THEME_FILES=
.for theme in ${WINDOWMAKER_THEMES}
THEME_FILES+=	${theme}.tar.gz
SITES.${theme}.tar.gz=	http://download.freshmeat.net/themes/${theme:C/-[^-]*$//}/
.endfor

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
	@cd ${WRKSRC}; \
	for DIR in *.themed; do \
	  if [ -d "$$DIR" ] && [ -n "`${LS} "$$DIR"`" ]; then \
	    ${ECHO} "Installing \"`${BASENAME} "$$DIR" .themed`\" theme."; \
	    ${INSTALL_DATA_DIR} "${PREFIX}/${WM_DATADIR}/Themes/$$DIR"; \
	    cd "${WRKSRC}/$$DIR"; \
	    for FILE in *; do \
	      ${INSTALL_DATA} "$$FILE" "${PREFIX}/${WM_DATADIR}/Themes/$$DIR"; \
	      ${ECHO} "${WM_DATADIR}/Themes/$$DIR/$$FILE" >>${PLIST_SRC}; \
	    done; \
	    cd ..; \
	  fi; \
	done

.include "../../mk/bsd.pkg.mk"
