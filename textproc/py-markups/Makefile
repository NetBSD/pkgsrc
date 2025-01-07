# $NetBSD: Makefile,v 1.18 2025/01/07 19:47:21 adam Exp $

DISTNAME=	markups-4.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=M/Markups/}

MAINTAINER=	gutteridge@NetBSD.org
HOMEPAGE=	https://github.com/retext-project/pymarkups
COMMENT=	Python text markup language wrapper module
LICENSE=	modified-bsd

WHEEL_NAME=	${DISTNAME:S/m/M/}

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=61.2:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-markdown-math-[0-9]*:../../textproc/py-markdown-math
# optional
DEPENDS+=	${PYPKGPREFIX}-docutils-[0-9]*:../../textproc/py-docutils
DEPENDS+=	${PYPKGPREFIX}-pygments-[0-9]*:../../textproc/py-pygments
DEPENDS+=	${PYPKGPREFIX}-textile-[0-9]*:../../textproc/py-textile
# As of 4.0.0, there is also asciidoc support, requiring textproc/asciidoc
# and textproc/py-lxml. This hasn't been enabled, in part because asciidoc
# (as packaged) doesn't seem intended to handle multiple Python versions.
# textproc/py-yaml is also an optional dependency for configurations using
# YAML.

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	39

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
