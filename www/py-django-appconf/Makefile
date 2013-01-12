# $NetBSD: Makefile,v 1.3 2013/01/12 19:59:19 ryoon Exp $
#

DISTNAME=	django-appconf-0.5
PKGREVISION=	1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www
MASTER_SITES=	-https://github.com/jezdez/django-appconf/archive/v0.5.tar.gz

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://github.com/jezdez/django-appconf/
COMMENT=	Helper class for handling configuration defaults of Django
LICENSE=	modified-bsd

DIST_SUBDIR=	${PKGNAME_NOREV}

# Force using "curl" for fetching the distribution file. It is only available
# over HTTPS and "curl" is the only fetch program which always supports HTTPS.
FETCH_USING=	curl

USE_LANGUAGES=	# none

EGG_NAME=	${DISTNAME:S/-/_/}

DEPENDS+=	${PYPKGPREFIX}-django-[0-9]*:../../www/py-django

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
