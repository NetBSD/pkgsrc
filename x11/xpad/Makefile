# $NetBSD: Makefile,v 1.1.1.1 2003/09/02 07:19:20 xtraeme Exp $
#

DISTNAME=	xpad-1.11
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=xpad/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	xtraeme@NetBSD.org
HOMEPAGE=	http://xpad.sourceforge.net/
COMMENT=	Sticky notes application in GTK 2

BUILD_USES_MSGFMT=	yes
DEPENDS+=		gnome2-dirs>=1.2:../../misc/gnome2-dirs

GNU_CONFIGURE=		yes
USE_BUILDLINK2=		yes
USE_GMAKE=		yes
USE_PKGLOCALEDIR=	yes
USE_X11=		yes

.include "../../converters/libiconv/buildlink2.mk"
.include "../../x11/gtk2/buildlink2.mk"
.include "../../textproc/intltool/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
