# $NetBSD: Makefile,v 1.9 2012/06/03 19:41:11 wiz Exp $
#

DISTNAME=		compositeproto-0.4.2
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_XORG:=proto/}

MAINTAINER=		joerg@NetBSD.org
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		Composite extension headers from modular X.org

PKG_DESTDIR_SUPPORT=	user-destdir

CONFLICTS+=		compositeext-[0-9]*

GNU_CONFIGURE=		YES
PKGCONFIG_OVERRIDE+=	compositeproto.pc.in

.include "../../x11/fixesproto/buildlink3.mk"
.include "../../x11/xproto/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
