# $NetBSD: Makefile,v 1.25 2014/04/15 08:29:23 wiz Exp $

DISTNAME=		xproto-7.0.26
CATEGORIES=		x11 devel
MASTER_SITES=		${MASTER_SITE_XORG:=proto/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		joerg@NetBSD.org
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		X protocol and ancillary headers from Xorg X11
LICENSE=		mit

PKG_INSTALLATION_TYPES=	overwrite pkgviews

GNU_CONFIGURE=		yes
PKGCONFIG_OVERRIDE+=	xproto.pc.in
USE_LANGUAGES=		c

post-extract:
	${MV} ${WRKSRC}/Xos_r.h ${WRKSRC}/Xos_r.h.in
	sleep 1 && ${TOUCH} ${WRKSRC}/aclocal.m4 ${WRKSRC}/Makefile.in

.include "../../mk/bsd.pkg.mk"
