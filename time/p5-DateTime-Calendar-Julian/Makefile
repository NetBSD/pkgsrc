# $NetBSD: Makefile,v 1.10 2021/03/27 23:44:41 wen Exp $

DISTNAME=	DateTime-Calendar-Julian-0.104
PKGNAME=	p5-${DISTNAME}
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
