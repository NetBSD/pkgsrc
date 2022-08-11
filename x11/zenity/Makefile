# $NetBSD: Makefile,v 1.106 2022/08/11 05:09:36 gutteridge Exp $
#

DISTNAME=	zenity-3.41.0
PKGREVISION=	3
CATEGORIES=	x11 gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/zenity/3.41/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.gnome.org/
COMMENT=	Display GNOME dialogs from the command line
LICENSE=	gnu-lgpl-v2.1

USE_TOOLS+=		pkg-config perl:run
USE_TOOLS+=		itstool msgfmt

TOOL_DEPENDS+=		yelp-tools-[0-9]*:../../textproc/yelp-tools

REPLACE_INTERPRETER+=	perl5
REPLACE.perl5.old=	@PERL@
REPLACE.perl5.new=	${PERL5}
REPLACE_FILES.perl5=	src/gdialog.in

.include "../../x11/gtk3/buildlink3.mk"
.include "../../sysutils/libnotify/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.8.0
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../textproc/gnome-doc-utils/buildlink3.mk"
.include "../../devel/meson/build.mk"
.include "../../mk/bsd.pkg.mk"
