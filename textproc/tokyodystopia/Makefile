# $NetBSD: Makefile,v 1.1.1.1 2008/09/04 12:21:20 obache Exp $
#

DISTNAME=	tokyodystopia-0.9.5
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=tokyocabinet/}

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://tokyocabinet.sourceforge.net/dystopiadoc/
COMMENT=	Full-text search system

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake pkg-config

PKGCONFIG_OVERRIDE+=	tokyodystopia.pc.in

CONFIGURE_ARGS+=	--enable-zlib
CONFIGURE_ARGS+=	--enable-bzip

TEST_TARGET=	check

.include "../../databases/tokyocabinet/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../archivers/bzip2/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
PTHREAD_AUTO_VARS=	yes
CONFIGURE_ARGS+=	--enable-pthread
SUBST_CLASSES+=		pthread
SUBST_STAGE.pthread=	pre-configure
SUBST_FILES.pthread=	configure
SUBST_SED.pthread=	-e 's|-lpthread|${PTHREAD_LIBS}|'
.include "../../mk/bsd.pkg.mk"
