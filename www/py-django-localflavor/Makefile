# $NetBSD: Makefile,v 1.1 2023/03/31 01:14:36 joerg Exp $

DISTNAME=	django-localflavor-3.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_PYPI:=d/django-localflavor/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://django-localflavor.readthedocs.io/en/latest/
COMMENT=	L18N support for Django
LICENSE=	modified-bsd

USE_LANGUAGES=	# none

DEPENDS+=	${PYPKGPREFIX}-django-[0-9]*:../../www/py-django
DEPENDS+=	${PYPKGPREFIX}-stdnum-[0-9]*:../../misc/py-stdnum

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
