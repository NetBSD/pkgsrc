# $NetBSD: Makefile,v 1.42 2014/01/25 10:30:24 wiz Exp $

DISTNAME=	docutils-0.11
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

.include "../../lang/python/application.mk"
.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
