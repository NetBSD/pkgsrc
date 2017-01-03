# $NetBSD: Makefile,v 1.5 2017/01/03 13:23:04 jperkin Exp $

DISTNAME=	rdflib-4.2.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	python textproc
MASTER_SITES=	${MASTER_SITE_PYPI:=r/rdflib/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/RDFLib/rdflib/
COMMENT=	Python library for working with RDF
LICENSE=	2-clause-bsd

DEPENDS+=	${PYPKGPREFIX}-isodate-[0-9]*:../../time/py-isodate
DEPENDS+=	${PYPKGPREFIX}-pyparsing-[0-9]*:../../devel/py-pyparsing
DEPENDS+=	${PYPKGPREFIX}-html5lib-[0-9]*:../../textproc/py-html5lib

USE_LANGUAGES=	# none

REPLACE_PYTHON+=	rdflib/extras/describer.py rdflib/extras/infixowl.py
REPLACE_PYTHON+=	rdflib/plugins/parsers/notation3.py
REPLACE_PYTHON+=	rdflib/plugins/parsers/ntriples.py
REPLACE_PYTHON+=	rdflib/plugins/parsers/pyRdfa/extras/httpheader.py
REPLACE_PYTHON+=	rdflib/plugins/parsers/structureddata.py
REPLACE_PYTHON+=	rdflib/tools/rdfpipe.py

post-install:
	${MV} ${DESTDIR}${PREFIX}/bin/csv2rdf \
		${DESTDIR}${PREFIX}/bin/csv2rdf${PYVERSSUFFIX} || ${TRUE}
	${MV} ${DESTDIR}${PREFIX}/bin/rdf2dot \
		${DESTDIR}${PREFIX}/bin/rdf2dot${PYVERSSUFFIX} || ${TRUE}
	${MV} ${DESTDIR}${PREFIX}/bin/rdfgraphisomorphism \
		${DESTDIR}${PREFIX}/bin/rdfgraphisomorphism${PYVERSSUFFIX} || ${TRUE}
	${MV} ${DESTDIR}${PREFIX}/bin/rdfpipe \
		${DESTDIR}${PREFIX}/bin/rdfpipe${PYVERSSUFFIX} || ${TRUE}
	${MV} ${DESTDIR}${PREFIX}/bin/rdfs2dot \
		${DESTDIR}${PREFIX}/bin/rdfs2dot${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
