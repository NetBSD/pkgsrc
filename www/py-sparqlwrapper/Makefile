# $NetBSD: Makefile,v 1.1 2015/04/19 22:20:48 rodent Exp $

DISTNAME=	SPARQLWrapper-1.6.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	python www
MASTER_SITES=	https://pypi.python.org/packages/source/S/SPARQLWrapper/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://rdflib.github.io/sparqlwrapper/
COMMENT=	SPARQL endpoint interface to Python
LICENSE=	w3c

DEPENDS+=	${PYPKGPREFIX}-rdflib>=2.4.2:../../textproc/py-rdflib

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
