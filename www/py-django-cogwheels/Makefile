# $NetBSD: Makefile,v 1.2 2022/01/04 20:55:19 wiz Exp $

DISTNAME=	django-cogwheels-0.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
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
