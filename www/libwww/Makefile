# $NetBSD: Makefile,v 1.23 2001/04/30 03:46:34 jlam Exp $
# FreeBSD Id: Makefile,v 1.10 1998/06/14 23:34:59 jseger Exp
#

DISTNAME=		w3c-${PKGNAME}
PKGNAME=		libwww-5.3.2
CATEGORIES=		www devel
MASTER_SITES=		http://www.w3.org/Library/Distribution/ \
			ftp://ftp.uni-hannover.de/pub/mirror/info-systems/WWW/libwww/

MAINTAINER=		tv@netbsd.org
HOMEPAGE=		http://www.w3.org/Library/
COMMENT=		The W3C Reference Library

BUILD_DEPENDS+=		autoconf-2.13:../../devel/autoconf
BUILD_DEPENDS+=		automake-1.4:../../devel/automake
BUILD_DEPENDS+=		perl>=${PERL5_REQD}:../../lang/perl5

USE_GMAKE=		yes
USE_LIBTOOL=		yes
USE_SSL=		yes

GNU_CONFIGURE=		yes
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
CONFIGURE_ARGS+= 	--with-socks4=${LOCALBASE}/lib/libsocks4.a --with-socks5=no
DEPENDS+=		socks4-2.2:../../net/socks4
.else
CONFIGURE_ARGS+= 	--with-socks5=${LOCALBASE}/lib/libsocks5.a --with-socks4=no
DEPENDS+=		socks5-1.0.2:../../net/socks5
.endif
.endif

.include "../../mk/bsd.pkg.mk"

# This has to come after bsd.pkg.mk's construction of "${CONFIGURE_ENV}"
# in order to have the desired effect. It's purpose is to allow "${SSLBASE}"
# to take control of which "openssl" is used, if several are installed.
CONFIGURE_ENV+=		LDFLAGS=""
