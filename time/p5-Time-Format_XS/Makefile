# $NetBSD: Makefile,v 1.13 2019/08/11 13:24:11 wiz Exp $
#

DISTNAME=	Time-Format_XS-1.03
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	10
CATEGORIES=	time
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Time/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Time-Format_XS
COMMENT=	Companion module for Time::Format, to speed up time formatting

BUILD_DEPENDS+=	p5-Time-Format>=1.01:../../time/p5-Time-Format

PERL5_PACKLIST=	auto/Time/Format_XS/.packlist
USE_LANGUAGES=	c

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
