# $NetBSD: Makefile,v 1.9 2023/12/07 17:57:26 adam Exp $

DISTNAME=	djangocms-style-3.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/djangocms-style/}

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	https://github.com/django-cms/djangocms-style
COMMENT=	Plugin for django CMS to add CSS classes to other plugins
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-django-cms>=3.7:../../www/py-django-cms
DEPENDS+=	${PYPKGPREFIX}-djangocms-attributes-field>=1.0:../../www/py-djangocms-attributes-field

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
