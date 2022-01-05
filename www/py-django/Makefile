# $NetBSD: Makefile,v 1.117 2022/01/05 15:41:29 wiz Exp $

DISTNAME=	Django-1.11.29
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
PKGREVISION=	3
CATEGORIES=	www python
MASTER_SITES=	https://www.djangoproject.com/m/releases/${PKGVERSION_NOREV:R}/

MAINTAINER=	joerg@NetBSD.org
HOMEPAGE=	https://www.djangoproject.com/
COMMENT=	Django, a high-level Python Web framework
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-pytz-[0-9]*:../../time/py-pytz

USE_LANGUAGES=	# none

REPLACE_PYTHON+=	django/bin/django-admin.py
REPLACE_PYTHON+=	django/conf/project_template/manage.py-tpl

USE_PKG_RESOURCES=	yes

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} django-admin django-admin-${PYVERSSUFFIX} && \
	${MV} django-admin.py django-admin-${PYVERSSUFFIX}.py || ${TRUE}

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
