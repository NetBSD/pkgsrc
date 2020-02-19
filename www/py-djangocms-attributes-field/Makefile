# $NetBSD: Makefile,v 1.4 2020/02/19 09:52:38 adam Exp $

DISTNAME=	djangocms-attributes-field-1.2.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/djangocms-attributes-field/}

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	https://github.com/divio/djangocms-attributes-field
COMMENT=	Implementation of JSONField for arbitrary HTML element attributes
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-django-cms>=3.4.5:../../www/py-django-cms

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
