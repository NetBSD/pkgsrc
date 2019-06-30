# $NetBSD: Makefile,v 1.13 2019/06/30 20:17:15 nia Exp $

DISTNAME=	DateTime-Format-SQLite-0.11
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	9
CATEGORIES=	time perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=DateTime/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/DateTime-Format-SQLite
COMMENT=	Parse and format SQLite dates and times
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-DateTime>=0.10:../../time/p5-DateTime
DEPENDS+=	p5-DateTime-Format-Builder>=0.60:../../time/p5-DateTime-Format-Builder

PERL5_PACKLIST=		auto/DateTime/Format/SQLite/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
