# $NetBSD: Makefile,v 1.3 2016/06/08 17:43:49 wiz Exp $

DISTNAME=	djangocms-style-1.7.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/djangocms-style/}

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	https://github.com/divio/djangocms-style/
COMMENT=	Plugin for django CMS to add CSS classes to other plugins
LICENSE=	modified-bsd

USE_LANGUAGES=		# empty

DEPENDS+=	${PYPKGPREFIX}-django-cms-[0-9]*:../../www/py-django-cms

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
