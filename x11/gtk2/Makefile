# $NetBSD: Makefile,v 1.4 2002/07/03 01:23:43 dmcmahill Exp $
#

DISTNAME=		gtk+-2.0.5
PKGNAME=		${DISTNAME:S/gtk/gtk2/}
CATEGORIES=		x11
MASTER_SITES=		ftp://ftp.gtk.org/pub/gtk/v2.0/ \
			ftp://ftp.cs.umn.edu/pub/gimp/gtk/v2.0/ \
			http://www.ameth.org/gimp/pub/gtk/v2.0/ \
			${MASTER_SITE_GNOME:=stable/sources/gtk/}

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.gtk.org/
COMMENT=		Gimp toolkit. Libraries for building X11 user interfaces

BUILD_USES_MSGFMT=	yes
USE_BUILDLINK_ONLY=	yes
USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
USE_GMAKE=		yes

GNU_CONFIGURE=		 yes
CONFIGURE_ARGS+=	--with-xinput=xfree
MAKE_ENV+=		PKGLOCALEDIR="${PKGLOCALEDIR}"

.include "../../devel/atk/buildlink.mk"
.include "../../devel/gettext-lib/buildlink.mk"
.include "../../devel/glib2/buildlink.mk"
.include "../../devel/pango/buildlink.mk"
.include "../../devel/pkgconfig/buildlink.mk"
.include "../../graphics/freetype2/buildlink.mk"
.include "../../graphics/jpeg/buildlink.mk"
.include "../../graphics/png/buildlink.mk"
.include "../../graphics/tiff/buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
