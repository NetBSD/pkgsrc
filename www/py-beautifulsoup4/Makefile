# $NetBSD: Makefile,v 1.29 2023/09/28 22:26:33 joerg Exp $

DISTNAME=	beautifulsoup4-4.12.2
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
TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

EXTRACT_USING=	bsdtar

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX} bs4

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
