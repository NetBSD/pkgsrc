# $NetBSD: Makefile,v 1.20 2024/08/11 02:02:26 wen Exp $

DISTNAME=	Date-ICal-2.682
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	time perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Date/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Date-ICal
COMMENT=	Perl extension for ICalendar date objects
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Date-Leapyear>=1.03:../../time/p5-Date-Leapyear

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Date/ICal/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
