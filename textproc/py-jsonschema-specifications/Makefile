# $NetBSD: Makefile,v 1.6 2025/05/26 05:14:53 adam Exp $

DISTNAME=	jsonschema_specifications-2025.4.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=j/jsonschema-specifications/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/python-jsonschema/jsonschema-specifications
COMMENT=	JSON Schema meta-schemas and vocabularies
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatch-vcs-[0-9]*:../../devel/py-hatch-vcs
TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling>=1.27.0:../../devel/py-hatchling
DEPENDS+=	${PYPKGPREFIX}-referencing>=0.31.0:../../textproc/py-referencing

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
