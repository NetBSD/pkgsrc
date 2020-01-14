# $NetBSD: Makefile,v 1.2 2020/01/14 21:35:45 adam Exp $

DISTNAME=	poyo-0.5.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/poyo/}

MAINTAINER=	gde@llew.me
HOMEPAGE=	https://github.com/hackebrot/poyo
COMMENT=	YAML Parser for Python
LICENSE=	mit

TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test

USE_LANGUAGES=	# none

do-test:
	cd ${WRKSRC} && pytest-${PYVERSSUFFIX} tests

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
