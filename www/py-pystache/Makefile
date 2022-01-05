# $NetBSD: Makefile,v 1.5 2022/01/05 15:41:30 wiz Exp $

DISTNAME=	pystache-0.5.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pystache/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/defunkt/pystache
COMMENT=	Mustache for Python
LICENSE=	mit

USE_LANGUAGES=	# none

USE_PKG_RESOURCES=	yes

post-extract:
	cd ${WRKSRC} && 2to3-${PYVERSSUFFIX} -w --no-diffs pystache

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHONBIN} test_pystache.py

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
