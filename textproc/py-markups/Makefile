# $NetBSD: Makefile,v 1.19 2025/01/28 02:24:35 gutteridge Exp $

DISTNAME=	markups-4.1.0
PKGREVISION=	1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=M/Markups/}

MAINTAINER=	gutteridge@NetBSD.org
HOMEPAGE=	https://github.com/retext-project/pymarkups
COMMENT=	Python text markup language wrapper module
LICENSE=	modified-bsd

WHEEL_NAME=	${DISTNAME:S/m/M/}

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=70.1:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-markdown-math-[0-9]*:../../textproc/py-markdown-math
DEPENDS+=	${PYPKGPREFIX}-docutils-[0-9]*:../../textproc/py-docutils
DEPENDS+=	${PYPKGPREFIX}-lxml-[0-9]*:../../textproc/py-lxml
DEPENDS+=	${PYPKGPREFIX}-pygments-[0-9]*:../../textproc/py-pygments
DEPENDS+=	${PYPKGPREFIX}-textile-[0-9]*:../../textproc/py-textile
DEPENDS+=	${PYPKGPREFIX}-yaml-[0-9]*:../../textproc/py-yaml
# As of 4.0.0, there is also asciidoc support, requiring textproc/asciidoc.
# This hasn't been enabled here, because asciidoc (as packaged) doesn't
# support installations of multiple Python versions.

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	39

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
