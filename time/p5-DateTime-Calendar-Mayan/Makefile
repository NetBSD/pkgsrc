# $NetBSD: Makefile,v 1.12 2019/06/30 20:17:14 nia Exp $
#

DISTNAME=	DateTime-Calendar-Mayan-0.0601
PKGNAME=	p5-${DISTNAME:S/0601/06.01/}
PKGREVISION=	9
CATEGORIES=	time perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=DateTime/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/DateTime-Calendar-Mayan
COMMENT=	The Mayan Long Count, Haab, and Tzolkin calendars
LICENSE=	${PERL5_LICENSE}

DEPENDS+=		p5-DateTime>=0.15:../../time/p5-DateTime
DEPENDS+=		p5-Params-Validate>=0.64:../../devel/p5-Params-Validate

PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/DateTime/Calendar/Mayan/.packlist
USE_LANGUAGES=		# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
