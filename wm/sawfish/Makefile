# $NetBSD: Makefile,v 1.7 2002/02/18 15:14:44 seb Exp $
#

PKGNAME=		sawfish-${SF_VERS}

COMMENT=		GNOME-aware window manager that is fully configurable in Lisp

DEPENDS+=		sawfish-replibs-${SF_VERS}:../../wm/sawfish-replibs

USE_X11BASE=		# defined

CONFIGURE_ENV+=		LOCALEDIR=${LOCALEDIR}
MAKE_ENV+=		LOCALEDIR=${LOCALEDIR}
TEXINFO_OVERRIDE=	YES

PLIST_SUBST+=		SF_VERS=${SF_VERS}

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
	${INSTALL_DATA_DIR} ${PREFIX}/share/sawfish/themes
	${TOUCH} ${PREFIX}/share/sawfish/themes/.directory
	${INSTALL_DATA_DIR} ${PREFIX}/share/sawfish/sounds
	${TOUCH} ${PREFIX}/share/sawfish/sounds/.directory

.include "../../wm/sawfish/Makefile.common"
