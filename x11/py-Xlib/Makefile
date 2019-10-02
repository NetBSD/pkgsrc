# $NetBSD: Makefile,v 1.13 2019/10/02 16:13:48 prlw1 Exp $

DISTNAME=	python-xlib-0.25
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

DEPENDS+=       ${PYPKGPREFIX}-setuptools_scm-[0-9]*:../../devel/py-setuptools_scm
DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
