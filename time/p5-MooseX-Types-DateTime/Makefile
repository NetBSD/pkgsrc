# $NetBSD: Makefile,v 1.1.1.2 2009/02/14 00:15:27 abs Exp $
#

DISTNAME=	MooseX-Types-DateTime-0.03
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
# MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/N/NU/NUFFIN/}
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=MooseX/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/perldoc?MooseX::Types::DateTime
COMMENT=	Organise your Moose types in libraries

DEPENDS+=	p5-Moose>=0.41:../../devel/p5-Moose
DEPENDS+=	p5-DateTime>=0.4302:../../time/p5-DateTime
DEPENDS+=	p5-DateTime-Locale>=0.42:../../time/p5-DateTime-Locale
DEPENDS+=	p5-DateTime-TimeZone>=0.81:../../time/p5-DateTime-TimeZone
DEPENDS+=	p5-Test-use-ok>=0.02:../../devel/p5-Test-use-ok
DEPENDS+=	p5-Test-Exception>=0.27:../../devel/p5-Test-Exception
DEPENDS+=	p5-MooseX-Types>=0.04:../../devel/p5-MooseX-Types
DEPENDS+=	p5-DateTime-Format-Natural>=0.71:../../time/p5-DateTime-Format-Natural
DEPENDS+=	p5-DateTime-Format-DateParse>=0.04:../../time/p5-DateTime-Format-DateParse
DEPENDS+=	p5-DateTime-Format-Flexible>=0.05:../../time/p5-DateTime-Format-Flexible
DEPENDS+=	p5-DateTimeX-Easy>=0.082:../../time/p5-DateTimeX-Easy
DEPENDS+=	p5-Time-Duration-Parse>=0.06:../../time/p5-Time-Duration-Parse
DEPENDS+=	p5-namespace-clean>=0.08:../../devel/p5-namespace-clean


PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/MooseX/Types/DateTime/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
