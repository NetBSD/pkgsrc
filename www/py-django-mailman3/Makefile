# $NetBSD: Makefile,v 1.6 2024/09/26 07:41:31 wiz Exp $

DISTNAME=	django_mailman3-1.3.15
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
PKGREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/django-mailman3/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://gitlab.com/mailman/django-mailman3
COMMENT=	Django library for Mailman UIs
LICENSE=	gnu-gpl-v3

TOOL_DEPENDS+=	${PYPKGPREFIX}-pdm_backend-[0-9]*:../../devel/py-pdm_backend
DEPENDS+=	${PYPKGPREFIX}-django>=4.2:../../www/py-django
DEPENDS+=	${PYPKGPREFIX}-django-allauth>=0.63:../../www/py-django-allauth
DEPENDS+=	${PYPKGPREFIX}-django-gravatar2>=1.0.6:../../www/py-django-gravatar2
DEPENDS+=	${PYPKGPREFIX}-mailmanclient>=3.3.3:../../mail/py-mailmanclient
TEST_DEPENDS+=	${PYPKGPREFIX}-test-django-[0-9]*:../../www/py-test-django

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	38

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
