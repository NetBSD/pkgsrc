# $NetBSD: Makefile,v 1.1 2018/08/20 03:03:53 wen Exp $
#

DISTNAME=	MooseX-Types-DateTime-MoreCoercions-0.15
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=MooseX/}

MAINTAINER=	wen@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/MooseX-Types-DateTime-MoreCoercions
COMMENT=	Extensions to MooseX::Types::DateTime
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-DateTime>=0.4302:../../time/p5-DateTime
DEPENDS+=	p5-DateTimeX-Easy>=0.085:../../time/p5-DateTimeX-Easy
DEPENDS+=	p5-Moose>=0.41:../../devel/p5-Moose
DEPENDS+=	p5-MooseX-Types>=0.30:../../devel/p5-MooseX-Types
DEPENDS+=	p5-namespace-clean>=0.19:../../devel/p5-namespace-clean

BUILD_DEPENDS+=	p5-Test-Fatal>=0:../../devel/p5-Test-Fatal

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/MooseX/Types/DateTime/MoreCoercions/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
