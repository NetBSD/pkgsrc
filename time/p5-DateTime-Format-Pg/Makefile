# $NetBSD: Makefile,v 1.7 2010/08/04 16:37:00 sno Exp $

DISTNAME=	DateTime-Format-Pg-0.16005
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	time perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=DateTime/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/DateTime-Format-Pg/
COMMENT=	Parse and format PostgreSQL dates and times
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-DateTime>=0.1000:../../time/p5-DateTime
DEPENDS+=	p5-DateTime-Format-Builder>=0.72:../../time/p5-DateTime-Format-Builder
DEPENDS+=	p5-DateTime-TimeZone>=0.05:../../time/p5-DateTime-TimeZone

PERL5_PACKLIST=		auto/DateTime/Format/Pg/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
