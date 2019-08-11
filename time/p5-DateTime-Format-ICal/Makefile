# $NetBSD: Makefile,v 1.17 2019/08/11 13:24:07 wiz Exp $

DISTNAME=		DateTime-Format-ICal-0.09
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		11
CATEGORIES=		time perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=DateTime/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://metacpan.org/release/DateTime-Format-ICal
COMMENT=		Parse and format iCal datetime and duration strings

DEPENDS+=		p5-DateTime>=0.17:../../time/p5-DateTime
DEPENDS+=		p5-DateTime-Event-ICal>=0.03:../../time/p5-DateTime-Event-ICal
DEPENDS+=		p5-DateTime-Set>=0.10:../../time/p5-DateTime-Set
PERL5_MODULE_TYPE=	Module::Build

PERL5_PACKLIST=		auto/DateTime/Format/ICal/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
