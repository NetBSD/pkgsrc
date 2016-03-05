# $NetBSD: Makefile,v 1.12 2016/03/05 08:26:42 wen Exp $

DISTNAME=		DateTime-Event-Recurrence-0.18
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		time perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=DateTime/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/DateTime-Event-Recurrence
COMMENT=		DateTime::Set extension to create basic recurrence sets
LICENSE=		${PERL5_LICENSE}

DEPENDS+=		p5-DateTime-Set>=0.3600:../../time/p5-DateTime-Set

PERL5_PACKLIST=		auto/DateTime/Event/Recurrence/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
