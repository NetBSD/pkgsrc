# $NetBSD: Makefile,v 1.24 2023/07/06 09:42:13 wiz Exp $

DISTNAME=	DateTime-Format-W3CDTF-0.08
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	time perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=DateTime/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/DateTime-Format-W3CDTF
COMMENT=	Convert between DateTime and W3CDTF date/time format
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-DateTime-[0-9]*:../../time/p5-DateTime

PERL5_PACKLIST=	auto/DateTime/Format/W3CDTF/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
