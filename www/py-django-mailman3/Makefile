# $NetBSD: Makefile,v 1.2 2023/11/07 22:38:09 wiz Exp $

DISTNAME=	django-mailman3-1.3.9
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/django-mailman3/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.list.org/
COMMENT=	Django library for Mailman UIs
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-django>=3.2:../../www/py-django3
DEPENDS+=	${PYPKGPREFIX}-django-allauth-[0-9]*:../../www/py-django-allauth
DEPENDS+=	${PYPKGPREFIX}-django-gravatar2>=1.0.6:../../www/py-django-gravatar2
DEPENDS+=	${PYPKGPREFIX}-mailmanclient>=3.3.3:../../mail/py-mailmanclient
DEPENDS+=	${PYPKGPREFIX}-pytz-[0-9]*:../../time/py-pytz

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27 38

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
