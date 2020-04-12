# $NetBSD: Makefile,v 1.96 2020/04/12 08:29:17 adam Exp $
#
# PKGNAME derives from the supported API (still from
# release 3.14). See also PLIST.
#

DISTNAME=	gtkhtml-3.32.2
PKGNAME=	${DISTNAME:S/gtkhtml/gtkhtml314/}
PKGREVISION=	51
CATEGORIES=	www gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gtkhtml/3.32/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.gnome.org/
COMMENT=	Lightweight HTML rendering/printing/editing engine
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-deprecated_warning_flags
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake intltool msgfmt pkg-config

PKGCONFIG_OVERRIDE+=	components/editor/gtkhtml-editor.pc.in
PKGCONFIG_OVERRIDE+=	gtkhtml/libgtkhtml.pc.in

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/GConf/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../graphics/gnome-icon-theme/buildlink3.mk"
.include "../../net/ORBit2/buildlink3.mk"
.include "../../net/libsoup/buildlink3.mk"
.include "../../textproc/enchant2/buildlink3.mk"
.include "../../textproc/iso-codes/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
