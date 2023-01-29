# $NetBSD: Makefile,v 1.1 2023/01/29 10:20:28 wiz Exp $

DISTNAME=	Date-Range-1.41
PKGNAME=	p5-${DISTNAME}
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
