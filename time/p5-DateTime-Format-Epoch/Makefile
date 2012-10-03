# $NetBSD: Makefile,v 1.10 2012/10/03 21:58:19 wiz Exp $

DISTNAME=	DateTime-Format-Epoch-0.13
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	time perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=DateTime/}

MAINTAINER=	bouyer@NetBSD.org
HOMEPAGE=	http://datetime.perl.org/
#HOMEPAGE=	http://search.cpan.org/dist/DateTime-Format-Epoch/
COMMENT=	Convert DateTimes to/from epoch seconds
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-DateTime>=0.31:../../time/p5-DateTime

PERL5_PACKLIST=	auto/DateTime/Format/Epoch/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
