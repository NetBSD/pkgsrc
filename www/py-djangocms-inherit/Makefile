# $NetBSD: Makefile,v 1.3 2016/03/06 14:33:23 adam Exp $

DISTNAME=	djangocms-inherit-0.1.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	http://pypi.python.org/packages/source/d/djangocms-inherit/

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	https://github.com/divio/djangocms-inherit/
COMMENT=	Flash plugin for django CMS
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-django-cms-[0-9]*:../../www/py-django-cms

USE_LANGUAGES=		# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
