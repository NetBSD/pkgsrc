# $NetBSD: Makefile,v 1.57 2018/08/22 09:48:01 wiz Exp $

DISTNAME=	gtksourceview-2.10.5
PKGNAME=	${DISTNAME:S/-/2-/}
PKGREVISION=	31
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gtksourceview/${PKGVERSION_NOREV:R}/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://gtksourceview.sourceforge.net/
COMMENT=	Text widget that extends GTK2's GtkTextView widget (v2)
LICENSE=	gnu-gpl-v2

USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake intltool msgfmt perl pkg-config
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-build-tests

PKGCONFIG_OVERRIDE=	gtksourceview-2.0.pc.in

SUBST_CLASSES+=		ige-mac
SUBST_STAGE.ige-mac=	pre-configure
SUBST_MESSAGE.ige-mac=	Do not require ige-mac-integration.
SUBST_FILES.ige-mac=	configure
SUBST_SED.ige-mac=	-e 's,os_osx=yes,os_osx=no,'

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
