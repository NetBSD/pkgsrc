# $NetBSD: Makefile,v 1.8 2001/09/27 23:18:51 jlam Exp $

DISTNAME=		httpd-2_0_16-beta
PKGNAME=		apache-2.0.16
CATEGORIES=		www
MASTER_SITES=		http://httpd.apache.org/dist/httpd/ \
			http://www.netbsd.org/images/logos/
EXTRACT_SUFX=		.tar.Z

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.apache.org/
COMMENT=		HTTP (Web) server, version 2

CONFLICTS=		apache-*modssl-[0-9]* apache-[0-9]*
CONFLICTS+=		apache6-[0-9]* ap-[0-9]*

# autodetect
BUILD_DEFS+=		USE_INET6

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
CONFIGURE_ARGS+=	--enable-rewrite
USE_LIBTOOL=		yes
LTCONFIG_OVERRIDE=	${WRKSRC}/srclib/pcre/ltconfig \
			${WRKSRC}/srclib/apr/build/ltconfig \
			${WRKSRC}/srclib/apr/shmem/unix/mm/ltconfig \
			${WRKSRC}/srclib/apr-util/build/ltconfig \
			${WRKSRC}/srclib/apr-util/xml/expat/conftools/ltconfig \
			${WRKSRC}/ltconfig

WRKSRC=			${WRKDIR}/httpd-2_0_16

AP_LIBS=	srclib/apr/shmem/unix/mm/libmm.la \
		srclib/apr/libapr.la \
		srclib/apr-util/xml/expat/lib/libexpat.la \
		srclib/apr-util/libaprutil.la

post-patch:
	${RM} ${WRKSRC}/docs/conf/*.orig
	(cd ${WRKSRC}; ${LN} -s ${LOCALBASE}/bin/libtool)

pre-configure:
	${CP} ${WRKSRC}/config.layout ${WRKSRC}/config.layout.bak
	${SED} -e 's:PKG_PREFIX:${PREFIX}:g' ${WRKSRC}/config.layout.bak > ${WRKSRC}/config.layout
	${CP} ${WRKSRC}/docs/conf/httpd-std.conf ${WRKSRC}/docs/conf/httpd-std.conf.bak
	${SED} -e 's:PKG_PREFIX:${PREFIX}:g' ${WRKSRC}/docs/conf/httpd-std.conf.bak > ${WRKSRC}/docs/conf/httpd-std.conf
	${RM} ${WRKSRC}/docs/conf/httpd-std.conf.bak ${WRKSRC}/config.layout.bak

pre-install:
	for i in ${AP_LIBS}; do \
		${SH} ${WRKSRC}/libtool ${INSTALL_DATA} \
			${WRKSRC}/$$i ${PREFIX}/lib; \
	done

.include "../../mk/bsd.pkg.mk"
