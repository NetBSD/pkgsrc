# $NetBSD: Makefile,v 1.67 2018/11/14 22:22:33 kleink Exp $
#

PKGVER=		0.8.8
PKGNAME=	compiz-fusion-plugins-extra-${PKGVER}
DISTNAME=	compiz-plugins-extra-${PKGVER}
PKGREVISION=	38
CATEGORIES=	wm x11
MASTER_SITES=	http://releases.compiz.org/${PKGVER}/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://compiz.org/
COMMENT=	Compositing window manager - extra plugins
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake intltool msgfmt msgmerge perl pkg-config xgettext
USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes

PKGCONFIG_OVERRIDE+=	compiz-animationaddon.pc.in

CONFIGURE_ARGS+=	--enable-schemas

GCONF_SCHEMAS+=		compiz-3d.schemas
GCONF_SCHEMAS+=		compiz-addhelper.schemas
GCONF_SCHEMAS+=		compiz-animationaddon.schemas
GCONF_SCHEMAS+=		compiz-bench.schemas
GCONF_SCHEMAS+=		compiz-bicubic.schemas
GCONF_SCHEMAS+=		compiz-crashhandler.schemas
GCONF_SCHEMAS+=		compiz-cubeaddon.schemas
GCONF_SCHEMAS+=		compiz-extrawm.schemas
GCONF_SCHEMAS+=		compiz-fadedesktop.schemas
GCONF_SCHEMAS+=		compiz-firepaint.schemas
GCONF_SCHEMAS+=		compiz-gears.schemas
GCONF_SCHEMAS+=		compiz-grid.schemas
GCONF_SCHEMAS+=		compiz-group.schemas
GCONF_SCHEMAS+=		compiz-loginout.schemas
GCONF_SCHEMAS+=		compiz-maximumize.schemas
GCONF_SCHEMAS+=		compiz-mblur.schemas
GCONF_SCHEMAS+=		compiz-reflex.schemas
GCONF_SCHEMAS+=		compiz-scalefilter.schemas
GCONF_SCHEMAS+=		compiz-shelf.schemas
GCONF_SCHEMAS+=		compiz-showdesktop.schemas
GCONF_SCHEMAS+=		compiz-showmouse.schemas
GCONF_SCHEMAS+=		compiz-splash.schemas
GCONF_SCHEMAS+=		compiz-trailfocus.schemas
GCONF_SCHEMAS+=		compiz-wallpaper.schemas
GCONF_SCHEMAS+=		compiz-widget.schemas

.include "../../x11/gtk2/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../x11/startup-notification/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../devel/GConf/schemas.mk"
BUILDLINK_API_DEPENDS.compiz-bcop+=	compiz-bcop>=0.7.3
.include "../../devel/compiz-bcop/buildlink3.mk"
.include "../../sysutils/libnotify/buildlink3.mk"
.include "../../wm/compiz-fusion-plugins-main/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../wm/compiz/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
