# $NetBSD: Makefile,v 1.99 2021/05/04 08:51:01 cirnatdan Exp $
#

DISTNAME=	zenity-3.32.0
PKGREVISION=	1
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
USE_TOOLS+=		automake gm4 aclocal xgettext autopoint itstool

TOOL_DEPENDS+=		yelp-tools-[0-9]*:../../textproc/yelp-tools
TOOL_DEPENDS+=		autoconf-archive-[0-9]*:../../devel/autoconf-archive

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
