# $NetBSD: Makefile,v 1.1 2020/08/04 00:38:23 joerg Exp $

DISTNAME=	django-cogwheels-0.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_GITHUB:=ababic/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ababic/django-cogwheels/
COMMENT=	Setting framework for Django
LICENSE=	mit

GITHUB_PROJECT=	django-cogwheels
GITHUB_TAG=	v${PKGVERSION_NOREV}

DEPENDS+=	${PYPKGPREFIX}-django>=1.11:../../www/py-django

USE_LANGUAGES=	# none

do-test:
	cd ${WRKSRC} && ${PYTHONBIN} ./runtests.py

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
