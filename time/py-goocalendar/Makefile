# $NetBSD: Makefile,v 1.13 2020/01/18 23:35:38 rillig Exp $

DISTNAME=	GooCalendar-0.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	python time
MASTER_SITES=	http://goocalendar.googlecode.com/files/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://goocalendar.tryton.org/
COMMENT=	Calendar widget using GooCanvas
LICENSE=	gnu-gpl-v2

DEPENDS+=	${PYPKGPREFIX}-goocanvas-[0-9]*:../../graphics/py-goocanvas

USE_LANGUAGES=	# none

PYTHON_VERSIONS_ACCEPTED=	27 # py-gtk2 via py-goocanvas

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
