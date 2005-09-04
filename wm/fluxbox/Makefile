# $NetBSD: Makefile,v 1.26 2005/09/04 20:21:18 tonio Exp $
#

DISTNAME=	fluxbox-0.9.13
CATEGORIES=	wm x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=fluxbox/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jmcneill@NetBSD.org
HOMEPAGE=	http://fluxbox.sourceforge.net/
COMMENT=	Window Manager for X based on Blackbox

DEPENDS=	bsetroot>=0.1nb1:../../wm/bsetroot

USE_LANGUAGES=	c c++
GNU_CONFIGURE=	YES
USE_TOOLS=	gmake
USE_LIBTOOL=	YES

.include "../../mk/bsd.prefs.mk"

BUILDLINK_TRANSFORM+=	rename:-O2:-O1

CONFIGURE_ARGS+=	--enable-nls
CONFIGURE_ARGS+=	--enable-xinerama

.include "options.mk"

.include "../../converters/libiconv/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
