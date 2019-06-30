# $NetBSD: Makefile,v 1.23 2019/06/30 20:17:46 nia Exp $

DISTNAME=		URI-Fetch-0.13
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		2
CATEGORIES=		www perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=URI/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://metacpan.org/release/URI-Fetch
COMMENT=		Perl module to intelligently fetch syndication feeds
LICENSE=		${PERL5_LICENSE}

DEPENDS+=		p5-libwww-[0-9]*:../../www/p5-libwww
DEPENDS+=		p5-Class-ErrorHandler-[0-9]*:../../devel/p5-Class-ErrorHandler
DEPENDS+=		p5-URI-[0-9]*:../../www/p5-URI

BUILD_DEPENDS+=		p5-Test-RequiresInternet>=0:../../net/p5-Test-RequiresInternet

USE_LANGUAGES=		# empty

MAKE_ENV+=		PERL_EXTUTILS_AUTOINSTALL=--defaultdeps
PERL5_PACKLIST=		auto/URI/Fetch/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
