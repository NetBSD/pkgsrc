# $NetBSD: Makefile,v 1.18 2017/12/21 07:33:44 adam Exp $

DISTNAME=	djangorestframework-3.7.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/djangorestframework/}

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://django-rest-framework.org/
COMMENT=	Lightweight REST framework for Django
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-django-[0-9]*:../../www/py-django

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
