# $NetBSD: Makefile,v 1.4 2022/04/09 07:42:19 adam Exp $

DISTNAME=	openapi-spec-validator-0.4.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc www python
MASTER_SITES=	${MASTER_SITE_PYPI:=o/openapi-spec-validator/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/p1c2u/openapi-spec-validator
COMMENT=	OpenAPI 2.0 (aka Swagger) and OpenAPI 3.0 spec validator
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-jsonschema>=3.2.0:../../textproc/py-jsonschema
DEPENDS+=	${PYPKGPREFIX}-openapi-schema-validator>=0.2.0:../../textproc/py-openapi-schema-validator
DEPENDS+=	${PYPKGPREFIX}-yaml>=5.1:../../textproc/py-yaml

USE_LANGUAGES=	# none

USE_PKG_RESOURCES=	yes

PYTHON_VERSIONS_INCOMPATIBLE=	27

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} openapi-spec-validator openapi-spec-validator-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
