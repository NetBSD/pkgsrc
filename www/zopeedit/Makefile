# $NetBSD: Makefile,v 1.22 2012/01/25 12:41:42 obache Exp $
#

DISTNAME=	zopeedit-0.7-src
PKGNAME=	${DISTNAME:S/-src//}
PKGREVISION=	4
CATEGORIES=	www
MASTER_SITES=	http://www.zope.org/Members/Caseman/ExternalEditor/0.7/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.zope.org/Members/Caseman/ExternalEditor
COMMENT=	Helper client application for Zope's ExternalEditor

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	#none

INSTALLATION_DIRS+=	share/doc/zopeedit ${PKGMANDIR}/man1

post-install:
	${INSTALL_DATA} ${WRKSRC}/README.txt ${DESTDIR}${PREFIX}/share/doc/zopeedit
	${INSTALL_MAN} ${WRKSRC}/man/zopeedit.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

EGG_NAME=	zopeedit-0.0.0

.include "../../lang/python/distutils.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
