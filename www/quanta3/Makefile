# $NetBSD: Makefile,v 1.18 2004/04/20 12:53:28 markd Exp $

DISTNAME=	quanta-${_KDE_VERSION}
CATEGORIES=	www
COMMENT= 	HTML editor suitable for experienced web developers

.include "../../meta-pkgs/kde3/Makefile.kde3"

USE_BUILDLINK3=		YES
USE_PERL5=		build

REPLACE_PERL=		quanta/data/scripts/TemplateMagic.pl \
			quanta/data/scripts/dwt.pl

.include "../../meta-pkgs/kde3/kde3.mk"
.include "../../x11/kdebase3/buildlink3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
