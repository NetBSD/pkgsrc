# $NetBSD: Makefile,v 1.10 2020/03/08 16:48:24 wiz Exp $

PKGREVISION= 9
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
