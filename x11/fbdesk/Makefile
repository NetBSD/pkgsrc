# $NetBSD: Makefile,v 1.11 2005/04/11 21:48:05 tv Exp $
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
USE_X11=	YES

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/fbdesk
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/fbdesk/

.include "../../graphics/png/buildlink3.mk"
.include "../../fonts/Xft2/buildlink3.mk"
.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
