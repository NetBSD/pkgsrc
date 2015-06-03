# $NetBSD: Makefile,v 1.1 2015/06/03 11:00:15 fhajny Exp $

DISTNAME=	spdylay-1.3.2
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=tatsuhiro-t/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/tatsuhiro-t/spdylay/
COMMENT=	Experimental SPDY protocol version 2, 3 and 3.1 implementation in C
LICENSE=	mit

GITHUB_RELEASE=	v${PKGVERSION_NOREV}

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=	lib/libspdylay.pc.in

CONFIGURE_ARGS=	--enable-examples --enable-src
CONFIGURE_ENV+=	LIBEVENT_OPENSSL_CFLAGS="-I${BUILDLINK_PREFIX.libevent}/include"
CONFIGURE_ENV+=	LIBEVENT_OPENSSL_LIBS="-L${BUILDLINK_PREFIX.libevent}/lib -levent_openssl -levent"

.include "../../mk/bsd.prefs.mk"

LIBS.SunOS+=	-lsocket

# bin/spdyd requires epoll or kqueue
PLIST_VARS+=	spdyd
.if ${OPSYS} != "SunOS"
PLIST.spdyd=	yes
.endif

BUILDLINK_API_DEPENDS.libevent+=	libevent>=2.0.8
BUILDLINK_API_DEPENDS.openssl+=		openssl>=1.0.1

.include "../../devel/libevent/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
