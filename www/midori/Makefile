# $NetBSD: Makefile,v 1.1.1.1 2008/12/11 20:15:49 ahoka Exp $
#

DISTNAME=	midori-0.1.1
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

CONFIGURE_ARGS+=	--prefix=${PREFIX:Q}

REPLACE_PYTHON=		waf wscript po/wscript_build katze/wscript_build
REPLACE_PYTHON+=	docs/api/wscript_build icons/wscript_build
REPLACE_PYTHON+=	midori/wscript_build

.include "../../lang/python/application.mk"

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libsexy/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../net/libsoup24/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../www/webkit-gtk/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
