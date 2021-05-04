# $NetBSD: Makefile,v 1.10 2021/05/04 08:33:14 fcambus Exp $

DISTNAME=	prettytable-2.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/prettytable/}

MAINTAINER=	fcambus@NetBSD.org
HOMEPAGE=	https://pypi.org/project/prettytable/
COMMENT=	Display tabular data in a visually appealing ASCII table format
LICENSE=	modified-bsd

USE_LANGUAGES=	# none

DEPENDS+=	${PYPKGPREFIX}-wcwidth-[0-9]*:../../devel/py-wcwidth

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
