# $NetBSD: Makefile,v 1.33 2012/01/26 11:34:28 obache Exp $

DJANGOVERS=	1.3.1
DISTNAME=	Django-${DJANGOVERS}
PKGNAME=	${PYPKGPREFIX}-django-${DJANGOVERS}
PKGREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	http://media.djangoproject.com/releases/1.3/

MAINTAINER=	joerg@NetBSD.org
HOMEPAGE=	http://www.djangoproject.com/
COMMENT=	Django, a high-level Python Web framework
LICENSE=	modified-bsd

PREV_PKGPATH=	www/py-django-devel

PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX:Q}

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# empty

DEPENDS+=	${PYPKGPREFIX}-flup-[0-9]*:../../www/py-flup

.include "options.mk"

pre-configure:
.if empty(PKG_OPTIONS:Moracle)
	rm -r ${WRKSRC}/django/db/backends/oracle
.endif
.if empty(PKG_OPTIONS:Mmysql)
	rm -r ${WRKSRC}/django/db/backends/mysql
.endif
.if empty(PKG_OPTIONS:Mpgsql)
	rm -r ${WRKSRC}/django/db/backends/postgresql
	rm -r ${WRKSRC}/django/db/backends/postgresql_psycopg2
.endif
.if empty(PKG_OPTIONS:Msqlite)
	rm -r ${WRKSRC}/django/db/backends/sqlite3
.endif

BACKEND_PATH=		${PYSITELIB}/django/db/backends
BACKEND_PATH_PLIST=	$${PYSITELIB}/django/db/backends

PRINT_PLIST_AWK+=	{ gsub("^${BACKEND_PATH}/mysql/", "$${PLIST.mysql}${BACKEND_PATH_PLIST}/mysql/") }
PRINT_PLIST_AWK+=	{ gsub("^${BACKEND_PATH}/oracle/", "$${PLIST.oracle}${BACKEND_PATH_PLIST}/oracle/") }
PRINT_PLIST_AWK+=	{ gsub("^${BACKEND_PATH}/postgresql/", "$${PLIST.pgsql}${BACKEND_PATH_PLIST}/postgresql/") }
PRINT_PLIST_AWK+=	{ gsub("^${BACKEND_PATH}/postgresql_psycopg2/", "$${PLIST.pgsql}${BACKEND_PATH_PLIST}/postgresql_psycopg2/") }
PRINT_PLIST_AWK+=	{ gsub("^${BACKEND_PATH}/sqlite3/", "$${PLIST.sqlite}${BACKEND_PATH_PLIST}/sqlite3/") }

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
