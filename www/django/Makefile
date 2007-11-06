# $NetBSD: Makefile,v 1.1.1.1 2007/11/06 13:52:51 rillig Exp $
#

DISTNAME=	Django-0.96.1
PKGNAME=	django-0.96.1
CATEGORIES=	www
MASTER_SITES=	http://media.djangoproject.com/releases/0.96/

MAINTAINER=	rillig@NetBSD.org
HOMEPAGE=	http://media.djangoproject.com/releases/0.96/
COMMENT=	Python web development framework

USE_LANGUAGES=	# only Python
PYTHON_VERSIONS_INCOMPATIBLE=	15 20 21 22
PY_PATCHPLIST=	yes
INSTALLATION_DIRS=	share/doc/django share/examples/django

do-build:
	cd ${WRKSRC} && env ${MAKE_ENV} ${PYTHONBIN} setup.py build

do-install:
	cd ${WRKSRC} && env ${INSTALL_ENV} ${MAKE_ENV} ${PYTHONBIN} setup.py install
	cd ${WRKSRC}/docs && pax -wr *.txt ${PREFIX}/share/doc/django
	cd ${WRKSRC}/examples && pax -wr * ${PREFIX}/share/examples/django
	cd ${WRKSRC} && ${INSTALL_DATA} AUTHORS LICENSE README ${PREFIX}/share/doc/django

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
