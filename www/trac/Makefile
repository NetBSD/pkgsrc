# $NetBSD: Makefile,v 1.74 2016/02/27 01:33:04 gdt Exp $

DISTNAME=	Trac-1.0.10
PKGNAME=	${DISTNAME:tl}
CATEGORIES=	devel www
MASTER_SITES=	http://ftp.edgewall.org/pub/trac/ \
		ftp://ftp.edgewall.org/pub/trac/

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	http://trac.edgewall.org/
COMMENT=	Repository browser, wiki, and issue tracking system
LICENSE=	modified-bsd

# Maintainer notes:
#
# This package is similar to wip/trac, which in turn structurally
# matches www/ja-trac.  Ideally, www/trac and ja-trac would converge.
# This note outlines the known differences and proposed resolution.
# Besides bringing the packages closer, a goal is to avoid breaking
# existing trac installations that blindly upgrade, to the extent that
# this is reasonable.
#
# www/trac options are not in options.mk (to be fixed).
#
# This package supports sqlite3 or postgresql.
# ja-trac supports sqlite3, postgresql, and mysql.
# ja-trac uses py-sqlite2 (separate Python DB API 2.0 support for sqlite3)
# while this package uses py-sqlite3 (bundled support for sqlite3).

DEPENDS+=	${PYPKGPREFIX}-genshi>=0.6:../../www/py-genshi
# Arguably there should be a trac-svn package that depends on
# subversion and trac.  This line is residual from when trac always
# included subversion support.
#DEPENDS+=	${PYPKGPREFIX}-subversion>=1.6:../../devel/py-subversion

USE_TOOLS+=	pax

PKG_OPTIONS_VAR=	PKG_OPTIONS.trac
PKG_OPTIONS_REQUIRED_GROUPS=	db
PKG_OPTIONS_GROUP.db=	sqlite psycopg2
PKG_SUGGESTED_OPTIONS=	sqlite

.include "../../mk/bsd.options.mk"

PYDISTUTILSPKG=	YES
PY_PATCHPLIST=	YES
REPLACE_PYTHON=	contrib/cgi-bin/trac.* contrib/*.py contrib/*-hook
REPLACE_PYTHON+=	trac/tests/functional/*.py
PYTHON_VERSIONS_INCOMPATIBLE=	33 34 35 # not yet ported as of 1.0

.include "../../lang/python/application.mk"

.if !empty(PKG_OPTIONS:Msqlite)
DEPENDS+=	${PYPKGPREFIX}-sqlite3>=0:../../databases/py-sqlite3
.endif
# trac 0.12 dropped support for py-PgSQL.  Switching to py-psycopg2 with
# an existing database that used to be accessed by py-PgSQL worked.
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
	${INSTALL_SCRIPT} ${WRKSRC}/contrib/cgi-bin/trac.* ${DESTDIR}${CGIBINDIR}
	cd ${WRKSRC}/contrib && pax -rwppm -s ',./rpm/.*$$,,' -s ',./rpm$$,,' \
		. ${DESTDIR}${EGDIR}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
