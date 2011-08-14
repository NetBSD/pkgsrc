# $NetBSD: Makefile,v 1.9 2011/08/14 15:28:46 obache Exp $

DISTNAME=	DateTime-Format-Pg-0.16005
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
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
