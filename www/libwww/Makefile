# $NetBSD: Makefile,v 1.36 2002/08/25 18:40:21 jlam Exp $

DISTNAME=		w3c-libwww-5.3.2
PKGNAME=		libwww-5.3.2
PKGREVISION=		3
CATEGORIES=		www devel
MASTER_SITES=		http://www.w3.org/Library/Distribution/ \
			ftp://ftp.uni-hannover.de/pub/mirror/info-systems/WWW/libwww/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.w3.org/Library/
COMMENT=		The W3C Reference Library

BUILD_DEPENDS+=		automake>=1.4:../../devel/automake

USE_BUILDLINK2=		YES
USE_GMAKE=		YES
USE_LIBTOOL=		YES
USE_PERL5=		build

GNU_CONFIGURE=		YES
CONFIGURE_ARGS=		--with-zlib --with-regex --without-x
CONFIGURE_ARGS+=	--with-ssl="${SSLBASE}"

DOCDIR=			${PREFIX}/share/doc/libwww
LTCONFIG_OVERRIDE=	${WRKSRC}/config/ltconfig

pre-configure:
	cd ${WRKSRC}; \
	    ${LOCALBASE}/bin/aclocal && \
	    ${LOCALBASE}/bin/automake && \
	    ${LOCALBASE}/bin/autoconf

.include "../../mk/bsd.prefs.mk"

# Include SOCKS firewall support
.if defined(USE_SOCKS) && (${USE_SOCKS} == 4 || ${USE_SOCKS} == 5)
.if ${USE_SOCKS} == 4
.include "../../net/socks4/buildlink.mk"
CONFIGURE_ARGS+= 	--with-socks4=${BUILDLINK_PREFIX.socks4}/lib/libsocks4.a
CONFIGURE_ARGS+=	--with-socks5=no
.else
.include "../../net/socks5/buildlink.mk"
CONFIGURE_ARGS+=	--with-socks4=no
CONFIGURE_ARGS+= 	--with-socks5=${BUILDLINK_prefix.socks5}/lib/libsocks5.a
.endif
.endif

.include "../../devel/zlib/buildlink2.mk"
.include "../../security/openssl/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
