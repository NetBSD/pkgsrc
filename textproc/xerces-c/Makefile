# $NetBSD: Makefile,v 1.43 2012/12/31 09:24:46 obache Exp $

DISTNAME=	xerces-c-3.1.1
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_APACHE:=xerces/c/3/sources/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://xerces.apache.org/
COMMENT=	Validating C++ XML parser with DOM and SAX support
LICENSE=	apache-2.0

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake
PKGCONFIG_OVERRIDE=	xerces-c.pc.in
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--without-curl
CONFIGURE_ARGS+=	--without-icu

.include "../../mk/bsd.prefs.mk"

PLIST_VARS+=		iconv gnuiconv macunicode

.if ${OPSYS} == "Darwin"
PLIST.macunicode=	yes
.elif ${OPSYS} == "SunOS"
PLIST.iconv=		yes
CONFIGURE_ARGS+=	--enable-transcoder-iconv
.else
PLIST.gnuiconv=		yes
CONFIGURE_ARGS+=	--enable-transcoder-gnuiconv
.include "../../converters/libiconv/buildlink3.mk"
LDFLAGS+=		-liconv
.endif

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
