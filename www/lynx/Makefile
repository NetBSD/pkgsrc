# $NetBSD: Makefile,v 1.98 2007/05/11 22:22:40 wiz Exp $

#
# NOTE: Please do not enable the lynxcgi feature unless it is lynx
# version 2.8.6dev.15 or later.  There is a known security issue
# with this feature in earlier versions.
#

DISTNAME=	lynx2.8.6rel.5
PKGNAME=	lynx-2.8.6.5
CATEGORIES=	www
MASTER_SITES=	http://lynx.isc.org/${SUBDIR:Q}/ \
		ftp://ftp.nl.uu.net/pub/unix/www/lynx/${SUBDIR:Q}/ \
		ftp://ftp.cyf-kr.edu.pl/pub/unix/lynx/${SUBDIR:Q}/ \
		ftp://ftp.netlab.is.tsukuba.ac.jp/pub/network/WWW/lynx/${SUBDIR:Q}/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	fredb@NetBSD.org
HOMEPAGE=	http://lynx.isc.org/
COMMENT=	Alphanumeric display oriented World-Wide Web Client

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

SUBDIR=			current
WRKSRC=			${WRKDIR}/lynx2-8-6
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
BROKEN_GETTEXT_DETECTION= yes
INSTALL_TARGET=		install-full
MAKE_FILE=		makefile

CONFIGURE_ENV+=		GZIP=${TOOLS_GZIP_CMD:Q}
USE_TOOLS+=		gzip msgfmt

CONF_FILES+=		share/examples/lynx/lynx.cfg ${PKG_SYSCONFDIR}/lynx.cfg
CONF_FILES+=		share/examples/lynx/lynx.lss ${PKG_SYSCONFDIR}/lynx.lss

# But no dependency on Perl.
REPLACE_PERL+=		samples/mailto-form.pl
CHECK_FILES_SKIP+=	samples/mailto-form.pl

.include "options.mk"

# For nls/gettext
CONFIGURE_ARGS+=	--enable-nls
CONFIGURE_ARGS+=	--with-nls-datadir=${PREFIX}/${PKGLOCALEDIR}
CONFIGURE_ARGS+=	--without-included-gettext

# With SSL, lynx can get https:// and snews:// URL's.
CONFIGURE_ARGS+=	--with-ssl

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

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
