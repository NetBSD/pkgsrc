# $NetBSD: Makefile,v 1.2 2020/01/08 21:32:47 adam Exp $

DISTNAME=	elementpath-1.4.0
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
