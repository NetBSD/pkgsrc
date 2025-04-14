# $NetBSD: Makefile,v 1.6 2025/04/14 12:50:20 adam Exp $

DISTNAME=	pygccxml-2.2.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_GITHUB:=CastXML/}
GITHUB_PROJECT=	pygccxml
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/CastXML/pygccxml
COMMENT=	Python package for easy C++ declarations navigation
LICENSE=	boost-license

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
