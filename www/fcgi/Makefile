# $NetBSD: Makefile,v 1.23 2025/04/24 10:13:19 wiz Exp $

DISTNAME=		fcgi2-2.4.5
PKGNAME=		${DISTNAME:S/fcgi2/fcgi/}
CATEGORIES=		www devel
MASTER_SITES=		${MASTER_SITE_GITHUB:=FastCGI-Archives/}
GITHUB_PROJECT=		fcgi2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://github.com/FastCGI-Archives/fcgi2
COMMENT=		FastCGI application development kit

USE_LANGUAGES=		c c++
GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_TOOLS+=		autoconf automake autoreconf

PKGCONFIG_OVERRIDE+=	*.pc.in

pre-configure:
	cd ${WRKSRC} && autoreconf -fiv

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
