# $NetBSD: Makefile,v 1.14 2000/10/15 12:56:25 fredb Exp $
# FreeBSD Id: Makefile,v 1.10 1998/06/14 23:34:59 jseger Exp
#

DISTNAME=		w3c-${PKGNAME}
PKGNAME=		libwww-5.3.1
CATEGORIES=		www devel
MASTER_SITES=		http://www.w3.org/Library/Distribution/ \
			ftp://ftp.uni-hannover.de/pub/mirror/info-systems/WWW/libwww/

MAINTAINER=		tv@netbsd.org
HOMEPAGE=		http://www.w3.org/Library/

USE_GMAKE=		yes
USE_LIBTOOL=		yes
USE_SSL=		yes

GNU_CONFIGURE=		yes
CONFIGURE_ARGS=		--with-zlib --with-regex --without-x
CONFIGURE_ARGS+=	--with-ssl

DOCDIR=			${PREFIX}/share/doc/libwww
LTCONFIG_OVERRIDE=	${WRKSRC}/config/ltconfig

pre-configure:
	cd ${WRKSRC}; \
	    for foo in configure.in aclocal.m4 `find . -name Makefile.in` \
		    configure stamp-h.in; do \
		${TOUCH} $$foo; \
	    done

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
