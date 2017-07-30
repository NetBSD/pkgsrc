# $NetBSD: Makefile,v 1.2 2017/07/30 22:32:27 wiz Exp $

DISTNAME=	pystache-0.5.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pystache/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/defunkt/pystache
COMMENT=	Mustache for Python
LICENSE=	mit

USE_LANGUAGES=	# none

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHONBIN} test_pystache.py

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
