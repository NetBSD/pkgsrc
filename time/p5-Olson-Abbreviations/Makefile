# $NetBSD: Makefile,v 1.10 2014/05/29 23:37:53 wiz Exp $
#

DISTNAME=	Olson-Abbreviations-0.04
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/E/EC/ECARROLL/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Olson-Abbreviations/
COMMENT=	Perl extension for globally unique timezones abbreviation handling
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Moose-[0-9]*:../../devel/p5-Moose
DEPENDS+=	p5-MooseX-AttributeHelpers-[0-9]*:../../devel/p5-MooseX-AttributeHelpers
DEPENDS+=	p5-MooseX-ClassAttribute>=0.25:../../devel/p5-MooseX-ClassAttribute

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Olson/Abbreviations/.packlist
PERL5_MODULE_TYPE=	Module::Install::Bundled

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
