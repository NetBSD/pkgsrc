# $NetBSD: Makefile,v 1.2.2.2 2009/01/29 17:30:55 tron Exp $
#

DISTNAME=	midori-0.1.1
PKGREVISION=	3
CATEGORIES=	www
MASTER_SITES=	http://goodies.xfce.org/releases/midori/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.twotoasts.de/media/midori/
COMMENT=	Lightweight web browser using WebKit
EXTRACT_SUFX=	.tar.bz2

HAS_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_DIRS+=	xdg-1.4
USE_TOOLS+=	gmake intltool msgfmt pkg-config

PKG_DESTDIR_SUPPORT=	user-destdir
CONFIGURE_ARGS+=	--prefix=${PREFIX:Q}

REPLACE_PYTHON=		waf wscript po/wscript_build katze/wscript_build
REPLACE_PYTHON+=	docs/api/wscript_build icons/wscript_build
REPLACE_PYTHON+=	midori/wscript_build

BUILD_DEPENDS+=		${PYPKGPREFIX}-docutils>=0.4:../../textproc/py-docutils
BUILD_DEPENDS+=		librsvg>=2.18:../../graphics/librsvg

.include "../../lang/python/application.mk"

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libsexy/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../net/libsoup24/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../www/webkit-gtk/buildlink3.mk"
.include "../../x11/libunique/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
