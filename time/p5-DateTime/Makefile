# $NetBSD: Makefile,v 1.15 2009/04/12 18:51:59 sno Exp $

DISTNAME=	DateTime-0.47
PKGNAME=	p5-${DISTNAME}00
CATEGORIES=	time perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=DateTime/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://datetime.perl.org/
COMMENT=	Perl module for date/time sets and ranges
LICENSE=	artistic-2.0

DEPENDS+=	p5-Class-Factory-Util-[0-9]*:../../devel/p5-Class-Factory-Util
DEPENDS+=	p5-DateTime-Locale>=0.41:../../time/p5-DateTime-Locale
DEPENDS+=	p5-DateTime-TimeZone>=0.59:../../time/p5-DateTime-TimeZone
DEPENDS+=	p5-Params-Validate>=0.76:../../devel/p5-Params-Validate
DEPENDS+=	{perl>=5.8.1,p5-Test-Simple-[0-9]*}:../../devel/p5-Test-Simple
#BUILD_DEPENDS+=	p5-podlators>=1.14:../../textproc/p5-podlators

USE_LANGUAGES=	c # installs C module
PERL5_PACKLIST=	auto/DateTime/.packlist

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
