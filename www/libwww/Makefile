# $NetBSD: Makefile,v 1.61.4.1 2005/11/05 17:25:26 snj Exp $

DISTNAME=		w3c-libwww-5.4.0
PKGNAME=		libwww-5.4.0
PKGREVISION=		4
CATEGORIES=		www devel
MASTER_SITES=		http://www.w3.org/Library/Distribution/ \
			ftp://ftp.uni-hannover.de/pub/mirror/info-systems/WWW/libwww/
EXTRACT_SUFX=		.tgz
DISTFILES=		${DISTNAME}${EXTRACT_SUFX} libwww-configure-5.4.0nb1.gz

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.w3.org/Library/
COMMENT=		The W3C Reference Library

PKG_INSTALLATION_TYPES=	overwrite pkgviews

EXTRACT_ONLY=		${DISTNAME}${EXTRACT_SUFX}
SITES_libwww-configure-5.4.0nb1.gz=	${MASTER_SITE_LOCAL}

USE_TOOLS+=		gmake perl
USE_LIBTOOL=		YES

GNU_CONFIGURE=		YES
CONFIGURE_ARGS=		--with-zlib --with-regex --without-x
CONFIGURE_ARGS+=	--with-ssl="${SSLBASE}"

# Avoid an ICE in gcc2 on sparc64
CONFIGURE_ENV+=		F77=${FALSE}

DOCDIR=			${PREFIX}/share/doc/libwww

pre-configure:
	${GZCAT} ${DISTDIR}/libwww-configure-5.4.0nb1.gz > ${WRKSRC}/configure
	${CHMOD} a+x ${WRKSRC}/configure
.for f in aclocal.m4 configure stamp-h.in
	${TOUCH} ${WRKSRC}/${f}
.endfor
	${TOUCH} `${FIND} ${WRKSRC} -name Makefile.in -print`

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
# Solaris has a /usr/lib/libmd5 which seems to be enouth, and
# /usr/local/lib/libmd5 breaks /usr/lib/librt
CONFIGURE_ARGS+= --without-md5
PLIST_SUBST+=	MD5LIB="@comment "
.else
.  if !exists(/usr/include/md5.h)
CONFIGURE_ARGS+=	--with-md5="${SSLBASE}"
.  endif
PLIST_SUBST+=	MD5LIB=""
.endif

# Include SOCKS firewall support
.if defined(USE_SOCKS) && (${USE_SOCKS} == 4 || ${USE_SOCKS} == 5)
.if ${USE_SOCKS} == 4
.include "../../net/socks4/buildlink3.mk"
CONFIGURE_ARGS+= 	--with-socks4=${BUILDLINK_PREFIX.socks4}/lib/libsocks4.a
CONFIGURE_ARGS+=	--with-socks5=no
.else
.include "../../net/socks5/buildlink3.mk"
CONFIGURE_ARGS+=	--with-socks4=no
CONFIGURE_ARGS+= 	--with-socks5=${BUILDLINK_prefix.socks5}/lib/libsocks5.a
.endif
.endif

.include "../../devel/zlib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
