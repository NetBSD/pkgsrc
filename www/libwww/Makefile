# $NetBSD: Makefile,v 1.11 2000/08/06 16:51:15 tron Exp $
# FreeBSD Id: Makefile,v 1.10 1998/06/14 23:34:59 jseger Exp
#

DISTNAME=		w3c-${PKGNAME}
PKGNAME=		libwww-5.3.1
CATEGORIES=		www devel
MASTER_SITES=		http://www.w3.org/Library/Distribution/ \
			ftp://ftp.uni-hannover.de/pub/mirror/info-systems/WWW/libwww/

MAINTAINER=		tv@netbsd.org
HOMEPAGE=		http://www.w3.org/Library/

BUILD_DEPENDS+=		autoconf:../../devel/autoconf

RESTRICTED=		"Crypto, export-controlled"
NO_BIN_ON_FTP=		${RESTRICTED}

USE_GMAKE=		# defined
USE_LIBTOOL=		# defined
LTCONFIG_OVERRIDE=	${WRKSRC}/config/ltconfig

GNU_CONFIGURE=		# defined
CONFIGURE_ARGS=		--with-zlib --with-regex --without-x
CONFIGURE_ARGS+=	--with-ssl

DOCDIR=			${PREFIX}/share/doc/libwww

pre-configure:
	cd ${WRKSRC}; autoconf

.include "../../mk/bsd.prefs.mk"

# Include SOCKS firewall support
.if defined(USE_SOCKS) && (${USE_SOCKS} == 4 || ${USE_SOCKS} == 5)
.if ${USE_SOCKS} == 4
CONFIGURE_ARGS+= 	--with-socks --with-socks4 --without-socks5
DEPENDS+=		socks4-2.2:../../net/socks4
.else
CONFIGURE_ARGS+= 	--with-socks --without-socks4 --with-socks5
DEPENDS+=		socks5-1.0.2:../../net/socks5
.endif
.endif

.include "../../mk/bsd.pkg.mk"
