# $NetBSD: Makefile,v 1.43 2001/12/21 03:55:50 fredb Exp $
#

DISTNAME=		lynx2.8.4rel.1
PKGNAME=		lynx-2.8.4.1
CATEGORIES=		www
MASTER_SITES=		http://lynx.isc.org/release/ \
			ftp://lynx.isc.org/lynx/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		fredb@netbsd.org
HOMEPAGE=		http://lynx.browser.org/
COMMENT=		Alphanumeric display oriented World-Wide Web Client

BUILD_USES_MSGFMT=	yes

WRKSRC=			${WRKDIR}/lynx2-8-4

GNU_CONFIGURE=		yes
USE_LIBINTL=		yes
USE_SSL=		yes
INSTALL_TARGET=		install-bin install-cfg install-help install-lss
INSTALL_TARGET+=	install-doc install-man
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
CONFIGURE_ARGS+=	--enable-prettysrc
CONFIGURE_ARGS+=	--enable-read-eta

post-install:
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/share/lynx

.include "../../mk/bsd.prefs.mk"

.if (${LYNX_SCREEN_LIB} == slang)
DEPENDS+=		libslang>=1.4.4:../../devel/libslang
.elif (${LYNX_SCREEN_LIB} == ncurses)
DEPENDS+=		ncurses-[0-9]*:../../devel/ncurses
CONFIGURE_ARGS+=	--enable-color-style
.elif (${LYNX_SCREEN_LIB} != curses)
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
DEPENDS+=		socks4-2.2:../../net/socks4
.else
CONFIGURE_ARGS+= 	--with-socks5
DEPENDS+=		socks5-1.0.2:../../net/socks5
.endif
.endif

# Do IPV6 on systems which can support it.
.if defined(USE_INET6) && ${USE_INET6} == YES
CONFIGURE_ARGS+=       --enable-ipv6
.endif

.include "../../mk/bsd.pkg.mk"

# "USE_SSL", set above, pulls in the openssl package, if needed, and
# "sets SSLBASE", which we use here to tell the package where it needs
# to look for SSL libs and includes.
.if (${SSLBASE} == /usr)
SSLLIBS=	-lssl -lcrypto
SSLINCS=	-I/usr/include/openssl
.else
SSLLIBS=	-L${SSLBASE}/lib -Wl,-R${SSLBASE}/lib -lssl -lcrypto
SSLINCS=	-I${SSLBASE}/include -I${SSLBASE}/include/openssl
.endif
