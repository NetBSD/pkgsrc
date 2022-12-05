# $NetBSD: Makefile,v 1.10 2022/12/05 09:32:34 wiz Exp $

DISTNAME=	elinks-0.15.1
PKGNAME=	${DISTNAME:S/elinks/felinks/}
PKGREVISION=	1
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=rkd77/}
GITHUB_RELEASE=	v${PKGVERSION_NOREV}
DIST_SUBDIR=	felinks
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/rkd77/elinks
COMMENT=	Fork of elinks, the text web browser
LICENSE=	gnu-gpl-v2

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_LANGUAGES=		c c++
USE_TOOLS+=		gmake pkg-config
USE_TOOLS+=		msgfmt xgettext

# ld: no input files
MAKE_JOBS_SAFE=	no

post-install:
	${RM} -f ${DESTDIR}${PREFIX}/lib/charset.alias

CONFIGURE_ARGS+=	--datadir=${PREFIX}/share/${PKGBASE}
CONFIGURE_ARGS+=	--enable-256-colors
CONFIGURE_ARGS+=	--enable-utf-8
CONFIGURE_ARGS+=	--without-bzlib
CONFIGURE_ARGS+=	--without-lzma
CONFIGURE_ARGS+=	--without-lua

.include "../../mk/bsd.prefs.mk"

# for backtrace
.if ${OPSYS} == "NetBSD" && exists(/usr/include/execinfo.h)
LIBS+=	-lexecinfo
.endif

.include "options.mk"

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/libidn/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
