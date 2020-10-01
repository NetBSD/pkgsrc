# $NetBSD: Makefile,v 1.15 2020/10/01 12:01:50 prlw1 Exp $

DISTNAME=	python-xlib-0.28
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/python-x/X/}
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

DEPENDS+=	${PYPKGPREFIX}-setuptools_scm-[0-9]*:../../devel/py-setuptools_scm
DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
