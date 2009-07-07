# $NetBSD: Makefile,v 1.18 2009/07/07 18:25:09 joerg Exp $
#

DISTNAME=	fspanel-0.8beta1
PKGNAME=	${DISTNAME:C/beta/.0./}
PKGREVISION=	6
CATEGORIES=	x11
MASTER_SITES=	http://www.chatjunkies.org/fspanel/

MAINTAINER=	ptiJo@noos.fr
HOMEPAGE=	http://www.chatjunkies.org/fspanel/
COMMENT=	F***ing Small Panel for listing X11 windows

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

HAS_CONFIGURE=	YES

CFLAGS+=	-DHAVE_XPM -DXFT

INSTALLATION_DIRS=	bin share/doc/fspanel

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/fspanel ${DESTDIR}${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/fspanel/

.include "../../x11/libXft/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
