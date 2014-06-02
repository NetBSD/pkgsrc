# $NetBSD: Makefile,v 1.1 2014/06/02 03:49:42 rodent Exp $

DISTNAME=	biplist-0.6
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	python textproc
MASTER_SITES=	https://pypi.python.org/packages/source/b/biplist/

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	https://pypi.python.org/packages/source/b/biplist/
COMMENT=	Library for reading/writing binary plists
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
