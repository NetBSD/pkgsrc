# $NetBSD: Makefile,v 1.10 2012/10/29 05:06:08 asau Exp $
#

DISTNAME=		compositeproto-0.4.2
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_XORG:=proto/}

MAINTAINER=		joerg@NetBSD.org
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		Composite extension headers from modular X.org

CONFLICTS+=		compositeext-[0-9]*

GNU_CONFIGURE=		YES
PKGCONFIG_OVERRIDE+=	compositeproto.pc.in

.include "../../x11/fixesproto/buildlink3.mk"
.include "../../x11/xproto/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
