# $NetBSD: Makefile,v 1.12 2002/09/11 22:36:51 wiz Exp $
#

DISTNAME=	gnomemm-1.2.2
PKGNAME=	${DISTNAME:S/mm/--/}
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gtkmm/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://gtkmm.sourceforge.net/
COMMENT=	C++ binding for the GNOME libraries

GNU_CONFIGURE=	yes
USE_PERL5=	build
USE_GMAKE=	yes
USE_LIBTOOL=	yes
USE_X11BASE=	yes
USE_BUILDLINK2=	yes
LTCONFIG_OVERRIDE=	${WRKSRC}/scripts/ltconfig
REPLACE_PERL=	docgen/pce2

.include "../../devel/libsigc++/buildlink2.mk"
.include "../../x11/gnome-libs/buildlink2.mk"
.include "../../x11/gtk--/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
