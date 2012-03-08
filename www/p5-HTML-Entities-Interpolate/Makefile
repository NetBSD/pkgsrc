# $NetBSD: Makefile,v 1.1.1.1 2012/03/08 11:28:25 fhajny Exp $
#

DISTNAME=	HTML-Entities-Interpolate-1.04
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=HTML/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/HTML-Entities-Interpolate/
COMMENT=	Call HTML::Entities::encode_entities, via a hash, within a string
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

BUILD_DEPENDS+=	p5-Test-Simple>=0:../../devel/p5-Test-Simple
BUILD_DEPENDS+=	p5-Test-Pod>=0:../../devel/p5-Test-Pod
BUILD_DEPENDS+=	p5-Module-Build>=0.38000:../../devel/p5-Module-Build
DEPENDS+=	p5-HTML-Parser>=0:../../www/p5-HTML-Parser
DEPENDS+=	p5-Tie-Function>=0:../../devel/p5-Tie-Function

PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/HTML/Entities/Interpolate/.packlist
USE_LANGUAGES=		# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
