# $NetBSD: Makefile,v 1.22 2022/06/28 11:36:57 wiz Exp $

DISTNAME=	Time-Clock-1.03
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	8
CATEGORIES=	time perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Time/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Time-Clock
COMMENT=	Twenty-four hour clock object with nanosecond precision
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Time/Clock/.packlist

post-extract:
	${FIND} ${WRKSRC} -name "*.pm" -type f -exec ${CHMOD} -x {} \;

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
