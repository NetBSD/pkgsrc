# $NetBSD: Makefile,v 1.14 2007/12/21 03:38:06 taca Exp $
#

DISTNAME=	trac-0.10.4-ja-1
PKGNAME=	ja-trac-0.10.4.1
PKGREVISION=	1
CATEGORIES=	www devel
MASTER_SITES=	http://www.i-act.co.jp/project/products/downloads/
EXTRACT_SUFX=	.zip

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://www.i-act.co.jp/project/products/products.html
COMMENT=	Trac issue tracking system with Japanese localization

CONFLICTS+=	trac-[0-9]*

DEPENDS+=	${PYPKGPREFIX}-clearsilver>=0.9.14:../../www/py-clearsilver
DEPENDS+=	${PYPKGPREFIX}-subversion>=1.1.0:../../devel/py-subversion
DEPENDS+=	${PYPKGPREFIX}-jpCodecs>=1.4.11:../../converters/py-jpCodecs

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
DEPENDS+=	${PYPKGPREFIX}-psycopg>=1.1.14:../../databases/py-psycopg2
.endif
# MySQL is sort of supported but not recommended by upstream and hence
# omitted.

PYDISTUTILSPKG=	YES
PY_PATCHPLIST=	YES
PYTHON_PATCH_SCRIPTS=	contrib/*.py contrib/*-hook
PYTHON_VERSIONS_ACCEPTED=	24 23

OWN_DIRS+=	${PREFIX}/share/trac
OWN_DIRS+=	${PREFIX}/share/trac/conf
OWN_DIRS+=	${PREFIX}/share/trac/plugins

EGDIR=		${PREFIX}/share/examples/trac

post-install:
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_SCRIPT} ${WRKSRC:Q}/contrib/* ${EGDIR}

.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
