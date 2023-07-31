# $NetBSD: Makefile,v 1.34 2023/07/31 16:27:07 adam Exp $

DISTNAME=	elementpath-4.1.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=e/elementpath/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/sissaschool/elementpath
COMMENT=	XPath 1.0/2.0 parsers and selectors for ElementTree and lxml
LICENSE=	mit

TEST_DEPENDS+=	${PYPKGPREFIX}-cElementTree-[0-9]*:../../textproc/py-cElementTree

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
