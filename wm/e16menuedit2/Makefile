# $NetBSD: Makefile,v 1.7 2006/01/24 07:32:39 wiz Exp $
#

DISTNAME=		e16menuedit2-0.0.1
PKGREVISION=		1
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

pre-configure:
	cd ${WRKSRC}; aclocal; autoheader; automake -a --foreign -i; autoconf

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libglade2/buildlink3.mk"
.include "../../textproc/intltool/buildlink3.mk"
.include "../../textproc/scrollkeeper/omf.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
