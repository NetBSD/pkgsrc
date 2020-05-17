# $NetBSD: Makefile,v 1.13 2020/05/17 21:38:47 adam Exp $

DISTNAME=	validators-0.14.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=v/validators/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/kvesteri/validators
COMMENT=	Python data validation for humans
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-decorator>=3.4.0:../../devel/py-decorator
DEPENDS+=	${PYPKGPREFIX}-six>=1.4.0:../../lang/py-six
TEST_DEPENDS+=	${PYPKGPREFIX}-flake8>=2.4.0:../../devel/py-flake8
TEST_DEPENDS+=	${PYPKGPREFIX}-isort>=4.2.2:../../devel/py-isort

PYTHON_VERSIONED_DEPENDENCIES=	test:test

USE_LANGUAGES=	# none

do-test:
	cd ${WRKSRC}/tests && pytest-${PYVERSSUFFIX}

.include "../../lang/python/egg.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
