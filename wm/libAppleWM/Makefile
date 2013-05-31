# $NetBSD: Makefile,v 1.1 2013/05/31 00:36:55 rodent Exp $
#

DISTNAME=	libAppleWM-1.4.0
CATEGORIES=	x11 devel
MASTER_SITES=	${MASTER_SITE_XORG:=lib/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://xorg.freedesktop.org/
COMMENT=	AppleWM library from modular X.org
LICENSE=	mit

PREV_PKGPATH=	x11/libAppleWM

ONLY_FOR_PLATFORM=	Darwin-*-*

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config
CONFIGURE_ENV+=		LIB_MAN_SUFFIX=3
PKGCONFIG_OVERRIDE+=	applewm.pc.in

.include "../../wm/applewmproto/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
