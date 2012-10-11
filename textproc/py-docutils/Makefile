# $NetBSD: Makefile,v 1.38 2012/10/11 14:46:24 drochner Exp $

DISTNAME=	docutils-0.9.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=docutils/}

MAINTAINER=	darcy@NetBSD.org
HOMEPAGE=	http://docutils.sourceforge.net/
COMMENT=	Python tool to generate documents
LICENSE=	public-domain AND 2-clause-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

PYTHON_VERSIONS_INCLUDE_3X= yes
DEPENDS+=	${PYPKGPREFIX}-roman>=1.4:../../math/py-roman
DEPENDS+=	${PYPKGPREFIX}-expat>=0:../../textproc/py-expat

USE_LANGUAGES=	#none

SUBST_CLASSES+=		env
SUBST_SED.env=		-e "s,\#! */usr/bin/env  *python[0-9.]*,\#!${PYTHONBIN},"
SUBST_MESSAGE.env=	Fixing path to python.
SUBST_STAGE.env=	post-patch
SUBST_FILES.env=	docutils/_string_template_compat.py
SUBST_FILES.env+=	docutils/error_reporting.py
SUBST_FILES.env+=	docutils/math/latex2mathml.py
SUBST_FILES.env+=	docutils/math/math2html.py
SUBST_FILES.env+=	docutils/writers/xetex/__init__.py
SUBST_FILES.env+=	docutils/utils/punctuation_chars.py

SUBST_CLASSES+=		python
SUBST_SED.python=	-e "s,\#!/usr/bin/python,\#!${PYTHONBIN},"
SUBST_MESSAGE.python=	Fixing path to python.
SUBST_STAGE.python=	post-patch
SUBST_FILES.python=	docutils/utils/code_analyzer.py

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
