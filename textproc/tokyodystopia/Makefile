# $NetBSD: Makefile,v 1.19 2019/07/11 09:25:26 nia Exp $
#

DISTNAME=	tokyodystopia-0.9.15
CATEGORIES=	textproc
MASTER_SITES=	${HOMEPAGE}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://fallabs.com/tokyodystopia/
COMMENT=	Full-text search system
LICENSE=	gnu-lgpl-v2.1

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake pkg-config

PKGCONFIG_OVERRIDE+=	tokyodystopia.pc.in

TEST_TARGET=	check

post-extract:
		${RM} -f ${WRKSRC}/doc/index.html~

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
PTHREAD_OPTS+=		require
.include "../../mk/pthread.buildlink3.mk"
PTHREAD_AUTO_VARS=	yes
SUBST_CLASSES+=		pthread
SUBST_STAGE.pthread=	pre-configure
SUBST_FILES.pthread=	configure
SUBST_SED.pthread=	-e 's|-lpthread|${PTHREAD_LIBS}|'
.include "../../mk/bsd.pkg.mk"
