# $NetBSD: Makefile,v 1.14 2005/07/21 16:30:00 wiz Exp $
#

DISTNAME=	fbdesk-1.2.1
PKGREVISION=	1
CATEGORIES=	x11 wm
MASTER_SITES=	http://fluxbox.sourceforge.net/download/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://fluxbox.sourceforge.net/fbdesk/
COMMENT=	Application that creates and manage icons on your desktop

USE_LIBTOOL=	YES
GNU_CONFIGURE=	YES

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/fbdesk
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/fbdesk/

.include "../../converters/libiconv/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../fonts/Xft2/buildlink3.mk"
.include "../../devel/pkg-config/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
