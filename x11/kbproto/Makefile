# $NetBSD: Makefile,v 1.6 2012/10/29 05:06:22 asau Exp $
#

DISTNAME=		kbproto-1.0.6
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_XORG:=proto/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		joerg@NetBSD.org
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		KB extension headers from X.org
LICENSE=		mit

CONFLICTS+=		xextensions-[0-9]*

GNU_CONFIGURE=		yes
PKGCONFIG_OVERRIDE+=	kbproto.pc.in

.include "../../mk/bsd.pkg.mk"
