# $NetBSD: Makefile,v 1.1.1.1 2007/11/04 16:02:12 adrianp Exp $
#

DISTNAME=	Time-Interval-1.22
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	time
MASTER_SITES=	http://search.cpan.org/CPAN/authors/id/A/AH/AHICOX/

MAINTAINER=	adrianp@NetBSD.org
HOMEPAGE=	http://search.cpan.org/CPAN/authors/id/A/AH/AHICOX/
COMMENT=	Converts time intervals of days, hours, minutes, and seconds

DEPENDS+=	p5-DateTime-[0-9]*:../../time/p5-DateTime

PERL5_PACKLIST=	auto/Time/Interval/.packlist
USE_LANGUAGES=	# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
