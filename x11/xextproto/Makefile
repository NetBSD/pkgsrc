# $NetBSD: Makefile,v 1.12 2011/10/16 17:05:38 cheusov Exp $
#

DISTNAME=		xextproto-7.2.0
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_XORG:=proto/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		joerg@NetBSD.org
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		XExt extension headers from X.org
LICENSE=		mit

PKG_DESTDIR_SUPPORT=	user-destdir

CONFLICTS+=		xextensions-[0-9]*

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--without-xmlto
PKGCONFIG_OVERRIDE+=	${WRKSRC}/xextproto.pc.in

post-install:
	${INSTALL_DATA} ${FILESDIR}/shmstr.h ${DESTDIR}${PREFIX}/include/X11/extensions

.include "../../mk/bsd.pkg.mk"
