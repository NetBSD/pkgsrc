# $NetBSD: Makefile,v 1.27 2026/07/16 19:05:34 wiz Exp $

DISTNAME=	DateTime-Format-Epoch-0.16
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	11
CATEGORIES=	time perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=DateTime/}

MAINTAINER=	bouyer@NetBSD.org
HOMEPAGE=	https://metacpan.org/dist/DateTime-Format-Epoch
COMMENT=	Convert DateTimes to/from epoch seconds
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-DateTime>=0.31:../../time/p5-DateTime

PERL5_PACKLIST=	auto/DateTime/Format/Epoch/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
