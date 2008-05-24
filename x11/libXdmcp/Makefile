# $NetBSD: Makefile,v 1.3 2008/05/24 21:45:15 tnn Exp $
#

DISTNAME=		libXdmcp-1.0.2
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_XORG:=lib/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		joerg@NetBSD.org
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		X Display Manager Control Protocol library from X.org

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config
PKGCONFIG_OVERRIDE+=	xdmcp.pc.in
GNU_CONFIGURE=		yes

.include "../../x11/xproto/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
