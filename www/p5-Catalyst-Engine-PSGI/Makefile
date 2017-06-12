# $NetBSD: Makefile,v 1.13 2017/06/12 08:08:03 maya Exp $

DISTNAME=	Catalyst-Engine-PSGI-0.13
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	6
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Catalyst/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Catalyst-Engine-PSGI/
COMMENT=	Perl 5 PSGI engine for Catalyst
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=	# empty
MAKE_ENV+=	PERL_USE_UNSAFE_INC=1
PERL5_PACKLIST=	auto/Catalyst/Engine/PSGI/.packlist

BUILD_DEPENDS+=	p5-Test-TCP-[0-9]*:../../net/p5-Test-TCP
BUILD_DEPENDS+=	p5-Test-Requires-[0-9]*:../../devel/p5-Test-Requires
BUILD_DEPENDS+=	p5-Plack-[0-9]*:../../www/p5-Plack
DEPENDS+=	p5-Catalyst-Action-RenderView-[0-9]*:../../www/p5-Catalyst-Action-RenderView
DEPENDS+=	p5-Catalyst-Runtime>=5.80007:../../www/p5-Catalyst-Runtime

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
