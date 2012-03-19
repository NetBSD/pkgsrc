# $NetBSD: Makefile,v 1.18 2012/03/19 19:08:36 bsiegert Exp $
#

DISTNAME=		xproto-7.0.18
PKGREVISION=		1
CATEGORIES=		x11 devel
MASTER_SITES=		${MASTER_SITE_XORG:=proto/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		joerg@NetBSD.org
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		X protocol and ancillary headers from Xorg X11
LICENSE=		mit

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
PKGCONFIG_OVERRIDE+=	xproto.pc.in
USE_LANGUAGES=		c

post-extract:
	${MV} ${WRKSRC}/Xos_r.h ${WRKSRC}/Xos_r.h.in

.include "../../mk/bsd.pkg.mk"
