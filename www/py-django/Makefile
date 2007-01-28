# $NetBSD: Makefile,v 1.4.2.1 2007/01/28 20:06:01 ghen Exp $

DISTNAME=	Django-0.95.1
PKGNAME=	${PYPKGPREFIX}-django-0.95.1
CATEGORIES=	www python
MASTER_SITES=	http://media.djangoproject.com/releases/0.95/

MAINTAINER=	joerg@NetBSD.org
HOMEPAGE=	http://www.djangoproject.com/
COMMENT=	Django, a high-level Python Web framework

PYDISTUTILSPKG=	# yes
PYBINMODULE=	# yes
PYTHON_VERSIONS_ACCEPTED=	24
PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX:Q}

PKG_DESTDIR_SUPPORT=	# empty

DEPENDS+=	${PYPKGPREFIX}-setuptools>=0.6c1nb1:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-flup-[0-9]*:../../www/py-flup

CHECK_FILES_SKIP+=	${PREFIX}/${PYSITELIB}/easy-install.pth

FILES_SUBST+=	PY_MANAGE_EGGS=${PREFIX}/bin/${PYPKGPREFIX}-manage-eggs
FILES_SUBST+=	DJANGOEGG=${PREFIX}/${PYSITELIB}/Django-0.95-py2.4.egg

.include "options.mk"

post-extract:
	rm -r ${WRKSRC}/django/db/backends/ado_mssql
	rm -r ${WRKSRC}/django/db/backends/oracle
.if empty(PKG_OPTIONS:Mmysql)
	rm -r ${WRKSRC}/django/db/backends/mysql
.endif
.if empty(PKG_OPTIONS:Mpsycopg1)
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
