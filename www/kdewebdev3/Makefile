# $NetBSD: Makefile,v 1.4.4.1 2005/05/01 17:36:58 salo Exp $

DISTNAME=	kdewebdev-${_KDE_VERSION}
PKGREVISION=	1
CATEGORIES=	www
COMMENT= 	HTML editor and tools suitable for experienced web developers

.include "../../meta-pkgs/kde3/Makefile.kde3"

USE_BUILDLINK3=		YES
USE_PERL5=		build

REPLACE_PERL=		quanta/scripts/TemplateMagic.pl \
			quanta/scripts/dwt.pl

.include "../../meta-pkgs/kde3/kde3.mk"
.include "../../x11/kdebase3/buildlink3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
