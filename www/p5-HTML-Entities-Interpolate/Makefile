# $NetBSD: Makefile,v 1.15 2019/06/30 20:17:29 nia Exp $
#

DISTNAME=	HTML-Entities-Interpolate-1.10
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=HTML/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/HTML-Entities-Interpolate
COMMENT=	Call HTML::Entities::encode_entities, via a hash, within a string
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-HTML-Parser>=3.69:../../www/p5-HTML-Parser
DEPENDS+=	p5-Tie-Function>=0:../../devel/p5-Tie-Function

# for make test
BUILD_DEPENDS+=	p5-Test-Simple>=1.302052:../../devel/p5-Test-Simple
BUILD_DEPENDS+=	p5-Test-Pod>=1.51:../../devel/p5-Test-Pod
BUILD_DEPENDS+=	p5-Capture-Tiny-[0-9]*:../../devel/p5-Capture-Tiny
BUILD_DEPENDS+=	p5-File-Slurper>=0.009:../../devel/p5-File-Slurper

PERL5_PACKLIST=		auto/HTML/Entities/Interpolate/.packlist
USE_LANGUAGES=		# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
