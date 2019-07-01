# $NetBSD: Makefile,v 1.19 2019/07/01 21:35:57 nia Exp $

DISTNAME=	Time-Interval-1.234
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	time
MASTER_SITES=	https://cpan.metacpan.org/authors/id/A/AH/AHICOX/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://cpan.metacpan.org/authors/id/A/AH/AHICOX/
COMMENT=	Converts time intervals of days, hours, minutes, and seconds
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-TimeDate-[0-9]*:../../time/p5-TimeDate

PERL5_PACKLIST=	auto/Time/Interval/.packlist
USE_LANGUAGES=	# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
