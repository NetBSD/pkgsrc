# $NetBSD: Makefile,v 1.25 2022/06/28 11:36:54 wiz Exp $

DISTNAME=	DateTime-Format-ISO8601-0.16
PKGNAME=	p5-${DISTNAME}00
PKGREVISION=	2
CATEGORIES=	time perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=DateTime/}

MAINTAINER=	abs@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/DateTime-Format-ISO8601
COMMENT=	Parses ISO8601 formats
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-DateTime>=1.45:../../time/p5-DateTime
DEPENDS+=	p5-DateTime-Format-Builder>=0.77:../../time/p5-DateTime-Format-Builder

TEST_DEPENDS+=	p5-Test2-Suite-[0-9]*:../../devel/p5-Test2-Suite

PERL5_PACKLIST=		auto/DateTime/Format/ISO8601/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
