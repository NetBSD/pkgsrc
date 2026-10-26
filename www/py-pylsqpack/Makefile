# $NetBSD: Makefile,v 1.8 2026/10/26 06:30:42 wiz Exp $

DISTNAME=	pylsqpack-0.3.24
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pylsqpack/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/aiortc/pylsqpack
COMMENT=	Python wrapper for the ls-qpack QPACK library
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=84.2:../../devel/py-setuptools

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
