# $NetBSD: Makefile,v 1.11 2017/06/05 14:25:04 ryoon Exp $

DISTNAME=	DateTime-Format-SQLite-0.11
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	8
CATEGORIES=	time perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=DateTime/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/DateTime-Format-SQLite/
COMMENT=	Parse and format SQLite dates and times
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-DateTime>=0.10:../../time/p5-DateTime
DEPENDS+=	p5-DateTime-Format-Builder>=0.60:../../time/p5-DateTime-Format-Builder

PERL5_PACKLIST=		auto/DateTime/Format/SQLite/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
