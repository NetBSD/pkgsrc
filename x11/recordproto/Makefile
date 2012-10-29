# $NetBSD: Makefile,v 1.6 2012/10/29 05:06:48 asau Exp $
#

DISTNAME=		recordproto-1.14.2
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_XORG:=proto/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		joerg@NetBSD.org
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		Record extension headers from X.org

GNU_CONFIGURE=		yes
PKGCONFIG_OVERRIDE+=	recordproto.pc.in

.include "../../mk/bsd.pkg.mk"
