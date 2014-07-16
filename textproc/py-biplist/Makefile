# $NetBSD: Makefile,v 1.2 2014/07/16 23:21:51 rodent Exp $

DISTNAME=	biplist-0.7
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	python textproc
MASTER_SITES=	https://pypi.python.org/packages/source/b/biplist/

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	https://bitbucket.org/wooster/biplist
COMMENT=	Library for reading/writing binary plists
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
