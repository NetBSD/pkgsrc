# $NetBSD: Makefile,v 1.25 2026/06/28 06:21:36 wiz Exp $

DISTNAME=	HTTP-Date-6.07
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/O/OA/OALDERS/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/HTTP-Date
COMMENT=	Perl 5 module providing date conversion routines
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-TimeDate-[0-9]*:../../time/p5-TimeDate

CONFLICTS+=	p5-libwww<6.00

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/HTTP/Date/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
