# $NetBSD: Makefile,v 1.4 2003/06/10 23:13:43 jmc Exp $
#

DISTNAME=	fbdesk-1.1.4
CATEGORIES=	x11 wm
MASTER_SITES=	http://fluxbox.sourceforge.net/download/

MAINTAINER=	jrp@hispabsd.org
HOMEPAGE=	http://fluxbox.sourceforge.net/fbdesk/
COMMENT=	Application that creates and manage icons on your Fluxbox desktop

DEPENDS+=	fluxbox>=0.1.14:../../wm/fluxbox

USE_BUILDLINK2=	YES
USE_LIBTOOL=	YES
GNU_CONFIGURE=	YES
USE_X11=	YES

LIBTOOL_OVERRIDE=       ${WRKSRC}/libtool

.include "../../graphics/png/buildlink2.mk"
.include "../../fonts/Xft2/buildlink2.mk"
.include "../../devel/pkgconfig/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
