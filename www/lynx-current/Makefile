# $NetBSD: Makefile,v 1.6 2000/04/27 06:46:02 tron Exp $
#

DISTNAME=		lynx2.8.3pre.7
PKGNAME=		lynx-2.8.3pre.7
CATEGORIES=		www
MASTER_SITES=		http://lynx.isc.org/current/
EXTRACT_SUFX=		.tar.bz2

PATCH_SITES=		http://www.moxienet.com/lynx/
PATCHFILES= 		lynx-283d17-ssl.patch.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=		fb@enteract.com
HOMEPAGE=		http://lynx.browser.org/

DEPENDS+=		gettext-0.10.*:../../devel/gettext
DEPENDS+=		libslang-*:../../devel/libslang

NO_PACKAGE=		${RESTRICTED}
RESTRICTED=		"Crypto; export-controlled"

WRKSRC=			${WRKDIR}/lynx2-8-3

GNU_CONFIGURE=		yes
USE_SSL=		yes
INSTALL_TARGET=		install-full
MAKEFILE=       	makefile

# For nls/gettext
CONFIGURE_ARGS+=	--enable-nls
CONFIGURE_ARGS+=	--with-nls-datadir=${PREFIX}/share
CONFIGURE_ARGS+=	--without-included-gettext
CONFIGURE_ENV+=		CPPFLAGS="-I${LOCALBASE}/include"

# Curses/slang
CONFIGURE_ARGS+=	--enable-default-colors
CONFIGURE_ARGS+=	--enable-scrollbar
CONFIGURE_ARGS+=	--with-screen=slang
CONFIGURE_ENV+=		LIBS="-lm -ltermcap"

# XXX Just for fun, to use ncurses instead of slang.
#CONFIGURE_ARGS+=	--enable-color-style
#CONFIGURE_ARGS+=	--with-screen=ncurses
#DEPENDS+=		ncurses-*:../../devel/ncurses

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

.include "../../mk/bsd.pkg.mk"

.if (${SSLBASE} == /usr)
SSLLIBS=	-lssl -lcrypto
SSLINCS=	-I/usr/include/openssl
.else
SSLLIBS=	-L${SSLBASE}/lib -Wl,-R${SSLBASE}/lib -lssl -lcrypto
SSLINCS=	-I${SSLBASE}/include -I${SSLBASE}/include/openssl
.endif
