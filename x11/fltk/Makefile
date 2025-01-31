# $NetBSD: Makefile,v 1.90 2025/01/31 12:22:44 micha Exp $

DISTNAME=	fltk-1.4.1-source
PKGNAME=	${DISTNAME:S/-source//}
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GITHUB:=fltk/}
GITHUB_PROJECT=	fltk
GITHUB_RELEASE=	release-${PKGVERSION_NOREV}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	micha@NetBSD.org
HOMEPAGE=	https://www.fltk.org/
COMMENT=	Fast Light Tool Kit for graphical user interfaces
LICENSE=	gnu-lgpl-v2

USE_LANGUAGES=		c c++
USE_CC_FEATURES+=	c99

USE_TOOLS+=		autoconf gmake nroff pkg-config
USE_LIBTOOL=		yes

PTHREAD_OPTS+=		require
GNU_CONFIGURE=		yes
GNU_CONFIGURE_STRICT=	no	# --enable-libtool is not officially known
CONFIGURE_ARGS+=	--enable-libtool=${LIBTOOL:Q}
CONFIGURE_ARGS+=	--enable-print
CONFIGURE_ARGS+=	--enable-svg
CONFIGURE_ARGS+=	--enable-threads
# Use pkgsrc versions of libraries, not package's bundled versions
CONFIGURE_ARGS+=	--disable-localjpeg
CONFIGURE_ARGS+=	--disable-localpng
CONFIGURE_ARGS+=	--disable-localzlib
# Disable build of test programs
CONFIGURE_ARGS+=	--disable-test

WRKSRC=			${WRKDIR}/${DISTNAME:S/-source//}

.include "options.mk"

BUILDLINK_API_DEPENDS.zlib+=	zlib>=1.2.3
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
