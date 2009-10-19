# $NetBSD: Makefile,v 1.21 2009/10/19 11:31:05 joerg Exp $

DJANGOVERS=	1.1.1
DISTNAME=	Django-${DJANGOVERS}
PKGNAME=	${PYPKGPREFIX}-django-${DJANGOVERS}
CATEGORIES=	www python
MASTER_SITES=	http://media.djangoproject.com/releases/${DJANGOVERS}/

MAINTAINER=	joerg@NetBSD.org
HOMEPAGE=	http://www.djangoproject.com/
COMMENT=	Django, a high-level Python Web framework

LICENSE=	modified-bsd

PREV_PKGPATH=	www/py-django-devel

PYDISTUTILSPKG=	# yes
PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX:Q}

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# empty

DEPENDS+=	${PYPKGPREFIX}-flup-[0-9]*:../../www/py-flup

.include "options.mk"

pre-configure:
	rm -r ${WRKSRC}/django/db/backends/oracle
.if empty(PKG_OPTIONS:Mmysql)
	rm -r ${WRKSRC}/django/db/backends/mysql
.endif
.if empty(PKG_OPTIONS:Mpsycopg1) && empty(PKG_OPTIONS:Mpsycopg2)
	rm -r ${WRKSRC}/django/db/backends/postgresql
.endif
.if empty(PKG_OPTIONS:Mpsycopg2)
	rm -r ${WRKSRC}/django/db/backends/postgresql_psycopg2
.endif
.if empty(PKG_OPTIONS:Msqlite)
	rm -r ${WRKSRC}/django/db/backends/sqlite3
.endif

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
