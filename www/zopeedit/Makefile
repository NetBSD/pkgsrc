# $NetBSD: Makefile,v 1.8 2003/12/04 01:14:12 xtraeme Exp $
#

DISTNAME=	zopeedit-0.7-src
PKGNAME=	${DISTNAME:S/-src//}
CATEGORIES=	www
MASTER_SITES=	http://www.zope.org/Members/Caseman/ExternalEditor/0.7/
EXTRACT_SUFX=	.tgz

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.zope.org/Members/Caseman/ExternalEditor
COMMENT=	Helper client application for Zope's ExternalEditor

USE_BUILDLINK2=	YES
PYTHON_VERSIONS_ACCEPTED= 22 22pth 23 23pth
PYDISTUTILSPKG=	yes

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/zopeedit
	${INSTALL_DATA} ${WRKSRC}/README.txt ${PREFIX}/share/doc/zopeedit
	${INSTALL_DATA} ${WRKSRC}/man/zopeedit.1 ${PREFIX}/man/man1

.include "../../lang/python/extension.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
