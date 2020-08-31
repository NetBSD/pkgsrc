# $NetBSD: Makefile,v 1.15 2020/08/31 18:12:24 wiz Exp $

DISTNAME=	DateTime-Precise-1.05
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	12
CATEGORIES=	time perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=DateTime/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/DateTime-Precise
COMMENT=	Perl module for common time and date operations with GPS ops

PERL5_PACKLIST=	auto/DateTime/Precise/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
