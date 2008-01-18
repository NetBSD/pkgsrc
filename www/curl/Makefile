# $NetBSD: Makefile,v 1.78 2008/01/18 05:09:48 tnn Exp $

DISTNAME=	curl-7.17.1
PKGREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://curl.haxx.se/download/ \
		ftp://ftp.sunet.se/pub/www/utilities/curl/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	recht@NetBSD.org
HOMEPAGE=	http://curl.haxx.se/
COMMENT=	Client that groks URLs

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

# list it into IPv6-ready packages
BUILD_DEFS+=	IPV6_READY

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-ssl=${BUILDLINK_PREFIX.openssl}
CONFIGURE_ARGS+=	--with-zlib=${BUILDLINK_PREFIX.zlib}
# Work around an ICE on sparc64 with gcc2
CONFIGURE_ENV+=		F77=${FALSE:Q}

.include "../../mk/bsd.prefs.mk"

.if !empty(PKGSRC_RUN_TEST:M[Yy][Ee][Ss])
TEST_TARGET=		check
USE_TOOLS+=		perl
.endif

.include "options.mk"

post-configure:
	if ${GREP} '#define HAVE_SYS_SELECT_H 1' ${WRKSRC}/src/config.h \
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
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/curl
	for _f in MANUAL TheArtOfHttpScripting FAQ			\
		curl-config.pdf curl.pdf; do				\
		${INSTALL_DATA} ${WRKSRC}/docs/$${_f}			\
			 ${DESTDIR}${PREFIX}/share/doc/curl/${_f};	\
	done
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/examples/curl
	for _f in ${WRKSRC}/docs/examples/*.c				\
		${WRKSRC}/docs/examples/README; do			\
		${INSTALL_DATA} $${_f} 					\
			${DESTDIR}${PREFIX}/share/examples/curl;	\
	done

.include "../../devel/libidn/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
