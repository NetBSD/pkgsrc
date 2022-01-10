# $NetBSD: Makefile,v 1.31 2022/01/10 08:02:13 wiz Exp $

GITHUB_PROJECT=	terminator
DISTNAME=	terminator-2.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
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

BUILD_DEPENDS+=	${PYPKGPREFIX}-test-runner-[0-9]*:../../devel/py-test-runner

DEPENDS+=	${PYPKGPREFIX}-cairo-[0-9]*:../../graphics/py-cairo
DEPENDS+=	${PYPKGPREFIX}-configobj-[0-9]*:../../devel/py-configobj
DEPENDS+=	${PYPKGPREFIX}-dbus-[0-9]*:../../sysutils/py-dbus
DEPENDS+=	${PYPKGPREFIX}-gobject3-[0-9]*:../../devel/py-gobject3
DEPENDS+=	${PYPKGPREFIX}-psutil>=5.6.3:../../sysutils/py-psutil

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
