# $NetBSD: Makefile,v 1.4 2012/10/29 05:07:19 asau Exp $
#

DISTNAME=		xproxymanagementprotocol-1.0.3
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_XORG:=proto/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		joerg@NetBSD.org
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		X Proxy Management extension headers from modular X.org X11

PKGCONFIG_OVERRIDE+=	xproxymngproto.pc.in
GNU_CONFIGURE=		yes

.include "../../mk/bsd.pkg.mk"
