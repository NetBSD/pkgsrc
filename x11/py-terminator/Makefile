# $NetBSD: Makefile,v 1.20 2019/06/11 23:50:13 kamil Exp $

DISTNAME=	terminator-0.98
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	9
CATEGORIES=	x11
MASTER_SITES=	https://launchpad.net/terminator/trunk/${PKGVERSION_NOREV}/+download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://launchpad.net/terminator
COMMENT=	Terminator, multiple terminals in one window
LICENSE=	gnu-gpl-v2

PYTHON_VERSIONS_INCOMPATIBLE=	36 37 # not yet ported as of 0.98

REPLACE_PYTHON+= *.py
REPLACE_PYTHON+= terminatorlib/*.py
REPLACE_PYTHON+= terminatorlib/plugins/*.py

USE_TOOLS+=	intltool bash

REPLACE_SH+=	terminator.wrapper
REPLACE_BASH+=	terminatorlib/pylint.sh
REPLACE_BASH+=	run_tests

SUBST_CLASSES+=		manpath
SUBST_STAGE.manpath=	pre-configure
SUBST_FILES.manpath=	setup.py
SUBST_VARS.manpath=	PKGMANDIR

DEPENDS+=	${PYPKGPREFIX}-psutil>=5.6.3:../../sysutils/py-psutil

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/distutils.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../sysutils/py-notify-python/buildlink3.mk"
.include "../../x11/py-keybinder/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/py-vte/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
