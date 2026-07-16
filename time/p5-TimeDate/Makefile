# $NetBSD: Makefile,v 1.46 2026/07/16 19:05:39 wiz Exp $

DISTNAME=	TimeDate-2.35
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	time perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/A/AT/ATOOMIC/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/TimeDate
COMMENT=	Perl5 TimeDate distribution
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/TimeDate/.packlist

post-extract:
	cd ${WRKSRC};							\
	for f in Russian_cp1251.pm Russian_koi8r.pm Turkish.pm; do	\
	chmod a-x lib/Date/Language/$${f};				\
	done

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
