# $NetBSD: Makefile,v 1.63 2023/10/23 06:37:54 wiz Exp $

DISTNAME=	docutils-0.20.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/docutils/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://docutils.sourceforge.io/
COMMENT=	Python tool to generate documents
LICENSE=	public-domain AND 2-clause-bsd

DEPENDS+=	${PYPKGPREFIX}-roman>=1.4:../../math/py-roman
DEPENDS+=	${PYPKGPREFIX}-pygments>=0:../../textproc/py-pygments

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

REPLACE_PYTHON+=	docutils/utils/code_analyzer.py
REPLACE_PYTHON+=	docutils/utils/error_reporting.py
REPLACE_PYTHON+=	docutils/utils/math/latex2mathml.py
REPLACE_PYTHON+=	docutils/utils/math/math2html.py
REPLACE_PYTHON+=	docutils/utils/punctuation_chars.py
REPLACE_PYTHON+=	docutils/utils/smartquotes.py
REPLACE_PYTHON+=	docutils/writers/xetex/__init__.py

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} docutils docutils-${PYVERSSUFFIX} || ${TRUE}
.for bin in rst2html rst2html4 rst2html5 rst2latex rst2man rst2odt \
	rst2odt_prepstyles rst2pseudoxml rst2s5 rst2xetex rst2xml rstpep2html
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} ${bin}.py ${bin}-${PYVERSSUFFIX} || ${TRUE}
.endfor

do-test:
	cd ${WRKSRC} && ${PYTHONBIN} test/alltests.py

.include "../../lang/python/batteries-included.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
