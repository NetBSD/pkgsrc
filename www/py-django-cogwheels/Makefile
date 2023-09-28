# $NetBSD: Makefile,v 1.4 2023/09/28 22:31:07 joerg Exp $

DISTNAME=	django-cogwheels-0.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_GITHUB:=ababic/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ababic/django-cogwheels/
COMMENT=	Setting framework for Django
LICENSE=	mit

GITHUB_PROJECT=	django-cogwheels
GITHUB_TAG=	v${PKGVERSION_NOREV}

DEPENDS+=	${PYPKGPREFIX}-django>=3:../../www/py-django3

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

post-extract:
	chmod -R g-w ${WRKSRC}

do-test:
	cd ${WRKSRC} && ${PYTHONBIN} ./runtests.py

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
