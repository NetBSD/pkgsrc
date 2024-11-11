# $NetBSD: Makefile,v 1.8 2024/11/11 07:29:19 wiz Exp $

DISTNAME=	django-modelcluster-6.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/django-modelcluster/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/wagtail/django-modelcluster
COMMENT=	Django extension for offline model instances
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-django>=3.2:../../www/py-django4
DEPENDS+=	${PYPKGPREFIX}-pytz>=2022.4:../../time/py-pytz
# taggit
DEPENDS+=	${PYPKGPREFIX}-django-taggit>=3.1:../../www/py-django-taggit

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
