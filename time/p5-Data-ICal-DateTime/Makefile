# $NetBSD: Makefile,v 1.24 2023/07/06 09:42:09 wiz Exp $

DISTNAME=		Data-ICal-DateTime-0.82
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		6
CATEGORIES=		time perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Data/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://metacpan.org/release/Data-ICal-DateTime
COMMENT=		Convenience methods for using Data::ICal with DateTime
LICENSE=		${PERL5_LICENSE}

DEPENDS+=		p5-Class-Accessor>=0.30:../../devel/p5-Class-Accessor
DEPENDS+=		p5-Clone>=0.22:../../devel/p5-Clone
DEPENDS+=		p5-Data-ICal>=0.07:../../time/p5-Data-ICal
DEPENDS+=		p5-DateTime-Format-ICal>=0.08:../../time/p5-DateTime-Format-ICal
DEPENDS+=		p5-DateTime-Set>=0.25:../../time/p5-DateTime-Set

TOOL_DEPENDS+=		p5-Test-LongString-[0-9]*:../../devel/p5-Test-LongString
TOOL_DEPENDS+=		p5-Test-NoWarnings-[0-9]*:../../devel/p5-Test-NoWarnings
TOOL_DEPENDS+=		p5-Test-Warn-[0-9]*:../../devel/p5-Test-Warn

PERL5_PACKLIST=		auto/Data/ICal/DateTime/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
