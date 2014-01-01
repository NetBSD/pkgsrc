# $NetBSD: Makefile,v 1.90 2014/01/01 11:52:37 wiz Exp $
#

DISTNAME=	epiphany-extensions-2.32.0
PKGREVISION=	26
CATEGORIES=	www gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/epiphany-extensions/2.32/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnome.org/projects/epiphany/extensions.html
COMMENT=	Extensions for the Epiphany web browser

GNU_CONFIGURE=		YES
USE_TOOLS+=		gmake intltool msgfmt pkg-config
USE_LIBTOOL=		YES
USE_PKGLOCALEDIR=	YES
USE_LANGUAGES=		c c++

# Avoid -Werror, which breaks the build sometimes.
CONFIGURE_ARGS+=	--enable-compile-warnings=no
CONFIGURE_ARGS+=	--with-extensions=all

.include "../../devel/GConf/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.15.5
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../textproc/gnome-doc-utils/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/opensp/buildlink3.mk"
.include "../../mk/omf-scrollkeeper.mk"
.include "../../www/epiphany/buildlink3.mk"
BUILDLINK_API_DEPENDS.gtk2+=	gtk2+>=2.11.6
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
