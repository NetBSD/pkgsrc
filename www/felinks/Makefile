# $NetBSD: Makefile,v 1.1 2020/06/20 15:13:56 nia Exp $

DISTNAME=	felinks-0.13.2
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=rkd77/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/rkd77/felinks
COMMENT=	Fork of elinks, the text web browser
LICENSE=	gnu-gpl-v2

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake pkg-config aclocal autoconf autoheader automake
USE_TOOLS+=		msgfmt xgettext

pre-configure:
	cd ${WRKSRC} && ${CONFIG_SHELL} autogen.sh

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
.include "../../lang/lua/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
