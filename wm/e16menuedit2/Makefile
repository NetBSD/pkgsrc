# $NetBSD: Makefile,v 1.19 2009/02/14 19:10:42 joerg Exp $
#

DISTNAME=		e16menuedit2-0.0.3
PKGREVISION=		1
CATEGORIES=		wm x11
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=enlightenment/}

MAINTAINER=		chriswareham@chriswareham.demon.co.uk
HOMEPAGE=		http://www.enlightenment.org/
COMMENT=		Menu editor for the Enlightenment window manager

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=		enlightenment-0.16.*:../../wm/enlightenment

BROKEN_GETTEXT_DETECTION=	yes

GNU_CONFIGURE=		yes
USE_TOOLS+=		automake intltool msgfmt pkg-config
USE_DIRS+=		gnome2-1.5
USE_PKGLOCALEDIR=	yes
MAKE_ENV+=		CATALOGS="de.gmo en.gmo ko.gmo tr.gmo"

BUILD_DEPENDS+=		gettext-m4>=0.14.6:../../devel/gettext-m4

pre-configure:
	set -e; cd ${WRKSRC:Q}; \
	aclocal; autoheader; automake -a --foreign -i; autoconf

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libglade/buildlink3.mk"
.include "../../devel/popt/buildlink3.mk"
.include "../../textproc/rarian/omf.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
