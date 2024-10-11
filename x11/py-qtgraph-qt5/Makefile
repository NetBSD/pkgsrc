# $NetBSD: Makefile,v 1.13 2024/10/11 14:19:15 jperkin Exp $

DISTNAME=	pyqtgraph-0.13.7
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/pyqtgraph/qtgraph-qt5/}
CATEGORIES=	x11 python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pyqtgraph/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/pyqtgraph/pyqtgraph
COMMENT=	Scientific Graphics and GUI Library for Python
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-numpy>=1.22:../../math/py-numpy
# Optional deps
DEPENDS+=	${PYPKGPREFIX}-OpenGL-[0-9]*:../../graphics/py-OpenGL
DEPENDS+=	${PYPKGPREFIX}-qt5-[0-9]*:../../x11/py-qt5
DEPENDS+=	${PYPKGPREFIX}-scipy-[0-9]*:../../math/py-scipy

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27 38 39 313

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
