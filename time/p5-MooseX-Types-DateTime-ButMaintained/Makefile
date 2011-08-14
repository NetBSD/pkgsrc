# $NetBSD: Makefile,v 1.5 2011/08/14 15:28:47 obache Exp $
#

DISTNAME=	MooseX-Types-DateTime-ButMaintained-0.11
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=MooseX/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/MooseX-Types-DateTime-ButMaintained/
COMMENT=	DateTime related constraints and coercions for Moose
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-DateTime>=0.4302:../../time/p5-DateTime
DEPENDS+=	p5-DateTime-Locale>=0.42:../../time/p5-DateTime-Locale
DEPENDS+=	p5-DateTime-TimeZone>=0.96:../../time/p5-DateTime-TimeZone
DEPENDS+=	p5-Moose>=0.41:../../devel/p5-Moose
DEPENDS+=	p5-MooseX-Types>=0.04:../../devel/p5-MooseX-Types
DEPENDS+=	p5-Olson-Abbreviations-[0-9]*:../../time/p5-Olson-Abbreviations
DEPENDS+=	p5-namespace-clean>=0.08:../../devel/p5-namespace-clean

BUILD_DEPENDS+=	p5-Test-Exception>=0.27:../../devel/p5-Test-Exception
BUILD_DEPENDS+=	p5-Test-use-ok>=0.02:../../devel/p5-Test-use-ok

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/MooseX/Types/DateTime/ButMaintained/.packlist
PERL5_MODULE_TYPE=	Module::Install

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
