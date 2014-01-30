# $NetBSD: Makefile,v 1.1 2014/01/30 03:36:35 rodent Exp $

DISTNAME=	GooCalendar-0.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	python time
MASTER_SITES=	http://goocalendar.googlecode.com/files/

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	http://code.google.com/p/goocalendar/
COMMENT=	Calendar widget using GooCanvas
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCLUDE_3X=	no

DEPENDS+=	${PYPKGPREFIX}-goocanvas-[0-9]*:../../graphics/py-goocanvas
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
