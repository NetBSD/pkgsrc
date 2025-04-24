# $NetBSD: Makefile,v 1.21 2025/04/24 07:12:19 wiz Exp $

DISTNAME=	python-xlib-0.33
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

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm-[0-9]*:../../devel/py-setuptools_scm
DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six
TEST_DEPENDS+=	${PYPKGPREFIX}-mock-[0-9]*:../../devel/py-mock

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
