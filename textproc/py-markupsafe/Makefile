# $NetBSD: Makefile,v 1.20 2024/10/09 13:04:10 wiz Exp $

DISTNAME=	markupsafe-3.0.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=M/MarkupSafe/}

MAINTAINER=	kleink@NetBSD.org
HOMEPAGE=	https://www.palletsprojects.com/p/markupsafe/
COMMENT=	Implements a unicode subclass that supports HTML strings
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel

WHEEL_NAME=	MarkupSafe-${PKGVERSION_NOREV}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
