# $NetBSD: Makefile,v 1.1 2012/08/26 13:32:17 adam Exp $

DISTNAME=	django-reversion-1.6.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	http://pypi.python.org/packages/source/d/django-reversion/

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	https://github.com/etianen/django-reversion/
COMMENT=	Version control facilities for Django
LICENSE=	modified-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		# empty
#EGG_NAME=		${DISTNAME:S/-/_/:S/-/_/}
PYDISTUTILSPKG=		yes

DEPENDS+=	${PYPKGPREFIX}-django-[0-9]*:../../www/py-django

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
