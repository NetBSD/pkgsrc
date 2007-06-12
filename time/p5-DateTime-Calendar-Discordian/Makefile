# $NetBSD: Makefile,v 1.1.1.1 2007/06/12 00:02:30 heinz Exp $
#

DISTNAME=	DateTime-Calendar-Discordian-0.9.4
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	time perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=DateTime/}

MAINTAINER=	heinz@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/DateTime-Calendar-Discordian
COMMENT=	Perl extension for the Discordian Calendar

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=		p5-DateTime-[0-9]*:../../time/p5-DateTime
DEPENDS+=		p5-DateTime-Locale-[0-9]*:../../time/p5-DateTime-Locale
DEPENDS+=		p5-Params-Validate-[0-9]*:../../devel/p5-Params-Validate

PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/DateTime/Calendar/Discordian/.packlist
USE_LANGUAGES=		# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
