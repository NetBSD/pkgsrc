# $NetBSD: Makefile,v 1.1.1.1 2008/03/16 18:56:11 tonnerre Exp $
#

DISTNAME=	CSS-Squish-0.07
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=CSS/}

MAINTAINER=	tonnerre@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/CSS-Squiish/
COMMENT=	Compact many CSS files into one big file

DEPENDS+=	p5-Test-LongString-[0-9]*:../../devel/p5-Test-LongString
DEPENDS+=	p5-URI-[0-9]*:../../www/p5-URI

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/CSS/Squish/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
