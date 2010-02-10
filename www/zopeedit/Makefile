# $NetBSD: Makefile,v 1.21 2010/02/10 19:17:48 joerg Exp $
#

DISTNAME=	zopeedit-0.7-src
PKGNAME=	${DISTNAME:S/-src//}
PKGREVISION=	3
CATEGORIES=	www
MASTER_SITES=	http://www.zope.org/Members/Caseman/ExternalEditor/0.7/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.zope.org/Members/Caseman/ExternalEditor
COMMENT=	Helper client application for Zope's ExternalEditor

PYDISTUTILSPKG=	yes

PKG_DESTDIR_SUPPORT=	user-destdir
INSTALLATION_DIRS+=	share/doc/zopeedit ${PKGMANDIR}/man1

post-install:
	${INSTALL_DATA} ${WRKSRC}/README.txt ${DESTDIR}${PREFIX}/share/doc/zopeedit
	${INSTALL_MAN} ${WRKSRC}/man/zopeedit.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../lang/python/extension.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
