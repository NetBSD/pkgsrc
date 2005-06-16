# $NetBSD: Makefile,v 1.11 2005/06/16 15:18:07 epg Exp $
#

DISTNAME=	trac-0.8.3
CATEGORIES=	devel www
MASTER_SITES=	http://ftp.edgewall.com/pub/trac/

MAINTAINER=	epg@NetBSD.org
HOMEPAGE=	http://www.edgewall.com/products/trac/
COMMENT=	Enhanced wiki and issue tracking system

DEPENDS+=	${PYPKGPREFIX}-clearsilver>=0.9.7:../../www/py-clearsilver
DEPENDS+=	${PYPKGPREFIX}-sqlite>=0.4.3:../../databases/py-sqlite
DEPENDS+=	${PYPKGPREFIX}-subversion>=0.37:../../devel/py-subversion

PYDISTUTILSPKG=	YES
PY_PATCHPLIST=	YES
PYTHON_PATCH_SCRIPTS=	contrib/*.py

EGDIR=		${PREFIX}/share/examples/trac

post-install:
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/contrib/* ${EGDIR}

.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
