# $NetBSD: Makefile,v 1.6 2012/10/29 05:06:52 asau Exp $
#

DISTNAME=		scrnsaverproto-1.2.2
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_XORG:=proto/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		joerg@NetBSD.org
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		ScrnSaver extension headers from X.org

GNU_CONFIGURE=		yes
PKGCONFIG_OVERRIDE+=	scrnsaverproto.pc.in
USE_LANGUAGES=		c

.include "../../x11/xproto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
