# $NetBSD: Makefile,v 1.3 2020/05/17 21:38:46 adam Exp $

DISTNAME=	poyo-0.5.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/poyo/}

MAINTAINER=	gde@llew.me
HOMEPAGE=	https://github.com/hackebrot/poyo
COMMENT=	YAML Parser for Python
LICENSE=	mit

PYTHON_VERSIONED_DEPENDENCIES=	test:test

USE_LANGUAGES=	# none

do-test:
	cd ${WRKSRC} && pytest-${PYVERSSUFFIX} tests

.include "../../lang/python/egg.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
