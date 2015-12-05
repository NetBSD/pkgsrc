# $NetBSD: Makefile,v 1.7 2015/12/05 21:26:05 adam Exp $

DISTNAME=	django-photologue-2.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	http://pypi.python.org/packages/source/d/django-photologue/
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/jdriscoll/django-photologue/
COMMENT=	Plug-in photo management application for the Django framework
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-imaging-[0-9]*:../../graphics/py-imaging
DEPENDS+=	${PYPKGPREFIX}-django-south-[0-9]*:../../www/py-django-south
DEPENDS+=	${PYPKGPREFIX}-django-tagging-[0-9]*:../../www/py-django-tagging

USE_LANGUAGES=		# none
PYTHON_VERSIONS_INCOMPATIBLE=	33 34 35 # py-django-tagging, py-imaging

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
