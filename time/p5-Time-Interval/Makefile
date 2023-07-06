# $NetBSD: Makefile,v 1.26 2023/07/06 09:42:17 wiz Exp $

DISTNAME=	Time-Interval-1.234
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	6
CATEGORIES=	time
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/A/AH/AHICOX/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/pod/distribution/Time-Interval/Interval.pod
COMMENT=	Converts time intervals of days, hours, minutes, and seconds
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-TimeDate-[0-9]*:../../time/p5-TimeDate

PERL5_PACKLIST=	auto/Time/Interval/.packlist
USE_LANGUAGES=	# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
