# $NetBSD: Makefile,v 1.1.1.1 2002/11/14 18:36:21 drochner Exp $
#

DISTNAME=	zopeedit-src-0.6
PKGNAME=	zopeedit-0.6
CATEGORIES=	www
MASTER_SITES=	http://www.zope.org/Members/Caseman/ExternalEditor/
EXTRACT_SUFX=	.tgz

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.zope.org/Members/Caseman/ExternalEditor
COMMENT=	helper client application for Zope's ExternalEditor

WRKSRC=		${WRKDIR}/zopeedit
USE_BUILDLINK2=	YES
PYTHON_VERSIONS_ACCEPTED= 22
PYTHON_PATCH_SCRIPTS= zopeedit.py
NO_BUILD=	yes

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/zopeedit.py ${PREFIX}/bin/zopeedit
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/zopeedit
	${INSTALL_DATA} ${WRKSRC}/README.txt ${PREFIX}/share/doc/zopeedit

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
