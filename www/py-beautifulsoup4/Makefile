# $NetBSD: Makefile,v 1.27 2023/04/02 12:41:02 adam Exp $

DISTNAME=	beautifulsoup4-4.12.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES+=	${MASTER_SITE_PYPI:=b/beautifulsoup4/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.crummy.com/software/BeautifulSoup/
COMMENT=	HTML/XML Parser for Python, version 4
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-lxml-[0-9]*:../../textproc/py-lxml
DEPENDS+=	${PYPKGPREFIX}-soupsieve>=1.2:../../www/py-soupsieve
TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX} bs4

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
