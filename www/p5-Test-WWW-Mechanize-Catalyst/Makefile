# $NetBSD: Makefile,v 1.1.1.1 2008/07/15 09:32:20 abs Exp $

DISTNAME=	Test-WWW-Mechanize-Catalyst-0.42
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Test-WWW-Mechanize-Catalyst/
COMMENT=	Test::WWW::Mechanize for Catalyst

DEPENDS+=	p5-WWW-Mechanize>=1.30:../../www/p5-WWW-Mechanize
DEPENDS+=	p5-Catalyst-Runtime>=5.00:../../www/p5-Catalyst-Runtime
DEPENDS+=	p5-Test-WWW-Mechanize>=1.20:../../www/p5-Test-WWW-Mechanize
DEPENDS+=	p5-Test-Exception>=0:../../devel/p5-Test-Exception

USE_LANGUAGES=	# empty
PERL5_PACKLIST= auto/Test/WWW/Mechanize/Catalyst/.packlist

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
