# $NetBSD: Makefile,v 1.96 2021/03/30 11:00:38 cirnatdan Exp $
#

DISTNAME=	zenity-3.32.0
CATEGORIES=	x11 gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/zenity/3.32/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.gnome.org/
COMMENT=	Display GNOME dialogs from the command line
LICENSE=	gnu-lgpl-v2

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake intltool msgfmt pkg-config autoreconf autoconf
USE_TOOLS+=		automake gm4 aclocal xgettext autopoint

BUILD_DEPENDS+=		gnome-common-[0-9]*:../../devel/gnome-common
BUILD_DEPENDS+=		yelp-tools-[0-9]*:../../textproc/yelp-tools

pre-configure:
	${RUN} cd ${WRKSRC} && ./autogen.sh

.include "../../x11/gtk3/buildlink3.mk"
.include "../../sysutils/libnotify/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.8.0
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../textproc/gnome-doc-utils/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
