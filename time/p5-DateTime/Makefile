# $NetBSD: Makefile,v 1.11 2008/06/01 15:39:37 wiz Exp $

DISTNAME=	DateTime-0.4302
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	time perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=DateTime/}

MAINTAINER=	cube@NetBSD.org
HOMEPAGE=	http://datetime.perl.org/
COMMENT=	Perl module for date/time sets and ranges

DEPENDS+=	p5-Class-Factory-Util-[0-9]*:../../devel/p5-Class-Factory-Util
DEPENDS+=	p5-DateTime-TimeZone>=0.59:../../time/p5-DateTime-TimeZone
DEPENDS+=	p5-DateTime-Locale>=0.40:../../time/p5-DateTime-Locale
DEPENDS+=	p5-Params-Validate>=0.76:../../devel/p5-Params-Validate
DEPENDS+=	{perl>=5.8.1,p5-Test-Simple-[0-9]*}:../../devel/p5-Test-Simple

USE_LANGUAGES=	c # installs C module
PERL5_PACKLIST=	auto/DateTime/.packlist

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
