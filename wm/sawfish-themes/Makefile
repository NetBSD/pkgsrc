# $NetBSD: Makefile,v 1.1.1.1 2002/10/07 17:00:43 jschauma Exp $

DISTNAME=		sawfish-themes-0.1
CATEGORIES=		x11 wm
DYNAMIC_MASTER_SITES=	yes
DISTFILES=		${SAWFISH_THEMES}

MAINTAINER=		jschauma@netbsd.org
HOMEPAGE=		http://themes.freshmeat.net/browse/926/
COMMENT=		Themes for the sawfish window manager

DEPENDS+=		sawfish>=1.0.1:../../wm/sawfish

DIST_SUBDIR=		sawfish-themes
THEMES_DIR=		share/sawfish/themes
PLIST_SRC=		${WRKDIR}/PLIST

NO_BUILD=		yes
NO_CONFIGURE=		yes
NO_PATCH=		yes

.include "../../mk/bsd.prefs.mk"

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

# here's what we do:
# - some themes contain .xvpics - let's clean those up
#   (Solaris can only '­print' (not '-print0' or -'printx'), thus tmpfile
# - create a PLIST
# - dirrm directives need to be reversed in case of subdirs
pre-install:
	@${RM} -f ${PLIST_SRC}
	@${TOUCH} ${PLIST_SRC}
	@cd ${WRKDIR} &&						\
		${FIND} . \( -type d -name ".xvpics" -or -name "CVS" \) \
			-print > ${WRKDIR}/.goners
	@for i in `${CAT} ${WRKDIR}/.goners`; do			\
		${RM} -fr -- "${WRKDIR}/$$i";				\
	done
	@cd ${WRKDIR} && 						\
		${FIND} . \( -type f ! -name ".*" ! -name "PLIST" \) 	\
			-print | 					\
		${SED} -e 's,^\.,share/sawfish/themes,' >> ${PLIST_SRC}
	@cd ${WRKDIR} && 						\
			${FIND} -d . \( -type d ! -name "." \) 		\
			-print |					\
		${SED} -e 's,^\.,@dirrm share/sawfish/themes,' >>	\
			${PLIST_SRC}
	@${ECHO} "@dirrm share/sawfish/themes" >> ${PLIST_SRC}

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/${THEMES_DIR}
	cd ${WRKDIR} && ${PAX} -s /^.\/[.].*// 				\
		-s /^.\/PLIST// -rw . ${PREFIX}/${THEMES_DIR}

.include "files/themes.sawfish"
.include "../../mk/bsd.pkg.mk"
