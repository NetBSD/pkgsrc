# $NetBSD: Makefile,v 1.3 2023/07/01 08:37:46 wiz Exp $

DISTNAME=	lunr-0.6.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=l/lunr/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/yeraydiazdiaz/lunr.py
COMMENT=	Python implementation of Lunr.js
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-nltk>=0:../../textproc/py-nltk
TEST_DEPENDS+=	${PYPKGPREFIX}-mock>=0:../../devel/py-mock
TEST_DEPENDS+=	${PYPKGPREFIX}-test>=0:../../devel/py-test

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27 37 38

# as of 0.6.2
# 1 failed, 297 passed, 1 warning
do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
