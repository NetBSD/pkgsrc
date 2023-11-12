# $NetBSD: Makefile,v 1.5 2023/11/12 13:24:22 wiz Exp $

DISTNAME=	wxPython-4.2.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_PYPI:=w/wxPython/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://wxpython.org/pages/downloads/
COMMENT=	GUI Toolkit for Python
# LGPLv2 with additional permission; http://opensource.org/licenses/wxwindows
LICENSE=	gnu-lgpl-v2

DEPENDS+=	${PYPKGPREFIX}-numpy-[0-9]*:../../math/py-numpy
DEPENDS+=	${PYPKGPREFIX}-Pillow-[0-9]*:../../graphics/py-Pillow
DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six

PYTHON_VERSIONS_INCOMPATIBLE=	27 38
USE_LANGUAGES+=			c c++
USE_TOOLS+=			pkg-config
MAKE_ENV+=			WX_CONFIG=wx-config-3.2
PYDISTUTILSPKG=			no

BUILD_ARGS+=			--use_syswx
BUILD_ARGS+=			--prefix=${PREFIX}
BUILD_ARGS+=			--destdir=${DESTDIR}

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${PYTHONBIN} build.py ${BUILD_ARGS} build_py

do-install:
	cd ${WRKSRC} && ${SETENV} ${INSTALL_ENV} ${PYTHONBIN} build.py ${BUILD_ARGS} install_py

.include "../../x11/wxGTK32/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
