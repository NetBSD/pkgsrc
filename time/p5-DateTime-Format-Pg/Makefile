# $NetBSD: Makefile,v 1.1.1.1 2007/06/10 11:23:14 abs Exp $

DISTNAME=	DateTime-Format-Pg-0.16001
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	time perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=DateTime/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/DateTime-Format-Pg/
COMMENT=	Parse and format PostgreSQL dates and times

DEPENDS+=	p5-DateTime-Format-Builder>=0.72:../../time/p5-DateTime-Format-Builder
DEPENDS+=	p5-DateTime-TimeZone>=0.05:../../time/p5-DateTime-TimeZone
DEPENDS+=	p5-DateTime>=0.10:../../time/p5-DateTime

PERL5_PACKLIST=		auto/DateTime/Format/Pg/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
