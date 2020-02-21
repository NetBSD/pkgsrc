# $NetBSD: Makefile,v 1.6 2020/02/21 06:35:53 adam Exp $

DISTNAME=	xmlschema-1.1.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=x/xmlschema/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/brunato/xmlschema
COMMENT=	XML Schema validator and decoder
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-elementpath>=1.4.0:../../textproc/py-elementpath

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27	# py-elementpath

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
