# $NetBSD: Makefile,v 1.15 2013/12/31 17:34:27 wiz Exp $

DISTNAME=		xextproto-7.3.0
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_XORG:=proto/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		joerg@NetBSD.org
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		XExt extension headers from X.org
LICENSE=		mit

CONFLICTS+=		xextensions-[0-9]*

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--without-xmlto
PKGCONFIG_OVERRIDE+=	${WRKSRC}/xextproto.pc.in

post-install:
	${INSTALL_DATA} ${FILESDIR}/shmstr.h ${DESTDIR}${PREFIX}/include/X11/extensions

.include "../../mk/bsd.pkg.mk"
