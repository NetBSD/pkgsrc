# $NetBSD: Makefile,v 1.6 2011/08/22 12:18:18 wiz Exp $

DISTNAME=	python-xlib-0.14
PKGNAME=	${PYPKGPREFIX}-Xlib-0.14
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=python-xlib/}

MAINTAINER=	ccatrian@eml.cc
HOMEPAGE=	http://python-xlib.sourceforge.net/
COMMENT=	Functional X client library for Python
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

PYTHON_VERSIONS_INCOMPATIBLE=	24 25

EGG_NAME=	python_xlib-0.12

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
