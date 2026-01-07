# $NetBSD: Makefile,v 1.68 2026/01/07 18:43:40 adam Exp $

DISTNAME=	xmlschema-4.3.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=x/xmlschema/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/brunato/xmlschema
COMMENT=	XML Schema validator and decoder
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-elementpath>=5.1.0:../../textproc/py-elementpath

USE_LANGUAGES=	# none

post-install:
.for bin in xmlschema-json2xml xmlschema-validate xmlschema-xml2json
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} ${bin} ${bin}-${PYVERSSUFFIX} || ${TRUE}
.endfor

.include "../../lang/python/batteries-included.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
