# $NetBSD: Makefile,v 1.29 2019/08/11 13:25:02 wiz Exp $

DISTNAME=	Test-WWW-Mechanize-1.52
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Test-WWW-Mechanize
COMMENT=	Perl5 module providing testing-specific WWW::Mechanize subclass
LICENSE=	artistic-2.0

PERL5_PACKLIST=		auto/Test/WWW/Mechanize/.packlist

DEPENDS+=	p5-Carp-Assert-More-[0-9]*:../../devel/p5-Carp-Assert-More
DEPENDS+=	p5-HTML-Parser-[0-9]*:../../www/p5-HTML-Parser
DEPENDS+=	p5-HTML-Tree-[0-9]*:../../www/p5-HTML-Tree
DEPENDS+=	p5-HTTP-Server-Simple>=0.42:../../www/p5-HTTP-Server-Simple
DEPENDS+=	p5-libwww>=6.02:../../www/p5-libwww
DEPENDS+=	p5-Test-LongString>=0.15:../../devel/p5-Test-LongString
DEPENDS+=	p5-URI-[0-9]*:../../www/p5-URI
DEPENDS+=	p5-WWW-Mechanize>=1.68:../../www/p5-WWW-Mechanize

# XXX for test
#BUILD_DEPENDS+=	p5-HTML-Lint>=2.20:../../www/p5-HTML-Lint

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
