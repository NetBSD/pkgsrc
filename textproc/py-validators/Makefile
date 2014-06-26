# $NetBSD: Makefile,v 1.2 2014/06/26 01:19:04 rodent Exp $

DISTNAME=	validators-0.6.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	python textproc
MASTER_SITES=	https://pypi.python.org/packages/source/v/validators/

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	https://github.com/kvesteri/validators
COMMENT=	Python data validation for humans
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six
DEPENDS+=	${PYPKGPREFIX}-decorator>=3.4.0:../../devel/py-decorator

USE_LANGUAGES=	# none

.include "options.mk"

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
