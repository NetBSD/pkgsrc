# $NetBSD: Makefile,v 1.36 2012/09/21 12:39:41 obache Exp $

DISTNAME=	docutils-0.9
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=docutils/}

MAINTAINER=	darcy@NetBSD.org
HOMEPAGE=	http://docutils.sourceforge.net/
COMMENT=	Python tool to generate documents
LICENSE=	public-domain AND 2-clause-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

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
SUBST_FILES.env+=	utils/punctuation_chars.py

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
