# $NetBSD: Makefile,v 1.2 2003/02/21 14:09:18 wiz Exp $
#

DISTNAME=	fbdesk-1.1.3
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
.include "../../mk/bsd.pkg.mk"
