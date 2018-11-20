# $NetBSD: Makefile,v 1.1 2018/11/20 18:38:34 adam Exp $

DISTNAME=	djangocms-attributes-field-0.4.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/djangocms-attributes-field/}

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	https://github.com/divio/djangocms-attributes-field
COMMENT=	Implementation of JSONField for arbitrary HTML element attributes
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-django>=1.11:../../www/py-django

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
