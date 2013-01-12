# $NetBSD: Makefile,v 1.2 2013/01/12 12:33:11 ryoon Exp $
#

DISTNAME=	filebrowser-safe-0.2.13
PKGNAME=	${PYPKGPREFIX}-django-mezzanine-${DISTNAME:S/-safe//}
PKGREVISION=	1
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_LOCAL}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://github.com/stephenmcd/filebrowser-safe/
COMMENT=	django-filebrowser for Mezzanine CMS
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-django-[0-9]*:../../www/py-django

USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		# none

EGG_NAME=	${DISTNAME:S/-/_/}

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
