# $NetBSD: Makefile,v 1.14 2003/01/10 01:05:05 mycroft Exp $
#

PKGNAME=		sawfish-${SF_VERS}
#PKGREVISION=		2

COMMENT=		GNOME-aware window manager that is fully configurable in Lisp

DEPENDS+=		sawfish-replibs-${SF_VERS}:../../wm/sawfish-replibs

USE_X11BASE=		# defined

CONFIGURE_ENV+=		PKGLOCALEDIR=${PKGLOCALEDIR}
MAKE_ENV+=		PKGLOCALEDIR=${PKGLOCALEDIR}
TEXINFO_OVERRIDE=	YES
BUILD_USES_MSGFMT=	YES

PLIST_SUBST+=		SF_VERS=${SF_VERS}

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/sawfish/themes
	${TOUCH} ${PREFIX}/share/sawfish/themes/.directory
	${INSTALL_DATA_DIR} ${PREFIX}/share/sawfish/sounds
	${TOUCH} ${PREFIX}/share/sawfish/sounds/.directory

.include "../../wm/sawfish/Makefile.common"
