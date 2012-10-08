# $NetBSD: Makefile,v 1.14 2012/10/08 13:04:23 asau Exp $

DISTNAME=	DateTime-Format-Strptime-1.52
PKGNAME=	p5-${DISTNAME}00
PKGREVISION=	1
CATEGORIES=	time perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=DateTime/}

MAINTAINER=	abs@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/DateTime-Format-Strptime/
COMMENT=	Perl 5 module to parse and format strp and strf time patterns
LICENSE=	artistic-2.0

DEPENDS+=	p5-DateTime>=0.4400:../../time/p5-DateTime
DEPENDS+=	p5-DateTime-Locale>=0.45:../../time/p5-DateTime-Locale
DEPENDS+=	p5-DateTime-TimeZone>=0.79:../../time/p5-DateTime-TimeZone
DEPENDS+=	p5-Params-Validate>=0.64:../../devel/p5-Params-Validate

PERL5_PACKLIST=		auto/DateTime/Format/Strptime/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
