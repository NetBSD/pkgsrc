# $NetBSD: Makefile,v 1.48 2010/03/10 15:27:01 gdt Exp $
#

DISTNAME=	Trac-0.11.7
PKGNAME=	${DISTNAME:tl}
CATEGORIES=	devel www
MASTER_SITES=	http://ftp.edgewall.org/pub/trac/ \
		ftp://ftp.edgewall.org/pub/trac/

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	http://trac.edgewall.org/
COMMENT=	Subversion repository browser, wiki, and issue tracking system
LICENSE=	modified-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	${PYPKGPREFIX}-genshi>=0.5:../../www/py-genshi
DEPENDS+=	${PYPKGPREFIX}-subversion>=1.1.0:../../devel/py-subversion

USE_TOOLS+=	pax

PKG_OPTIONS_VAR=	PKG_OPTIONS.trac
PKG_OPTIONS_REQUIRED_GROUPS=	db
PKG_OPTIONS_GROUP.db=	sqlite pgsql psycopg2
PKG_SUGGESTED_OPTIONS=	sqlite

.include "../../mk/bsd.options.mk"

PYDISTUTILSPKG=	YES
PY_PATCHPLIST=	YES
PYTHON_PATCH_SCRIPTS=	cgi-bin/trac.* contrib/*.py contrib/*-hook
PYTHON_PATCH_SCRIPTS+=	trac/tests/functional/*.py

.include "../../lang/python/application.mk"

.if !empty(PKG_OPTIONS:Msqlite)
.if defined(PYPACKAGE) && \
    (${PYPACKAGE} == "python23" || ${PYPACKAGE} == "python24")
DEPENDS+=	${PYPKGPREFIX}-sqlite2>=2:../../databases/py-sqlite2
.else
DEPENDS+=	${PYPKGPREFIX}-sqlite3>=0:../../databases/py-sqlite3
.endif
.endif
.if !empty(PKG_OPTIONS:Mpgsql)
DEPENDS+=	${PYPKGPREFIX}-PgSQL>=2.4:../../databases/py-PgSQL
.endif
.if !empty(PKG_OPTIONS:Mpsycopg2)
DEPENDS+=	${PYPKGPREFIX}-psycopg2>=2:../../databases/py-psycopg2
.endif
# MySQL is sort of supported but not recommended by upstream and hence
# omitted.

EGDIR=		${PREFIX}/share/examples/trac
CGIBINDIR=	${PREFIX}/libexec/trac

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${EGDIR}
	${INSTALL_PROGRAM_DIR} ${DESTDIR}${CGIBINDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/cgi-bin/trac.* ${DESTDIR}${CGIBINDIR}
	cd ${WRKSRC}/contrib && pax -rwppm -s ',./rpm/.*$$,,' -s ',./rpm$$,,' \
		. ${DESTDIR}${EGDIR}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
