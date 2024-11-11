# $NetBSD: Makefile,v 1.22 2024/11/11 07:29:05 wiz Exp $

DISTNAME=	markupsafe-3.0.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=M/MarkupSafe/}

MAINTAINER=	kleink@NetBSD.org
HOMEPAGE=	https://www.palletsprojects.com/p/markupsafe/
COMMENT=	Implements a unicode subclass that supports HTML strings
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools

WHEEL_NAME=	MarkupSafe-${PKGVERSION_NOREV}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
