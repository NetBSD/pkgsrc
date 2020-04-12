# $NetBSD: Makefile,v 1.51 2020/04/12 11:19:48 adam Exp $

DISTNAME=	docutils-0.16
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/docutils/}

MAINTAINER=	darcy@NetBSD.org
HOMEPAGE=	https://docutils.sourceforge.io/
COMMENT=	Python tool to generate documents
LICENSE=	public-domain AND 2-clause-bsd

DEPENDS+=	${PYPKGPREFIX}-expat>=0:../../textproc/py-expat
DEPENDS+=	${PYPKGPREFIX}-roman>=1.4:../../math/py-roman

USE_LANGUAGES=	# none

REPLACE_PYTHON+=	docutils/utils/code_analyzer.py
REPLACE_PYTHON+=	docutils/utils/error_reporting.py
REPLACE_PYTHON+=	docutils/utils/math/latex2mathml.py
REPLACE_PYTHON+=	docutils/utils/math/math2html.py
REPLACE_PYTHON+=	docutils/utils/punctuation_chars.py
REPLACE_PYTHON+=	docutils/utils/smartquotes.py
REPLACE_PYTHON+=	docutils/writers/xetex/__init__.py

post-install:
.for bin in rst2html rst2html4 rst2html5 rst2latex rst2man rst2odt \
	rst2odt_prepstyles rst2pseudoxml rst2s5 rst2xetex rst2xml rstpep2html
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} ${bin}.py ${bin}-${PYVERSSUFFIX} || ${TRUE}
.endfor

do-test:
	cd ${WRKSRC} && ${PYTHONBIN} test/alltests.py

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
