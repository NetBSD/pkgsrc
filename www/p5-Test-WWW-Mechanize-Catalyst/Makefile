# $NetBSD: Makefile,v 1.16 2017/06/05 14:25:32 ryoon Exp $

DISTNAME=	Test-WWW-Mechanize-Catalyst-0.60
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Test-WWW-Mechanize-Catalyst/
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

BUILD_DEPENDS+=	p5-Catalyst-Plugin-Session-[0-9]*:../../www/p5-Catalyst-Plugin-Session
BUILD_DEPENDS+=	p5-Catalyst-Plugin-Session-State-Cookie-[0-9]*:../../www/p5-Catalyst-Plugin-Session-State-Cookie
BUILD_DEPENDS+=	p5-Test-Exception-[0-9]*:../../devel/p5-Test-Exception

USE_LANGUAGES=	# empty
PERL5_PACKLIST= auto/Test/WWW/Mechanize/Catalyst/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
