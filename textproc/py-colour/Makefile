# $NetBSD: Makefile,v 1.3 2015/04/05 23:20:58 rodent Exp $

DISTNAME=	colour-0.1.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	python textproc
MASTER_SITES=	https://pypi.python.org/packages/source/c/colour/

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	http://github.com/vaab/colour
COMMENT=	Converts and manipulates various color representation
LICENSE=	2-clause-bsd

DEPENDS+=	${PYPKGPREFIX}-d2to1-[0-9]*:../../devel/py-d2to1

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
