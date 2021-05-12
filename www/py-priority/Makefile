# $NetBSD: Makefile,v 1.1 2021/05/12 09:09:27 adam Exp $

DISTNAME=	priority-1.3.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/priority/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://python-hyper.org/priority/
COMMENT=	Pure-Python implementation of the HTTP/2 priority tree
LICENSE=	mit

TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test

USE_LANGUAGES=	# none

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX} test

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
