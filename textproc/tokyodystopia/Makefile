# $NetBSD: Makefile,v 1.13 2009/12/19 12:56:45 obache Exp $
#

DISTNAME=	tokyodystopia-0.9.13
PKGREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=tokyocabinet/}

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://1978th.net/tokyodystopia/
COMMENT=	Full-text search system
LICENSE=	gnu-lgpl-v2.1

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake pkg-config

PKGCONFIG_OVERRIDE+=	tokyodystopia.pc.in

TEST_TARGET=	check

BUILDLINK_API_DEPENDS.tokyocabinet+=	tokyocabinet>=1.4.29
.include "../../databases/tokyocabinet/buildlink3.mk"
.if !empty(PKG_BUILD_OPTIONS.tokyocabinet:Mbzip2)
CONFIGURE_ARGS+=	--enable-bzip
CONFIGURE_ARGS+=	--with-bzip=${BUILDLINK_PREFIX.bzip2}
.else
CONFIGURE_ARGS+=	--disable-bzip
.endif
.if !empty(PKG_BUILD_OPTIONS.tokyocabinet:Mzlib)
CONFIGURE_ARGS+=	--enable-zlib
CONFIGURE_ARGS+=	--with-zlib=${BUILDLINK_PREFIX.zlib}
.else
CONFIGURE_ARGS+=	--disable-zlib
.endif
.include "../../mk/pthread.buildlink3.mk"
PTHREAD_AUTO_VARS=	yes
CONFIGURE_ARGS+=	--enable-pthread
SUBST_CLASSES+=		pthread
SUBST_STAGE.pthread=	pre-configure
SUBST_FILES.pthread=	configure
SUBST_SED.pthread=	-e 's|-lpthread|${PTHREAD_LIBS}|'
.include "../../mk/bsd.pkg.mk"
