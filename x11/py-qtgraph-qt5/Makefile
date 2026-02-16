# $NetBSD: Makefile,v 1.22 2026/02/16 15:40:53 adam Exp $

DISTNAME=	pyqtgraph-0.14.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/pyqtgraph/qtgraph-qt5/}
CATEGORIES=	x11 python
# Missing source code distfile for 0.14.0 on PyPI.
#MASTER_SITES=	${MASTER_SITE_PYPI:=p/pyqtgraph/}
MASTER_SITES=	${MASTER_SITE_GITHUB:=pyqtgraph/}
GITHUB_PROJECT=	pyqtgraph
GITHUB_TAG=	${DISTNAME}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/pyqtgraph/pyqtgraph
COMMENT=	Scientific Graphics and GUI Library for Python
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-colorama-[0-9]*:../../comms/py-colorama
DEPENDS+=	${PYPKGPREFIX}-numpy>=1.22:../../math/py-numpy
# Optional deps
DEPENDS+=	${PYPKGPREFIX}-OpenGL-[0-9]*:../../graphics/py-OpenGL
DEPENDS+=	${PYPKGPREFIX}-qt5-[0-9]*:../../x11/py-qt5
DEPENDS+=	${PYPKGPREFIX}-scipy-[0-9]*:../../math/py-scipy

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	310

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
