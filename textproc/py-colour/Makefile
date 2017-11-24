# $NetBSD: Makefile,v 1.8 2017/11/24 12:46:42 adam Exp $

DISTNAME=	colour-0.1.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/colour/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/vaab/colour
COMMENT=	Converts and manipulates various color representation
LICENSE=	2-clause-bsd

DEPENDS+=	${PYPKGPREFIX}-d2to1-[0-9]*:../../devel/py-d2to1

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
