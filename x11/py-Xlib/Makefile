# $NetBSD: Makefile,v 1.18 2022/01/13 19:31:25 wiz Exp $

DISTNAME=	python-xlib-0.29
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/python-x/X/}
PKGREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GITHUB:=python-xlib/}
GITHUB_PROJECT=	python-xlib
GITHUB_RELEASE=	${PKGVERSION_NOREV}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	prlw1@cam.ac.uk
HOMEPAGE=	https://github.com/python-xlib/python-xlib/
COMMENT=	XLib in pure Python
LICENSE=	gnu-lgpl-v2.1

USE_LANGUAGES=	# none

DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six

PYTHON_VERSIONED_DEPENDENCIES=	setuptools_scm

.include "../../lang/python/egg.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
