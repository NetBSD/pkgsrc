# $NetBSD: Makefile,v 1.20 2000/10/18 03:55:47 fredb Exp $
#

DISTNAME=		lynx2.8.4dev.10
PKGNAME=		lynx-2.8.4dev.10
CATEGORIES=		www
MASTER_SITES=		http://lynx.isc.org/current/ \
			http://lynx.isc.org/po/ \
			http://www.iro.umontreal.ca/contrib/po/teams/PO/
EXTRACT_SUFX=		.tar.bz2
DISTFILES+=		${DISTNAME}${EXTRACT_SUFX}
DISTFILES+=		lynx-2.8.3.rel1.cs.po
DISTFILES+=		lynx-2.8.4.da.po
DISTFILES+=		lynx-2.8.3.rel1.de.po
DISTFILES+=		lynx-2.8.3.rel1.ja.po
DISTFILES+=		lynx-2.8.3.rel1.nl.po
DISTFILES+=		lynx-2.8.3.rel1.pt_BR.po
DISTFILES+=		lynx-2.8.3.rel1.ru.po
DISTFILES+=		lynx-2.8.3.rel1.sl.po

PATCH_SITES=		http://www.moxienet.com/lynx/
PATCHFILES= 		lynx-283-ssl.patch.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=		fb@enteract.com
HOMEPAGE=		http://lynx.browser.org/

DEPENDS+=		gettext>=0.10.35nb1:../../devel/gettext

DIST_SUBDIR=		lynx
EXTRACT_ONLY=		${DISTFILES:M*.tar.bz2}
WRKSRC=			${WRKDIR}/lynx2-8-4

GNU_CONFIGURE=		yes
USE_SSL=		yes
INSTALL_TARGET=		install-bin install-man install-cfg install-help install-doc
MAKEFILE=       	makefile

BUILD_DEFS+=		LYNX_SCREEN_LIB USE_SOCKS USE_INET6

# For nls/gettext
CONFIGURE_ARGS+=	--enable-nls
CONFIGURE_ARGS+=	--with-nls-datadir=${PREFIX}/share
CONFIGURE_ARGS+=	--without-included-gettext
CONFIGURE_ENV+=		CPPFLAGS="-I${LOCALBASE}/include"

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

post-extract:
	${CP} ${DISTDIR}/${DIST_SUBDIR}/lynx-2.8.3.rel1.cs.po \
	  ${WRKSRC}/po/cs.po
	${CP} ${DISTDIR}/${DIST_SUBDIR}/lynx-2.8.4.da.po \
	  ${WRKSRC}/po/da.po
	${CP} ${DISTDIR}/${DIST_SUBDIR}/lynx-2.8.3.rel1.de.po \
	  ${WRKSRC}/po/de.po
	${CP} ${DISTDIR}/${DIST_SUBDIR}/lynx-2.8.3.rel1.ja.po \
	  ${WRKSRC}/po/ja.po
	${CP} ${DISTDIR}/${DIST_SUBDIR}/lynx-2.8.3.rel1.nl.po \
	  ${WRKSRC}/po/nl.po
	${CP} ${DISTDIR}/${DIST_SUBDIR}/lynx-2.8.3.rel1.pt_BR.po \
	  ${WRKSRC}/po/pt_BR.po
	${CP} ${DISTDIR}/${DIST_SUBDIR}/lynx-2.8.3.rel1.ru.po \
	  ${WRKSRC}/po/ru.po
	${CP} ${DISTDIR}/${DIST_SUBDIR}/lynx-2.8.3.rel1.sl.po \
	  ${WRKSRC}/po/sl.po

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

# Pick a terminal library. Choice affects support for colors, mouse,
# "color styles", and more. No library supports all features.
LYNX_SCREEN_LIB?=	slang
.if (${LYNX_SCREEN_LIB} == slang)
DEPENDS+=		libslang-*:../../devel/libslang
CONFIGURE_ENV+=		LIBS="-lm -ltermcap"
.elif (${LYNX_SCREEN_LIB} == ncurses)
DEPENDS+=		ncurses-*:../../devel/ncurses
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
