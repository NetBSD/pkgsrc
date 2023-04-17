# $NetBSD: Makefile,v 1.1 2023/04/17 20:35:02 adam Exp $

DISTNAME=	rapidfuzz-3.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=r/rapidfuzz/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/maxbachmann/RapidFuzz
COMMENT=	Rapid fuzzy string matching
LICENSE=	mit

TEST_DEPENDS+=	${PYPKGPREFIX}-test>=7.1:../../devel/py-test

PYTHON_VERSIONS_INCOMPATIBLE=	27

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX} tests

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
