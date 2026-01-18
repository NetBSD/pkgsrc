# $NetBSD: Makefile,v 1.5 2026/01/18 09:09:44 wiz Exp $

DISTNAME=	DateTime-HiRes-0.04
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
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
