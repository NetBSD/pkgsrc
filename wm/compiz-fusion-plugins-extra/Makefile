# $NetBSD: Makefile,v 1.4 2009/08/26 19:58:23 sno Exp $
#

DISTNAME=	compiz-fusion-plugins-extra-0.6.0
PKGREVISION=	1
CATEGORIES=	wm x11
MASTER_SITES=	http://releases.compiz-fusion.org/0.6.0/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.compiz-fusion.org/
COMMENT=	Compositing window manager - extra plugins

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_TOOLS+=		intltool pkg-config msgfmt gmake
USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes

PKGCONFIG_OVERRIDE+=	compiz-text.pc.in

CONFIGURE_ARGS+=	--disable-inotify
CONFIGURE_ARGS+=	--enable-schemas

GCONF_SCHEMAS+=	compiz-addhelper.schemas
GCONF_SCHEMAS+=	compiz-bench.schemas
GCONF_SCHEMAS+=	compiz-crashhandler.schemas
GCONF_SCHEMAS+=	compiz-cubecaps.schemas
GCONF_SCHEMAS+=	compiz-cubereflex.schemas
GCONF_SCHEMAS+=	compiz-extrawm.schemas
GCONF_SCHEMAS+=	compiz-fadedesktop.schemas
GCONF_SCHEMAS+=	compiz-firepaint.schemas
GCONF_SCHEMAS+=	compiz-gears.schemas
GCONF_SCHEMAS+=	compiz-group.schemas
GCONF_SCHEMAS+=	compiz-mblur.schemas
GCONF_SCHEMAS+=	compiz-reflex.schemas
GCONF_SCHEMAS+=	compiz-scalefilter.schemas
GCONF_SCHEMAS+=	compiz-showdesktop.schemas
GCONF_SCHEMAS+=	compiz-splash.schemas
GCONF_SCHEMAS+=	compiz-trailfocus.schemas
GCONF_SCHEMAS+=	compiz-widget.schemas

.include "../../devel/GConf/schemas.mk"
.include "../../devel/compiz-bcop/buildlink3.mk"
.include "../../wm/compiz-fusion-plugins-main/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../wm/compiz/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
