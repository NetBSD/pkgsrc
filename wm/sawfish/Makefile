# $NetBSD: Makefile,v 1.1.1.1 2000/12/12 02:03:49 wiz Exp $
#

PKGNAME=		sawfish-${SF_VERS}

DEPENDS+=		sawfish-replibs-${SF_VERS}:../../x11/sawfish-replibs

USE_X11BASE=		# defined

CONFIGURE_ENV+=		LOCALEBASE=${LOCALEBASE}
MAKE_ENV+=		LOCALEBASE=${LOCALEBASE}

PLIST_SUBST+=		SF_VERS=${SF_VERS}
PLIST_SUBST+=		LOCALEBASE=${LOCALEBASE}

.include "../../mk/bsd.prefs.mk"

# The directory in which locale files are found is:
#
#	${PREFIX}/${LOCALEBASE}/locale/<lang>/LC_MESSAGES
#
.if ${OPSYS} == "SunOS"
LOCALEBASE=		lib
.else
LOCALEBASE=		share
.endif

post-install:
	${MKDIR} ${PREFIX}/share/sawfish/themes
	${TOUCH} ${PREFIX}/share/sawfish/themes/.directory
	${MKDIR} ${PREFIX}/share/sawfish/sounds
	${TOUCH} ${PREFIX}/share/sawfish/sounds/.directory

.include "../../wm/sawfish/Makefile.common"
