# $NetBSD: Makefile,v 1.9 2020/02/24 16:16:00 adam Exp $

DISTNAME=	django-admin-sortable2-0.7.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/django-admin-sortable2/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/jrief/django-admin-sortable2
COMMENT=	Generic drag-and-drop sorting for Views in the Django Admin
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-django>=1.8:../../www/py-django

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
