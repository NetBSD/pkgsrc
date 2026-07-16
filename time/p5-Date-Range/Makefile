# $NetBSD: Makefile,v 1.5 2026/07/16 19:05:32 wiz Exp $

DISTNAME=	Date-Range-1.41
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	time perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Date/}

MAINTAINER=	kuli0020@umn.edu
HOMEPAGE=	https://metacpan.org/release/Date-Range
COMMENT=	Date::Range - deal with a range of dates
LICENSE=	gnu-gpl-v2

DEPENDS+=		p5-Date-Simple>=0.03:../../devel/p5-Date-Simple

USE_LANGUAGES=	# empty

PERL5_PACKLIST=	auto/Date/Range/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
