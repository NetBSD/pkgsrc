# $NetBSD: Makefile,v 1.7 2000/05/08 01:46:55 fredb Exp $
#

DISTNAME=		lynx2.8.3rel.1
PKGNAME=		lynx-2.8.3rel.1
CATEGORIES=		www
MASTER_SITES=		http://lynx.isc.org/current/
EXTRACT_SUFX=		.tar.bz2

PATCH_SITES=		http://www.moxienet.com/lynx/
PATCHFILES= 		lynx-283-ssl.patch.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=		fb@enteract.com
HOMEPAGE=		http://lynx.browser.org/

DEPENDS+=		gettext-0.10.*:../../devel/gettext

NO_PACKAGE=		${RESTRICTED}
RESTRICTED=		"Crypto; export-controlled"

WRKSRC=			${WRKDIR}/lynx2-8-3

GNU_CONFIGURE=		yes
USE_SSL=		yes
INSTALL_TARGET=		install-full
MAKEFILE=       	makefile

BUILD_DEFS+=		LYNX_SCREEN_LIB

# For nls/gettext
CONFIGURE_ARGS+=	--enable-nls
CONFIGURE_ARGS+=	--with-nls-datadir=${PREFIX}/share
CONFIGURE_ARGS+=	--without-included-gettext
CONFIGURE_ENV+=		CPPFLAGS="-I${LOCALBASE}/include"

# Note: the following have no effect with curses screen
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

post-configure:
	(${ECHO}; \
	${ECHO} '#undef LYNX_CFG_FILE'; \
	${ECHO} '#define LYNX_CFG_FILE "${PREFIX}/etc/lynx.cfg"'; \
	${ECHO} '#undef LYNX_LSS_FILE'; \
	${ECHO} '#define LYNX_LSS_FILE "${PREFIX}/etc/lynx.lss"') \
	    >> ${WRKSRC}/userdefs.h
	(${ECHO}; \
	${ECHO} 'SSL_LIBS= ${SSLLIBS}'; \
	${ECHO} 'SSL_DEFINES= -DUSE_SSL ${SSLINCS}') \
	    >> ${WRKSRC}/makefile
	(${ECHO}; \
	${ECHO} 'INTLLIB= ${LOCALBASE}/lib/libintl.a'; \
	${ECHO} 'INTLDIR_CPPFLAGS= -I${LOCALBASE}/include') \
	    >> ${WRKSRC}/src/makefile

post-install:
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/share/lynx
	if [ ! -f ${PREFIX}/etc/lynx.cfg ]; then \
	    ${CP} ${PREFIX}/share/lynx/lynx.cfg ${PREFIX}/etc/; \
	fi
	if [ ! -f ${PREFIX}/etc/lynx.lss ]; then \
	    ${CP} ${PREFIX}/share/lynx/lynx_doc/samples/lynx.lss ${PREFIX}/etc/; \
	fi

.include "../../mk/bsd.prefs.mk"

# XXX until our curses does color...
LYNX_SCREEN_LIB?=	slang

.if (${LYNX_SCREEN_LIB} == slang)
DEPENDS+=		libslang-*:../../devel/libslang
CONFIGURE_ARGS+=	--with-screen=slang
CONFIGURE_ENV+=		LIBS="-lm -ltermcap"
.elif (${LYNX_SCREEN_LIB} == ncurses)
DEPENDS+=		ncurses-*:../../devel/ncurses
CONFIGURE_ARGS+=	--enable-color-style
CONFIGURE_ARGS+=	--with-screen=ncurses
.elif (${LYNX_SCREEN_LIB} == curses)
CONFIGURE_ARGS+=	--with-screen=curses
.else
pre-configure:
	@${ECHO} '****************************************************'
	@${ECHO} '* Invalid value for LYNX_SCREEN_LIB. Please choose *'
	@${ECHO} '* one of "slang", "ncurses", or "curses"!          *'
	@${ECHO} '****************************************************'
	@false
.endif

.include "../../mk/bsd.pkg.mk"

.if (${SSLBASE} == /usr)
SSLLIBS=	-lssl -lcrypto
SSLINCS=	-I/usr/include/openssl
.else
SSLLIBS=	-L${SSLBASE}/lib -Wl,-R${SSLBASE}/lib -lssl -lcrypto
SSLINCS=	-I${SSLBASE}/include -I${SSLBASE}/include/openssl
.endif
