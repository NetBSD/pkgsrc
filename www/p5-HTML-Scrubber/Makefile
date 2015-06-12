# $NetBSD: Makefile,v 1.19 2015/06/12 10:52:00 wiz Exp $
#

DISTNAME=	HTML-Scrubber-0.11
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=HTML/}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Extension for scrubbing/sanitizing html
LICENSE=	${PERL5_LICENSE}

DEPENDS+=		p5-HTML-Parser>=3.47:../../www/p5-HTML-Parser

PERL5_MODULE_TYPE=	Module::Build

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/HTML/Scrubber/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
