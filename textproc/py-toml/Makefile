# $NetBSD: Makefile,v 1.3 2020/05/17 21:38:47 adam Exp $

DISTNAME=	toml-0.10.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=t/toml/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/uiri/toml
COMMENT=	Python Library for Tom's Obvious, Minimal Language
LICENSE=	mit

PYTHON_VERSIONED_DEPENDENCIES=	test:test

USE_LANGUAGES=	# none

do-test:
	cd ${WRKSRC} && pytest-${PYVERSSUFFIX} tests

.include "../../lang/python/egg.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
