# $NetBSD: Makefile,v 1.3 2019/01/04 02:37:28 wen Exp $
#

DISTNAME=	DateTime-Calendar-Julian-0.100
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	time perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=DateTime/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/DateTime-Calendar-Julian/
COMMENT=	Dates in the Julian calendar
LICENSE=	${PERL5_LICENSE}

DEPENDS+=		p5-DateTime>=0.15:../../time/p5-DateTime

PERL5_PACKLIST=		auto/DateTime/Calendar/Julian/.packlist
USE_LANGUAGES=		# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
