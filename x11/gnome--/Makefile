# $NetBSD: Makefile,v 1.24 2005/04/11 21:48:07 tv Exp $
#

DISTNAME=	gnomemm-1.2.4
PKGNAME=	${DISTNAME:S/mm/--/}
PKGREVISION=	2
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gtkmm/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://gtkmm.sourceforge.net/
COMMENT=	C++ binding for the GNOME libraries

GNU_CONFIGURE=	yes
USE_PERL5=	build
USE_GNU_TOOLS+=	make
USE_LIBTOOL=	yes
USE_X11BASE=	yes
REPLACE_PERL=	docgen/pce2

.include "../../devel/libsigc++10/buildlink3.mk"
.include "../../x11/gnome-libs/buildlink3.mk"
.include "../../x11/gtk--/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
