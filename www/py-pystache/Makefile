# $NetBSD: Makefile,v 1.6 2022/11/22 13:24:11 adam Exp $

DISTNAME=	pystache-0.6.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pystache/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/defunkt/pystache
COMMENT=	Mustache for Python
LICENSE=	mit

USE_LANGUAGES=	# none

USE_PKG_RESOURCES=	yes

PYTHON_VERSIONS_INCOMPATIBLE=	27

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHONBIN} test_pystache.py

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
