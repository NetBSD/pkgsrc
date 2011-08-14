# $NetBSD: Makefile,v 1.7 2011/08/14 15:28:44 obache Exp $

DISTNAME=		DateTime-Event-ICal-0.10
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		2
CATEGORIES=		time perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=DateTime/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/DateTime-Event-ICal
COMMENT=		DateTime extension for computing rfc2445 recurrences
LICENSE=		${PERL5_LICENSE}

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=		p5-DateTime>=0.36:../../time/p5-DateTime
DEPENDS+=		p5-DateTime-Event-Recurrence>=0.16:../../time/p5-DateTime-Event-Recurrence

PERL5_PACKLIST=		auto/DateTime/Event/ICal/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
