# $NetBSD: Makefile,v 1.46.4.1 2016/07/12 20:43:32 bsiegert Exp $

DISTNAME=	xerces-c-3.1.4
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_APACHE:=xerces/c/3/sources/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://xerces.apache.org/
COMMENT=	Validating C++ XML parser with DOM and SAX support
LICENSE=	apache-2.0

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
