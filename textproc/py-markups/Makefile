# $NetBSD: Makefile,v 1.22 2025/04/29 15:46:22 adam Exp $

DISTNAME=	markups-4.1.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=M/Markups/}

MAINTAINER=	gutteridge@NetBSD.org
HOMEPAGE=	https://github.com/retext-project/pymarkups
COMMENT=	Python text markup language wrapper module
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
# asciidoc
# As of 4.0.0, there is also asciidoc support, requiring textproc/asciidoc.
# This hasn't been enabled here, because asciidoc (as packaged) doesn't
# support installations of multiple Python versions.
DEPENDS+=	${PYPKGPREFIX}-lxml-[0-9]*:../../textproc/py-lxml
# highlighting
DEPENDS+=	${PYPKGPREFIX}-pygments-[0-9]*:../../textproc/py-pygments
# markdown
DEPENDS+=	${PYPKGPREFIX}-markdown>=3:../../textproc/py-markdown
DEPENDS+=	${PYPKGPREFIX}-markdown-math-[0-9]*:../../textproc/py-markdown-math
DEPENDS+=	${PYPKGPREFIX}-yaml-[0-9]*:../../textproc/py-yaml
# restructuredtext
DEPENDS+=	${PYPKGPREFIX}-docutils-[0-9]*:../../textproc/py-docutils
# textile
DEPENDS+=	${PYPKGPREFIX}-textile-[0-9]*:../../textproc/py-textile

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	39

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
