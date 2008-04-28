# $NetBSD: Makefile,v 1.1.1.1 2008/04/28 14:19:58 mjl Exp $
#

DISTNAME=	iCal-Parser-1.14
PKGNAME=        p5-${DISTNAME}
CATEGORIES=	textproc perl5
MASTER_SITES=	http://search.cpan.org/CPAN/authors/id/R/RF/RFRANKEL/

MAINTAINER=     pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/CPAN/authors/id/R/RF/RFRANKEL/
COMMENT=	Parse iCalendar files into a data structure

# PERL5_MODULE_TYPE=      Module::Build
PERL5_PACKLIST=         auto/iCal/Parser/.packlist
USE_LANGUAGES=          # none

DEPENDS+=       p5-DateTime-Format-ICal>=0.08:../../time/p5-DateTime-Format-ICal
DEPENDS+=       p5-Text-vFile-asData>=0.02:../../textproc/p5-Text-vFile-asData

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
