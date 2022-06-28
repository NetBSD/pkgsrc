# $NetBSD: Makefile,v 1.17 2022/06/28 11:36:55 wiz Exp $

DISTNAME=	DateTime-Precise-1.05
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	14
CATEGORIES=	time perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=DateTime/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/DateTime-Precise
COMMENT=	Perl module for common time and date operations with GPS ops

PERL5_PACKLIST=	auto/DateTime/Precise/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
