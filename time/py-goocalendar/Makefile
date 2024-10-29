# $NetBSD: Makefile,v 1.29 2024/10/29 20:06:46 adam Exp $

DISTNAME=	GooCalendar-0.8.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	time python
MASTER_SITES=	${MASTER_SITE_PYPI:=G/GooCalendar/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://goocalendar.readthedocs.io/
COMMENT=	Calendar widget using GooCanvas
LICENSE=	gnu-gpl-v2

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-gobject3>=3.20:../../devel/py-gobject3

USE_LANGUAGES=	# none

.include "../../graphics/goocanvas2/buildlink3.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
