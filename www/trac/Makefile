# $NetBSD: Makefile,v 1.1.1.1 2004/02/26 05:52:57 epg Exp $
#

DISTNAME=	trac-0.5.1
CATEGORIES=	devel www
MASTER_SITES=	http://ftp.edgewall.com/pub/trac/

MAINTAINER=	epg@NetBSD.org
HOMEPAGE=	http://www.edgewall.com/products/trac/
COMMENT=	Enhanced wiki and issue tracking system

DEPENDS+=	clearsilver>=0.9.7:../../www/clearsilver
DEPENDS+=	${PYPKGPREFIX}-sqlite>=0.4.3:../../databases/py-sqlite
DEPENDS+=	${PYPKGPREFIX}-subversion>=0.37:../../devel/py-subversion

PYDISTUTILSPKG=	YES
PY_PATCHPLIST=	YES

post-install:
	${INSTALL_PROGRAM_DIR} ${PREFIX}/libexec/cgi-bin
	${INSTALL_SCRIPT} ${WRKSRC}/cgi-bin/trac.cgi ${PREFIX}/libexec/cgi-bin

.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
