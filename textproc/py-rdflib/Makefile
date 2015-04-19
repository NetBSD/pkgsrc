# $NetBSD: Makefile,v 1.1 2015/04/19 22:03:29 rodent Exp $

DISTNAME=	rdflib-4.2.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	python textproc
MASTER_SITES=	https://pypi.python.org/packages/source/r/rdflib/

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	${MASTER_SITE_GITHUB:=RDFLib/rdflib/}
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

PLIST_SUBST+=		PYVERSSUFFIX=${PYVERSSUFFIX}

post-install:
	${MV} ${DESTDIR}${PREFIX}/bin/csv2rdf \
		${DESTDIR}${PREFIX}/bin/csv2rdf${PYVERSSUFFIX}
	${MV} ${DESTDIR}${PREFIX}/bin/rdf2dot \
		${DESTDIR}${PREFIX}/bin/rdf2dot${PYVERSSUFFIX}
	${MV} ${DESTDIR}${PREFIX}/bin/rdfgraphisomorphism \
		${DESTDIR}${PREFIX}/bin/rdfgraphisomorphism${PYVERSSUFFIX}
	${MV} ${DESTDIR}${PREFIX}/bin/rdfpipe \
		${DESTDIR}${PREFIX}/bin/rdfpipe${PYVERSSUFFIX}
	${MV} ${DESTDIR}${PREFIX}/bin/rdfs2dot \
		${DESTDIR}${PREFIX}/bin/rdfs2dot${PYVERSSUFFIX}

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
