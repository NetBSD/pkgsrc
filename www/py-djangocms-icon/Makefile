# $NetBSD: Makefile,v 1.5 2021/01/16 09:57:53 adam Exp $

DISTNAME=	djangocms-icon-2.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/djangocms-icon/}

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	https://github.com/divio/djangocms-icon
COMMENT=	Django CMS plugin that inserts an icon (font or svg)
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-django-cms>=3.7:../../www/py-django-cms
DEPENDS+=	${PYPKGPREFIX}-djangocms-attributes-field>=1.0:../../www/py-djangocms-attributes-field

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
