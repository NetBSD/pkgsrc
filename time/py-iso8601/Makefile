# $NetBSD: Makefile,v 1.12 2022/10/25 09:09:26 adam Exp $

DISTNAME=	iso8601-1.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	time python
MASTER_SITES=	${MASTER_SITE_PYPI:=i/iso8601/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/micktwomey/pyiso8601
COMMENT=	Simple Python module to parse ISO 8601 dates
LICENSE=	mit

TEST_DEPENDS+=	${PYPKGPREFIX}-hypothesis-[0-9]*:../../devel/py-hypothesis
TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX} iso8601/test_iso8601.py

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
