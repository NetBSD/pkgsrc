# $NetBSD: Makefile,v 1.55 2025/01/31 12:18:20 wiz Exp $

DISTNAME=	xerces-c-3.2.4
PKGREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_APACHE:=xerces/c/3/sources/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://xerces.apache.org/
COMMENT=	Validating C++ XML parser with DOM and SAX support
LICENSE=	apache-2.0

USE_LANGUAGES=		c c++11
PKGCONFIG_OVERRIDE=	xerces-c.pc.in

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

.include "../../devel/cmake/build.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
