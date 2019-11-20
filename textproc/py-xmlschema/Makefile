# $NetBSD: Makefile,v 1.2 2019/11/20 10:09:36 adam Exp $

DISTNAME=	xmlschema-1.0.16
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

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
