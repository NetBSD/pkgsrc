# $NetBSD: Makefile,v 1.8 2004/05/07 01:14:50 xtraeme Exp $
#

DISTNAME=	fbdesk-1.1.5
CATEGORIES=	x11 wm
MASTER_SITES=	http://fluxbox.sourceforge.net/download/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://fluxbox.sourceforge.net/fbdesk/
COMMENT=	Application that creates and manage icons on your Fluxbox desktop

DEPENDS+=	fluxbox>=0.1.14:../../wm/fluxbox

USE_BUILDLINK3=	YES
USE_LIBTOOL=	YES
GNU_CONFIGURE=	YES
USE_X11=	YES

.include "../../graphics/png/buildlink3.mk"
.include "../../fonts/Xft2/buildlink3.mk"
.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
