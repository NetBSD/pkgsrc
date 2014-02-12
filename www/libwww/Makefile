# $NetBSD: Makefile,v 1.86 2014/02/12 23:18:45 tron Exp $

DISTNAME=		w3c-libwww-5.4.0
PKGNAME=		libwww-5.4.0
PKGREVISION=		13
CATEGORIES=		www devel
MASTER_SITES=		http://www.w3.org/Library/Distribution/
EXTRACT_SUFX=		.tgz
DISTFILES=		${DISTNAME}${EXTRACT_SUFX} libwww-configure-5.4.0nb2.gz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.w3.org/Library/
COMMENT=		The W3C Reference Library

PKG_INSTALLATION_TYPES=	overwrite pkgviews

EXTRACT_ONLY=		${DISTNAME}${EXTRACT_SUFX}
SITES.libwww-configure-5.4.0nb2.gz=	${MASTER_SITE_LOCAL}

USE_TOOLS+=		automake14 gmake gzcat perl
USE_LIBTOOL=		YES

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--with-zlib --without-x
CONFIGURE_ARGS+=	--with-ssl=${SSLBASE:Q}

.include "options.mk"

post-extract:
	gzcat ${DISTDIR}/libwww-configure-5.4.0nb2.gz > ${WRKSRC}/configure

pre-configure:
	chmod a+x ${WRKSRC}/configure
.for f in aclocal.m4 configure stamp-h.in
	touch ${WRKSRC}/${f}
.endfor
	cd ${WRKSRC} && automake

.include "../../mk/bsd.prefs.mk"

.if !empty(MACHINE_PLATFORM:MIRIX-5*)
# IRIX 5 does not have libregex
CONFIGURE_ARGS+=	--with-regex
.endif

PLIST_VARS+=		md5
.if ${OPSYS} == "SunOS"
# Solaris has a /usr/lib/libmd5 which seems to be enough, and
# /usr/local/lib/libmd5 breaks /usr/lib/librt
CONFIGURE_ARGS+=	--without-md5
.else
PLIST.md5=		yes
.  if !exists(/usr/include/md5.h)
CONFIGURE_ARGS+=	--with-md5=${SSLBASE:Q}
.  endif
.endif

.include "../../devel/zlib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
