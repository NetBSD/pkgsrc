# $NetBSD: Makefile,v 1.14 2022/06/28 11:37:47 wiz Exp $

DISTNAME=	WWW-Mechanize-Shell-0.59
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=WWW/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/WWW-Mechanize-Shell
COMMENT=	Interactive shell for WWW::Mechanize
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Term-Shell>=0.02:../../devel/p5-Term-Shell
DEPENDS+=	p5-URI-[0-9]*:../../www/p5-URI
DEPENDS+=	p5-libwww>=5.69:../../www/p5-libwww
DEPENDS+=	p5-WWW-Mechanize>=1.20:../../www/p5-WWW-Mechanize
DEPENDS+=	p5-WWW-Mechanize-FormFiller>=0.05:../../www/p5-WWW-Mechanize-FormFiller
DEPENDS+=	p5-Hook-LexWrap>0.20:../../devel/p5-Hook-LexWrap
DEPENDS+=	p5-HTML-Display-[0-9]*:../../www/p5-HTML-Display
DEPENDS+=	p5-HTML-TokeParser-Simple>=2.0:../../www/p5-HTML-TokeParser-Simple
TEST_DEPENDS+=	p5-Test-HTTP-LocalServer-[0-9]*:../../devel/p5-Test-HTTP-LocalServer

USE_LANGUAGES=		# empty
PERL5_MODULE_TYPE=	MakeMaker
PERL5_PACKLIST=		auto/WWW/Mechanize/Shell/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
