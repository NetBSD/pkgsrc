# $NetBSD: Makefile,v 1.37 2008/09/15 17:44:03 abs Exp $
#

DISTNAME=	Trac-0.11.1
PKGREVISION=	1
PKGNAME=	${DISTNAME:tl}
EGG_NAME=	${DISTNAME}
CATEGORIES=	devel www
MASTER_SITES=	http://ftp.edgewall.org/pub/trac/ \
		ftp://ftp.edgewall.org/pub/trac/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://trac.edgewall.org/
COMMENT=	Subversion repository browser, wiki, and issue tracking system

DEPENDS+=	${PYPKGPREFIX}-genshi>=0:../../www/py-genshi
DEPENDS+=	${PYPKGPREFIX}-subversion>=1.1.0:../../devel/py-subversion

PKG_OPTIONS_VAR=	PKG_OPTIONS.trac
PKG_OPTIONS_REQUIRED_GROUPS=	db
PKG_OPTIONS_GROUP.db=	sqlite pgsql psycopg2
PKG_SUGGESTED_OPTIONS=	sqlite

.include "../../mk/bsd.options.mk"
.include "../../lang/python/application.mk"

.if !empty(PKG_OPTIONS:Msqlite)
.if !empty(PYPKGPREFIX:M2*[1234])
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

PYDISTUTILSPKG=	YES
PY_PATCHPLIST=	YES
PYTHON_PATCH_SCRIPTS=	cgi-bin/trac.* contrib/*.py contrib/*-hook

EGDIR=		${PREFIX}/share/examples/trac
CGIBINDIR=	${PREFIX}/libexec/trac

post-install:
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_PROGRAM_DIR} ${CGIBINDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/contrib/[A-qs-v]* ${EGDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/cgi-bin/trac.* ${CGIBINDIR}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
