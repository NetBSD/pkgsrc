# $NetBSD: Makefile,v 1.2 2004/12/20 11:31:13 grant Exp $
#

DISTNAME=	HTML-Scrubber-0.08
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=HTML/}

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Extension for scrubbing/sanitizing html

DEPENDS+=	p5-HTML-Parser>=3:../../www/p5-HTML-Parser

USE_BUILDLINK3=		YES
USE_LANGUAGES=		# empty
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/HTML/Scrubber/.packlist
EXTRACT_USING_PAX=	YES

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
