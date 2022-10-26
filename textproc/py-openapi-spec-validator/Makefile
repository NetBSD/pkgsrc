# $NetBSD: Makefile,v 1.5 2022/10/26 12:52:34 adam Exp $

DISTNAME=	openapi-spec-validator-0.5.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc www python
MASTER_SITES=	${MASTER_SITE_PYPI:=o/openapi-spec-validator/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/p1c2u/openapi-spec-validator
COMMENT=	OpenAPI 2.0 (aka Swagger) and OpenAPI 3.0 spec validator
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-importlib-resources>=5.8.0:../../devel/py-importlib-resources
DEPENDS+=	${PYPKGPREFIX}-jsonschema>=4.0.0:../../textproc/py-jsonschema
DEPENDS+=	${PYPKGPREFIX}-jsonschema-spec>=0.1.1:../../textproc/py-jsonschema-spec
DEPENDS+=	${PYPKGPREFIX}-lazy-object-proxy>=1.7.1:../../devel/py-lazy-object-proxy
DEPENDS+=	${PYPKGPREFIX}-openapi-schema-validator>=0.3.2:../../textproc/py-openapi-schema-validator
DEPENDS+=	${PYPKGPREFIX}-yaml>=5.1:../../textproc/py-yaml

USE_LANGUAGES=	# none

USE_PKG_RESOURCES=	yes

PYTHON_VERSIONS_INCOMPATIBLE=	27

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} openapi-spec-validator openapi-spec-validator-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
