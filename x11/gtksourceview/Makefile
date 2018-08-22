# $NetBSD: Makefile,v 1.93 2018/08/22 09:48:01 wiz Exp $

DISTNAME=	gtksourceview-1.8.5
PKGREVISION=	42
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gtksourceview/1.8/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://gtksourceview.sourceforge.net/
COMMENT=	Text widget that extends GTK2's GtkTextView widget (v1)
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake intltool msgfmt perl pkg-config

CFLAGS.Linux+=		-D_GNU_SOURCE

PKGCONFIG_OVERRIDE=	gtksourceview-1.0.pc.in

CONFIGURE_ARGS+=	--disable-build-tests

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../print/libgnomeprint/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
