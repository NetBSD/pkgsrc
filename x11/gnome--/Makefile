# $NetBSD: Makefile,v 1.18 2003/09/12 16:19:50 drochner Exp $
#

DISTNAME=	gnomemm-1.2.4
PKGNAME=	${DISTNAME:S/mm/--/}
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gtkmm/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://gtkmm.sourceforge.net/
COMMENT=	C++ binding for the GNOME libraries

GNU_CONFIGURE=	yes
USE_PERL5=	build
USE_GMAKE=	yes
USE_LIBTOOL=	yes
USE_X11BASE=	yes
USE_BUILDLINK2=	yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
REPLACE_PERL=	docgen/pce2

.include "../../devel/libsigc++10/buildlink2.mk"
.include "../../x11/gnome-libs/buildlink2.mk"
.include "../../x11/gtk--/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
