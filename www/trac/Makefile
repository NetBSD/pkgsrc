# $NetBSD: Makefile,v 1.78 2016/09/11 15:29:31 gdt Exp $

DISTNAME=	Trac-1.0.13
PKGNAME=	${DISTNAME:tl}
CATEGORIES=	devel www
MASTER_SITES=	http://ftp.edgewall.org/pub/trac/ \
		ftp://ftp.edgewall.org/pub/trac/

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	http://trac.edgewall.org/
COMMENT=	Repository browser, wiki, and issue tracking system
LICENSE=	modified-bsd

# Updates to micro-releases along stable branches are commited without
# testing.
#
# Trac supports svn and git in the base, plus others via plugins,
# using them at runtime if configured.  Therefore this package does
# not depend on svn or git to avoid installing them for trac installs
# that use the other.

DEPENDS+=	${PYPKGPREFIX}-genshi>=0.6:../../www/py-genshi

USE_TOOLS+=	pax

PYDISTUTILSPKG=	YES
PY_PATCHPLIST=	YES
REPLACE_PYTHON=	contrib/cgi-bin/trac.* contrib/*.py contrib/*-hook
REPLACE_PYTHON+=	trac/tests/functional/*.py
PYTHON_VERSIONS_INCOMPATIBLE=	34 35 # not yet ported as of 1.0

.include "../../lang/python/application.mk"

# TODO: move to options.mk
PKG_OPTIONS_VAR=	PKG_OPTIONS.trac
PKG_OPTIONS_REQUIRED_GROUPS=	db
PKG_OPTIONS_GROUP.db=	sqlite psycopg2
PKG_SUGGESTED_OPTIONS=	sqlite

.include "../../mk/bsd.options.mk"

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
