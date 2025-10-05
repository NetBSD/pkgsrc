# $NetBSD: Makefile,v 1.2 2025/10/05 19:26:26 js Exp $

DISTNAME=	kiwix-tools-3.7.0.20250613
PKGREVISION=	1
CATEGORIES=	www textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=kiwix/}
#GITHUB_TAG=	${PKGVERSION_NOREV}
# 3.7.0 does not accept libkiwix 14+
GITHUB_TAG=	acad8a85ab4706ff527cabdaac4635a930f3bdd4

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/kiwix/kiwix-tools/
COMMENT=	Command-line Kiwix tools
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=	c++
USE_TOOLS+=	pkg-config

.include "../../devel/meson/build.mk"
.include "../../devel/docopt.cpp/buildlink3.mk"
.include "../../textproc/libzim/buildlink3.mk"
.include "../../www/libkiwix/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
