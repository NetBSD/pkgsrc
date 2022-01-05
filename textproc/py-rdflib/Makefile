# $NetBSD: Makefile,v 1.10 2022/01/05 15:41:26 wiz Exp $

DISTNAME=	rdflib-5.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=r/rdflib/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/RDFLib/rdflib
COMMENT=	Python library for working with RDF
LICENSE=	2-clause-bsd

DEPENDS+=	${PYPKGPREFIX}-isodate-[0-9]*:../../time/py-isodate
DEPENDS+=	${PYPKGPREFIX}-pyparsing-[0-9]*:../../devel/py-pyparsing
DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six
TEST_DEPENDS+=	${PYPKGPREFIX}-html5lib-[0-9]*:../../textproc/py-html5lib
TEST_DEPENDS+=	${PYPKGPREFIX}-networkx-[0-9]*:../../math/py-networkx

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27	# py-networkx

USE_PKG_RESOURCES=	yes

REPLACE_PYTHON+=	rdflib/extras/describer.py rdflib/extras/infixowl.py
REPLACE_PYTHON+=	rdflib/plugins/parsers/notation3.py
REPLACE_PYTHON+=	rdflib/plugins/parsers/ntriples.py
REPLACE_PYTHON+=	rdflib/plugins/parsers/pyRdfa/extras/httpheader.py
REPLACE_PYTHON+=	rdflib/plugins/parsers/structureddata.py
REPLACE_PYTHON+=	rdflib/tools/rdfpipe.py

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} csv2rdf csv2rdf-${PYVERSSUFFIX} && \
	${MV} rdf2dot rdf2dot-${PYVERSSUFFIX} && \
	${MV} rdfgraphisomorphism rdfgraphisomorphism-${PYVERSSUFFIX} && \
	${MV} rdfpipe rdfpipe-${PYVERSSUFFIX} && \
	${MV} rdfs2dot rdfs2dot-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
