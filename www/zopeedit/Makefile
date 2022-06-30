# $NetBSD: Makefile,v 1.30 2022/06/30 11:19:00 nia Exp $

DISTNAME=	zopeedit-0.7-src
PKGNAME=	${DISTNAME:S/-src//}
PKGREVISION=	10
CATEGORIES=	www
#MASTER_SITES=	http://www.zope.org/Members/Caseman/ExternalEditor/0.7/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://www.zope.org/Members/Caseman/ExternalEditor
COMMENT=	Helper client application for Zope's ExternalEditor

USE_LANGUAGES=	#none

INSTALLATION_DIRS+=	share/doc/zopeedit ${PKGMANDIR}/man1

post-install:
	${INSTALL_DATA} ${WRKSRC}/README.txt ${DESTDIR}${PREFIX}/share/doc/zopeedit
	${INSTALL_MAN} ${WRKSRC}/man/zopeedit.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

EGG_NAME=	zopeedit-0.0.0

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
