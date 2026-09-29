# $NetBSD: Makefile,v 1.32 2026/09/29 06:08:19 wiz Exp $

PKGREVISION= 30
.include "Makefile.common"

CATEGORIES=	x11

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Library for registering keyboard shortcuts
LICENSE=	gnu-gpl-v2

TOOL_DEPENDS+=		glib2-introspection-[0-9]*:../../devel/glib2-introspection

CONFIGURE_ARGS+=	--disable-lua
CONFIGURE_ARGS+=	--disable-python

.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
