# $NetBSD: Makefile,v 1.3 2021/02/11 03:22:35 gutteridge Exp $

VERSION=	0.8
DISTNAME=	python-markdown-math-${VERSION}
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/python-//}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/python-markdown-math/}

MAINTAINER=	gutteridge@NetBSD.org
HOMEPAGE=	https://github.com/mitya57/python-markdown-math
COMMENT=	Python extension adding math formula support to py-markdown
LICENSE=	modified-bsd

PYTHON_VERSIONS_INCOMPATIBLE=	27

DEPENDS+=	${PYPKGPREFIX}-markdown>=3.0:../../textproc/py-markdown

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
