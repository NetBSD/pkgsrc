# $NetBSD: Makefile,v 1.148 2024/05/16 06:15:42 wiz Exp $

DISTNAME=	lynx2.8.9rel.1
PKGNAME=	${DISTNAME:S/lynx/lynx-/:S/rel//}
PKGREVISION=	12
CATEGORIES=	www
MASTER_SITES=	https://invisible-mirror.net/archives/lynx/tarballs/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://lynx.invisible-island.net/
COMMENT=	Alphanumeric display oriented World-Wide Web Client
LICENSE=	gnu-gpl-v2 # OpenSSL exception

# problem with WWW/Library/Implementation
MAKE_JOBS_SAFE=		no

SUBDIR=				current
USE_PKGLOCALEDIR=		yes
GNU_CONFIGURE=			yes
BROKEN_GETTEXT_DETECTION=	yes
INSTALL_TARGET=			install-full
MAKE_FILE=			makefile

CONFIGURE_ENV+=		GZIP=${TOOLS_GZIP_CMD:Q}
CONFIGURE_ENV+=		UNZIP=${TOOLS_PATH.unzip:Q}
USE_TOOLS+=		gzip msgfmt unzip:run

CONF_FILES+=		share/examples/lynx/lynx.cfg ${PKG_SYSCONFDIR}/lynx.cfg
CONF_FILES+=		share/examples/lynx/lynx.lss ${PKG_SYSCONFDIR}/lynx.lss

# But no dependency on Perl.
REPLACE_PERL+=			samples/mailto-form.pl
CHECK_INTERPRETER_SKIP+=	share/lynx/lynx_doc/samples/mailto-form.pl
CHECK_WRKREF_SKIP+=		bin/lynx

.include "options.mk"

# For nls/gettext
CONFIGURE_ARGS+=	--enable-nls
CONFIGURE_ARGS+=	--with-nls-datadir=${PREFIX}/${PKGLOCALEDIR}
CONFIGURE_ARGS+=	--without-included-gettext

# Note: --enable-{default-colors,scrollbar} are simply ignored
# for certain settings of --with-screen.
CONFIGURE_ARGS+=	--with-screen=${SCREENTYPE:Q}
CONFIGURE_ARGS+=	--enable-default-colors
CONFIGURE_ARGS+=	--enable-scrollbar

# Install gzip'ed help files to ${PREFIX}/share/lynx
CONFIGURE_ARGS+=	--datadir="${PREFIX}/share/lynx"
CONFIGURE_ARGS+=	--enable-gzip-help --with-zlib

# Miscellaneous
CONFIGURE_ARGS+=	--enable-externs
CONFIGURE_ARGS+=	--enable-source-cache
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}

# Experimental features
CONFIGURE_ARGS+=	--enable-file-upload
CONFIGURE_ARGS+=	--enable-justify-elts
CONFIGURE_ARGS+=	--enable-kbd-layout
CONFIGURE_ARGS+=	--enable-nested-tables
CONFIGURE_ARGS+=	--enable-prettysrc
CONFIGURE_ARGS+=	--enable-read-eta

.if !empty(USE_CROSS_COMPILE:M[yY][eE][sS])
CONFIGURE_ENV+=		BUILD_CC=${NATIVE_CC:Q}
.endif

CONFIGURE_ENV.SunOS+=	cf_cv_xopen_source=no

.include "../../devel/gettext-tools/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
