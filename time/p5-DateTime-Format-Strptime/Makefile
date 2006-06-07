# $NetBSD: Makefile,v 1.1.1.1 2006/06/07 11:46:16 abs Exp $

DISTNAME=	DateTime-Format-Strptime-1.0700
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	time perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=DateTime/}

MAINTAINER=	abs@NetBSD.org
HOMEPAGE=	http://search.cpan.org/~rickm/DateTime-Format-Strptime/
COMMENT=	Parse and format strp and strf time patterns

DEPENDS+=	p5-DateTime>=0.14:../../time/p5-DateTime

PERL5_PACKLIST=		auto/DateTime/Format/Strptime/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
