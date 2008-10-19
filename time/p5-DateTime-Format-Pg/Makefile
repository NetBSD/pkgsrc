# $NetBSD: Makefile,v 1.4 2008/10/19 19:19:00 he Exp $

DISTNAME=	DateTime-Format-Pg-0.16002
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	time perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=DateTime/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/DateTime-Format-Pg/
COMMENT=	Parse and format PostgreSQL dates and times

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-DateTime-Format-Builder>=0.72:../../time/p5-DateTime-Format-Builder
DEPENDS+=	p5-DateTime-TimeZone>=0.05:../../time/p5-DateTime-TimeZone
DEPENDS+=	p5-DateTime>=0.10:../../time/p5-DateTime

PERL5_PACKLIST=		auto/DateTime/Format/Pg/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
