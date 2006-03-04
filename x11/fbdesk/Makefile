# $NetBSD: Makefile,v 1.18 2006/03/04 21:31:08 jlam Exp $
#

DISTNAME=	fbdesk-1.2.1
PKGREVISION=	3
CATEGORIES=	x11 wm
MASTER_SITES=	http://fluxbox.sourceforge.net/download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://fluxbox.sourceforge.net/fbdesk/
COMMENT=	Application that creates and manage icons on your desktop

USE_TOOLS+=	pkg-config
USE_LIBTOOL=	YES
GNU_CONFIGURE=	YES

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/fbdesk
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/fbdesk/

.include "../../converters/libiconv/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../fonts/Xft2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
