# $NetBSD: Makefile,v 1.5 2005/07/13 18:01:47 jlam Exp $
#

DISTNAME=	HTML-Scrubber-0.08
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=HTML/}

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Extension for scrubbing/sanitizing html

DEPENDS+=	p5-HTML-Parser>=3:../../www/p5-HTML-Parser

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/HTML/Scrubber/.packlist
EXTRACT_USING=		pax

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
