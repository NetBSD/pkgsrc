# $NetBSD: Makefile,v 1.2 2021/12/30 13:05:42 adam Exp $

DISTNAME=	pyqtgraph-0.12.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/pyqtgraph/qtgraph-qt5/}
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GITHUB:=pyqtgraph/}
GITHUB_TAG=	pyqtgraph-${PKGVERSION_NOREV}
GITHUB_PROJECT=	pyqtgraph

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/pyqtgraph/pyqtgraph
COMMENT=	Scientific Graphics and GUI Library for Python
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-numpy>=1.17:../../math/py-numpy
# Optional deps
DEPENDS+=	${PYPKGPREFIX}-scipy-[0-9]*:../../math/py-scipy
DEPENDS+=	${PYPKGPREFIX}-OpenGL-[0-9]*:../../graphics/py-OpenGL

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../x11/py-qt5/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
