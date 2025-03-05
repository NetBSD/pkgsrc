# $NetBSD: Makefile,v 1.20 2025/03/05 10:32:46 wiz Exp $

DISTNAME=	markups-4.1.0
PKGREVISION=	2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=M/Markups/}

MAINTAINER=	gutteridge@NetBSD.org
HOMEPAGE=	https://github.com/retext-project/pymarkups
COMMENT=	Python text markup language wrapper module
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=75.8.2:../../devel/py-setuptools
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
