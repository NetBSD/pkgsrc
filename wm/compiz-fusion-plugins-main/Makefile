# $NetBSD: Makefile,v 1.64 2018/11/14 22:22:33 kleink Exp $
#

PKGVER=		0.8.8
PKGNAME=	compiz-fusion-plugins-main-${PKGVER}
DISTNAME=	compiz-plugins-main-${PKGVER}
PKGREVISION=	33
CATEGORIES=	wm x11
MASTER_SITES=	http://releases.compiz.org/${PKGVER}/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://compiz.org/
COMMENT=	Compositing window manager - main plugins
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake intltool msgfmt msgmerge pkg-config xgettext
USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes

PKGCONFIG_OVERRIDE+=	compiz-text.pc.in

CONFIGURE_ARGS+=	--enable-schemas

GCONF_SCHEMAS+=		compiz-animation.schemas
GCONF_SCHEMAS+=		compiz-colorfilter.schemas
GCONF_SCHEMAS+=		compiz-expo.schemas
GCONF_SCHEMAS+=		compiz-ezoom.schemas
GCONF_SCHEMAS+=		compiz-imgjpeg.schemas
GCONF_SCHEMAS+=		compiz-kdecompat.schemas
GCONF_SCHEMAS+=		compiz-mag.schemas
GCONF_SCHEMAS+=		compiz-mousepoll.schemas
GCONF_SCHEMAS+=		compiz-neg.schemas
GCONF_SCHEMAS+=		compiz-opacify.schemas
GCONF_SCHEMAS+=		compiz-put.schemas
GCONF_SCHEMAS+=		compiz-resizeinfo.schemas
GCONF_SCHEMAS+=		compiz-ring.schemas
GCONF_SCHEMAS+=		compiz-scaleaddon.schemas
GCONF_SCHEMAS+=		compiz-session.schemas
GCONF_SCHEMAS+=		compiz-shift.schemas
GCONF_SCHEMAS+=		compiz-snap.schemas
GCONF_SCHEMAS+=		compiz-staticswitcher.schemas
GCONF_SCHEMAS+=		compiz-text.schemas
GCONF_SCHEMAS+=		compiz-thumbnail.schemas
GCONF_SCHEMAS+=		compiz-titleinfo.schemas
GCONF_SCHEMAS+=		compiz-vpswitch.schemas
GCONF_SCHEMAS+=		compiz-wall.schemas
GCONF_SCHEMAS+=		compiz-winrules.schemas
GCONF_SCHEMAS+=		compiz-workarounds.schemas

.include "../../x11/libXrandr/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../x11/startup-notification/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../devel/GConf/schemas.mk"
BUILDLINK_API_DEPENDS.compiz-bcop+=	compiz-bcop>=0.7.3
.include "../../devel/compiz-bcop/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../wm/compiz/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
