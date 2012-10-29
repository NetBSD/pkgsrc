# $NetBSD: Makefile,v 1.8 2012/10/29 05:06:09 asau Exp $
#

DISTNAME=		dri2proto-2.8
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_XORG:=proto/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		DRI2 extension headers from modular X.org

GNU_CONFIGURE=		yes
PKGCONFIG_OVERRIDE+=	dri2proto.pc.in

.include "../../mk/bsd.pkg.mk"
