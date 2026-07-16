# $NetBSD: Makefile,v 1.6 2026/07/16 19:05:36 wiz Exp $

DISTNAME=	DateTime-HiRes-0.04
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	time perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=DateTime/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/pod/DateTime::HiRes
COMMENT=	Create DateTime objects with sub-second current time resolution
LICENSE=	artistic-2.0

DEPENDS+=	p5-DateTime>=0:../../time/p5-DateTime

PERL5_PACKLIST=	auto/DateTime/HiRes/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
