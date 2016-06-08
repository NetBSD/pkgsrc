# $NetBSD: Makefile,v 1.22 2016/06/08 19:25:04 wiz Exp $
#

DISTNAME=	HTML-Scrubber-0.15
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
#PKGREVISION=	0
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=HTML/}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Extension for scrubbing/sanitizing html
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-HTML-Parser>=3.47:../../www/p5-HTML-Parser
BUILD_DEPENDS+=	p5-Test-NoTabs-[0-9]*:../../devel/p5-Test-NoTabs

PERL5_MODULE_TYPE=	Module::Build

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/HTML/Scrubber/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
