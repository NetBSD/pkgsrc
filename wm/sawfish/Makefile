# $NetBSD: Makefile,v 1.24 2004/03/08 19:40:43 jmmv Exp $
#

PKGNAME=		sawfish-${SF_VERS}
PKGREVISION=		8

COMMENT=		GNOME-aware window manager that is fully configurable in Lisp

DEPENDS+=		sawfish-replibs-${SF_VERS}nb4:../../wm/sawfish-replibs
DEPENDS+=		xdg-x11-dirs>=1.1:../../misc/xdg-x11-dirs

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
