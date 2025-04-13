# $NetBSD: Makefile,v 1.5 2025/04/13 00:28:42 gutteridge Exp $

DISTNAME=	python-markdown-math-0.9
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/python-//}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/python-markdown-math/}

MAINTAINER=	gutteridge@NetBSD.org
HOMEPAGE=	https://github.com/mitya57/python-markdown-math
COMMENT=	Python extension adding math formula support to py-markdown
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-markdown>=3.0:../../textproc/py-markdown

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
