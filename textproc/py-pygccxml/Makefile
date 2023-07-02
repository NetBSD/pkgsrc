# $NetBSD: Makefile,v 1.3 2023/07/02 12:39:23 wiz Exp $

DISTNAME=	pygccxml-2.2.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_GITHUB:=CastXML/}
GITHUB_PROJECT=	pygccxml
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/CastXML/pygccxml
COMMENT=	Python package for easy C++ declarations navigation
LICENSE=	boost-license

TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
