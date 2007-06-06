# $NetBSD: Makefile,v 1.1.1.1 2007/06/06 12:12:35 markd Exp $

DISTNAME=		Data-ICal-0.13
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		time perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Data/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Data-ICal
COMMENT=		Generates iCalendar (RFC 2445) calendar files

DEPENDS+=		p5-Class-Accessor>=0.30:../../devel/p5-Class-Accessor
DEPENDS+=		p5-Class-ReturnValue>=0.53:../../devel/p5-Class-ReturnValue
DEPENDS+=		p5-Text-vFile-asData>=0.05:../../textproc/p5-Text-vFile-asData

BUILD_DEPENDS+=		p5-Test-LongString-[0-9]*:../../devel/p5-Test-LongString
BUILD_DEPENDS+=		p5-Test-NoWarnings-[0-9]*:../../devel/p5-Test-NoWarnings
BUILD_DEPENDS+=		p5-Test-Warn-[0-9]*:../../devel/p5-Test-Warn

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/Data/ICal/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
