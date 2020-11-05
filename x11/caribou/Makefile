# $NetBSD: Makefile,v 1.11 2020/11/05 09:09:23 ryoon Exp $

DISTNAME=	caribou-0.4.21
PKGREVISION=	9
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/caribou/0.4/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	youri@NetBSD.org
HOMEPAGE=	https://wiki.gnome.org/Caribou
COMMENT=	Simplified in-place on-screen keyboard
LICENSE=	gnu-lgpl-v2.1

DEPENDS+=	${PYPKGPREFIX}-gobject3-[0-9]*:../../devel/py-gobject3

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config intltool gmake xgettext

PY_PATCHPLIST=	yes

CONF_FILES=	${PREFIX}/share/examples/caribou/autostart/caribou-autostart.desktop \
		${PKG_SYSCONFDIR}/xdg/autostart/caribou-autostart.desktop

.include "../../devel/glib2/schemas.mk"
.include "../../lang/python/extension.mk"
.include "../../devel/py-gobject3-common/buildlink3.mk"
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../x11/libxklavier/buildlink3.mk"
.include "../../devel/libgee/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/libxslt/xsltproc-nonet.mk"
.include "../../graphics/clutter/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
