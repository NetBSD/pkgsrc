# $NetBSD: Makefile,v 1.6 2004/02/14 17:21:55 jlam Exp $
#

DISTNAME=	fbdesk-1.1.4
CATEGORIES=	x11 wm
MASTER_SITES=	http://fluxbox.sourceforge.net/download/

MAINTAINER=	xtraeme@NetBSD.org
HOMEPAGE=	http://fluxbox.sourceforge.net/fbdesk/
COMMENT=	Application that creates and manage icons on your Fluxbox desktop

DEPENDS+=	fluxbox>=0.1.14:../../wm/fluxbox

USE_BUILDLINK2=	YES
USE_LIBTOOL=	YES
GNU_CONFIGURE=	YES
USE_X11=	YES

.include "../../graphics/png/buildlink2.mk"
.include "../../fonts/Xft2/buildlink2.mk"
.include "../../devel/pkgconfig/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
