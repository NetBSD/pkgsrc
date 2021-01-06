# $NetBSD: Makefile,v 1.12 2021/01/06 12:13:27 adam Exp $

DISTNAME=	elementpath-2.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=e/elementpath/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/sissaschool/elementpath
COMMENT=	XPath 1.0/2.0 parsers and selectors for ElementTree and lxml
LICENSE=	mit

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
