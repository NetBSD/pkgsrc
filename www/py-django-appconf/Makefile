# $NetBSD: Makefile,v 1.6 2014/12/31 13:57:30 wiz Exp $

DISTNAME=	django-appconf-0.6
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www
MASTER_SITES=	-http://nodeload.github.com/jezdez/django-appconf/tar.gz/v0.6

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://github.com/jezdez/django-appconf/
COMMENT=	Helper class for handling configuration defaults of Django
LICENSE=	modified-bsd

USE_LANGUAGES=	# none

DEPENDS+=	${PYPKGPREFIX}-django-[0-9]*:../../www/py-django

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
