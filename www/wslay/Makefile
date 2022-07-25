# $NetBSD: Makefile,v 1.4 2022/07/25 11:12:30 wiz Exp $

DISTNAME=	wslay-1.1.1
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=tatsuhiro-t/}
EXTRACT_SUFX=	.tar.xz
GITHUB_RELEASE=	release-${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/tatsuhiro-t/wslay/
COMMENT=	WebSocket library written in C
LICENSE=	mit

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
PKGCONFIG_OVERRIDE+=	lib/libwslay.pc.in

.include "../../mk/bsd.pkg.mk"
