# $NetBSD: Makefile,v 1.1.1.1 2000/12/15 23:25:18 wiz Exp $

DISTNAME=	wmthemes-0.62.x
CATEGORIES=	x11 wm
MASTER_SITES=	http://download.themes.org/wm/
DISTFILES=	${THEME_FILES}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://wm.themes.org/

DEPENDS+=	windowmaker-*:../../wm/windowmaker

DIST_SUBDIR=	wmthemes

USE_X11BASE=	yes
NO_BUILD=	yes
NO_CHECKSUM=	yes
NO_WRKSUBDIR=	yes

PLIST_SRC=	${WRKDIR}/PLIST
THEME_SUBDIRS=	Backgrounds IconSets Icons Pixmaps Sounds Styles Themes
WM_DATADIR=	share/WindowMaker

BUILD_DEFS+=	WINDOWMAKER_THEMES

.include "../../mk/bsd.prefs.mk"

WINDOWMAKER_THEMES?=	FreeBSD-theme-0.52

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
	  if [ -d "$$DIR" ] && [ -n "`ls "$$DIR"`" ]; then \
	    ${ECHO} "Installing \"$${DIR%.*}\" theme."; \
	    ${MKDIR} "${PREFIX}/${WM_DATADIR}/Themes/$$DIR"; \
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

THEME_FILES=
.for FILE in ${WINDOWMAKER_THEMES}
THEME_FILES+=	${FILE}${EXTRACT_SUFX}
.endfor
