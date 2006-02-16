# $NetBSD: Makefile,v 1.9 2006/02/16 07:37:38 rillig Exp $
#

DISTNAME=		e16menuedit2-0.0.1
PKGREVISION=		3
CATEGORIES=		wm x11
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=enlightenment/}

MAINTAINER=		chriswareham@chriswareham.demon.co.uk
HOMEPAGE=		http://www.enlightenment.org/
COMMENT=		Menu editor for the Enlightenment window manager

DEPENDS+=		enlightenment-0.16.*:../../wm/enlightenment

BUILD_USES_MSGFMT=	yes

GNU_CONFIGURE=		yes
USE_TOOLS+=		automake pkg-config
USE_DIRS+=		gnome2-1.5
USE_PKGLOCALEDIR=	yes
MAKE_ENV+=		CATALOGS="de.gmo en.gmo ko.gmo tr.gmo"

pre-configure:
	set -e; cd ${WRKSRC:Q}; \
	aclocal; autoheader; automake -a --foreign -i; autoconf

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libglade2/buildlink3.mk"
.include "../../textproc/intltool/buildlink3.mk"
.include "../../textproc/scrollkeeper/omf.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
