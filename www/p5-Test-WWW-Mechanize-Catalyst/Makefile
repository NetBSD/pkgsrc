# $NetBSD: Makefile,v 1.25 2022/06/28 11:37:44 wiz Exp $

DISTNAME=	Test-WWW-Mechanize-Catalyst-0.62
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Test-WWW-Mechanize-Catalyst
COMMENT=	Test::WWW::Mechanize for Catalyst
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Catalyst-Runtime>=5.00000:../../www/p5-Catalyst-Runtime
DEPENDS+=	p5-Moose>=0.67:../../devel/p5-Moose
DEPENDS+=	p5-Test-WWW-Mechanize>=1.20:../../www/p5-Test-WWW-Mechanize
DEPENDS+=	p5-Test-Exception>=0:../../devel/p5-Test-Exception
DEPENDS+=	p5-Test-WWW-Mechanize>=1.14:../../www/p5-Test-WWW-Mechanize
DEPENDS+=	p5-WWW-Mechanize>=1.54:../../www/p5-WWW-Mechanize
DEPENDS+=	p5-libwww>=5.816:../../www/p5-libwww
DEPENDS+=	p5-namespace-clean>=0.09:../../devel/p5-namespace-clean

TEST_DEPENDS+=	p5-Catalyst-Plugin-Session-[0-9]*:../../www/p5-Catalyst-Plugin-Session
TEST_DEPENDS+=	p5-Catalyst-Plugin-Session-State-Cookie-[0-9]*:../../www/p5-Catalyst-Plugin-Session-State-Cookie
TEST_DEPENDS+=	p5-Test-Exception-[0-9]*:../../devel/p5-Test-Exception
TEST_DEPENDS+=	p5-Test-utf8-[0-9]*:../../devel/p5-Test-utf8

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Test/WWW/Mechanize/Catalyst/.packlist

MAKE_ENV+=	PERL_USE_UNSAFE_INC=1

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
