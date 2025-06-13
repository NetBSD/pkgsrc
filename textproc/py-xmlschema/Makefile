# $NetBSD: Makefile,v 1.66 2025/06/13 07:14:18 adam Exp $

DISTNAME=	xmlschema-4.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=x/xmlschema/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/brunato/xmlschema
COMMENT=	XML Schema validator and decoder
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-elementpath>=5.0.1:../../textproc/py-elementpath

USE_LANGUAGES=	# none

post-install:
.for bin in xmlschema-json2xml xmlschema-validate xmlschema-xml2json
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} ${bin} ${bin}-${PYVERSSUFFIX} || ${TRUE}
.endfor

.include "../../lang/python/batteries-included.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
