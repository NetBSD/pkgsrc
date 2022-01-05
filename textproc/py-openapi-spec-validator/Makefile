# $NetBSD: Makefile,v 1.3 2022/01/05 15:41:25 wiz Exp $

DISTNAME=	openapi-spec-validator-0.3.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	textproc www python
MASTER_SITES=	${MASTER_SITE_PYPI:=o/openapi-spec-validator/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/p1c2u/openapi-spec-validator
COMMENT=	OpenAPI 2.0 (aka Swagger) and OpenAPI 3.0 spec validator
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-jsonschema-[0-9]*:../../textproc/py-jsonschema
DEPENDS+=	${PYPKGPREFIX}-openapi-schema-validator-[0-9]*:../../textproc/py-openapi-schema-validator
DEPENDS+=	${PYPKGPREFIX}-yaml-[0-9]*:../../textproc/py-yaml
DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six
TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov-[0-9]*:../../devel/py-test-cov
TEST_DEPENDS+=	${PYPKGPREFIX}-test-flake8-[0-9]*:../../devel/py-test-flake8

USE_LANGUAGES=	# none

USE_PKG_RESOURCES=	yes

TEST_ENV+=	PYTHONPATH=${WRKSRC}/build/lib

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
