# $NetBSD: Makefile,v 1.12 2013/12/09 14:17:56 obache Exp $

DISTNAME=		URI-Fetch-0.09
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		4
SVR4_PKGNAME=		p5urf
CATEGORIES=		www perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=URI/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/URI-Fetch/
COMMENT=		Perl module to intelligently fetch syndication feeds
LICENSE=		${PERL5_LICENSE}

DEPENDS+=		p5-libwww-[0-9]*:../../www/p5-libwww
DEPENDS+=		p5-Class-ErrorHandler-[0-9]*:../../devel/p5-Class-ErrorHandler
DEPENDS+=		{perl>=5.9.3,p5-IO-Compress>=2.017}:../../devel/p5-IO-Compress	# Compress::Zlib
#DEPENDS+=		p5-Storable-[0-9]*:../../devel/p5-Storable
DEPENDS+=		p5-URI-[0-9]*:../../www/p5-URI

USE_LANGUAGES=		# empty

MAKE_ENV+=		PERL_EXTUTILS_AUTOINSTALL=--defaultdeps
PERL5_PACKLIST=		auto/URI/Fetch/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
