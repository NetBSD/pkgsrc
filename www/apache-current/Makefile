# $NetBSD: Makefile,v 1.1.1.1 2001/03/30 22:06:00 itojun Exp $

DISTNAME=		httpd-2_0_15-alpha
PKGNAME=		apache-2.0.15
CATEGORIES=		www
MASTER_SITES=		http://httpd.apache.org/dist/httpd/ \
			http://www.netbsd.org/images/logos/
EXTRACT_SUFX=		.tar.Z

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.apache.org/
COMMENT=		HTTP (Web) server

CONFLICTS=		apache-*modssl-* apache-* apache6-*

GNU_CONFIGURE=		# defined
USE_GMAKE=		yes
USE_SSL=		yes
CONFIGURE_ARGS+=	--enable-layout=NetBSD
CONFIGURE_ARGS+=	--with-port=80
.if exists(${LOCALBASE}/include/openssl/ssl.h)
CONFIGURE_ARGS+=	--with-ssl=${LOCALBASE}/include --enable-tls
.else
CONFIGURE_ARGS+=	--with-ssl=/usr/include --enable-tls
.endif
CONFIGURE_ARGS+=	--prefix=${PREFIX}
CONFIGURE_ARGS+=	--enable-shared
USE_LIBTOOL=		yes
LTCONFIG_OVERRIDE=	${WRKSRC}/srclib/pcre/ltconfig \
			${WRKSRC}/srclib/apr/build/ltconfig \
			${WRKSRC}/srclib/apr/shmem/unix/mm/ltconfig \
			${WRKSRC}/srclib/apr-util/build/ltconfig \
			${WRKSRC}/srclib/apr-util/xml/expat/conftools/ltconfig \
			${WRKSRC}/ltconfig

WRKSRC=			${WRKDIR}/httpd-2_0_15

LIBS=	srclib/apr/shmem/unix/mm/libmm.la \
	srclib/apr/libapr.la \
	srclib/apr-util/xml/expat/lib/libexpat.la \
	srclib/apr-util/libaprutil.la

post-patch:
	${RM} ${WRKSRC}/docs/conf/*.orig

pre-install:
	for i in ${LIBS}; do \
		${SH} ${WRKSRC}/libtool ${INSTALL_DATA} \
			${WRKSRC}/$$i ${PREFIX}/lib; \
	done

.include "../../mk/bsd.pkg.mk"
