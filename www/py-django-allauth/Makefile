# $NetBSD: Makefile,v 1.24 2025/12/10 17:49:29 adam Exp $

DISTNAME=	django_allauth-65.13.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/django-allauth/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/pennersr/django-allauth
COMMENT=	Authentication, registration, account mgmt and 3rd party account auth
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-asgiref>=3.8.1:../../www/py-asgiref
DEPENDS+=	${PYPKGPREFIX}-django>=4.2.16:../../www/py-django
# openid
DEPENDS+=	${PYPKGPREFIX}-openid>=3.0.8:../../security/py-openid
# socialaccount
DEPENDS+=	${PYPKGPREFIX}-JWT>=2.0:../../textproc/py-JWT
DEPENDS+=	${PYPKGPREFIX}-oauthlib>=3.3.0:../../security/py-oauthlib
DEPENDS+=	${PYPKGPREFIX}-requests>=2.0.0:../../devel/py-requests

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
