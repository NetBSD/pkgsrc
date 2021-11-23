# $NetBSD: Makefile,v 1.100 2021/11/23 13:38:29 cirnatdan Exp $
#

DISTNAME=	zenity-3.41.0
CATEGORIES=	x11 gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/zenity/3.41/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.gnome.org/
COMMENT=	Display GNOME dialogs from the command line
LICENSE=	gnu-lgpl-v2.1

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		intltool msgfmt pkg-config
USE_TOOLS+=		automake gm4 aclocal xgettext autopoint itstool

TOOL_DEPENDS+=		yelp-tools-[0-9]*:../../textproc/yelp-tools
TOOL_DEPENDS+=		autoconf-archive-[0-9]*:../../devel/autoconf-archive

REPLACE_INTERPRETER+=	perl5
REPLACE.perl5.old=	@PERL@
REPLACE.perl5.new=	${PERL5}
REPLACE_FILES.perl5=	src/gdialog.in

.include "../../lang/perl5/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../sysutils/libnotify/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.8.0
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../textproc/gnome-doc-utils/buildlink3.mk"
.include "../../devel/meson/build.mk"
.include "../../mk/bsd.pkg.mk"
