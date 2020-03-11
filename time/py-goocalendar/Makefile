# $NetBSD: Makefile,v 1.14 2020/03/11 19:45:46 wiz Exp $

DISTNAME=	GooCalendar-0.7.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	time python
MASTER_SITES=	${MASTER_SITE_PYPI:=G/GooCalendar/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pypi.org/project/GooCalendar/
COMMENT=	Calendar widget using GooCanvas
LICENSE=	gnu-gpl-v2

DEPENDS+=	${PYPKGPREFIX}-gobject3>=3.20:../../devel/py-gobject3

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../graphics/goocanvas2/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
