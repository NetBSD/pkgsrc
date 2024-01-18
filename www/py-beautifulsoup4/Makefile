# $NetBSD: Makefile,v 1.31 2024/01/18 10:20:45 adam Exp $

DISTNAME=	beautifulsoup4-4.12.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES+=	${MASTER_SITE_PYPI:=b/beautifulsoup4/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.crummy.com/software/BeautifulSoup/
COMMENT=	HTML/XML Parser for Python, version 4
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling-[0-9]*:../../devel/py-hatchling
DEPENDS+=	${PYPKGPREFIX}-lxml-[0-9]*:../../textproc/py-lxml
DEPENDS+=	${PYPKGPREFIX}-soupsieve>=1.2:../../www/py-soupsieve

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

EXTRACT_USING=	bsdtar

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
