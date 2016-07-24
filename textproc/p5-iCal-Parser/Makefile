# $NetBSD: Makefile,v 1.14 2016/07/24 20:04:10 rillig Exp $
#

DISTNAME=	iCal-Parser-1.20
PKGNAME=	p5-${DISTNAME}
PKGREVISION=    2
CATEGORIES=	textproc perl5
MASTER_SITES=	http://search.cpan.org/CPAN/authors/id/R/RF/RFRANKEL/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/CPAN/authors/id/R/RF/RFRANKEL/
COMMENT=	Parse iCalendar files into a data structure
LICENSE=	${PERL5_LICENSE}

# PERL5_MODULE_TYPE=      Module::Build
PERL5_PACKLIST=	auto/iCal/Parser/.packlist

DEPENDS+=	p5-DateTime-Format-ICal>=0.08:../../time/p5-DateTime-Format-ICal
DEPENDS+=	p5-Text-vFile-asData>=0.02:../../textproc/p5-Text-vFile-asData
DEPENDS+=	p5-FreezeThaw>=0.43:../../devel/p5-FreezeThaw
DEPENDS+=	p5-IO-String-[0-9]*:../../devel/p5-IO-String

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
