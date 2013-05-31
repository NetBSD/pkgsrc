# $NetBSD: Makefile,v 1.10 2013/05/31 12:42:25 wiz Exp $

DISTNAME=		DateTime-Event-ICal-0.10
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		4
CATEGORIES=		time perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=DateTime/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/DateTime-Event-ICal
COMMENT=		DateTime extension for computing rfc2445 recurrences
LICENSE=		${PERL5_LICENSE}

PKG_INSTALLATION_TYPES=	overwrite pkgviews

DEPENDS+=		p5-DateTime>=0.36:../../time/p5-DateTime
DEPENDS+=		p5-DateTime-Event-Recurrence>=0.16:../../time/p5-DateTime-Event-Recurrence

PERL5_PACKLIST=		auto/DateTime/Event/ICal/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
