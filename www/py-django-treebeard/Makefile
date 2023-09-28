# $NetBSD: Makefile,v 1.18 2023/09/28 22:31:08 joerg Exp $

DISTNAME=	django-treebeard-4.7
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/django-treebeard/}

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	https://github.com/django-treebeard/django-treebeard
COMMENT=	Efficient tree implementations for the Django Web Framework
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-django>=3.2:../../www/py-django3

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

post-extract:
	chmod -R go-w ${WRKSRC}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
