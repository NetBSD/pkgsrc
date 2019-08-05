# $NetBSD: Makefile,v 1.12 2019/08/05 12:26:15 prlw1 Exp $

DISTNAME=	python-xlib-0.25
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

post-extract:
	${CHMOD} 644 ${WRKSRC}/python_xlib.egg-info/*

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
