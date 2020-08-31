# $NetBSD: Makefile,v 1.17 2020/08/31 18:12:25 wiz Exp $

DISTNAME=	Schedule-At-1.15
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	6
CATEGORIES=	time perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Schedule/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Schedule-At
COMMENT=	OS independent interface to the Unix 'at' command
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Schedule/At/.packlist

TEST_ENV=	AT_CAN_EXEC=1

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
