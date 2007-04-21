# $NetBSD: Makefile,v 1.74 2007/04/21 11:17:47 obache Exp $

DISTNAME=		w3c-libwww-5.4.0
PKGNAME=		libwww-5.4.0
PKGREVISION=		5
CATEGORIES=		www devel
MASTER_SITES=		http://www.w3.org/Library/Distribution/
EXTRACT_SUFX=		.tgz
DISTFILES=		${DISTNAME}${EXTRACT_SUFX} libwww-configure-5.4.0nb2.gz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.w3.org/Library/
COMMENT=		The W3C Reference Library

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

EXTRACT_ONLY=		${DISTNAME}${EXTRACT_SUFX}
SITES.libwww-configure-5.4.0nb2.gz=	${MASTER_SITE_LOCAL}

USE_TOOLS+=		automake14 gmake gzcat perl
USE_LIBTOOL=		YES

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--with-zlib --without-x
CONFIGURE_ARGS+=	--with-ssl=${SSLBASE:Q}

# Avoid an ICE in gcc2 on sparc64
CONFIGURE_ENV+=		F77=${FALSE:Q}

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

.if empty(LOWER_OPSYS:Mirix5*)
# IRIX 5 does not have libregex
CONFIGURE_ARGS+=	--with-regex
.endif

.if ${OPSYS} == "SunOS"
# Solaris has a /usr/lib/libmd5 which seems to be enouth, and
# /usr/local/lib/libmd5 breaks /usr/lib/librt
CONFIGURE_ARGS+= --without-md5
PLIST_SUBST+=	MD5LIB="@comment "
.else
.  if !exists(/usr/include/md5.h)
CONFIGURE_ARGS+=	--with-md5=${SSLBASE:Q}
.  endif
PLIST_SUBST+=	MD5LIB=""
.endif

.include "../../devel/zlib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
