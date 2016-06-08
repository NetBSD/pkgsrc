# $NetBSD: Makefile,v 1.11 2016/06/08 19:24:58 wiz Exp $

DISTNAME=	Catalyst-Engine-PSGI-0.13
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	5
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Catalyst/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Catalyst-Engine-PSGI/
COMMENT=	Perl 5 PSGI engine for Catalyst
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=	# empty
PERL5_PACKLIST= auto/Catalyst/Engine/PSGI/.packlist


BUILD_DEPENDS+=	p5-Test-TCP-[0-9]*:../../net/p5-Test-TCP
BUILD_DEPENDS+=	p5-Test-Requires-[0-9]*:../../devel/p5-Test-Requires
BUILD_DEPENDS+=	p5-Plack-[0-9]*:../../www/p5-Plack
DEPENDS+=	p5-Catalyst-Action-RenderView-[0-9]*:../../www/p5-Catalyst-Action-RenderView
DEPENDS+=	p5-Catalyst-Runtime>=5.80007:../../www/p5-Catalyst-Runtime

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
