# $NetBSD: Makefile,v 1.54 2012/01/27 05:58:56 obache Exp $
#

DISTNAME=	Trac-0.12.2
PKGNAME=	${DISTNAME:tl}
PKGREVISION=	1
CATEGORIES=	devel www
MASTER_SITES=	http://ftp.edgewall.org/pub/trac/ \
		ftp://ftp.edgewall.org/pub/trac/

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	http://trac.edgewall.org/
COMMENT=	Subversion repository browser, wiki, and issue tracking system
LICENSE=	modified-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

# Maintainer notes:
#
# This package is similar to wip/trac, which in turn structurally
# matches www/ja-trac.  Ideally, www/trac and ja-trac would converge.
# This note outlines the known differences and proposed resolution.
# Besides bringing the packages closer, a goal is to avoid breaking
# existing trac installations that blindly upgrade, to the extent that
# this is reasonable.
#
# subversion dependency: ja-trac does not depend on subversion,
# because 1) trac is useful without a repo, and because one can use
# other than svn.  Perhaps options to specify repo support (not a
# group, because trac can support multiple), defaulting to subversion
# is a good strategy for now.
#
# www/trac options are not in options.mk (to be fixed).
#
# sqlite2 vs sqlite3: This package has logic to choose sqlite2 vs
# sqlite3, and ja-trac uses only sqlite2.  This is hard, because
# database format changes are disruptive, and gdt should consult
# upstream's idea of best practice.

DEPENDS+=	${PYPKGPREFIX}-genshi>=0.5:../../www/py-genshi
DEPENDS+=	${PYPKGPREFIX}-subversion>=1.1.0:../../devel/py-subversion

USE_TOOLS+=	pax

PKG_OPTIONS_VAR=	PKG_OPTIONS.trac
PKG_OPTIONS_REQUIRED_GROUPS=	db
PKG_OPTIONS_GROUP.db=	sqlite psycopg2
PKG_SUGGESTED_OPTIONS=	sqlite

.include "../../mk/bsd.options.mk"

PYDISTUTILSPKG=	YES
PY_PATCHPLIST=	YES
PYTHON_PATCH_SCRIPTS=	cgi-bin/trac.* contrib/*.py contrib/*-hook
PYTHON_PATCH_SCRIPTS+=	trac/tests/functional/*.py

.include "../../lang/python/application.mk"

.if !empty(PKG_OPTIONS:Msqlite)
.if defined(PYPACKAGE) && ${PYPACKAGE} == "python24"
DEPENDS+=	${PYPKGPREFIX}-sqlite2>=2:../../databases/py-sqlite2
.else
DEPENDS+=	${PYPKGPREFIX}-sqlite3>=0:../../databases/py-sqlite3
.endif
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
	${INSTALL_SCRIPT} ${WRKSRC}/cgi-bin/trac.* ${DESTDIR}${CGIBINDIR}
	cd ${WRKSRC}/contrib && pax -rwppm -s ',./rpm/.*$$,,' -s ',./rpm$$,,' \
		. ${DESTDIR}${EGDIR}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
