# $NetBSD: Makefile,v 1.10 2009/06/14 06:04:11 obache Exp $
#

DISTNAME=	tokyodystopia-0.9.12
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=tokyocabinet/}

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://tokyocabinet.sourceforge.net/dystopiadoc/
COMMENT=	Full-text search system
LICENSE=	gnu-lgpl-v2.1

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake pkg-config

PKGCONFIG_OVERRIDE+=	tokyodystopia.pc.in

CONFIGURE_ARGS+=	--enable-zlib
CONFIGURE_ARGS+=	--enable-bzip

TEST_TARGET=	check

BUILDLINK_API_DEPENDS.tokyocabinet+=	tokyocabinet>=1.4.17
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
