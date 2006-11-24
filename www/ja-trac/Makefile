# $NetBSD: Makefile,v 1.4.2.1 2006/11/24 15:03:41 ghen Exp $
#

DISTNAME=	trac-0.10-ja-3
PKGNAME=	ja-trac-0.10.0.3
CATEGORIES=	www devel
MASTER_SITES=	http://www.i-act.co.jp/project/products/downloads/
EXTRACT_SUFX=	.zip

MAINTAINER=	obata@lins.jp
HOMEPAGE=	http://www.i-act.co.jp/project/products/products.html
COMMENT=	Trac issue tracking system with Japanese localization

CONFLICTS+=	trac-[0-9]*

DEPENDS+=	${PYPKGPREFIX}-clearsilver>=0.9.14:../../www/py-clearsilver
DEPENDS+=	${PYPKGPREFIX}-subversion>=1.1.0:../../devel/py-subversion
DEPENDS+=	${PYPKGPREFIX}-{PgSQL>=2.4,psycopg>=1.1.14,sqlite>=0.5}:../../databases/py-sqlite
DEPENDS+=	${PYPKGPREFIX}-jpCodecs>=1.4.11:../../converters/py-jpCodecs

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
