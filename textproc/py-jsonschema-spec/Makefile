# $NetBSD: Makefile,v 1.1 2022/10/26 12:49:54 adam Exp $

DISTNAME=	jsonschema-spec-0.1.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=j/jsonschema-spec/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/p1c2u/jsonschema-spec
COMMENT=	JSONSchema Spec with object-oriented paths
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-jsonschema>=4.0.0:../../textproc/py-jsonschema
DEPENDS+=	${PYPKGPREFIX}-pathable>=0.4.1:../../devel/py-pathable
DEPENDS+=	${PYPKGPREFIX}-typing-extensions>=4.3.0:../../devel/py-typing-extensions
DEPENDS+=	${PYPKGPREFIX}-yaml>=5.1:../../textproc/py-yaml

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
