# $NetBSD: Makefile,v 1.26 2026/09/12 17:19:04 wiz Exp $

DISTNAME=	django_allauth-65.19.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
PKGREVISION=	1
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
