# $NetBSD: Makefile,v 1.3 2017/09/06 15:21:54 adam Exp $

DISTNAME=	model_mommy-1.4.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=m/model_mommy/}

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	https://github.com/vandersonmota/model_mommy/
COMMENT=	Smart object creation facility for Django
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-django-[0-9]*:../../www/py-django
DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six

USE_LANGUAGES=		# empty

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
