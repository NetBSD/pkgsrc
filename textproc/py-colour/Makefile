# $NetBSD: Makefile,v 1.5 2017/07/30 22:32:23 wiz Exp $

DISTNAME=	colour-0.1.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	python textproc
MASTER_SITES=	${MASTER_SITE_PYPI:=c/colour/}

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	https://github.com/vaab/colour
COMMENT=	Converts and manipulates various color representation
LICENSE=	2-clause-bsd

DEPENDS+=	${PYPKGPREFIX}-d2to1-[0-9]*:../../devel/py-d2to1

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
