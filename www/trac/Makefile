# $NetBSD: Makefile,v 1.15.2.1 2006/01/13 00:23:02 salo Exp $
#

DISTNAME=	trac-0.9.3
CATEGORIES=	devel www
MASTER_SITES=	http://ftp.edgewall.com/pub/trac/ \
		ftp://ftp.edgewall.com/pub/trac/

MAINTAINER=	epg@NetBSD.org
HOMEPAGE=	http://www.edgewall.com/trac/
COMMENT=	Subversion repository browser, wiki, and issue tracking system

DEPENDS+=	${PYPKGPREFIX}-clearsilver>=0.9.14:../../www/py-clearsilver
DEPENDS+=	${PYPKGPREFIX}-subversion>=1.1.0:../../devel/py-subversion
DEPENDS+=	${PYPKGPREFIX}-{PgSQL>=2.4,psycopg>=1.1.14,sqlite>=0.5}:../../databases/py-sqlite

PYDISTUTILSPKG=	YES
PY_PATCHPLIST=	YES
PYTHON_PATCH_SCRIPTS=	contrib/*.py contrib/*-hook
PYTHON_VERSIONS_ACCEPTED=	24 23

EGDIR=		${PREFIX}/share/examples/trac

post-install:
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/contrib/* ${EGDIR}

.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
