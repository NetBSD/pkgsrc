# $NetBSD: Makefile,v 1.1.1.1 2006/11/14 15:27:49 joerg Exp $
#

DISTNAME=		liblbxutil-1.0.1
CATEGORIES=		x11
MASTER_SITES=		http://xorg.freedesktop.org/releases/individual/lib/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		joerg@NetBSD.org
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		Low-Bandwidth X (LBX) utilities library

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LIBTOOL=		yes
PKGCONFIG_OVERRIDE+=	${WRKSRC}/lbxutil.pc.in
USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		yes

.include "../../devel/zlib/buildlink3.mk"
.include "../../x11/xextproto/buildlink3.mk"
.include "../../x11/xproto/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
