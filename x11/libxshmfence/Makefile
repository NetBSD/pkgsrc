# $NetBSD: Makefile,v 1.3 2015/09/24 23:34:16 tnn Exp $

DISTNAME=	libxshmfence-1.2
PKGREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	http://xorg.freedesktop.org/archive/individual/lib/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://xorg.freedesktop.org/
COMMENT=	Shared memory 'SyncFence' synchronization primitive
LICENSE=	mit

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config autoconf automake autoreconf

PKGCONFIG_OVERRIDE+=	xshmfence.pc.in

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
CONFIGURE_ARGS+=	--disable-futex
CONFIGURE_ARGS+=	--enable-semaphore
LIBXSHM_PAGESIZE!=	/sbin/sysctl -n hw.pagesize
CPPFLAGS+=		-DLIBXSHM_PAGESIZE=${LIBXSHM_PAGESIZE}
.endif

post-extract:
	cp ${FILESDIR}/xshmfence_semaphore.[ch] ${WRKSRC}/src

pre-configure:
	cd ${WRKSRC} && autoreconf -vif

.include "../../devel/xorg-util-macros/buildlink3.mk"
.include "../../x11/xproto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
