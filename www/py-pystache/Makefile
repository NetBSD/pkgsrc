# $NetBSD: Makefile,v 1.1 2017/02/14 07:33:27 adam Exp $

DISTNAME=	pystache-0.5.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pystache/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://github.com/defunkt/pystache
COMMENT=	Mustache for Python
LICENSE=	mit

USE_LANGUAGES=	# none

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHONBIN} test_pystache.py

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
