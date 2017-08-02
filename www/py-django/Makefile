# $NetBSD: Makefile,v 1.88 2017/08/02 10:45:09 adam Exp $

DISTNAME=	Django-1.11.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	www python
MASTER_SITES=	http://www.djangoproject.com/m/releases/${PKGVERSION_NOREV:R}/

MAINTAINER=	joerg@NetBSD.org
HOMEPAGE=	http://www.djangoproject.com/
COMMENT=	Django, a high-level Python Web framework
LICENSE=	modified-bsd

USE_LANGUAGES=		# empty
REPLACE_PYTHON=		${WRKSRC}/django/bin/django-admin.py
REPLACE_PYTHON+=	${WRKSRC}/django/conf/project_template/manage.py-tpl

DEPENDS+=	${PYPKGPREFIX}-pytz-[0-9]*:../../time/py-pytz

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
		${MV} django-admin django-admin${PYVERSSUFFIX} && \
		${MV} django-admin.py django-admin${PYVERSSUFFIX}.py || ${TRUE}

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
