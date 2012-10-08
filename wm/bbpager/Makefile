# $NetBSD: Makefile,v 1.22 2012/10/08 12:42:17 asau Exp $
#

DISTNAME=	bbpager-0.3.1
PKGREVISION=	2
CATEGORIES=	wm x11
MASTER_SITES=	http://bbtools.windsofstorm.net/sources/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://bbtools.windsofstorm.net/available.phtml
COMMENT=	Pager for the blackbox window manager

CONFLICTS+=	bbpager04-*

GNU_CONFIGURE=	YES
USE_LANGUAGES=	c c++

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 ${PKGMANDIR}/man5 share/bbtools

post-install:
	${INSTALL_MAN} ${WRKSRC}/bbpager.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_MAN} ${WRKSRC}/bbpager.bb.5 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man5

BUILDLINK_DEPMETHOD.libXt?=	build

.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
