# $NetBSD: Makefile,v 1.8 2025/10/31 10:53:33 adam Exp $

DISTNAME=	django_localflavor-5.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/django-localflavor/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://django-localflavor.readthedocs.io/en/latest/
COMMENT=	L18N support for Django
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-django>=4.2:../../www/py-django
DEPENDS+=	${PYPKGPREFIX}-stdnum>=1.6:../../misc/py-stdnum

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
