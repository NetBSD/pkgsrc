# $NetBSD: Makefile,v 1.5 2004/10/03 00:18:25 tv Exp $
#

DISTNAME=	epiphany-extensions-1.4.0
PKGREVISION=	1
CATEGORIES=	www gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/epiphany-extensions/1.4/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jmmv@NetBSD.org
HOMEPAGE=	http://www.gnome.org/projects/epiphany/extensions.html
COMMENT=	Extensions for the Epiphany web browser

GNU_CONFIGURE=		YES
USE_BUILDLINK3=		YES
USE_LIBTOOL=		YES
USE_PKGLOCALEDIR=	YES

CPPFLAGS+=		-I${BUILDLINK_PREFIX.mozilla-gtk2}/include/mozilla-gtk2/webbrwsr

.include "../../devel/GConf2/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libglade2/buildlink3.mk"
.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../textproc/intltool/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/opensp/buildlink3.mk"
.include "../../www/epiphany/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
