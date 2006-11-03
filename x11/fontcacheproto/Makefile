# $NetBSD: Makefile,v 1.1.1.1 2006/11/03 19:54:04 joerg Exp $
#

DISTNAME=		fontcacheproto-0.1.2
CATEGORIES=		x11
MASTER_SITES=		http://xorg.freedesktop.org/releases/individual/proto/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		joerg@NetBSD.org
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		Fontcache extension headers from X.org

PKG_DESTDIR_SUPPORT=	user-destdir

USE_PKGLOCALEDIR=	yes
PKGCONFIG_OVERRIDE+=	${WRKSRC}/fontcacheproto.pc.in
GNU_CONFIGURE=		yes

.include "../../mk/bsd.pkg.mk"
