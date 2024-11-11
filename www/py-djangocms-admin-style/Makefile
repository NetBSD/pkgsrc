# $NetBSD: Makefile,v 1.25 2024/11/11 07:29:20 wiz Exp $

DISTNAME=	djangocms-admin-style-3.3.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/djangocms-admin-style/}

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	https://github.com/django-cms/djangocms-admin-style
COMMENT=	Adds pretty CSS styles for the django CMS admin interface
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-django>=3:../../www/py-django

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
