# $NetBSD: Makefile,v 1.15 2024/11/11 07:29:27 wiz Exp $

DISTNAME=	SPARQLWrapper-2.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=S/SPARQLWrapper/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://rdflib.github.io/sparqlwrapper/
COMMENT=	SPARQL endpoint interface to Python
LICENSE=	w3c

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-rdflib>=6.1.1:../../textproc/py-rdflib

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	39

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} rqw rqw-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
