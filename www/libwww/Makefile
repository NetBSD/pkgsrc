# $NetBSD: Makefile,v 1.27 2001/08/26 10:32:24 skrll Exp $
# FreeBSD Id: Makefile,v 1.10 1998/06/14 23:34:59 jseger Exp
#

DISTNAME=		w3c-libwww-5.3.2
PKGNAME=		libwww-5.3.2nb1
CATEGORIES=		www devel
MASTER_SITES=		http://www.w3.org/Library/Distribution/ \
			ftp://ftp.uni-hannover.de/pub/mirror/info-systems/WWW/libwww/

MAINTAINER=		tv@netbsd.org
HOMEPAGE=		http://www.w3.org/Library/
COMMENT=		The W3C Reference Library

BUILD_DEPENDS+=		autoconf-2.13:../../devel/autoconf
BUILD_DEPENDS+=		automake>=1.4:../../devel/automake
BUILD_DEPENDS+=		perl>=${PERL5_REQD}:../../lang/perl5

USE_BUILDLINK_ONLY=	yes
USE_GMAKE=		yes
USE_LIBTOOL=		yes
#USE_SSL=		yes

GNU_CONFIGURE=		yes
CONFIGURE_ARGS=		--with-zlib --with-regex --without-x
CONFIGURE_ARGS+=	--with-ssl="${BUILDLINK_DIR}"

DOCDIR=			${PREFIX}/share/doc/libwww
LTCONFIG_OVERRIDE=	${WRKSRC}/config/ltconfig

CFLAGS+=		${LDFLAGS}

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
CONFIGURE_ARGS+= 	--with-socks4=${BUILDLINK_DIR}/lib/libsocks4.a
CONFIGURE_ARGS+=	--with-socks5=no
.else
.include "../../net/socks5/buildlink.mk"
CONFIGURE_ARGS+=	--with-socks4=no
CONFIGURE_ARGS+= 	--with-socks5=${BUILDLINK_DIR}/lib/libsocks5.a
.endif
.endif

.include "../../devel/zlib/buildlink.mk"
.include "../../security/openssl/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
