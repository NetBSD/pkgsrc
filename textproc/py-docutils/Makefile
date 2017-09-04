# $NetBSD: Makefile,v 1.47 2017/09/04 18:05:58 adam Exp $

DISTNAME=	docutils-0.14
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=docutils/}

MAINTAINER=	darcy@NetBSD.org
HOMEPAGE=	http://docutils.sourceforge.net/
COMMENT=	Python tool to generate documents
LICENSE=	public-domain AND 2-clause-bsd

DEPENDS+=	${PYPKGPREFIX}-roman>=1.4:../../math/py-roman
DEPENDS+=	${PYPKGPREFIX}-expat>=0:../../textproc/py-expat

USE_LANGUAGES=	#none

REPLACE_PYTHON+=	docutils/utils/code_analyzer.py
REPLACE_PYTHON+=	docutils/utils/error_reporting.py
REPLACE_PYTHON+=	docutils/utils/math/latex2mathml.py
REPLACE_PYTHON+=	docutils/utils/math/math2html.py
REPLACE_PYTHON+=	docutils/utils/punctuation_chars.py
REPLACE_PYTHON+=	docutils/utils/smartquotes.py
REPLACE_PYTHON+=	docutils/writers/xetex/__init__.py

CMDS=	rst2html rst2html4 rst2html5 rst2latex rst2man rst2odt rst2odt_prepstyles
CMDS+=	rst2pseudoxml rst2s5 rst2xetex rst2xml rstpep2html

post-install:
	for f in ${CMDS}; do \
	${MV} ${DESTDIR}${PREFIX}/bin/$$f.py ${DESTDIR}${PREFIX}/bin/$$f-${PYVERSSUFFIX}.py || ${TRUE}; \
	done

.include "../../lang/python/application.mk"
.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
