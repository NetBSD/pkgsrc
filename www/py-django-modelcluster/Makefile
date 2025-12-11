# $NetBSD: Makefile,v 1.11 2025/12/11 10:40:05 adam Exp $

DISTNAME=	django_modelcluster-6.4.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/django-modelcluster/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/wagtail/django-modelcluster
COMMENT=	Django extension for offline model instances
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-django>=4.2:../../www/py-django4
# taggit
DEPENDS+=	${PYPKGPREFIX}-django-taggit>=3.1:../../www/py-django-taggit

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
