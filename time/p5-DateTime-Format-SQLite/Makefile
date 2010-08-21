# $NetBSD: Makefile,v 1.3 2010/08/21 16:36:24 seb Exp $

DISTNAME=	DateTime-Format-SQLite-0.11
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	time perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=DateTime/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/DateTime-Format-SQLite/
COMMENT=	Parse and format SQLite dates and times
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-DateTime>=0.10:../../time/p5-DateTime
DEPENDS+=	p5-DateTime-Format-Builder>=0.60:../../time/p5-DateTime-Format-Builder

PERL5_PACKLIST=		auto/DateTime/Format/SQLite/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
