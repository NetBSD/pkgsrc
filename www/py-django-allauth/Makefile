# $NetBSD: Makefile,v 1.1 2023/06/04 02:29:21 markd Exp $

DISTNAME=	django-allauth-0.54.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/django-allauth/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/pennersr/django-allauth/
COMMENT=	Authentication, registration, account mgmt and 3rd party account auth
LICENSE=	mit

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

DEPENDS+=	${PYPKGPREFIX}-django>=3.2:../../www/py-django3
DEPENDS+=	${PYPKGPREFIX}-openid>=3.0.8:../../security/py-openid
DEPENDS+=	${PYPKGPREFIX}-requests-[0-9]*:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-requests-oauthlib>=0.3.0:../../security/py-requests-oauthlib
DEPENDS+=	${PYPKGPREFIX}-JWT>=1.7:../../textproc/py-JWT

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
