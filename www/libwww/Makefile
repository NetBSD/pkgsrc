# $NetBSD: Makefile,v 1.45 2003/09/15 00:51:48 jschauma Exp $

DISTNAME=		w3c-libwww-5.4.0
PKGNAME=		libwww-5.4.0
CATEGORIES=		www devel
MASTER_SITES=		http://www.w3.org/Library/Distribution/ \
			ftp://ftp.uni-hannover.de/pub/mirror/info-systems/WWW/libwww/
EXTRACT_SUFX=		.tgz

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.w3.org/Library/
COMMENT=		The W3C Reference Library

USE_BUILDLINK2=		YES
USE_GMAKE=		YES
USE_LIBTOOL=		YES
USE_PERL5=		build

AUTOMAKE_REQD=		1.4

GNU_CONFIGURE=		YES
CONFIGURE_ARGS=		--with-zlib --with-regex --without-x
CONFIGURE_ARGS+=	--with-ssl="${SSLBASE}"

DOCDIR=			${PREFIX}/share/doc/libwww
LTCONFIG_OVERRIDE=	${WRKSRC}/config/ltconfig

pre-configure:
	cd ${WRKSRC}; \
	    ${ACLOCAL} && \
	    ${AUTOMAKE} -i && \
	    ${AUTOCONF}

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
# Solaris has a /usr/lib/libmd5 which seems to be enouth, and
# /usr/local/lib/libmd5 breaks /usr/lib/librt
CONFIGURE_ARGS+= --without-md5
PLIST_SUBST+=	MD5LIB="@comment "
.else
.  if !exists(/usr/include/md5.h)
CONFIGURE_ARGS+=	--with-md5="${SSLBASE}"
.  endif
PLIST_SUBST+=	MD5LIB=""
.endif

# Include SOCKS firewall support
.if defined(USE_SOCKS) && (${USE_SOCKS} == 4 || ${USE_SOCKS} == 5)
.if ${USE_SOCKS} == 4
.include "../../net/socks4/buildlink2.mk"
CONFIGURE_ARGS+= 	--with-socks4=${BUILDLINK_PREFIX.socks4}/lib/libsocks4.a
CONFIGURE_ARGS+=	--with-socks5=no
.else
.include "../../net/socks5/buildlink2.mk"
CONFIGURE_ARGS+=	--with-socks4=no
CONFIGURE_ARGS+= 	--with-socks5=${BUILDLINK_prefix.socks5}/lib/libsocks5.a
.endif
.endif

.include "../../devel/zlib/buildlink2.mk"
.include "../../security/openssl/buildlink2.mk"

.include "../../mk/automake.mk"
.include "../../mk/bsd.pkg.mk"
