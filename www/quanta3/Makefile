# $NetBSD: Makefile,v 1.4 2003/05/22 02:48:58 markd Exp $

DISTNAME=	quanta-3.1.2
CATEGORIES=	www
COMMENT= 	HTML editor suitable for experienced web developers

.include "../../x11/kde3/Makefile.kde3"

USE_BUILDLINK2=		YES

USE_PERL5=		build
USE_GMAKE=              YES
GNU_CONFIGURE=          YES
USE_LIBTOOL=            YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

.include "../../x11/kde3/buildlink2.mk"
.include "../../x11/kdebase3/buildlink2.mk"
.include "../../x11/qt3-tools/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
