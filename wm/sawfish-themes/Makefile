# $NetBSD: Makefile,v 1.13 2006/07/27 15:16:44 jlam Exp $

DISTNAME=		sawfish-themes-0.2
PKGREVISION=		5
CATEGORIES=		x11 wm
DISTFILES=		${SAWFISH_THEMES}

MAINTAINER=		jschauma@NetBSD.org
HOMEPAGE=		http://themes.freshmeat.net/browse/926/
COMMENT=		Themes for the sawfish window manager

DEPENDS+=		sawfish>=1.0.1:../../wm/sawfish

DIST_SUBDIR=		sawfish-themes
THEMES_DIR=		share/sawfish/themes
PLIST_SRC=		${WRKDIR}/PLIST

NO_BUILD=		yes
NO_CONFIGURE=		yes
USE_X11BASE=		yes

.include "../../mk/bsd.prefs.mk"

.include "../../mk/x11.buildlink3.mk"

pre-fetch:
	@${ECHO} "==========================================================="
	@${ECHO}
	@${ECHO} " We're now downloading >150 themes for Sawfish - if you"
	@${ECHO} " would like to install only a subset, you can specify the"
	@${ECHO} " themes using the SAWFISH_THEMES environment variable."
	@${ECHO} " (See ${FILESDIR}/themes.sawfish for defaults.)"
	@${ECHO}
	@${ECHO} "==========================================================="
	@sleep 5

pre-extract:
	@${MKDIR} ${WRKSRC}

post-extract:
	@${MV} ${WRKDIR}/* ${WRKSRC} 2>/dev/null || ${TRUE}

# here's what we do:
# - some themes contain .xvpics - let's clean those up
# - create a PLIST
# - dirrm directives need to be reversed in case of subdirs
pre-install:
	@${RM} -f ${PLIST_SRC}
	@${TOUCH} ${PLIST_SRC}
	@cd ${WRKSRC} &&						\
		${FIND} . \( -type d -name ".xvpics" -or -name "CVS" \) \
			-print | ${XARGS} ${RM} -fr
	@cd ${WRKSRC} && 						\
		${FIND} . \( -type f -or -type l \)		 	\
			-print | 					\
		${SED} -e 's,^\.,share/sawfish/themes,' >> ${PLIST_SRC}
	@cd ${WRKSRC} && 						\
			${FIND} -d . \( -type d ! -name "." \) 		\
			-print |					\
		${SED} -e 's,^\.,@dirrm share/sawfish/themes,' >>	\
			${PLIST_SRC}
	@${ECHO} "@dirrm share/sawfish/themes" >> ${PLIST_SRC}

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/${THEMES_DIR}
	cd ${WRKSRC} && ${PAX} -s ,^./[.].*,,				\
		-s ,^./PLIST,, -rw . ${PREFIX}/${THEMES_DIR}

.include "files/themes.sawfish"
.include "../../mk/bsd.pkg.mk"
