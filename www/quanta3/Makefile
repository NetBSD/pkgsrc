# $NetBSD: Makefile,v 1.10 2004/01/03 18:49:55 reed Exp $

DISTNAME=	quanta-3.1.4
PKGREVISION=	1
CATEGORIES=	www
COMMENT= 	HTML editor suitable for experienced web developers
PKGREVISION=	1

.include "../../meta-pkgs/kde3/Makefile.kde3"

USE_BUILDLINK2=		YES

USE_PERL5=		build
USE_GMAKE=              YES
GNU_CONFIGURE=          YES
USE_LIBTOOL=            YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

.include "../../meta-pkgs/kde3/buildlink2.mk"
.include "../../x11/kdebase3/buildlink2.mk"
.include "../../x11/qt3-tools/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
