# $NetBSD: Makefile,v 1.17 2025/04/14 20:28:02 adam Exp $

DISTNAME=	SPARQLWrapper-2.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
PKGREVISION=	2
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=S/SPARQLWrapper/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://rdflib.github.io/sparqlwrapper/
COMMENT=	SPARQL endpoint interface to Python
LICENSE=	w3c

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-rdflib>=6.1.1:../../textproc/py-rdflib

USE_LANGUAGES=	# none

WHEEL_NAME=	${DISTNAME:tl}

PYTHON_VERSIONS_INCOMPATIBLE=	39

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} rqw rqw-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
