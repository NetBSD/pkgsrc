# $NetBSD: Makefile,v 1.6 2003/07/22 04:14:47 martti Exp $
#

DISTNAME=	zopeedit-0.7-src
PKGNAME=	zopeedit-0.7
CATEGORIES=	www
MASTER_SITES=	http://www.zope.org/Members/Caseman/ExternalEditor/
EXTRACT_SUFX=	.tgz

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.zope.org/Members/Caseman/ExternalEditor
COMMENT=	Helper client application for Zope's ExternalEditor

USE_BUILDLINK2=	YES
PYTHON_VERSIONS_ACCEPTED= 22
PYDISTUTILSPKG=	yes

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/zopeedit
	${INSTALL_DATA} ${WRKSRC}/README.txt ${PREFIX}/share/doc/zopeedit
	${INSTALL_DATA} ${WRKSRC}/man/zopeedit.1 ${PREFIX}/man/man1

.include "../../lang/python/extension.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
