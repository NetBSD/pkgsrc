# $NetBSD: Makefile,v 1.12 2020/08/27 12:28:59 joerg Exp $

DISTNAME=	xmlschema-1.2.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=x/xmlschema/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/brunato/xmlschema
COMMENT=	XML Schema validator and decoder
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-pip-[0-9]*:../../devel/py-pip
DEPENDS+=	${PYPKGPREFIX}-elementpath>=1.4.0:../../textproc/py-elementpath
TEST_DEPENDS+=	${PYPKGPREFIX}-cElementTree-[0-9]*:../../textproc/py-cElementTree

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27	# py-elementpath

post-install:
.for bin in xmlschema-json2xml xmlschema-validate xmlschema-xml2json
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} ${bin} ${bin}-${PYVERSSUFFIX} || ${TRUE}
.endfor

do-test:
	cd ${WRKSRC} && ${PYTHONBIN} -m unittest discover -v

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
