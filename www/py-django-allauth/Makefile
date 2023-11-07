# $NetBSD: Makefile,v 1.4 2023/11/07 22:38:09 wiz Exp $

DISTNAME=	django-allauth-0.55.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/django-allauth/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/pennersr/django-allauth/
COMMENT=	Authentication, registration, account mgmt and 3rd party account auth
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-JWT>=1.7:../../textproc/py-JWT
DEPENDS+=	${PYPKGPREFIX}-django>=3.2:../../www/py-django3
DEPENDS+=	${PYPKGPREFIX}-openid>=3.0.8:../../security/py-openid
DEPENDS+=	${PYPKGPREFIX}-requests>=2.0.0:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-requests-oauthlib>=0.3.0:../../security/py-requests-oauthlib

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27 38

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
