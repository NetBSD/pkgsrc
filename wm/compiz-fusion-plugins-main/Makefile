# $NetBSD: Makefile,v 1.22 2012/10/02 17:12:06 tron Exp $
#

PKGVER=		0.8.4
PKGNAME=	compiz-fusion-plugins-main-${PKGVER}
DISTNAME=	compiz-plugins-main-${PKGVER}
PKGREVISION=	14
CATEGORIES=	wm x11
MASTER_SITES=	http://releases.compiz.org/${PKGVER}/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://compiz.org/
COMMENT=	Compositing window manager - main plugins
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_TOOLS+=		intltool pkg-config msgfmt gmake
USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes

PKGCONFIG_OVERRIDE+=	compiz-text.pc.in

CONFIGURE_ARGS+=	--disable-inotify
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

.include "../../devel/GConf/schemas.mk"
.include "../../devel/compiz-bcop/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../wm/compiz/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

