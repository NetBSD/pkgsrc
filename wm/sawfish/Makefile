# $NetBSD: Makefile,v 1.32 2006/01/24 07:32:40 wiz Exp $
#

PKGNAME=		sawfish-${SF_VERS}
PKGREVISION=		11

COMMENT=		GNOME-aware window manager that is fully configurable in Lisp

DEPENDS+=		sawfish-replibs-${SF_VERS}nb5:../../wm/sawfish-replibs

USE_DIRS+=		xdg-1.1
USE_X11BASE=		yes

CONFIGURE_ENV+=		PKGLOCALEDIR=${PKGLOCALEDIR:Q}
MAKE_ENV+=		PKGLOCALEDIR=${PKGLOCALEDIR:Q}
BUILD_USES_MSGFMT=	YES

USE_MAKEINFO=		YES
INFO_FILES=		sawfish.info

PLIST_SUBST+=		SF_VERS=${SF_VERS:Q}

.include "../../mk/x11.buildlink3.mk"

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/sawfish/themes
	${TOUCH} ${PREFIX}/share/sawfish/themes/.directory
	${INSTALL_DATA_DIR} ${PREFIX}/share/sawfish/sounds
	${TOUCH} ${PREFIX}/share/sawfish/sounds/.directory

.include "../../wm/sawfish/Makefile.common"
