# $NetBSD: Makefile,v 1.84 2024/05/16 06:15:40 wiz Exp $

DISTNAME=	elinks-0.17.0
PKGREVISION=	1
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=rkd77/}
GITHUB_RELEASE=	v${PKGVERSION_NOREV}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/rkd77/elinks
COMMENT=	Feature-rich text mode web browser
LICENSE=	gnu-gpl-v2

CONFLICTS+=	felinks-[0-9]*
SUPERSEDES+=	felinks-[0-9]*

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_LANGUAGES=		c c++
USE_CXX_FEATURES+=	c++17
USE_TOOLS+=		bash gmake pkg-config
USE_TOOLS+=		msgfmt xgettext

# uses '<<<'
CONFIG_SHELL=		bash

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
