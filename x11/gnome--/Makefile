# $NetBSD: Makefile,v 1.13 2003/03/01 11:49:11 jmmv Exp $
#

DISTNAME=	gnomemm-1.2.2
PKGNAME=	${DISTNAME:S/mm/--/}
PKGREVISION=	1
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

.include "../../devel/libsigc++10/buildlink2.mk"
.include "../../x11/gnome-libs/buildlink2.mk"
.include "../../x11/gtk--/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
