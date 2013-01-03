# $NetBSD: Makefile,v 1.1 2013/01/03 14:29:29 ryoon Exp $
#

DISTNAME=	Mezzanine-1.2.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	www
MASTER_SITES=	http://pypi.python.org/packages/source/M/Mezzanine/

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://mezzanine.jupo.org/
COMMENT=	Open source content management platform on Django
LICENSE=	2-clause-bsd

PYTHON_VERSIONS_ACCEPTED=	27 26

DEPENDS+=	${PYPKGPREFIX}-flakes-[0-9]*:../../devel/py-flakes
DEPENDS+=	${PYPKGPREFIX}-pep8-[0-9]*:../../devel/py-pep8
DEPENDS+=	${PYPKGPREFIX}-imaging-[0-9]*:../../graphics/py-imaging
DEPENDS+=	${PYPKGPREFIX}-html5lib-[0-9]*:../../textproc/py-html5lib
DEPENDS+=	${PYPKGPREFIX}-pytz-[0-9]*:../../time/py-pytz
DEPENDS+=	${PYPKGPREFIX}-django-[0-9]*:../../www/py-django
DEPENDS+=	${PYPKGPREFIX}-django-south-[0-9]*:../../www/py-django-south
DEPENDS+=	${PYPKGPREFIX}-bleach-[0-9]*:../../www/py-bleach

DEPENDS+=	${PYPKGPREFIX}-django-mezzanine-filebrowser-[0-9]*:../../www/py-django-mezzanine-filebrowser
DEPENDS+=	${PYPKGPREFIX}-django-mezzanine-grappelli-[0-9]*:../../www/py-django-mezzanine-grappelli

USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		# none

MESSAGE_SUBST+=	PYTHONBIN=${PYTHONBIN}

.include "../../lang/python/application.mk"
.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
