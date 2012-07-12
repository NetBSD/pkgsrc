# $NetBSD: Makefile,v 1.13 2012/07/12 14:16:49 wiz Exp $
#

DISTNAME=		randrproto-1.4.0
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_XORG:=proto/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		joerg@NetBSD.org
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		Randr extension headers from modular X.org

PKG_DESTDIR_SUPPORT=	user-destdir

CONFLICTS+=		randrext-[0-9]*

GNU_CONFIGURE=		yes
PKGCONFIG_OVERRIDE+=	randrproto.pc.in

.include "../../mk/bsd.pkg.mk"
