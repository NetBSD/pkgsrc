# $NetBSD: Makefile,v 1.7 2020/08/31 18:12:21 wiz Exp $
#

DISTNAME=	DateTime-Calendar-Julian-0.101
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	time perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=DateTime/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/DateTime-Calendar-Julian
COMMENT=	Dates in the Julian calendar
LICENSE=	${PERL5_LICENSE}

DEPENDS+=		p5-DateTime>=0.15:../../time/p5-DateTime

PERL5_PACKLIST=		auto/DateTime/Calendar/Julian/.packlist
USE_LANGUAGES=		# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
