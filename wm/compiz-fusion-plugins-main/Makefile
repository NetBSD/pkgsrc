# $NetBSD: Makefile,v 1.2 2008/05/12 13:19:17 jmcneill Exp $
#

DISTNAME=	compiz-fusion-plugins-main-0.6.0
PKGREVISION=	1
CATEGORIES=	wm x11
MASTER_SITES=	http://releases.compiz-fusion.org/0.6.0/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.compiz-fusion.org/
COMMENT=	Compositing window manager - main plugins

GNU_CONFIGURE=		yes
USE_TOOLS+=		intltool pkg-config msgfmt
USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes

PKGCONFIG_OVERRIDE+=	compiz-text.pc.in

CONFIGURE_ARGS+=	--disable-inotify
CONFIGURE_ARGS+=	--enable-schemas

.include "../../devel/GConf/schemas.mk"
.include "../../devel/compiz-bcop/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../wm/compiz/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
