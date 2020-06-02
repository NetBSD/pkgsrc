# $NetBSD: Makefile,v 1.9 2020/06/02 08:23:01 adam Exp $

DISTNAME=	spdylay-1.4.0
PKGREVISION=	2
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=tatsuhiro-t/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/tatsuhiro-t/spdylay/
COMMENT=	Experimental SPDY protocol version 2, 3 and 3.1 implementation in C
LICENSE=	mit

GITHUB_RELEASE=	v${PKGVERSION_NOREV}

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		yes

CONFIGURE_ARGS=		--enable-examples
CONFIGURE_ARGS+=	--enable-src
CONFIGURE_ENV+=		LIBEVENT_OPENSSL_CFLAGS="-I${BUILDLINK_PREFIX.libevent}/include"
CONFIGURE_ENV+=		LIBEVENT_OPENSSL_LIBS="-L${BUILDLINK_PREFIX.libevent}/lib -levent_openssl -levent"

PKGCONFIG_OVERRIDE+=	lib/libspdylay.pc.in

.include "../../mk/bsd.prefs.mk"

CPPFLAGS+=		-D__STDC_LIMIT_MACROS

LIBS.SunOS+=	-lsocket

# bin/spdyd requires epoll or kqueue
PLIST_VARS+=	spdyd
.if ${OPSYS} != "SunOS"
PLIST.spdyd=	yes
.endif

BUILDLINK_API_DEPENDS.libevent+=	libevent>=2.0.8

.include "../../devel/libevent/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
