# $NetBSD: Makefile,v 1.16 2015/05/27 06:42:07 wiz Exp $

DISTNAME=		randrproto-1.5.0
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_XORG:=proto/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		joerg@NetBSD.org
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		Randr extension headers from modular X.org

CONFLICTS+=		randrext-[0-9]*

GNU_CONFIGURE=		yes
PKGCONFIG_OVERRIDE+=	randrproto.pc.in

.include "../../mk/bsd.pkg.mk"
