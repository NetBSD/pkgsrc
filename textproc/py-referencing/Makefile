# $NetBSD: Makefile,v 1.9 2024/03/17 12:52:13 adam Exp $

DISTNAME=	referencing-0.34.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=r/referencing/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/python-jsonschema/referencing
COMMENT=	JSON Referencing in Python
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling-[0-9]*:../../devel/py-hatchling
TOOL_DEPENDS+=	${PYPKGPREFIX}-hatch-vcs-[0-9]*:../../devel/py-hatch-vcs
DEPENDS+=	${PYPKGPREFIX}-attrs>=22.2.0:../../devel/py-attrs
DEPENDS+=	${PYPKGPREFIX}-rpds-py>=0.7.0:../../devel/py-rpds-py

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
