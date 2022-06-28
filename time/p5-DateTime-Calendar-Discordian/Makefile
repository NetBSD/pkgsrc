# $NetBSD: Makefile,v 1.20 2022/06/28 11:36:52 wiz Exp $
#

DISTNAME=	DateTime-Calendar-Discordian-1.0
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	9
CATEGORIES=	time perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=DateTime/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/DateTime-Calendar-Discordian
COMMENT=	Perl extension for the Discordian Calendar
LICENSE=	${PERL5_LICENSE}

DEPENDS+=		p5-DateTime-[0-9]*:../../time/p5-DateTime
DEPENDS+=		p5-DateTime-Locale-[0-9]*:../../time/p5-DateTime-Locale
DEPENDS+=		p5-Params-Validate-[0-9]*:../../devel/p5-Params-Validate

PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/DateTime/Calendar/Discordian/.packlist
USE_LANGUAGES=		# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
