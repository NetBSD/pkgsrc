# $NetBSD: Makefile,v 1.6 2017/05/24 11:24:44 adam Exp $

DISTNAME=	django-treebeard-4.1.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/django-treebeard/}

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	https://tabo.pe/projects/django-treebeard/
COMMENT=	Efficient tree implementations for the Django Web Framework
LICENSE=	apache-2.0

USE_LANGUAGES=		# empty

DEPENDS+=	${PYPKGPREFIX}-django-[0-9]*:../../www/py-django

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
