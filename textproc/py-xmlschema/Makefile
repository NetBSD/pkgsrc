# $NetBSD: Makefile,v 1.4 2020/01/08 21:34:38 adam Exp $

DISTNAME=	xmlschema-1.0.18
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=x/xmlschema/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/brunato/xmlschema
COMMENT=	XML Schema validator and decoder
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-elementpath>=1.3.0:../../textproc/py-elementpath

USE_LANGUAGES=	# none

REPLACE_PYTHON+=	xmlschema/tests/check_etree_import.py
REPLACE_PYTHON+=	xmlschema/tests/check_memory.py

PYTHON_VERSIONS_INCOMPATIBLE=	27	# py-elementpath

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
