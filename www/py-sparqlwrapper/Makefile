# $NetBSD: Makefile,v 1.9 2021/05/05 09:54:42 adam Exp $

DISTNAME=	SPARQLWrapper-1.8.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=S/SPARQLWrapper/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://rdflib.github.io/sparqlwrapper/
COMMENT=	SPARQL endpoint interface to Python
LICENSE=	w3c

DEPENDS+=	${PYPKGPREFIX}-rdflib>=4.0:../../textproc/py-rdflib

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27	# py-networkx via py-rdflib

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
