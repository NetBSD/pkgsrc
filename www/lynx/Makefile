# $NetBSD: Makefile,v 1.116 2014/02/20 10:07:35 wiz Exp $

DISTNAME=	lynx2.8.8rel.1
PKGNAME=	${DISTNAME:S/lynx/lynx-/:S/rel//}
CATEGORIES=	www
MASTER_SITES=	http://lynx.isc.org/${SUBDIR:Q}/ \
		ftp://ftp.cyf-kr.edu.pl/pub/unix/lynx/${SUBDIR:Q}/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://lynx.isc.org/
COMMENT=	Alphanumeric display oriented World-Wide Web Client
LICENSE=	gnu-gpl-v2

# problem with WWW/Library/Implementation
MAKE_JOBS_SAFE=		no

PKG_INSTALLATION_TYPES=	overwrite pkgviews

SUBDIR=			current
WRKSRC=			${WRKDIR}/lynx2-8-8
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
BROKEN_GETTEXT_DETECTION= yes
INSTALL_TARGET=		install-full
MAKE_FILE=		makefile

CONFIGURE_ENV+=		GZIP=${TOOLS_GZIP_CMD:Q}
CONFIGURE_ENV+=		UNZIP=${TOOLS_PATH.unzip:Q}
USE_TOOLS+=		gzip msgfmt unzip:run

CONF_FILES+=		share/examples/lynx/lynx.cfg ${PKG_SYSCONFDIR}/lynx.cfg
CONF_FILES+=		share/examples/lynx/lynx.lss ${PKG_SYSCONFDIR}/lynx.lss

# But no dependency on Perl.
REPLACE_PERL+=			samples/mailto-form.pl
CHECK_INTERPRETER_SKIP+=	share/lynx/lynx_doc/samples/mailto-form.pl

.include "options.mk"

# For nls/gettext
CONFIGURE_ARGS+=	--enable-nls
CONFIGURE_ARGS+=	--with-nls-datadir=${PREFIX}/${PKGLOCALEDIR}
CONFIGURE_ARGS+=	--without-included-gettext

# With SSL, lynx can get https:// and snews:// URL's.
CONFIGURE_ARGS+=	--with-ssl
CPPFLAGS+=		-I${BUILDLINK_PREFIX.openssl}/include/openssl

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

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
