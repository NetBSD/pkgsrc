# $NetBSD: Makefile,v 1.31 2012/07/06 11:53:37 sno Exp $

DISTNAME=	DateTime-0.76
PKGNAME=	p5-${DISTNAME}00
CATEGORIES=	time perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=DateTime/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://datetime.perl.org/
COMMENT=	Perl module for date/time sets and ranges
LICENSE=	artistic-2.0

BUILD_DEPENDS+=	p5-Test-Exception-[0-9]*:../../devel/p5-Test-Exception
BUILD_DEPENDS+=	p5-Test-Fatal-[0-9]*:../../devel/p5-Test-Fatal
BUILD_DEPENDS+=	{perl>=5.10.1,p5-Test-Simple>=0.88}:../../devel/p5-Test-Simple

DEPENDS+=	p5-DateTime-Locale>=0.41:../../time/p5-DateTime-Locale
DEPENDS+=	p5-DateTime-TimeZone>=1.09:../../time/p5-DateTime-TimeZone
DEPENDS+=	p5-Params-Validate>=0.76:../../devel/p5-Params-Validate
DEPENDS+=	p5-Math-Round-[0-9]*:../../math/p5-Math-Round

USE_LANGUAGES=	c # installs C module
PERL5_PACKLIST=	auto/DateTime/.packlist
PERL5_MODULE_TYPE=	Module::Build

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
