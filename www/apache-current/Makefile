# $NetBSD: Makefile,v 1.9 2002/01/04 09:45:09 martti Exp $

DISTNAME=		httpd-2_0_28-beta
PKGNAME=		apache-2.0.28
CATEGORIES=		www
MASTER_SITES=		http://httpd.apache.org/dist/httpd/ \
			http://www.netbsd.org/images/logos/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.apache.org/
COMMENT=		HTTP (Web) server, version 2

CONFLICTS=		apache-*modssl-[0-9]* apache-[0-9]*
CONFLICTS+=		apache6-[0-9]* ap-[0-9]*

# autodetect
BUILD_DEFS+=		USE_INET6

USE_BUILDLINK_ONLY=	YES
HAS_CONFIGURE=		YES
USE_GMAKE=		YES
USE_SSL=		YES
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
CONFIGURE_ARGS+=	--with-expat=${BUILDLINK_DIR}
USE_LIBTOOL=		yes
LTCONFIG_OVERRIDE=	${WRKSRC}/srclib/pcre/ltconfig \
			${WRKSRC}/srclib/apr/build/ltconfig

WRKSRC=			${WRKDIR}/httpd-2_0_28

post-patch:
	${RM} ${WRKSRC}/docs/conf/*.orig
	(cd ${WRKSRC} && ${LN} -s ${LOCALBASE}/bin/libtool)
	(cd ${WRKSRC} && ${RM} -rf srclib/apr-util/xml/expat)

pre-configure:
	${CP} ${WRKSRC}/config.layout ${WRKSRC}/config.layout.bak
	${SED} -e 's:PKG_PREFIX:${PREFIX}:g' ${WRKSRC}/config.layout.bak \
		> ${WRKSRC}/config.layout
	${CP} ${WRKSRC}/docs/conf/httpd-std.conf \
		${WRKSRC}/docs/conf/httpd-std.conf.bak
	${SED} -e 's:PKG_PREFIX:${PREFIX}:g' \
		${WRKSRC}/docs/conf/httpd-std.conf.bak \
		> ${WRKSRC}/docs/conf/httpd-std.conf
	${RM} ${WRKSRC}/docs/conf/httpd-std.conf.bak ${WRKSRC}/config.layout.bak

.include "../../textproc/expat/buildlink.mk"
.include "../../mk/bsd.pkg.install.mk"
.include "../../mk/bsd.pkg.mk"
