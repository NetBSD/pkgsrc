# $NetBSD: Makefile,v 1.20 2009/03/07 17:45:20 joerg Exp $
#

DISTNAME=		e16menuedit2-0.0.3
PKGREVISION=		2
CATEGORIES=		wm x11
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=enlightenment/}

MAINTAINER=		chriswareham@chriswareham.demon.co.uk
HOMEPAGE=		http://www.enlightenment.org/
COMMENT=		Menu editor for the Enlightenment window manager

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=		enlightenment-0.16.*:../../wm/enlightenment

BROKEN_GETTEXT_DETECTION=	yes

GNU_CONFIGURE=		yes
USE_TOOLS+=		intltool msgfmt pkg-config
USE_DIRS+=		gnome2-1.5
USE_PKGLOCALEDIR=	yes

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libglade/buildlink3.mk"
.include "../../devel/popt/buildlink3.mk"
.include "../../textproc/rarian/omf.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
