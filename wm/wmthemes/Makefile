# $NetBSD: Makefile,v 1.30 2013/04/06 13:24:20 rodent Exp $

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
.for dir in ${THEME_SUBDIRS}
	@if [ -d ${WRKSRC}/${dir} ] && [ -n "`ls ${WRKSRC}/${dir}`" ]; then \
	  ${ECHO} "Installing files in directory ${dir}."; \
	  cd ${WRKSRC}/${dir}; \
	  for file in *; do \
	    ${MKDIR} ${DESTDIR}${PREFIX}/${WM_DATADIR}/${dir}; \
	    ${INSTALL_DATA} "$$file" ${DESTDIR}${PREFIX}/${WM_DATADIR}/${dir}; \
	    ${ECHO} "${WM_DATADIR}/${dir}/$$file" >>${PLIST_SRC}; \
	  done; \
	fi
.endfor
	@cd ${WRKSRC}; \
	for dir in *.themed; do \
	  if [ -d "$$dir" ] && [ -n "`${LS} "$$dir"`" ]; then \
	    ${ECHO} "Installing \"`${BASENAME} "$$dir" .themed`\" theme."; \
	    ${INSTALL_DATA_DIR} "${DESTDIR}${PREFIX}/${WM_DATADIR}/Themes/$$dir"; \
	    cd "${WRKSRC}/$$dir"; \
	    for file in *; do \
	      ${INSTALL_DATA} "$$file" "${DESTDIR}${PREFIX}/${WM_DATADIR}/Themes/$$dir"; \
	      ${ECHO} "${WM_DATADIR}/Themes/$$dir/$$file" >>${PLIST_SRC}; \
	    done; \
	    cd ..; \
	  fi; \
	done

.include "../../mk/bsd.pkg.mk"
