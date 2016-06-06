# $NetBSD: Makefile,v 1.73 2016/06/06 09:34:59 adam Exp $

DISTNAME=	Django-1.9.7
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
CATEGORIES=	www python
MASTER_SITES=	http://www.djangoproject.com/m/releases/${PKGVERSION_NOREV:R}/

MAINTAINER=	joerg@NetBSD.org
HOMEPAGE=	http://www.djangoproject.com/
COMMENT=	Django, a high-level Python Web framework
LICENSE=	modified-bsd

PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX:Q}

USE_LANGUAGES=		# empty
REPLACE_PYTHON=		${WRKSRC}/django/bin/django-admin.py
REPLACE_PYTHON+=	${WRKSRC}/django/conf/project_template/manage.py-tpl

PYTHON_VERSIONED_DEPENDENCIES=	flup

post-install:
	${MV} ${DESTDIR}${PREFIX}/bin/django-admin \
		${DESTDIR}${PREFIX}/bin/django-admin${PYVERSSUFFIX}
	${MV} ${DESTDIR}${PREFIX}/bin/django-admin.py \
		${DESTDIR}${PREFIX}/bin/django-admin${PYVERSSUFFIX}.py

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
