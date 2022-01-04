# $NetBSD: Makefile,v 1.2 2022/01/04 20:55:32 wiz Exp $

DISTNAME=	priority-1.3.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
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
