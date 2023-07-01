# $NetBSD: Makefile,v 1.8 2023/07/01 08:37:42 wiz Exp $

DISTNAME=	pyqtgraph-0.12.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/pyqtgraph/qtgraph-qt5/}
PKGREVISION=	1
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
DEPENDS+=	${PYPKGPREFIX}-qt5-[0-9]*:../../x11/py-qt5
DEPENDS+=	${PYPKGPREFIX}-scipy-[0-9]*:../../math/py-scipy
DEPENDS+=	${PYPKGPREFIX}-OpenGL-[0-9]*:../../graphics/py-OpenGL

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27 37 38

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
