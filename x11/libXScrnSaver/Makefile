# $NetBSD: Makefile,v 1.11 2016/02/26 11:27:14 jperkin Exp $
#

DISTNAME=		libXScrnSaver-1.2.2
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_XORG:=lib/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		joerg@NetBSD.org
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		X11 Screen Saver Library

CONFLICTS+=		scrnsaverproto<1.2.0

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config

PKGCONFIG_OVERRIDE+=	xscrnsaver.pc.in

CONFIGURE_ARGS.NetBSD+=	--disable-malloc0returnsnull

.include "../../meta-pkgs/modular-xorg/hacks.mk"

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
BUILDLINK_API_DEPENDS.scrnsaverproto+=	scrnsaverproto>=1.2.0
.include "../../x11/scrnsaverproto/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
