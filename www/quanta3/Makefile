# $NetBSD: Makefile,v 1.15 2004/02/14 17:21:54 jlam Exp $

DISTNAME=	quanta-${_KDE_VERSION}
CATEGORIES=	www
COMMENT= 	HTML editor suitable for experienced web developers

.include "../../meta-pkgs/kde3/Makefile.kde3"

USE_BUILDLINK2=		YES

USE_PERL5=		build
USE_GNU_TOOLS+=		make
GNU_CONFIGURE=          YES
USE_LIBTOOL=            YES

.include "../../meta-pkgs/kde3/buildlink2.mk"
.include "../../x11/kdebase3/buildlink2.mk"
.include "../../x11/qt3-tools/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
