# $NetBSD: Makefile,v 1.42 2026/06/11 11:08:43 adam Exp $

DISTNAME=	beautifulsoup4-4.15.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES+=	${MASTER_SITE_PYPI:=b/beautifulsoup4/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.crummy.com/software/BeautifulSoup/
COMMENT=	HTML/XML Parser for Python, version 4
LICENSE=	mit

EXTRACT_USING=	bsdtar

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling-[0-9]*:../../devel/py-hatchling
DEPENDS+=	${PYPKGPREFIX}-soupsieve>=1.6.1:../../www/py-soupsieve
DEPENDS+=	${PYPKGPREFIX}-typing-extensions>=4.0.0:../../devel/py-typing-extensions
# lxml
DEPENDS+=	${PYPKGPREFIX}-lxml-[0-9]*:../../textproc/py-lxml

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	310

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
