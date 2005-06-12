# $NetBSD: Makefile,v 1.55 2005/06/12 13:43:36 jmmv Exp $

DISTNAME=	curl-7.14.0
PKGREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://curl.haxx.se/download/ \
		ftp://ftp.sunet.se/pub/www/utilities/curl/ \
		ftp://ftp.rge.com/pub/networking/curl/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	recht@NetBSD.org
HOMEPAGE=	http://curl.haxx.se/
COMMENT=	Client that groks URLs

PKG_INSTALLATION_TYPES=	overwrite pkgviews

# list it into IPv6-ready packages
BUILD_DEFS+=	USE_INET6

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
CONFIGURE_ARGS+=	--with-ssl=${BUILDLINK_PREFIX.openssl}
CONFIGURE_ARGS+=	--with-zlib=${BUILDLINK_PREFIX.zlib}

TEST_TARGET=		check

# Work around an ICE on sparc64 with gcc2
CONFIGURE_ENV+=		F77=${FALSE}

.include "../../mk/bsd.prefs.mk"

.if empty(USE_INET6:M[yY][eE][sS])
CONFIGURE_ARGS+=	--disable-ipv6
.endif

post-configure:
	@if ${GREP} '#define HAVE_SYS_SELECT_H 1' ${WRKSRC}/src/config.h \
		>/dev/null; \
	then \
	    line='#include <sys/select.h>'; \
	else \
	    line='/* sys/select.h not included because it does not exist */'; \
	fi; \
	${SED} -e "s|__INCLUDE_SYS_SELECT_H__|$${line}|" \
	       <${WRKSRC}/include/curl/multi.h \
	       >${WRKSRC}/include/curl/multi.h.new; \
	${MV} ${WRKSRC}/include/curl/multi.h.new \
	      ${WRKSRC}/include/curl/multi.h

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/curl
	for _f in MANUAL TheArtOfHttpScripting FAQ		\
		curl-config.pdf curl.pdf; do				\
		${INSTALL_DATA} ${WRKSRC}/docs/$${_f}		\
			 ${PREFIX}/share/doc/curl/${_f};	\
	done
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/curl
	for _f in ${WRKSRC}/docs/examples/*.c				\
		${WRKSRC}/docs/examples/README; do			\
		${INSTALL_DATA} $${_f} ${PREFIX}/share/examples/curl;	\
	done

.include "../../devel/libidn/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
