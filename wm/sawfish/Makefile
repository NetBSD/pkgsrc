# $NetBSD: Makefile,v 1.3 2001/02/13 11:47:07 tron Exp $
#

PKGNAME=		sawfish-${SF_VERS}

DEPENDS+=		sawfish-replibs-${SF_VERS}:../../wm/sawfish-replibs

USE_X11BASE=		# defined

CONFIGURE_ENV+=		LOCALEDIR=${LOCALEDIR}
MAKE_ENV+=		LOCALEDIR=${LOCALEDIR}

PLIST_SUBST+=		SF_VERS=${SF_VERS}
PLIST_SUBST+=		LOCALEDIR=${LOCALEDIR}

.include "../../mk/bsd.prefs.mk"

# The directory in which locale files are found is:
#
#	${PREFIX}/${LOCALEDIR}/locale/<lang>/LC_MESSAGES
#
.if ${OPSYS} == "SunOS"
LOCALEDIR=		lib
.else
LOCALEDIR=		share
.endif

post-install:
	${MKDIR} ${PREFIX}/share/sawfish/themes
	${TOUCH} ${PREFIX}/share/sawfish/themes/.directory
	${MKDIR} ${PREFIX}/share/sawfish/sounds
	${TOUCH} ${PREFIX}/share/sawfish/sounds/.directory

.include "../../wm/sawfish/Makefile.common"
