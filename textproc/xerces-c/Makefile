# $NetBSD: Makefile,v 1.39 2011/02/23 08:31:13 adam Exp $

DISTNAME=	xerces-c-3.1.1
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_APACHE:=xerces/c/3/sources/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://xerces.apache.org/
COMMENT=	Validating C++ XML parser with DOM and SAX support
LICENSE=	apache-2.0

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake
PKGCONFIG_OVERRIDE=	${WRKSRC}/xerces-c.pc.in
GNU_CONFIGURE=		yes

.include "../../mk/bsd.prefs.mk"

PLIST_VARS+=		gnuiconv macunicode

.if ${OPSYS} == "Darwin"
PLIST.macunicode=	yes
.else
PLIST.gnuiconv=		yes
.endif

.include "../../converters/libiconv/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
