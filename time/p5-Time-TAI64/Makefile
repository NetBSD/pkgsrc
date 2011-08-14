# $NetBSD: Makefile,v 1.6 2011/08/14 15:28:49 obache Exp $

DISTNAME=	Time-TAI64-2.11
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
SVR4_PKGNAME=	p5tt6
CATEGORIES=	time perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Time/}

MAINTAINER=	kleink@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Time-TAI64/
COMMENT=	Convert TAI64 strings into standard unix timestamps

PKG_DESTDIR_SUPPORT=	user-destdir

BUILD_DEPENDS+=	p5-Test-Simple-[0-9]*:../../devel/p5-Test-Simple
DEPENDS+=	p5-Time-HiRes-[0-9]*:../../time/p5-Time-HiRes

PERL5_PACKLIST=		auto/Time/TAI64/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
