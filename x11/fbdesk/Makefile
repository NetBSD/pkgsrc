# $NetBSD: Makefile,v 1.1.1.1 2003/02/17 21:51:52 jschauma Exp $
#

DISTNAME=	fbdesk-1.1.3
CATEGORIES=	x11 wm
MASTER_SITES=	http://fluxbox.sourceforge.net/download/

MAINTAINER=	jrp@hispabsd.org
HOMEPAGE=	http://fluxbox.sourceforge.net/fbdesk/
COMMENT=	Application that creates and manage icons on your Fluxbox desktop

DEPENDS+=	fluxbox:../../wm/fluxbox

USE_BUILDLINK2=	YES
USE_LIBTOOL=	YES
GNU_CONFIGURE=	YES
USE_X11=	YES

LIBTOOL_OVERRIDE=       ${WRKSRC}/libtool

.include "../../graphics/png/buildlink2.mk"
.include "../../fonts/Xft2/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
