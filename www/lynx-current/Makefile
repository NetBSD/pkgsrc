# $NetBSD: Makefile,v 1.46 2003/09/27 17:07:38 grant Exp $
#

DISTNAME=		lynx2.8.5dev.7
PKGNAME=		lynx-2.8.5.0.7
PKGREVISION=		2
WRKSRC=			${WRKDIR}/lynx2-8-5
CATEGORIES=		www
MASTER_SITES=		http://lynx.isc.org/current/ \
			ftp://ftp.nl.uu.net/pub/unix/www/lynx/current/ \
			ftp://ftp.cyf-kr.edu.pl/pub/unix/lynx/current/ \
			ftp://ftp.netlab.is.tsukuba.ac.jp/pub/network/WWW/lynx/current/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		fredb@NetBSD.org
HOMEPAGE=		http://lynx.browser.org/
COMMENT=		Alphanumeric display oriented World-Wide Web Client

BUILD_USES_MSGFMT=	yes

USE_BUILDLINK2=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_GMAKE=		yes
INSTALL_TARGET=		install-full install-lss
MAKEFILE=       	makefile

BUILD_DEFS+=		LYNX_SCREEN_LIB USE_SOCKS USE_INET6

# For nls/gettext
CONFIGURE_ARGS+=	--enable-nls
CONFIGURE_ARGS+=	--with-nls-datadir=${PREFIX}/share
CONFIGURE_ARGS+=	--without-included-gettext

# With SSL, lynx can get https:// and snews:// URL's.
CONFIGURE_ARGS+=	--with-ssl

# Note: --enable-{default-colors,scrollbar} are simply ignored
# for certain settings of --with-screen.
CONFIGURE_ARGS+=	--with-screen=${LYNX_SCREEN_LIB}
CONFIGURE_ARGS+=	--enable-default-colors
CONFIGURE_ARGS+=	--enable-scrollbar

# Install gzip'ed help files to ${PREFIX}/share/lynx
CONFIGURE_ARGS+=	--libdir="${PREFIX}/share/lynx"
CONFIGURE_ARGS+=	--enable-gzip-help --with-zlib

# Miscellaneous
CONFIGURE_ARGS+=	--enable-externs
CONFIGURE_ARGS+=	--enable-source-cache

# Experimental features
CONFIGURE_ARGS+=	--enable-file-upload
CONFIGURE_ARGS+=	--enable-justify-elts
CONFIGURE_ARGS+=	--enable-kbd-layout
CONFIGURE_ARGS+=	--enable-nested-tables
CONFIGURE_ARGS+=	--enable-prettysrc
CONFIGURE_ARGS+=	--enable-read-eta

post-install:
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/share/lynx

.include "../../mk/bsd.prefs.mk"

.if (${LYNX_SCREEN_LIB} == slang)
.  include "../../devel/libslang/buildlink2.mk"
.elif (${LYNX_SCREEN_LIB} == ncurses)
USE_NCURSES=		color
.  include "../../mk/curses.buildlink2.mk"
CONFIGURE_ARGS+=	--enable-color-style
.elif (${LYNX_SCREEN_LIB} == curses)
.  if ${MACHINE_PLATFORM:MNetBSD-1.5*-i386} != ""
CONFIGURE_ARGS+=	--enable-color-style
.  endif
.else
pre-configure:
	@${ECHO} '****************************************************'
	@${ECHO} '* Invalid value for LYNX_SCREEN_LIB. Please choose *'
	@${ECHO} '* one of "slang", "ncurses", or "curses"!          *'
	@${ECHO} '****************************************************'
	@${FALSE}

.endif

# Include SOCKS firewall support, if desired.
.if defined(USE_SOCKS) && (${USE_SOCKS} == 4 || ${USE_SOCKS} == 5)
.if (${LYNX_SCREEN_LIB} == slang)
pre-configure:
	@${ECHO} '******************************************************'
	@${ECHO} '* Socks may not be enabled together with the "slang" *'
	@${ECHO} '* screen library. If socks support is desired,       *'
	@${ECHO} '* please also set LYNX_SCREEN_LIB to one of "curses" *'
	@${ECHO} '* or "ncurses"!                                      *'
	@${ECHO} '******************************************************'
	@${FALSE}

.endif
.if ${USE_SOCKS} == 4
CONFIGURE_ARGS+= 	--with-socks
.  include "../../net/socks4/buildlink2.mk"
.else
CONFIGURE_ARGS+= 	--with-socks5
.  include "../../net/socks5/buildlink2.mk"
.endif
.endif

# Do IPV6 on systems which can support it.
.if defined(USE_INET6) && ${USE_INET6} == YES
CONFIGURE_ARGS+=       --enable-ipv6
.endif

.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../devel/zlib/buildlink2.mk"
.include "../../security/openssl/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
