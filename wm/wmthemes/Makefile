# $NetBSD: Makefile,v 1.9 2001/12/19 15:35:40 tron Exp $

#
# There is no distinfo file since the files change contents so often on the
# master site
#

DISTNAME=	wmthemes-0.62nb1
CATEGORIES=	x11 wm
MASTER_SITES=	http://download.themes.org/wm/
DISTFILES=	${THEME_FILES}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://wm.themes.org/
COMMENT=	Themes for the window manager WindowMaker

DEPENDS+=	windowmaker-[0-9]*:../../wm/windowmaker

DIST_SUBDIR=	wmthemes

USE_X11BASE=	yes
NO_BUILD=	yes
NO_CHECKSUM=	yes
WRKSRC=		${WRKDIR}

PLIST_SRC=	${WRKDIR}/PLIST
THEME_SUBDIRS=	Backgrounds IconSets Icons Pixmaps Sounds Styles Themes
WM_DATADIR=	share/WindowMaker

BUILD_DEFS+=	WINDOWMAKER_THEMES

.include "../../mk/bsd.prefs.mk"

WINDOWMAKER_THEMES?=	FreeBSD-theme-0.52

THEME_FILES=
.for FILE in ${WINDOWMAKER_THEMES}
THEME_FILES+=	${FILE}${EXTRACT_SUFX}
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
	    ${ECHO} "@dirrm ${WM_DATADIR}/Themes/$$DIR" >>${PLIST_SRC}; \
	  fi; \
	done

.include "../../mk/bsd.pkg.mk"
