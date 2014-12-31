# $NetBSD: Makefile,v 1.2 2014/12/31 13:57:31 wiz Exp $

DISTNAME=	djangocms-teaser-0.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	http://pypi.python.org/packages/source/d/djangocms-teaser/

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	https://github.com/divio/djangocms-teaser/
COMMENT=	Flash plugin for django CMS
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-django-cms-[0-9]*:../../www/py-django-cms

USE_LANGUAGES=		# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
