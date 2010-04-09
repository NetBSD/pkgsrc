# $NetBSD: Makefile,v 1.4 2010/04/09 08:27:31 tnn Exp $
#

DISTNAME=		recordproto-1.14
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_XORG:=proto/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		joerg@NetBSD.org
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		Record extension headers from X.org

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
PKGCONFIG_OVERRIDE+=	recordproto.pc.in

.include "../../mk/bsd.pkg.mk"
