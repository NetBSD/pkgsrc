# $NetBSD: Makefile,v 1.70 2026/06/30 20:29:58 adam Exp $

DISTNAME=	xmlschema-4.3.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=x/xmlschema/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/brunato/xmlschema
COMMENT=	XML Schema validator and decoder
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-elementpath>=5.1.3:../../textproc/py-elementpath

USE_LANGUAGES=	# none

PY_RENAME_BINARIES=	xmlschema-json2xml xmlschema-validate xmlschema-xml2json

.include "../../lang/python/batteries-included.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
