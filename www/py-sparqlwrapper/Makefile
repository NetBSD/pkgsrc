# $NetBSD: Makefile,v 1.8 2021/05/04 14:21:30 nia Exp $

DISTNAME=	SPARQLWrapper-1.8.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=S/SPARQLWrapper/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://rdflib.github.io/sparqlwrapper/
COMMENT=	SPARQL endpoint interface to Python
LICENSE=	w3c

DEPENDS+=	${PYPKGPREFIX}-rdflib>=4.0:../../textproc/py-rdflib

PYTHON_VERSIONS_INCOMPATIBLE=	27	# py-networkx via py-rdflib

# 'ascii' codec can't decode byte 0xc3 in position 390:
# ordinal not in range(128)
PYTHON_VERSIONS_INCOMPATIBLE+=	36

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
