# $NetBSD: Makefile,v 1.6 2017/01/01 14:44:02 wiz Exp $

DISTNAME=	GooCalendar-0.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	python time
MASTER_SITES=	http://goocalendar.googlecode.com/files/

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	http://code.google.com/p/goocalendar/
COMMENT=	Calendar widget using GooCanvas
LICENSE=	gnu-gpl-v2

DEPENDS+=	${PYPKGPREFIX}-goocanvas-[0-9]*:../../graphics/py-goocanvas

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 # py-gtk2 via py-goocanvas

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
