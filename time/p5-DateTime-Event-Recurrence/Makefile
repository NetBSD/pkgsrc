# $NetBSD: Makefile,v 1.1.1.1 2007/06/06 12:09:21 markd Exp $

DISTNAME=		DateTime-Event-Recurrence-0.16
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		time perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=DateTime/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/DateTime-Event-Recurrence
COMMENT=		DateTime::Set extension to create basic recurrence sets

DEPENDS+=		p5-DateTime-Set>=0.17:../../time/p5-DateTime-Set

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/DateTime/Event/Recurrence/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
