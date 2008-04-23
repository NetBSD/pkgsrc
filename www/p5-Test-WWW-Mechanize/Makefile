# $NetBSD: Makefile,v 1.4 2008/04/23 21:10:32 wiz Exp $
#

DISTNAME=	Test-WWW-Mechanize-1.20
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5twm
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Test-WWW-Mechanize/
COMMENT=	Perl5 module providing testing-specific WWW::Mechanize subclass

PERL5_PACKLIST=		auto/Test/WWW/Mechanize/.packlist

DEPENDS+=	p5-Carp-Assert-More-[0-9]*:../../devel/p5-Carp-Assert-More
DEPENDS+=	p5-Carp-Assert-[0-9]*:../../devel/p5-Carp-Assert
DEPENDS+=	p5-HTTP-Server-Simple>=0.07:../../www/p5-HTTP-Server-Simple
DEPENDS+=	p5-Test-LongString>=0.09nb1:../../devel/p5-Test-LongString
DEPENDS+=	p5-URI-[0-9]*:../../www/p5-URI
DEPENDS+=	p5-WWW-Mechanize>=1.0:../../www/p5-WWW-Mechanize

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
