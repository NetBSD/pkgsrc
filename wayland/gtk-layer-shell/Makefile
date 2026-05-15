# $NetBSD: Makefile,v 1.2 2026/05/15 17:01:05 wiz Exp $

DISTNAME=	gtk-layer-shell-0.10.1
CATEGORIES=	wayland
MASTER_SITES=	${MASTER_SITE_GITHUB:=wmww/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	kikadf.01@gmail.com
HOMEPAGE=	https://github.com/wmww/gtk4-layer-shell/
COMMENT=	Library to create desktop components for Wayland
LICENSE=	gnu-gpl-v3

TOOL_DEPENDS+=	glib2-introspection-[0-9]*:../../devel/glib2-introspection

USE_TOOLS+=	pkg-config

.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../devel/meson/build.mk"
.include "../../devel/wayland/buildlink3.mk"
.include "../../devel/wayland-protocols/buildlink3.mk"
.include "../../lang/vala/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
