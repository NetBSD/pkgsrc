# $NetBSD: Makefile,v 1.11 2016/06/08 19:25:02 wiz Exp $
#

DISTNAME=	HTML-Entities-Interpolate-1.09
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=HTML/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/HTML-Entities-Interpolate/
COMMENT=	Call HTML::Entities::encode_entities, via a hash, within a string
LICENSE=	${PERL5_LICENSE}

#BUILD_DEPENDS+=	{perl>=5.6.2,p5-Test-Simple>=0}:../../devel/p5-Test-Simple
BUILD_DEPENDS+=	p5-Test-Pod>=0:../../devel/p5-Test-Pod
#BUILD_DEPENDS+=	{perl>=5.13.11,p5-Module-Build>=0.38000}:../../devel/p5-Module-Build
DEPENDS+=	p5-HTML-Parser>=0:../../www/p5-HTML-Parser
DEPENDS+=	p5-Tie-Function>=0:../../devel/p5-Tie-Function
# for make test
BUILD_DEPENDS+=	p5-Test-Stream-[0-9]*:../../devel/p5-Test-Stream
BUILD_DEPENDS+=	p5-Capture-Tiny-[0-9]*:../../devel/p5-Capture-Tiny
BUILD_DEPENDS+=	p5-File-Slurper-[0-9]*:../../devel/p5-File-Slurper

PERL5_PACKLIST=		auto/HTML/Entities/Interpolate/.packlist
USE_LANGUAGES=		# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
