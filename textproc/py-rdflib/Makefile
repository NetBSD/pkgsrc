# $NetBSD: Makefile,v 1.23 2026/10/16 18:31:41 adam Exp $

DISTNAME=	rdflib-7.6.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=r/rdflib/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/RDFLib/rdflib
COMMENT=	Python library for working with RDF
LICENSE=	2-clause-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-poetry-core>=2.2.1:../../devel/py-poetry-core
DEPENDS+=	${PYPKGPREFIX}-pyparsing>=2.1.0:../../devel/py-pyparsing
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov>=4.0.0:../../devel/py-test-cov

USE_LANGUAGES=	# none

REPLACE_PYTHON+=	rdflib/extras/describer.py
REPLACE_PYTHON+=	rdflib/extras/infixowl.py
REPLACE_PYTHON+=	rdflib/plugins/parsers/notation3.py
REPLACE_PYTHON+=	rdflib/plugins/parsers/ntriples.py
REPLACE_PYTHON+=	rdflib/plugins/parsers/pyRdfa/extras/httpheader.py
REPLACE_PYTHON+=	rdflib/plugins/parsers/structureddata.py
REPLACE_PYTHON+=	rdflib/tools/rdfpipe.py

post-install:
.for bin in csv2rdf rdf2dot rdfgraphisomorphism rdfpipe rdfs2dot sparqlquery sq
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} ${bin} ${bin}-${PYVERSSUFFIX} || ${TRUE}
.endfor

.include "../../lang/python/application.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
