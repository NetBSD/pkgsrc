# $NetBSD: Makefile,v 1.15 2009/03/06 10:28:32 wiz Exp $
#

DISTNAME=		xproto-7.0.15
CATEGORIES=		x11 devel
MASTER_SITES=		${MASTER_SITE_XORG:=proto/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		joerg@NetBSD.org
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		X protocol and ancillary headers from Xorg X11

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
PKGCONFIG_OVERRIDE+=	xproto.pc.in
USE_LANGUAGES=		c

post-extract:
	${MV} ${WRKSRC}/Xos_r.h ${WRKSRC}/Xos_r.h.in

.include "../../mk/bsd.pkg.mk"
