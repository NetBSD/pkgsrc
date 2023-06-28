# $NetBSD: Makefile,v 1.21 2023/06/28 01:34:36 riastradh Exp $

DISTNAME=	libxshmfence-1.3.2
PKGREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_XORG:=lib/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://xorg.freedesktop.org/
COMMENT=	Shared memory 'SyncFence' synchronization primitive
LICENSE=	mit

GNU_CONFIGURE=	yes
TEST_TARGET=	check
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config autoconf automake autoreconf

PKGCONFIG_OVERRIDE+=	xshmfence.pc.in

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
CONFIGURE_ARGS+=	--disable-futex
CONFIGURE_ARGS+=	--enable-semaphore
.endif

post-extract:
	cp ${FILESDIR}/xshmfence_semaphore.[ch] ${WRKSRC}/src

pre-configure:
	cd ${WRKSRC} && autoreconf -vif

TOOL_DEPENDS+=	xorg-util-macros>=0:../../devel/xorg-util-macros

.include "../../mk/pthread.buildlink3.mk"
X11_LIB_NAME?=		libxshmfence
.include "../../meta-pkgs/modular-xorg/avoid-duplicate.mk"
.include "../../x11/xorgproto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
