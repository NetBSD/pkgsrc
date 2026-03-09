# $NetBSD: Makefile,v 1.7 2026/03/09 16:35:38 wiz Exp $

DISTNAME=	libkiwix-14.2.0
CATEGORIES=	www textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=kiwix/}
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/kiwix/libkiwix/
COMMENT=	Common code base for all Kiwix ports
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=	c++
USE_TOOLS+=	pkg-config

REPLACE_PYTHON+=	scripts/kiwix-compile-i18n
REPLACE_PYTHON+=	scripts/kiwix-compile-resources

PKGCONFIG_OVERRIDE+=		output/meson-private/libkiwix.pc
PKGCONFIG_OVERRIDE_STAGE=	post-configure

.include "../../lang/python/application.mk"
.include "../../lang/python/tool.mk"
.include "../../devel/meson/build.mk"
.include "../../devel/mustache/buildlink3.mk"
.include "../../textproc/icu/buildlink3.mk"
.include "../../textproc/pugixml/buildlink3.mk"
.include "../../textproc/xapian/buildlink3.mk"
BUILDLINK_API_DEPENDS.libzim+=	libzim>=9.4.0
.include "../../textproc/libzim/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../www/libmicrohttpd/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
