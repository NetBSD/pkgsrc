# $NetBSD: Makefile,v 1.19 2020/08/31 18:12:21 wiz Exp $

DISTNAME=		DateTime-Event-Recurrence-0.19
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		4
CATEGORIES=		time perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=DateTime/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://metacpan.org/release/DateTime-Event-Recurrence
COMMENT=		DateTime::Set extension to create basic recurrence sets
LICENSE=		${PERL5_LICENSE}

DEPENDS+=		p5-DateTime-Set>=0.3600:../../time/p5-DateTime-Set

PERL5_PACKLIST=		auto/DateTime/Event/Recurrence/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
