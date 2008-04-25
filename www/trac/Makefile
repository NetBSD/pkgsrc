# $NetBSD: Makefile,v 1.31 2008/04/25 20:39:14 joerg Exp $
#

DISTNAME=	trac-0.10.4
CATEGORIES=	devel www
MASTER_SITES=	http://ftp.edgewall.org/pub/trac/ \
		ftp://ftp.edgewall.org/pub/trac/

MAINTAINER=	epg@NetBSD.org
HOMEPAGE=	http://trac.edgewall.org/
COMMENT=	Subversion repository browser, wiki, and issue tracking system

DEPENDS+=	${PYPKGPREFIX}-clearsilver>=0.9.14:../../www/py-clearsilver
DEPENDS+=	${PYPKGPREFIX}-subversion>=1.1.0:../../devel/py-subversion

PKG_OPTIONS_VAR=	PKG_OPTIONS.trac
PKG_OPTIONS_REQUIRED_GROUPS=	db
PKG_OPTIONS_GROUP.db=	sqlite pgsql psycopg2
PKG_SUGGESTED_OPTIONS=	sqlite

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Msqlite)
DEPENDS+=	${PYPKGPREFIX}-sqlite2>=2:../../databases/py-sqlite2
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
PYTHON_PATCH_SCRIPTS=	contrib/*.py contrib/*-hook

EGDIR=		${PREFIX}/share/examples/trac

post-install:
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/contrib/* ${EGDIR}

.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
