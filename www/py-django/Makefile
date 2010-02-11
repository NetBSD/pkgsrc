# $NetBSD: Makefile,v 1.24 2010/02/11 13:37:44 joerg Exp $

DJANGOVERS=	1.1.1
DISTNAME=	Django-${DJANGOVERS}
PKGNAME=	${PYPKGPREFIX}-django-${DJANGOVERS}
PKGREVISION=	1
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

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
