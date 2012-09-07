# $NetBSD: Makefile,v 1.33 2012/09/07 19:17:38 adam Exp $
#

DISTNAME=		e16menuedit2-0.0.3
PKGREVISION=		13
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
USE_PKGLOCALEDIR=	yes

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libglade/buildlink3.mk"
.include "../../devel/popt/buildlink3.mk"
.include "../../mk/omf-scrollkeeper.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
