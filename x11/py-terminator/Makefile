# $NetBSD: Makefile,v 1.29 2021/01/24 11:15:07 kamil Exp $

GITHUB_PROJECT=	terminator
DISTNAME=	terminator-2.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GITHUB:=gnome-terminator/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://launchpad.net/terminator
COMMENT=	Terminator, multiple terminals in one window
LICENSE=	gnu-gpl-v2

REPLACE_PYTHON+=	*.py
REPLACE_PYTHON+=	terminatorlib/*.py
REPLACE_PYTHON+=	terminatorlib/plugins/*.py

USE_TOOLS+=	intltool bash

REPLACE_SH+=	terminator.wrapper
REPLACE_BASH+=	terminatorlib/pylint.sh
REPLACE_BASH+=	run_tests

SUBST_CLASSES+=		manpath
SUBST_STAGE.manpath=	pre-configure
SUBST_FILES.manpath=	setup.py
SUBST_VARS.manpath=	PKGMANDIR

DEPENDS+=	${PYPKGPREFIX}-babel-[0-9]*:../../devel/py-babel
DEPENDS+=	${PYPKGPREFIX}-configobj-[0-9]*:../../devel/py-configobj
DEPENDS+=	${PYPKGPREFIX}-psutil>=5.6.3:../../sysutils/py-psutil

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/distutils.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
