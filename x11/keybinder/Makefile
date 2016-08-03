# $NetBSD: Makefile,v 1.2 2016/08/03 10:22:23 adam Exp $

PKGREVISION= 1
.include "Makefile.common"

CATEGORIES=	x11

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Library for registering keyboard shortcuts
LICENSE=	gnu-gpl-v2

CONFIGURE_ARGS+=	--disable-lua
CONFIGURE_ARGS+=	--disable-python

.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
