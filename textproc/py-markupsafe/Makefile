# $NetBSD: Makefile,v 1.19 2024/02/06 21:47:09 adam Exp $

DISTNAME=	MarkupSafe-2.1.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=M/MarkupSafe/}

MAINTAINER=	kleink@NetBSD.org
HOMEPAGE=	https://www.palletsprojects.com/p/markupsafe/
COMMENT=	Implements a unicode subclass that supports HTML strings
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
