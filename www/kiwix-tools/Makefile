# $NetBSD: Makefile,v 1.10 2026/11/11 11:56:16 wiz Exp $

DISTNAME=	kiwix-tools-3.8.2
PKGREVISION=	2
CATEGORIES=	www textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=kiwix/}
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/kiwix/kiwix-tools/
COMMENT=	Command-line Kiwix tools
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=	c++
USE_TOOLS+=	pkg-config

BUILDLINK_TRANSFORM+=	rm:-Wl,--fatal-warnings

.include "../../devel/meson/build.mk"
.include "../../devel/docopt.cpp/buildlink3.mk"
.include "../../textproc/libzim/buildlink3.mk"
BUILDLINK_API_DEPENDS.libkiwix+=	libkiwix>=14.1.0
.include "../../www/libkiwix/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
