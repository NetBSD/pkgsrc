# $NetBSD: Makefile,v 1.1.1.1 2010/10/16 13:10:05 obache Exp $
#

DISTNAME=		libAppleWM-1.4.0
CATEGORIES=		x11 devel
MASTER_SITES=		${MASTER_SITE_XORG:=lib/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		AppleWM library from modular X.org
LICENSE=		mit

PKG_DESTDIR_SUPPORT=	user-destdir

ONLY_FOR_PLATFORM=	Darwin-*-*

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config
CONFIGURE_ENV+=		LIB_MAN_SUFFIX=3
PKGCONFIG_OVERRIDE+=	applewm.pc.in

.include "../../x11/applewmproto/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/xextproto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
