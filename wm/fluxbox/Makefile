# $NetBSD: Makefile,v 1.20 2005/03/24 15:00:40 jmcneill Exp $
#

DISTNAME=	fluxbox-0.9.12
CATEGORIES=	wm x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=fluxbox/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jmcneill@NetBSD.org
HOMEPAGE=	http://fluxbox.sourceforge.net/
COMMENT=	Window Manager for X based on Blackbox

DEPENDS=	bsetroot>=0.1nb1:../../wm/bsetroot

USE_BUILDLINK3=	YES
USE_X11=	YES
USE_LANGUAGES=	c c++
GNU_CONFIGURE=	YES
USE_GNU_TOOLS=	make
USE_LIBTOOL=	YES

CONFIGURE_ARGS+=	--enable-nls
CONFIGURE_ARGS+=	--enable-xinerama

.include "../../mk/bsd.prefs.mk"
.include "options.mk"

.include "../../mk/bsd.pkg.mk"
