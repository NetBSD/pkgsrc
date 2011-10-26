# $NetBSD: Makefile,v 1.33 2011/10/26 19:01:18 gls Exp $

DISTNAME=	docutils-0.8.1
PKGREVISION=	1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=docutils/}

MAINTAINER=	darcy@NetBSD.org
HOMEPAGE=	http://docutils.sourceforge.net/
COMMENT=	Python tool to generate documents
LICENSE=	public-domain AND 2-clause-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	${PYPKGPREFIX}-roman>=1.4:../../math/py-roman

SUBST_CLASSES+=		env
SUBST_SED.env=		-e "s,\#! */usr/bin/env  *python[0-9.]*,\#!${PYTHONBIN},"
SUBST_MESSAGE.env=	Fixing path to python.
SUBST_STAGE.env=	post-patch
SUBST_FILES.env=	docutils/_string_template_compat.py
SUBST_FILES.env+=	docutils/error_reporting.py
SUBST_FILES.env+=	docutils/math/latex2mathml.py
SUBST_FILES.env+=	docutils/math/math2html.py
SUBST_FILES.env+=	docutils/writers/xetex/__init__.py

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
