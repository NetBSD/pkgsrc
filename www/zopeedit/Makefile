# $NetBSD: Makefile,v 1.17 2008/04/25 20:39:14 joerg Exp $
#

DISTNAME=	zopeedit-0.7-src
PKGNAME=	${DISTNAME:S/-src//}
PKGREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://www.zope.org/Members/Caseman/ExternalEditor/0.7/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.zope.org/Members/Caseman/ExternalEditor
COMMENT=	Helper client application for Zope's ExternalEditor

PYTHON_VERSIONS_ACCEPTED=	25 24 23
PYDISTUTILSPKG=	yes

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/zopeedit
	${INSTALL_DATA} ${WRKSRC}/README.txt ${PREFIX}/share/doc/zopeedit
	${INSTALL_MAN} ${WRKSRC}/man/zopeedit.1 ${PREFIX}/${PKGMANDIR}/man1

.include "../../lang/python/extension.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
