# $NetBSD: Makefile,v 1.3 2017/09/04 18:08:30 wiz Exp $

DISTNAME=	SPARQLWrapper-1.6.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	python www
MASTER_SITES=	${MASTER_SITE_PYPI:=S/SPARQLWrapper/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://rdflib.github.io/sparqlwrapper/
COMMENT=	SPARQL endpoint interface to Python
LICENSE=	w3c

DEPENDS+=	${PYPKGPREFIX}-rdflib>=2.4.2:../../textproc/py-rdflib

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
