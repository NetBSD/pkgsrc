# $NetBSD: Makefile,v 1.10 2013/08/15 08:51:48 wen Exp $
#

DISTNAME=	MooseX-Types-DateTime-0.08
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=MooseX/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/perldoc?MooseX::Types::DateTime
COMMENT=	DateTime related constraints and coercions for Moose
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-DateTime>=0.4302:../../time/p5-DateTime
DEPENDS+=	p5-DateTime-Locale>=0.42:../../time/p5-DateTime-Locale
DEPENDS+=	p5-DateTime-TimeZone>=0.95:../../time/p5-DateTime-TimeZone
DEPENDS+=	p5-Moose>=0.41:../../devel/p5-Moose
DEPENDS+=	p5-MooseX-Types>=0.30:../../devel/p5-MooseX-Types
DEPENDS+=	p5-Time-Duration-Parse>=0.06:../../time/p5-Time-Duration-Parse
DEPENDS+=	p5-namespace-clean>=0.08:../../devel/p5-namespace-clean

BUILD_DEPENDS+=	p5-Test-Exception>=0.27:../../devel/p5-Test-Exception
BUILD_DEPENDS+=	p5-Test-use-ok>=0.02:../../devel/p5-Test-use-ok

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/MooseX/Types/DateTime/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
