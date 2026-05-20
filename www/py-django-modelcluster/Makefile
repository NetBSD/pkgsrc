# $NetBSD: Makefile,v 1.12 2026/05/20 09:58:11 adam Exp $

DISTNAME=	django_modelcluster-6.5
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
