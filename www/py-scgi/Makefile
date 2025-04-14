# $NetBSD: Makefile,v 1.22 2025/04/14 20:28:02 adam Exp $

DISTNAME=	scgi-2.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/scgi/}

MAINTAINER=	manu@NetBSD.org
HOMEPAGE=	https://python.ca/scgi/
COMMENT=	Simple Common Gateway Interface
LICENSE=	cnri-license

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
