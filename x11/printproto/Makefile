# $NetBSD: Makefile,v 1.6 2012/07/02 16:03:46 joerg Exp $
#

DISTNAME=		printproto-1.0.5
CATEGORIES=		x11 print
MASTER_SITES=		${MASTER_SITE_XORG:=proto/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		joerg@NetBSD.org
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		Print extension headers from X.org

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		yes

PKGCONFIG_OVERRIDE+=	printproto.pc.in

CONFIGURE_ENV+=		MISC_MAN_SUFFIX=7

.include "../../x11/xproto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
