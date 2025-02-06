# $NetBSD: Makefile,v 1.21 2025/02/06 13:49:19 adam Exp $

DISTNAME=	scgi-2.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/scgi/}

MAINTAINER=	manu@NetBSD.org
HOMEPAGE=	https://python.ca/scgi/
COMMENT=	Simple Common Gateway Interface
LICENSE=	cnri-license

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
