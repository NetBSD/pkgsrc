# $NetBSD: Makefile,v 1.2 2008/06/12 02:14:51 joerg Exp $
#

DISTNAME=	iCal-Parser-1.14
PKGNAME=        p5-${DISTNAME}
CATEGORIES=	textproc perl5
MASTER_SITES=	http://search.cpan.org/CPAN/authors/id/R/RF/RFRANKEL/

MAINTAINER=     pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/CPAN/authors/id/R/RF/RFRANKEL/
COMMENT=	Parse iCalendar files into a data structure

PKG_DESTDIR_SUPPORT=	user-destdir

# PERL5_MODULE_TYPE=      Module::Build
PERL5_PACKLIST=         auto/iCal/Parser/.packlist
USE_LANGUAGES=          # none

DEPENDS+=       p5-DateTime-Format-ICal>=0.08:../../time/p5-DateTime-Format-ICal
DEPENDS+=       p5-Text-vFile-asData>=0.02:../../textproc/p5-Text-vFile-asData

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
