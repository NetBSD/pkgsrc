# $NetBSD: Makefile,v 1.2 2023/07/06 09:42:13 wiz Exp $

DISTNAME=	DateTime-HiRes-0.04
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	time perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=DateTime/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://datetime.perl.org/
COMMENT=	Create DateTime objects with sub-second current time resolution
LICENSE=	artistic-2.0

DEPENDS+=	p5-DateTime>=0:../../time/p5-DateTime

PERL5_PACKLIST=	auto/DateTime/HiRes/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
