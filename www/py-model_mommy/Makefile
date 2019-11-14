# $NetBSD: Makefile,v 1.8 2019/11/14 18:30:10 adam Exp $

DISTNAME=	model_mommy-2.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=m/model_mommy/}

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	https://github.com/vandersonmota/model_mommy
COMMENT=	Smart object creation facility for Django
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-django>=1.8.0:../../www/py-django
DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
