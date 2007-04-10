# $NetBSD: Makefile,v 1.1.1.1 2007/04/10 13:47:08 joerg Exp $
#

DISTNAME=		xproxymanagementprotocol-1.0.2
CATEGORIES=		x11
MASTER_SITES=		http://xorg.freedesktop.org/releases/individual/proto/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		joerg@NetBSD.org
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		X Proxy Management extension headers from modular X.org X11

PKG_DESTDIR_SUPPORT=	user-destdir

PKGCONFIG_OVERRIDE+=	xproxymngproto.pc.in
GNU_CONFIGURE=		yes
USE_LANGUAGES=		# empty

.include "../../mk/bsd.pkg.mk"
