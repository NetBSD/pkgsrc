# $NetBSD: Makefile,v 1.11 2022/01/04 20:55:35 wiz Exp $

DISTNAME=	SPARQLWrapper-1.8.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
PKGREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=S/SPARQLWrapper/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://rdflib.github.io/sparqlwrapper/
COMMENT=	SPARQL endpoint interface to Python
LICENSE=	w3c

DEPENDS+=	${PYPKGPREFIX}-rdflib>=4.0:../../textproc/py-rdflib

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27	# py-networkx via py-rdflib

post-extract:
	cd ${WRKSRC} && 2to3-${PYVERSSUFFIX} -w --no-diffs SPARQLWrapper

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
