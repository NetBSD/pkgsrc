# $NetBSD: Makefile,v 1.15 2003/06/02 01:15:45 jschauma Exp $
#

DISTNAME=	gnomemm-1.2.2
PKGNAME=	${DISTNAME:S/mm/--/}
PKGREVISION=	2
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gtkmm/}

MAINTAINER=	tech-pkg@netbsd.org
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

.include "../../devel/libsigc++10/buildlink2.mk"
.include "../../x11/gnome-libs/buildlink2.mk"
.include "../../x11/gtk--/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
