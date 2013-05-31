# $NetBSD: Makefile,v 1.6 2013/05/31 12:42:48 wiz Exp $
#

DISTNAME=	ParallelUserAgent-2.57
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	www net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=LWP/}
MASTER_SITES=  	${MASTER_SITE_PERL_CPAN:=../../authors/id/M/MA/MARCLANG/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/ParallelUserAgent/
COMMENT=	CPAN Bundle for the LWP Parallel User Agent extension

DEPENDS+=     p5-libwww>=5.64:../../www/p5-libwww

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/LWP/Parallel/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
