# $NetBSD: Makefile,v 1.26 2004/04/14 19:30:22 jmmv Exp $
#

PKGNAME=		sawfish-${SF_VERS}
PKGREVISION=		8

COMMENT=		GNOME-aware window manager that is fully configurable in Lisp

DEPENDS+=		sawfish-replibs-${SF_VERS}nb4:../../wm/sawfish-replibs

USE_DIRS+=		xdg-1.1
USE_X11BASE=		# defined

CONFIGURE_ENV+=		PKGLOCALEDIR=${PKGLOCALEDIR}
MAKE_ENV+=		PKGLOCALEDIR=${PKGLOCALEDIR}
BUILD_USES_MSGFMT=	YES

USE_MAKEINFO=		YES
INFO_FILES=		sawfish.info

PLIST_SUBST+=		SF_VERS=${SF_VERS}

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/sawfish/themes
	${TOUCH} ${PREFIX}/share/sawfish/themes/.directory
	${INSTALL_DATA_DIR} ${PREFIX}/share/sawfish/sounds
	${TOUCH} ${PREFIX}/share/sawfish/sounds/.directory

.include "../../wm/sawfish/Makefile.common"
